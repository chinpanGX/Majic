/*-------------------------------------------------------------

	[Input.h]
	Author : �o���đ�

	[����]
	DirectInput�̓��͏���
	�X�^�e�B�b�N

--------------------------------------------------------------*/
#include <Windows.h>
#define DIRECTINPUT_VERSION (0x0800)	//	DirectInput�̃o�[�W����
#include <dinput.h>

#pragma comment(lib, "dinput8.lib")
#pragma comment(lib, "dxguid.lib")

// �}�N����`	
#define SAFE_RELEASE(p) do {if(p){(p)->Release(); (p) = NULL;} } while(0)	// DirectX�f�o�C�X����}�N��
#define	NUM_KEY_MAX			(256)
// �Q�[���p�b�h�p�̐ݒ�l
#define DEADZONE	(2500)	// �e����25%�𖳌��]�[���Ƃ���
#define RANGE_MAX	(1000)	// �L���͈͂̍ő�l
#define RANGE_MIN	(-1000)	// �L���͈͂̍ŏ��l

//�Q�[���p�b�h�iXbox��PS4�j�̓��͂̃}�N��
#define LS_UP		(0x00000001l) // PS4	Xbox : ���X�e�B�b�N��(.IY<0)
#define LS_DOWN		(0x00000002l) // PS4	Xbox : ���X�e�B�b�N��(.IY>0)
#define LS_LEFT		(0x00000004l) // PS4	Xbox : ���X�e�B�b�N��(.IX<0)
#define LS_RIGHT	(0x00000008l) // PS4	Xbox : ���X�e�B�b�N�E(.IX>0)
#define POV_UP		(0x00400000l) // PS4	Xbox : �����L�[��(rgdwPOV[0] = 0)
#define POV_DOWN	(0x00800000l) // PS4	Xbox : �����L�[��(.rgdwPOV[0] = 18000)
#define POV_LEFT	(0x01000000l) // PS4	Xbox : �����L�[��(.rgdwPOV[0] = 27000)
#define POV_RIGHT	(0x02000000l) // PS4	Xbox : �����L�[�E(.rgdwPOV[0] = 9000)

#define BTN_1		(0x00008000l) // PS4 �F ���{�^��	  Xbox : �x�{�^��(.rgbButtons[3]&0x80)
#define BTN_2		(0x00004000l) // PS4 �F �Z�{�^��	  Xbox : �w�{�^��(.rgbButtons[2]&0x80)
#define BTN_3		(0x00002000l) // PS4 �F �~�{�^��	  Xbox : �a�{�^��(.rgbButtons[1]&0x80)
#define BTN_4		(0x00001000l) // PS4 �F ���{�^��	  Xbox : �`�{�^��(.rgbButtons[0]&0x80)
#define BTN_L1		(0x00010000l) // PS4 �F L1�{�^��	  Xbox : LB�{�^��(.rgbButtons[4]&0x80)
#define BTN_R1		(0x00020000l) // PS4 �F R1�{�^��	  Xbox : RB�{�^��(.rgbButtons[5]&0x80)
#define BTN_L2		(0x00000400l) // PS4 : L2�g���K�[(.lRx>10000)
#define BTN_R2		(0x00000800l) // PS4 : R2�g���K�[(.lRy>10000)

#define BTN_OPTION	(0x00040000l) // PS4 �F OPTION�{�^��  Xbox : BACK�{�^��(.rgbButtons[6]&0x80)
#define BTN_SHARE	(0x00080000l) // PS4 �F SHARE�{�^��	  Xbox : START�{�^��(.rgbButtons[7]&0x80)

#define RS_UP		(0x00000010l) // PS4 : �E�X�e�B�b�N��(.lRz<16383)
#define RS_DOWN		(0x00000020l) // PS4 : �E�X�e�B�b�N��(.lRz>49150)
#define RS_RIGHT	(0x00000040l) // PS4 : �E�X�e�B�b�N�E(.lZ<16383)
#define RS_LEFT		(0x00000080l) // PS4 : �E�X�e�B�b�N��(.lZ>49150)

