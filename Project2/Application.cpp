/*-----------------------------------------------

	[Application.cpp]
	Author : �o���đ�

	[����]
	�A�v���P�[�V�����S�̂̊Ǘ��F�V���O���g��

-----------------------------------------------*/
#include "Application.h"
#include "Input.h"
#include "Fps.h"
#include "Manager.h"
#include "Resource.h"

// �E�B���h�E�v���V�[�W��
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
	if (MessageBox(NULL, "�E�B���h�E���[�h�ŋN�����܂����H", "��ʃ��[�h�m�F", MB_YESNO) == IDYES)
	{
		m_Mode = true;
	}
	CreateGameWindow(m_hwnd, m_WindowClass); // �Q�[���E�B���h�E
	InputDevice::Init(h, m_hwnd, m_Mode);			// �R���g���[���̏�����
}

void Application::Run()
{
	// �E�B���h�E�\��
	ShowWindow(m_hwnd, SW_SHOW);
	UpdateWindow(m_hwnd);

	// �t���[�����[�g�̏�����
	Fps& fps = Fps::GetInstance();
	fps.Init();
	//Manager::Init();
	Manager& mgr = Manager::GetInstance();
	mgr.Init();
	// ���b�Z�[�W���[�v
	MSG msg;
	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) // PostQuitMessage()���Ă΂ꂽ�烋�[�v�I��
			{
				break;
			}
			else
			{
				// ���b�Z�[�W�̖|��ƃf�B�X�p�b�`
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			if (fps.Update())
			{
				InputDevice::Update(); // �R���g���[���̍X�V
				mgr.Update();
				mgr.Draw();
			}
		}
	}


	mgr.Uninit();
	fps.Uninit();
	InputDevice::Uninit();  // �R���g���[���̏I������ 
	timeEndPeriod(1);		// ����\��߂�
	UnregisterClass(m_WindowClass.lpszClassName, m_WindowClass.hInstance); // �E�B���h�E�N���X�̓o�^������
}

void Application::CreateGameWindow(HWND & hwnd, WNDCLASSEX & window)
{
	if (m_Mode == true) // �E�B���h�E���[�h
	{
		HINSTANCE hInstance = GetModuleHandle(NULL);
		// �E�B���h�E�̐������o�^
		window.cbSize = sizeof(WNDCLASSEX);
		window.lpfnWndProc = (WNDPROC)WndProc; // �R�[���o�b�N�֐��̎w��
		window.lpszClassName = "Dx11";			// �A�v���P�[�V������
		window.hInstance = GetModuleHandle(0);	// �n���h���̎w��
		RegisterClassEx(&window);				// �A�v���P�[�V�����N���X
		RECT wrc = { 0,0,m_Width, m_Height };
		AdjustWindowRect(&wrc, WS_OVERLAPPEDWINDOW, false);
		// �E�B���h�E�I�u�W�F�N�g�̐���
		hwnd = CreateWindow(window.lpszClassName,		// �N���X��
			"�Q�[���A�v��",								// �^�C�g���o�[
			WS_OVERLAPPEDWINDOW,						// �E�B���h�E�^�C�v
			CW_USEDEFAULT, CW_USEDEFAULT,				// �\��xy���W��OS�ɔC����
			wrc.right - wrc.left, wrc.bottom - wrc.top, // �E�B���h�E���ƍ���
			NULL, NULL, window.hInstance, NULL);		// �E�B���h�E�n���h��, ���j���[�n���h��,�Ăяo���A�v���P�[�V�����n���h��, �ǉ��p�����[�^
	}
	else if(m_Mode == false)
	{
		HINSTANCE hInstance = GetModuleHandle(NULL);
		// �E�B���h�E�̐������o�^
		window.cbSize = sizeof(WNDCLASSEX);
		window.lpfnWndProc = (WNDPROC)WndProc; // �R�[���o�b�N�֐��̎w��
		window.lpszClassName = "Dx11";			// �A�v���P�[�V������
		window.hInstance = GetModuleHandle(0);	// �n���h���̎w��
		RegisterClassEx(&window);				// �A�v���P�[�V�����N���X
		RECT wrc = { 0,0,m_Width, m_Height };
		AdjustWindowRect(&wrc, WS_CAPTION, false);
		// �E�B���h�E�I�u�W�F�N�g�̐���
		hwnd = CreateWindow(window.lpszClassName,		// �N���X��
			"�Q�[���A�v��",								// �^�C�g���o�[
			WS_VISIBLE | WS_POPUP,						// �E�B���h�E�^�C�v
			CW_USEDEFAULT, CW_USEDEFAULT,				// �\��xy���W��OS�ɔC����
			wrc.right - wrc.left, wrc.bottom - wrc.top, // �E�B���h�E���ƍ���
			NULL, NULL, window.hInstance, NULL);		// �E�B���h�E�n���h��, ���j���[�n���h��,�Ăяo���A�v���P�[�V�����n���h��, �ǉ��p�����[�^
	}
}
