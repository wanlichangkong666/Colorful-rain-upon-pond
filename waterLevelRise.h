#pragma once
#include"statement.h"
#include"initScene.h"
void waterLevelRise()//水位增长函数
{
	//当水位增长一定量时，对池塘重新进行绘制
	if (waterLevel - lastWaterLevel >= 0.01)
	{
		waterHeight--;//让池塘的y坐标-1
		pond();
		lastWaterLevel = waterLevel;//池塘重新绘制后当前水位就变成了上次水位
	}
}