/*  返回值类型后置  */
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/*
语法:  auto func(参数1,参数2......)->decltype(参数表达式)
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

	//不显式指定也是可以调用的
	cout << func(a, b) << endl;


	/*以下部分是vector删除元素的代码,并非主题*/
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




