/*-----------------------------------------------

	[Application.cpp]
	Author : 出合翔太

	[説明]
	アプリケーション全体の管理：シングルトン

-----------------------------------------------*/
#include "Application.h"
#include "Input.h"
#include "Fps.h"
#include "GameManager.h"
#include "Resource.h"

// ウィンドウプロシージャ
LRESULT WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_ESCAPE:
			DestroyWindow(hWnd);
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}


void Application::Init(HINSTANCE h)
{
	auto result = CoInitializeEx(0, COINITBASE_MULTITHREADED);
	if (MessageBox(NULL, "ウィンドウモードで起動しますか？", "画面モード確認", MB_YESNO) == IDYES)
	{
		m_Mode = true;
	}
	CreateGameWindow(m_hwnd, m_WindowClass); // ゲームウィンドウ
	InputDevice::Init(h, m_hwnd, m_Mode);			// コントローラの初期化
}

void Application::Run()
{
	// ウィンドウ表示
	ShowWindow(m_hwnd, SW_SHOW);
	UpdateWindow(m_hwnd);

	// フレームレートの初期化
	Fps& fps = Fps::GetInstance();
	fps.Init();
	GameManager& mgr = GameManager::GetInstance();
	mgr.Init();

	// メッセージループ
	MSG msg;
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) // PostQuitMessage()が呼ばれたらループ終了
			{
				break;
			}
			else
			{
				// メッセージの翻訳とディスパッチ
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			if (fps.Update())
			{
				InputDevice::Update(); // コントローラの更新
				mgr.Update();
				mgr.Draw();
			}
		}
	}


	mgr.Uninit();
	fps.Uninit();
	InputDevice::Uninit();  // コントローラの終了処理 
	timeEndPeriod(1);		// 分解能を戻す
	UnregisterClass(m_WindowClass.lpszClassName, m_WindowClass.hInstance); // ウィンドウクラスの登録を解除
}

void Application::CreateGameWindow(HWND & hwnd, WNDCLASSEX & window)
{
	if (m_Mode == true) // ウィンドウモード
	{
		HINSTANCE hInstance = GetModuleHandle(NULL);
		// ウィンドウの生成＆登録
		window.cbSize = sizeof(WNDCLASSEX);
		window.lpfnWndProc = (WNDPROC)WndProc; // コールバック関数の指定
		window.lpszClassName = "Dx11";			// アプリケーション名
		window.hInstance = GetModuleHandle(0);	// ハンドルの指定
		RegisterClassEx(&window);				// アプリケーションクラス
		RECT wrc = { 0,0,m_Width, m_Height };
		AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);
		// ウィンドウオブジェクトの生成
		hwnd = CreateWindow(window.lpszClassName,		// クラス名
			"ゲームアプリ",								// タイトルバー
			WS_OVERLAPPEDWINDOW,						// ウィンドウタイプ
			CW_USEDEFAULT, CW_USEDEFAULT,				// 表示xy座標はOSに任せる
			wrc.right - wrc.left, wrc.bottom - wrc.top, // ウィンドウ幅と高さ
			NULL, NULL, window.hInstance, NULL);		// ウィンドウハンドル, メニューハンドル,呼び出しアプリケーションハンドル, 追加パラメータ
	}
	else if(m_Mode == false)
	{
		HINSTANCE hInstance = GetModuleHandle(NULL);
		// ウィンドウの生成＆登録
		window.cbSize = sizeof(WNDCLASSEX);
		window.lpfnWndProc = (WNDPROC)WndProc; // コールバック関数の指定
		window.lpszClassName = "Dx11";			// アプリケーション名
		window.hInstance = GetModuleHandle(0);	// ハンドルの指定
		RegisterClassEx(&window);				// アプリケーションクラス
		RECT wrc = { 0,0,m_Width, m_Height };
		AdjustWindowRect(&wrc, WS_CAPTION, false);
		// ウィンドウオブジェクトの生成
		hwnd = CreateWindow(window.lpszClassName,		// クラス名
			"ゲームアプリ",								// タイトルバー
			WS_VISIBLE | WS_POPUP,						// ウィンドウタイプ
			CW_USEDEFAULT, CW_USEDEFAULT,				// 表示xy座標はOSに任せる
			wrc.right - wrc.left, wrc.bottom - wrc.top, // ウィンドウ幅と高さ
			NULL, NULL, window.hInstance, NULL);		// ウィンドウハンドル, メニューハンドル,呼び出しアプリケーションハンドル, 追加パラメータ
	}
}
