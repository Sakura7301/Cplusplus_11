#include<iostream>
using namespace std;
#include<string>
#include"Yuan.h"
#include"Point.h"
int main()
{
	//ʵ����һ��Բ
	Yuan y;
	Point center;
	y.setR(10);
	center.setX(10);
	center.setY(0);//����Բ������
	y.setCenter(center);

	//ʵ����һ����
	Point p;
	p.setX(10);
	p.setY(10);//���õ������

	DD(y, p);//����DD����
}