/*  ����ֵ���ͺ���  */
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
�﷨:  auto func(����1,����2......)->decltype(��������ʽ)
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


	/*���²�����vectorɾ��Ԫ�صĴ���,��������*/
	vector<int> arr = {1,0,3,0,5};
	for (auto i : arr)
	{
		cout << " "<<i ;
	}
	for (vector<int>::iterator it=arr.begin();it!=arr.end();)
	{
		if (*it == 0)
		{
			arr.erase(it);
			it = arr.begin();
		}
		else
		{
			it++;
		}
	}
	cout << endl;
	for (auto i : arr)
	{
		cout << " " << i ;
	}
	cout << endl;
	string csss;
	int len=sizeof(csss);
	int len2 = csss.length();
	cout << "len=" << len << " len2=" << len2 << endl;
	return 0;
}



