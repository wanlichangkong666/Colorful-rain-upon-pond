#pragma once
#include"statement.h"
#include"initScene.h"
void waterLevelRise()//ˮλ��������
{
	//��ˮλ����һ����ʱ���Գ������½��л���
	if (waterLevel - lastWaterLevel >= 0.01)
	{
		waterHeight--;//�ó�����y����-1
		pond();
		lastWaterLevel = waterLevel;//�������»��ƺ�ǰˮλ�ͱ�����ϴ�ˮλ
	}
}