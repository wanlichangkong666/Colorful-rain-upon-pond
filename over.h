#pragma once
#include"statement.h"
void over()//������������

{
	getch();
	cleardevice();
	mciSendString(L"close bgm", 0, 0, 0);//�رձ�������
	mciSendString(L"close rain", 0, 0, 0);//�ر�����
	TerminateThread(thundering, 0);//�����׵��߳�
	CloseHandle(thundering);//�ͷŵ��׵��߳���ռ��ջ
	_stprintf(s, _T("%.5f"), waterLevel);//��������ˮλת��Ϊ�ַ������ͣ���������ʾ��ͼ�ν�����
	settextstyle(50, 0, L"����");
	//������ֱ�ʾ�������
	setcolor(LIGHTRED);
	outtextxy(150, 200, L"һҹ����.....");
	getch();
	cleardevice();//��������ʾ����ˮλ
	//��ʾ���ճ���ˮλ
	setcolor(LIGHTBLUE);
	settextstyle(50, 0, L"����");
	outtextxy(70, 200, L"����ˮλ��");
	outtextxy(320, 200, s);
	getch();
	//��ʾ��βͼƬ
	IMAGE secondDay;
	loadimage(&secondDay, L"����.jpg", window_X, window_Y);
	putimage(0, 0, &secondDay);
	getch();
	//�ͷŵ����������ռ�ռ�
	struct raindrop *p, *pf;
	p = head;
	while (p != NULL)
	{
		pf = p;
		p = p->next;
		free(pf);
	}
	closegraph();//�ر�ͼ�ν���
}