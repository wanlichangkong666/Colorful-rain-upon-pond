#pragma once
#include"rain.h"
#include"statement.h"
void updateRainCircle(struct raindrop *p)//更新涟漪函数
{
	p->riffle.curR += p->riffle.rainCircleSpeed;//让当前半径变大
}
void drawRainCircle(struct raindrop *p)//绘制涟漪函数
{
	//涟漪颜色与相应雨滴颜色相同
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
void clearRainCircle(struct raindrop *p)//清除涟漪函数

{
	//使用池塘颜色覆盖掉涟漪，以达到清除效果
	setcolor(BLUE);
	circle(p->riffle.x, p->riffle.y, p->riffle.curR);
}
void riffleInWater(struct raindrop *p)//涟漪函数
{
	//当涟漪当前半径达到最大半径时，涟漪消失并重生雨滴
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