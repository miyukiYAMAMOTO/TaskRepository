#include <DxLib.h>
//�f�t�H���g��X86�ɂȂ��Ă���̂ŁAX64�ɂ��ĂˁI�I


int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	SetGraphMode(640, 480, 32);
	SetWindowText(_T("1916045_�R�{���R�I"));
	ChangeWindowMode(true);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	

	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClearDrawScreen();
		ScreenFlip();
	}

	DxLib_End();
	return 0;
}