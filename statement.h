#pragma once
#include <stdlib.h>
#include<easyx.h>
#include <conio.h>
#include <time.h>
#include <dos.h>
#include <graphics.h>
#include<stdio.h>
#include<ctime>
#include<Windows.h>
#include <Mmsystem.h>	
#pragma comment ( lib, "Winmm.lib" )
#define LEN sizeof(struct raindrop)
int raindropNumber;//雨量
int window_X;//图形界面宽度
int window_Y;//图形界面高度
int wind;//风速
int rainTime = 0;//下雨时长
int thunderTime = 5000;//电闪雷鸣时间间隔
HANDLE thundering;//雷电线程句柄
TCHAR s[10];//用来接收需要进行字符串转换的变量
float waterLevel = 1.5;//池塘水位，初始为1.5
float lastWaterLevel = 0;//上次池塘水位
int waterHeight = 350;//池塘绘制时的y坐标
struct raindrop *head;//雨滴链表头指针
struct rainCircle//涟漪结构体
{
	int x;//涟漪中心点x坐标
	int y;//涟漪中心点y坐标
	int r;//涟漪最大半径
	int curR;//涟漪当前半径
	int rainCircleSpeed;//涟漪扩散速度
};
struct raindrop//雨滴结构体
{
	int startX;//雨滴线条尾端x坐标
	int startY;//雨滴线条尾端y坐标
	int endY;//雨滴形成涟漪时的y坐标
	int curX;//雨滴线条首端x坐标
	int curY;//雨滴线条首端y坐标
	int rainColor;//雨滴颜色
	int rainSpeed;//雨滴下落速度
	int rainLength;//雨滴线条长度
	int isRiffle;//雨滴是否变成涟漪的标志
	struct rainCircle riffle;//雨滴相对应的涟漪
	struct raindrop *next;//当前雨滴相对应的下一个雨滴的指针
};
