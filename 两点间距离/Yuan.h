#pragma once
#include<iostream>
using namespace std;
#include"Point.h"
class Yuan
{
public:
	void setR(int r);

	int  getR();

	void setCenter(Point center);//����Բ��

	Point getCenter();//��ȡԲ��

private:
	int m_R;
	Point m_Center;
};
void DD(Yuan  &y, Point &p);