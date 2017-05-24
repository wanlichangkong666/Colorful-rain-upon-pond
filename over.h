#pragma once
#include"statement.h"
void over()//场景结束函数

{
	getch();
	cleardevice();
	mciSendString(L"close bgm", 0, 0, 0);//关闭背景音乐
	mciSendString(L"close rain", 0, 0, 0);//关闭雨声
	TerminateThread(thundering, 0);//结束雷电线程
	CloseHandle(thundering);//释放掉雷电线程所占堆栈
	_stprintf(s, _T("%.5f"), waterLevel);//将浮点型水位转化为字符串类型，以用来显示在图形界面上
	settextstyle(50, 0, L"黑体");
	//输出文字表示下雨结束
	setcolor(LIGHTRED);
	outtextxy(150, 200, L"一夜过后.....");
	getch();
	cleardevice();//清屏来显示池塘水位
	//显示最终池塘水位
	setcolor(LIGHTBLUE);
	settextstyle(50, 0, L"黑体");
	outtextxy(70, 200, L"池塘水位：");
	outtextxy(320, 200, s);
	getch();
	//显示结尾图片
	IMAGE secondDay;
	loadimage(&secondDay, L"白天.jpg", window_X, window_Y);
	putimage(0, 0, &secondDay);
	getch();
	//释放掉雨滴链表所占空间
	struct raindrop *p, *pf;
	p = head;
	while (p != NULL)
	{
		pf = p;
		p = p->next;
		free(pf);
	}
	closegraph();//关闭图形界面
}