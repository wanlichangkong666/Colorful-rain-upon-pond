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
int raindropNumber;//����
int window_X;//ͼ�ν�����
int window_Y;//ͼ�ν���߶�
int wind;//����
int rainTime = 0;//����ʱ��
int thunderTime = 5000;//��������ʱ����
HANDLE thundering;//�׵��߳̾��
TCHAR s[10];//����������Ҫ�����ַ���ת���ı���
float waterLevel = 1.5;//����ˮλ����ʼΪ1.5
float lastWaterLevel = 0;//�ϴγ���ˮλ
int waterHeight = 350;//��������ʱ��y����
struct raindrop *head;//�������ͷָ��
struct rainCircle//�����ṹ��
{
	int x;//�������ĵ�x����
	int y;//�������ĵ�y����
	int r;//�������뾶
	int curR;//������ǰ�뾶
	int rainCircleSpeed;//������ɢ�ٶ�
};
struct raindrop//��νṹ��
{
	int startX;//�������β��x����
	int startY;//�������β��y����
	int endY;//����γ�����ʱ��y����
	int curX;//��������׶�x����
	int curY;//��������׶�y����
	int rainColor;//�����ɫ
	int rainSpeed;//��������ٶ�
	int rainLength;//�����������
	int isRiffle;//����Ƿ��������ı�־
	struct rainCircle riffle;//������Ӧ������
	struct raindrop *next;//��ǰ������Ӧ����һ����ε�ָ��
};
