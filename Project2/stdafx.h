/*--------------------------------------------------------------------
	
	[stdafx,h]
	Author : �o���đ�

--------------------------------------------------------------------*/
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define NOMINMAX
#include <stdio.h>
#include <windows.h>
#include <wrl/client.h>
#include <array>
#include <vector>
#include <memory>

#pragma warning(disable:4005)
#pragma warning(push)

// DirectX��API
#include <d3d11.h>
#include <d3dx9.h>
#include <d3dx11.h>
// �Z�p���C�u����
#include <DirectXMath.h>
// �V�F�[�_�[�̃R���p�C��
#include <d3dcompiler.h>

#pragma warning(pop)

#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"d3dx11.lib")
#pragma comment(lib,"dxgi.lib")
#pragma comment(lib,"d3dcompiler.lib")


