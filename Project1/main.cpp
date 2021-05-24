#include <stdio.h>
#include <DxLib.h>
#include <cassert>
#include <sstream>
#include <iomanip>
//デフォルトでX86になっているので、X64にしてね！！

class Vector2
{
public:
	Vector2() :x_(0), y_(0) {};
	Vector2(int x,int y) :x_(x), y_(y) {};
	~Vector2() {};
	int x_;
	int y_;

};



int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	SetGraphMode(640, 480, 32);
	SetWindowText(_T("1916045_山本美由紀"));
	ChangeWindowMode(true);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	
	int advenH[6];
	for (int i = 0; i < 6; i++)
	{
		wchar_t path[30];
		wsprintf(path, L"img/adventurer-run-0%d.png",i);
		advenH[i] = LoadGraph(path);
		assert(advenH[i] != -1);
	}
	unsigned int frame = 0;
	Vector2 pos = { 50, 50 };
	while (!ProcessMessage() && !CheckHitKey(KEY_INPUT_ESCAPE))
	{
		ClearDrawScreen();
		DrawCircle(pos.x_, pos.y_, 10, 0xffffff, true);
		char out[64];
	/*	printf_s(out, L"x = %d,y = %d",pos.x_,pos.y_);
		OutputDebugStringA(out);
	*/	//std::ostringstream oss;
		/*oss << L"x = %d" << pos.x_;
		oss << L", y = %d" << pos.y_;
		OutputDebugStringA(oss.str().c_str());*/
		DrawRotaGraph(pos.x_, pos.y_, 2.0f, 0.0f, advenH[frame / 10], true);

		if (CheckHitKey(KEY_INPUT_RIGHT))
		{
			pos.x_ += 5;
		}
		if (CheckHitKey(KEY_INPUT_LEFT))
		{
			pos.x_ -= 5;
		}
		if (CheckHitKey(KEY_INPUT_UP))
		{
			pos.y_ -= 5;
		}
		if (CheckHitKey(KEY_INPUT_DOWN))
		{
			pos.y_ += 5;
		}
		ScreenFlip();

		frame = (frame + 1) % 100;
	}

	DxLib_End();
	return 0;
}