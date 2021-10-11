#if 0




#include<iostream>
#include<string>
using namespace std;

class Test {
public:
	int num = 0;
	string text;
	static const int value = 100;
};

void test_01()
{
	int a = 10;
	decltype(a)b=99;
	decltype(a + 3.14) c;
	decltype(a + 3.14) c2=600.14;
	decltype(Test::value) temp1=500;
	decltype(Test::num) temp2;
	decltype(Test::text) temp3 = "asdasd";
	
	/*表达式是函数->推导出的结果是函数返回值*/

}

int main()
{

}

#endif // 0