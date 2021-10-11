#if 0



#include <iostream>
#include <vector>

class Foo {
public:
	Foo() {}
	Foo(int a, int b) : value_a(a), value_b(b) 
	{
		/*初始化列表*/
	}
public:
	int value_a;
	int value_b;
};

int main() {
	// before C++11
	int arr[3] = { 1, 2, 3 };
	Foo foo(1, 2);
	std::vector<int> vec = { 1, 2, 3, 4, 5 };

	std::cout << "arr[0]: " << arr[0] << std::endl;
	std::cout << "foo:" << foo.value_a << ", " << foo.value_b << std::endl;
	for (auto it : vec)
	{
		std::cout << it << " ";
	}
	return 0;
}
#endif // 0