#if 0


/*  ����ֵ���ͺ���  */
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
�﷨:  auto func(����1,����2......)->decltype(�������ʽ)
*/

template <typename T, typename U>
auto func(T t, U u)->decltype(t + u)
{
	return t + u;
}



int main()
{
	int a = 100;
	double b = 3.14;
	cout << func<int, double>(a, b) << endl;

	//����ʽָ��Ҳ�ǿ��Ե��õ�
	cout << func(a, b) << endl;

	return 0;
}



#endif // 0

