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
	cout << "Բ������X=" << y.getCenter().getX() << "\t" << "Բ������Y=" << y.getCenter().getY() << endl;
	cout << "������X=" << p.getX() << "\t" << "������Y=" << p.getY() << endl;
	cout << "��������=" << dd << endl;
	cout << "R^2=" << RR << endl;
	if (dd < RR)
	{
		cout << "�жϽ��������Բ��" << endl;
	}
	else if (dd == RR)
	{
		cout << "�жϽ��������Բ��" << endl;
	}
	else if (dd > RR)
	{
		cout << "�жϽ��������Բ��" << endl;
	}
}
