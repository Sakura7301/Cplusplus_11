#if 0


#include<iostream>
#include<string>

using namespace std;

int main()
{
	/*��ֵ����*/
	int&& a = 250;
	/*
	250��һ����ֵ(�޷�ȡ��ַ)
	a��һ����ֵ����
	*/


	/*��ֵ����*/
	int b = 100;
	int&c = b;
	/*
	b��һ����ֵ(����ȡ��ַ)
	c��һ����ֵ����
	*/


	/*������ֵ����*/
	const int& d = b;
	/*
	b��һ����ֵ(����ȡ��ַ)
	���ñ�����ָ�볣��(����const����ָ���ָ��)
	��ʹ��const��ȥ��������,����ָ���ֵҲ�������޸�;
	d��һ��������ֵ����, �Ȳ������޸�ָ��, Ҳ�������޸���ָ���ֵ
	*/

	/*������ֵ����*/
	const int&& f = 250;
	/*
	����const�Ƿ��޶�,��ֵ���ö�����ʹ����ֵ��ʼ��
	*/
	int *s = new int(100);
	int&& g = move(*s);//��s�е���Դת�Ƶ�g
	cout << "g address:" <<&g<< endl;
	cout << "s-> address:" <<s<< endl;
	cout << g << endl;
	delete s;
	cout << "g address:" << &g << endl;
	cout << "s-> address:" << s << endl;
	cout << g << endl;

	int *x = new int(250);
	int *y = move(s);
	cout << *x << endl;
	cout << y << endl;
	cout << "x-> address:" << x << endl;
	cout << "y-> address:" << y << endl;
	system("pause");
	return 0;
	

}
#endif // 0