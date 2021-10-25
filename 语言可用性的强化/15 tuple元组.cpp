#if 1
#include<iostream>
#include<tuple>
using namespace std;

void test_01()
{
	tuple<int, string> student;
	student = make_tuple(20,"张三");

	tuple<int, string> teacher(student);				       // 2)   second{}
	tuple<int, char> one(make_tuple(20, 'b'));				 // 3)   third{20,'b'}
	tuple<long, char> two(one);								// 4)的左值方式, fourth{20,'b'}
	tuple<int, char> three(10, 'a');						 // 5)的右值方式, fifth{10.'a'}
	tuple<int, char> four(make_pair(30, 'c'));			 	// 6)的右值方式, sixth{30,''c}
}

int main()
{
	test_01();

	return 0;
}


#endif // 1
