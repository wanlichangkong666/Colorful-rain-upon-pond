#pragma once
#include"statement.h"

struct raindrop *createRaindrop(void)//����������κ���
{
	struct raindrop *p;
	p = (struct raindrop *)malloc(LEN);//Ϊ��ζ�̬�����ڴ�
	p->startX = rand() % window_X;
	p->startY = rand() % 450 + 50;
	p->endY = waterHeight + 70 + rand() % (window_Y - waterHeight - 70);//��εĽ���y����Ҫ�ڳ���֮��
	p->curX = p->startX;
	p->curY = p->startY;
	p->rainSpeed = raindropNumber;//ʹ������������Э��
	p->rainColor = rand() % 10;
	p->rainLength = rand() % 10 + 10;
	p->isRiffle = 0;//��־��ʼΪ0�����������
	p->riffle.x = p->startX;
	p->riffle.y = p->endY;
	p->riffle.r = rand() % 30+10;
	p->riffle.curR = rand() % 2;
	p->riffle.rainCircleSpeed = raindropNumber/10;//ʹ������ɢ�ٶ���������Э��
	p->next = NULL;
	return(p);
}
void reviveRaindrop(struct raindrop *p)//������³�ʼ������
{
	p->startX = rand() % window_X;
	p->startY = rand() % 100 + 50;
	p->endY = waterHeight + 70 + rand() % (window_Y - waterHeight - 70);//��εĽ���y����Ҫ�ڳ���֮��
	p->curX = p->startX;
	p->curY = p->startY;
	p->rainSpeed = raindropNumber;//ʹ������������Э��
	p->rainColor = rand() % 10;
	p->rainLength = rand() % 10 + 10;
	p->isRiffle = 0;//��־��ʼΪ0�����������
	p->riffle.x = p->startX;
	p->riffle.y = p->endY;
	p->riffle.r = rand() % 30+2;
	p->riffle.curR = rand() % 2;
	p->riffle.rainCircleSpeed = raindropNumber/10;//ʹ������ɢ�ٶ���������Э��
}

void createAllRain(void)//�������������
{
	struct raindrop *p1, *p2;
	int i;
	p2 = createRaindrop();
	p1 = p2;
	head = p1;//Ϊ��������ͷָ�븳ֵ
	//����������ΪraindropNumber���������
	for (i = 0; i<raindropNumber; i++)
	{
		p2 = createRaindrop();
		p1->next = p2;
		p1 = p2;
	}
}
void updateRainLine(struct raindrop *p)//������κ���
{
	//�����Ч��ɵ���κ���ƫ��
	p->curX += wind;
	p->curY += p->rainSpeed;
	p->startX += wind;
	p->riffle.x += wind;
	p->startY = p->curY - p->rainLength;
}
void drawRainLine(struct raindrop *p)//������κ���
{
	//�������ֵȷ�������ɫ
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
	//ֻ���ڳ����Ϸ�ʱ�Ż����������
	if (p->curY - p->rainLength < waterHeight - 15)
	{
		setlinestyle(PS_SOLID, 2);
		line(p->startX, p->startY, p->curX + wind, p->curY);
	}
}

void clearRainLine(struct raindrop *p)//�����κ���
{
	if (p->curY - p->rainLength <waterHeight - 15)
	{
		//ʹ�ú�ɫ���ǵ���һ����������ﵽ���Ч��
		setcolor(BLACK);
		line(p->startX, p->startY, p->curX + wind, p->curY);
	}
}
void raindropDown(struct raindrop *p)//���꺯��
{
	//������䵽��͵�ʱ����־��Ϊ1����ʾ�������
	if (p->curY >= p->endY)
	{
		clearRainLine(p);
		p->isRiffle = 1;
	}
	else
	{
		clearRainLine(p);
		updateRainLine(p);
		drawRainLine(p);
	}
}
