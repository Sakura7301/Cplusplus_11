#include<iostream>
using namespace std;
#include<string>
#include"Yuan.h"
#include"Point.h"
int main()
{
	//实例化一个圆
	Yuan y;
	Point center;
	y.setR(10);
	center.setX(10);
	center.setY(0);//设置圆心坐标
	y.setCenter(center);

	//实例化一个点
	Point p;
	p.setX(10);
	p.setY(10);//设置点的坐标

	DD(y, p);//调用DD函数
}