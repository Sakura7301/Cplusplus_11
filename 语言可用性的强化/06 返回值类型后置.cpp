#if 0


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

	return 0;
}



#endif // 0

