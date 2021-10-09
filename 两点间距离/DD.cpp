#include"Yuan.h"
void DD(Yuan  &y, Point &p)
{
	int a = y.getCenter().getX();
	int b = y.getCenter().getY();
	int A = p.getX();
	int B = p.getY();
	int r = y.getR();
	int dd = ((a - A)*(a - A)) + ((b - B)*(b - B));
	int RR = r * r;
	cout << "圆心坐标X=" << y.getCenter().getX() << "\t" << "圆心坐标Y=" << y.getCenter().getY() << endl;
	cout << "点坐标X=" << p.getX() << "\t" << "点坐标Y=" << p.getY() << endl;
	cout << "两点间距离=" << dd << endl;
	cout << "R^2=" << RR << endl;
	if (dd < RR)
	{
		cout << "判断结果：点在圆内" << endl;
	}
	else if (dd == RR)
	{
		cout << "判断结果：点在圆上" << endl;
	}
	else if (dd > RR)
	{
		cout << "判断结果：点在圆外" << endl;
	}
}
