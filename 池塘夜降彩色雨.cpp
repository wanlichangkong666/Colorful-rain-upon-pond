
#include"statement.h"
#include"initScene.h"
#include"thunder.h"
#include"rain.h"
#include"riffle.h"
#include"waterLevelRise.h"
#include"over.h"

void rain()//池塘夜降彩色雨主体函数
{
	srand((unsigned)time(NULL));//使用系统时间作为随机数发生种子，避免每次运行程序随机值都相同
	createAllRain();//根据用户输入的雨量创建雨滴链表
	//将雷电函数单独放到一个线程中执行，避免出现打雷时雨滴停止下落的情况
	thundering = CreateThread(NULL, 0, thunder, NULL, 0, NULL);
	//循环播放背景音乐和雨声
	mciSendString(L"open 三国杀.mp3 alias bgm", 0, 0, 0);
	mciSendString(L"play bgm repeat", 0, 0, 0);
	mciSendString(L"open 雨声.mp3 alias rain", 0, 0, 0);
	mciSendString(L"play rain repeat", 0, 0, 0);
	struct raindrop *p;
	p = head->next;
	while (!kbhit())//只要用户不按下按键，便一直展现彩色雨景象
	{		
		if (p == NULL)
		{			
			p = head;
		}
		else
		{
			//当标志为0即雨滴还没有变成涟漪时，雨滴继续下落
			if (p->isRiffle == 0)			
				raindropDown(p);
			//当标志为1即雨滴变成涟漪时，绘制相应涟漪
			if (p->isRiffle == 1)
			{
				riffleInWater(p);
				waterLevel += 0.00001;//落入池塘一滴雨水位便增加0.00001
			}
		}
		waterLevelRise();//每落入一滴雨都检测一遍水位变化
		Sleep(1);
		p = p->next;
	}
}
void main()
{
	initScene();//初始化场景
	//等待用户输入雨量及风速信息
	InputBox(s, 10, L"请输入雨量(20~60)", L"池塘夜降彩色雨", L"10", 300, 100, false);
	_stscanf(s, L"%d", &raindropNumber);
	InputBox(s, 10, L"请输入风速(-5~5,正代表西风，负代表东风)", L"池塘夜降彩色雨", L"0", 300, 100, false);
	_stscanf(s, L"%d", &wind);
	//开始展示池塘夜降彩色雨景象
	rain();
	//展示结束
	over();
}