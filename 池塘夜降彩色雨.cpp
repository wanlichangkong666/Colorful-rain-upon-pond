
#include"statement.h"
#include"initScene.h"
#include"thunder.h"
#include"rain.h"
#include"riffle.h"
#include"waterLevelRise.h"
#include"over.h"

void rain()//����ҹ����ɫ�����庯��
{
	srand((unsigned)time(NULL));//ʹ��ϵͳʱ����Ϊ������������ӣ�����ÿ�����г������ֵ����ͬ
	createAllRain();//�����û���������������������
	//���׵纯�������ŵ�һ���߳���ִ�У�������ִ���ʱ���ֹͣ��������
	thundering = CreateThread(NULL, 0, thunder, NULL, 0, NULL);
	//ѭ�����ű������ֺ�����
	mciSendString(L"open ����ɱ.mp3 alias bgm", 0, 0, 0);
	mciSendString(L"play bgm repeat", 0, 0, 0);
	mciSendString(L"open ����.mp3 alias rain", 0, 0, 0);
	mciSendString(L"play rain repeat", 0, 0, 0);
	struct raindrop *p;
	p = head->next;
	while (!kbhit())//ֻҪ�û������°�������һֱչ�ֲ�ɫ�꾰��
	{		
		if (p == NULL)
		{			
			p = head;
		}
		else
		{
			//����־Ϊ0����λ�û�б������ʱ����μ�������
			if (p->isRiffle == 0)			
				raindropDown(p);
			//����־Ϊ1����α������ʱ��������Ӧ����
			if (p->isRiffle == 1)
			{
				riffleInWater(p);
				waterLevel += 0.00001;//�������һ����ˮλ������0.00001
			}
		}
		waterLevelRise();//ÿ����һ���궼���һ��ˮλ�仯
		Sleep(1);
		p = p->next;
	}
}
void main()
{
	initScene();//��ʼ������
	//�ȴ��û�����������������Ϣ
	InputBox(s, 10, L"����������(20~60)", L"����ҹ����ɫ��", L"10", 300, 100, false);
	_stscanf(s, L"%d", &raindropNumber);
	InputBox(s, 10, L"���������(-5~5,���������磬��������)", L"����ҹ����ɫ��", L"0", 300, 100, false);
	_stscanf(s, L"%d", &wind);
	//��ʼչʾ����ҹ����ɫ�꾰��
	rain();
	//չʾ����
	over();
}