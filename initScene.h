#pragma once
#include"statement.h"
void darkClouds()//绘制乌云函数
{
	int x;
	setfillcolor(DARKGRAY);
	solidrectangle(0, 0, 640, 30);
	for (x = 1; x <= 20; x++)
		solidcircle(x * 32 - 16, 30, 20);
}
void lotusLeaf()//绘制荷叶函数
{
	int i;
	int x;
	setfillcolor(LIGHTGREEN);
	solidellipse(x = 70, waterHeight, x + 60, waterHeight + 30);
	solidellipse(x = 100, waterHeight, x + 60, waterHeight + 30);
	solidellipse(x = 250, waterHeight, x + 60, waterHeight + 30);
	solidellipse(x = 300, waterHeight, x + 60, waterHeight + 30);
	solidellipse(x = 500, waterHeight, x + 60, waterHeight + 30);
}
void pond()//绘制池塘函数
{
	setfillcolor(BLUE);
	solidrectangle(0, waterHeight, window_X, window_Y);
	lotusLeaf();
}
void start()//场景开头介绍函数
{
	int x;
	int y;
	_stprintf(s, _T("%.5f"), waterLevel);
	IMAGE bg;
	loadimage(&bg, L"梦幻.jpg", window_X, window_Y);
	setbkmode(TRANSPARENT);//设置字体背景为透明
	x = 190;
	y = 100;
	putimage(0, 0, &bg);
	//以彩虹的颜色顺序显示主题
	settextstyle(50, 0, L"楷体");
	settextcolor(LIGHTRED);
	outtextxy(x + 10, y + 10, L"池");
	settextcolor(RGB(250, 200, 50));
	outtextxy(x + 60, y + 10, L"塘");
	settextcolor(YELLOW);
	outtextxy(x + 110, y + 10, L"夜");
	settextcolor(LIGHTGREEN);
	outtextxy(x + 160, y + 10, L"降");
	settextcolor(LIGHTCYAN);
	outtextxy(x + 90, y + 100, L"彩");
	settextcolor(LIGHTBLUE);
	outtextxy(x + 140, y + 100, L"色");
	settextcolor(LIGHTMAGENTA);
	outtextxy(x + 190, y + 100, L"雨");
	//显示项目成员
	setcolor(YELLOW);
	settextstyle(30, 0, L"宋体");
	outtextxy(x - 180, y + 250, L"----");
	outtextxy(x - 100, y + 250, L"王翔宇");
	outtextxy(x + 50, y + 250, L"马纯翠");
	outtextxy(x + 200, y + 250, L"吴艳丽");
	outtextxy(x + 350, y + 250, L"傅  宇");
	getch();
	cleardevice();
	//显示初始水位
	setcolor(LIGHTBLUE);
	settextstyle(50, 0, L"黑体");
	outtextxy(70, 200, L"池塘水位：");
	outtextxy(320, 200, s);
	getch();
	cleardevice();
}
void initScene(void) //场景初始化函数
{
	initgraph(640, 480);//初始化图形界面
	window_X = getwidth();//获得图形界面宽度以备后用
	window_Y = getheight();//获得图形界面高度以备后用
	start();
	pond();
	darkClouds();
}