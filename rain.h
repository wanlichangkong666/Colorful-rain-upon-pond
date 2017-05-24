#pragma once
#include"statement.h"

struct raindrop *createRaindrop(void)//创建单个雨滴函数
{
	struct raindrop *p;
	p = (struct raindrop *)malloc(LEN);//为雨滴动态分配内存
	p->startX = rand() % window_X;
	p->startY = rand() % 450 + 50;
	p->endY = waterHeight + 70 + rand() % (window_Y - waterHeight - 70);//雨滴的结束y坐标要在池塘之内
	p->curX = p->startX;
	p->curY = p->startY;
	p->rainSpeed = raindropNumber;//使雨速与雨量相协调
	p->rainColor = rand() % 10;
	p->rainLength = rand() % 10 + 10;
	p->isRiffle = 0;//标志初始为0，代表还是雨滴
	p->riffle.x = p->startX;
	p->riffle.y = p->endY;
	p->riffle.r = rand() % 30+10;
	p->riffle.curR = rand() % 2;
	p->riffle.rainCircleSpeed = raindropNumber/10;//使涟漪扩散速度与雨量相协调
	p->next = NULL;
	return(p);
}
void reviveRaindrop(struct raindrop *p)//雨滴重新初始化函数
{
	p->startX = rand() % window_X;
	p->startY = rand() % 100 + 50;
	p->endY = waterHeight + 70 + rand() % (window_Y - waterHeight - 70);//雨滴的结束y坐标要在池塘之内
	p->curX = p->startX;
	p->curY = p->startY;
	p->rainSpeed = raindropNumber;//使雨速与雨量相协调
	p->rainColor = rand() % 10;
	p->rainLength = rand() % 10 + 10;
	p->isRiffle = 0;//标志初始为0，代表还是雨滴
	p->riffle.x = p->startX;
	p->riffle.y = p->endY;
	p->riffle.r = rand() % 30+2;
	p->riffle.curR = rand() % 2;
	p->riffle.rainCircleSpeed = raindropNumber/10;//使涟漪扩散速度与雨量相协调
}

void createAllRain(void)//创建雨滴链表函数
{
	struct raindrop *p1, *p2;
	int i;
	p2 = createRaindrop();
	p1 = p2;
	head = p1;//为雨滴链表的头指针赋值
	//创建结点个数为raindropNumber的雨滴链表
	for (i = 0; i<raindropNumber; i++)
	{
		p2 = createRaindrop();
		p1->next = p2;
		p1 = p2;
	}
}
void updateRainLine(struct raindrop *p)//更新雨滴函数
{
	//融入风效造成的雨滴横向偏移
	p->curX += wind;
	p->curY += p->rainSpeed;
	p->startX += wind;
	p->riffle.x += wind;
	p->startY = p->curY - p->rainLength;
}
void drawRainLine(struct raindrop *p)//绘制雨滴函数
{
	//根据随机值确定雨滴颜色
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
	//只有在池塘上方时才绘制雨滴线条
	if (p->curY - p->rainLength < waterHeight - 15)
	{
		setlinestyle(PS_SOLID, 2);
		line(p->startX, p->startY, p->curX + wind, p->curY);
	}
}

void clearRainLine(struct raindrop *p)//清除雨滴函数
{
	if (p->curY - p->rainLength <waterHeight - 15)
	{
		//使用黑色覆盖掉上一个雨滴线条达到清除效果
		setcolor(BLACK);
		line(p->startX, p->startY, p->curX + wind, p->curY);
	}
}
void raindropDown(struct raindrop *p)//降雨函数
{
	//当雨滴落到最低点时将标志置为1，表示变成涟漪
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
