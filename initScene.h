#pragma once
#include"statement.h"
void darkClouds()//�������ƺ���
{
	int x;
	setfillcolor(DARKGRAY);
	solidrectangle(0, 0, 640, 30);
	for (x = 1; x <= 20; x++)
		solidcircle(x * 32 - 16, 30, 20);
}
void lotusLeaf()//���ƺ�Ҷ����
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
void pond()//���Ƴ�������
{
	setfillcolor(BLUE);
	solidrectangle(0, waterHeight, window_X, window_Y);
	lotusLeaf();
}
void start()//������ͷ���ܺ���
{
	int x;
	int y;
	_stprintf(s, _T("%.5f"), waterLevel);
	IMAGE bg;
	loadimage(&bg, L"�λ�.jpg", window_X, window_Y);
	setbkmode(TRANSPARENT);//�������屳��Ϊ͸��
	x = 190;
	y = 100;
	putimage(0, 0, &bg);
	//�Բʺ����ɫ˳����ʾ����
	settextstyle(50, 0, L"����");
	settextcolor(LIGHTRED);
	outtextxy(x + 10, y + 10, L"��");
	settextcolor(RGB(250, 200, 50));
	outtextxy(x + 60, y + 10, L"��");
	settextcolor(YELLOW);
	outtextxy(x + 110, y + 10, L"ҹ");
	settextcolor(LIGHTGREEN);
	outtextxy(x + 160, y + 10, L"��");
	settextcolor(LIGHTCYAN);
	outtextxy(x + 90, y + 100, L"��");
	settextcolor(LIGHTBLUE);
	outtextxy(x + 140, y + 100, L"ɫ");
	settextcolor(LIGHTMAGENTA);
	outtextxy(x + 190, y + 100, L"��");
	//��ʾ��Ŀ��Ա
	setcolor(YELLOW);
	settextstyle(30, 0, L"����");
	outtextxy(x - 180, y + 250, L"----");
	outtextxy(x - 100, y + 250, L"������");
	outtextxy(x + 50, y + 250, L"����");
	outtextxy(x + 200, y + 250, L"������");
	outtextxy(x + 350, y + 250, L"��  ��");
	getch();
	cleardevice();
	//��ʾ��ʼˮλ
	setcolor(LIGHTBLUE);
	settextstyle(50, 0, L"����");
	outtextxy(70, 200, L"����ˮλ��");
	outtextxy(320, 200, s);
	getch();
	cleardevice();
}
void initScene(void) //������ʼ������
{
	initgraph(640, 480);//��ʼ��ͼ�ν���
	window_X = getwidth();//���ͼ�ν������Ա�����
	window_Y = getheight();//���ͼ�ν���߶��Ա�����
	start();
	pond();
	darkClouds();
}