#define XboxRIGHTSTICK_UP	 (0x04000000l) // Xbox : �E�X�e�B�b�N��(.lRz<16383)
#define XboxRIGHTSTICK_DOWN	 (0x10000000l) // Xbox : �E�X�e�B�b�N��(.lRz>49150)
#define XboxRIGHTSTICK_LEFT	 (0x20000000l) // Xbox : �E�X�e�B�b�N�E(.lZ<16383)
#define XboxRIGHTSTICK_RIGHT (0x40000000l) // Xbox : �E�X�e�B�b�N��(.lZ>49150
#define TRIGGER_LT			 (0x00000100l) // Xbox : LT�g���K�[(.lZ>49150)
#define TRIGGER_RT			 (0x00000200l) // Xbox : RT�g���K�[(.lZ<16383)
#define BUTTON_L3			 (0x00100000l) // Xbox : L3�{�^��(.rgbButtons[8]&0x80)
#define BUTTON_R3			 (0x00200000l) // Xbox : R3�{�^��(.rgbButtons[9]&0x80)

#define GAMEPADMAX (4) // �����ɐڑ�����W���C�p�b�h�̍ő吔���Z�b�g

class InputDevice
{
protected:
	static LPDIRECTINPUT8 m_Input;
public:
	static bool Init(HINSTANCE hInstance, HWND hWnd, bool UseMouse = false);
	static void Uninit();
	static void Update();
};

/* �L�[�{�[�h�̓��͂��Ǘ� */
class KeyBoard : public InputDevice
{
private:
	static LPDIRECTINPUTDEVICE8	m_DevKeyboard;						//	�L�[�{�[�h�f�o�C�X
	static BYTE					m_aKeyState[NUM_KEY_MAX];			//	�L�[�{�[�h���(�����Ă���Ƃ�)
	static BYTE					m_aKeyStateTrigger[NUM_KEY_MAX];	//	�L�[�{�[�h���(�������u��)
	static BYTE					m_aKeyStateRelease[NUM_KEY_MAX];	//	�L�[�{�[�h���(�������u��)
public:
	static HRESULT Init(HINSTANCE hInstance, HWND hWnd);			//	����������
	static void Uninit();											//	�I������
	static void Update();											//	�X�V����
	static bool IsPress(int nKey);									//	�����Ă����
	static bool IsTrigger(int nKey);								//	�������u��
	static bool IsRelease(int nKey);								//	�������u��
};

/* �Q�[���p�b�h�R���g���[���̓��͂��Ǘ� */
class GamePad : public InputDevice
{
private:
	static LPDIRECTINPUTDEVICE8	m_GamePad[GAMEPADMAX];								//�@�p�b�h�f�o�C�X
	static DWORD				m_padState[GAMEPADMAX];								//	�p�b�h���(�����Ă���Ƃ�)
	static DWORD				m_padTrigger[GAMEPADMAX];							//	�p�b�h���(�������u��)
	static int					m_padCount;											//�@���o�����p�b�h�̐�
public:
	static BOOL CALLBACK SearchGamePadCallback(LPDIDEVICEINSTANCE lpddi, LPVOID);	//	�R�[���o�b�N�֐�
	static HRESULT Init(HINSTANCE hInstance, HWND hWnd);							//	������
	static void Uninit();															//	�I������
	static void Update();															//	�X�V����
	static BOOL IsPress(int padNo, DWORD button);									//	�{�^���������Ă����
	static BOOL IsTrigger(int padNo, DWORD button);									//	�{�^�����������u��
};

/* �}�E�X�̓��͂��Ǘ� */
class Mouse : public InputDevice
{
private:
	static LPDIRECTINPUTDEVICE8 m_Mouse;		// �}�E�X�f�o�C�X
	static DIMOUSESTATE2		m_mouseState;	// �}�E�X�̃_�C���N�g�ȏ��
	static DIMOUSESTATE2		m_mouseTrigger;	// �����ꂽ�u�Ԃ���ON
public:
	static HRESULT	Init(HINSTANCE hInst, HWND hWnd, bool bShaw = false); //	������
	static void		Uninit();									 // �I������
	static HRESULT	Update();									 // �X�V����
	static BOOL		LeftPress();								 // ���N���b�N�������
	static BOOL		LeftTrigger();								 // ���N���b�N�����u��
	static BOOL		RightPress();								 // �E�N���b�N�������
	static BOOL		RightTrigger();								 // �E�N���b�N�����u��
	static BOOL		CenterPress();								 // �����N���b�N�������
	static BOOL		CenterTrigger();							 // �����N���b�N�����u��
	static long		GetMouseX();								 // �}�E�X��X�����ɓ��������Βl
	static long		GetMouseY();								 // �}�E�X��Y�����ɓ��������Βl
	static long		GetMouseZ();								 // �}�E�X�z�C�[�������������Βl
};

