#pragma once
#include<iostream>
using namespace std;
#include"Point.h"
class Yuan
{
public:
	void setR(int r);

	int  getR();

	void setCenter(Point center);//设置圆心

	Point getCenter();//获取圆心

private:
	int m_R;
	Point m_Center;
};
void DD(Yuan  &y, Point &p);