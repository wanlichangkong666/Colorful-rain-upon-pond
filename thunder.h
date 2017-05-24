#pragma once
#include"statement.h"
DWORD WINAPI thunder(LPVOID lpParam)//电闪雷鸣函数（单独一个线程）
{
	IMAGE thunder;
	loadimage(&thunder, L"闪电.jpg", 120, 200);//用thunder变量接收闪电图片
	int thunder_X;//定义闪电出现的x坐标
	for (; ; rainTime++)
	{
		//当下雨时长达到雷电时间间隔时便出现电闪雷鸣效果
		if (rainTime%thunderTime == 0)
		{
			//先看见闪电再听到雷声
			putimage(thunder_X = 120 * rand() % window_X, 50, &thunder);//闪电在天空中随机位置出现
			mciSendString(L"play 雷声.mp3", 0, 0, 0);
			//让闪电短暂显示后消失
			Sleep(500);
			clearrectangle(thunder_X, 50, thunder_X + 120, 250);
		}
		Sleep(3);
	}
	return 0;
}