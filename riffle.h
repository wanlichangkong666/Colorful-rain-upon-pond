#pragma once
#include"rain.h"
#include"statement.h"
void updateRainCircle(struct raindrop *p)//������������
{
	p->riffle.curR += p->riffle.rainCircleSpeed;//�õ�ǰ�뾶���
}
void drawRainCircle(struct raindrop *p)//������������
{
	//������ɫ����Ӧ�����ɫ��ͬ
	switch (p->rainColor)
	{
	case 0:setcolor(YELLOW); break;
	case 1:setcolor(RED); break;
	case 2:setcolor(GREEN); break;
	case 3:setcolor(CYAN); break;
	case 4:setcolor(MAGENTA); break;
	case 5:setcolor(BROWN); break;
	case 6:setcolor(LIGHTGRAY); break;
	case 7:setcolor(WHITE); break;
	case 8:setcolor(LIGHTGREEN); break;
	case 9:setcolor(LIGHTRED); break;
	}
	circle(p->riffle.x, p->riffle.y, p->riffle.curR);
}
void clearRainCircle(struct raindrop *p)//�����������

{
	//ʹ�ó�����ɫ���ǵ��������Դﵽ���Ч��
	setcolor(BLUE);
	circle(p->riffle.x, p->riffle.y, p->riffle.curR);
}
void riffleInWater(struct raindrop *p)//��������
{
	//��������ǰ�뾶�ﵽ���뾶ʱ��������ʧ���������
	if (p->riffle.curR >= p->riffle.r)
	{
		clearRainCircle(p);
		reviveRaindrop(p);
	}
	else
	{
		clearRainCircle(p);
		updateRainCircle(p);
		drawRainCircle(p);
	}
}