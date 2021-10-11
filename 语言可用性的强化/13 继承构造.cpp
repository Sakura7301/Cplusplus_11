#if 0


#include <iostream>
class Base {
public:
	int value1;
	int value2;
	Base() {
		std::cout << "父类的无参构造" << std::endl;
		value1 = 1;
	}
	Base(int value) : Base() { 
		/*委托 Base() 构造函数*/
		std::cout << "父类的有参构造" << std::endl;
		value2 = value;
	}
};
class Subclass : public Base {
public:
	using Base::Base; // 继承构造
};


int main() {
	Subclass s(3);
	std::cout << s.value1 << std::endl;
	std::cout << s.value2 << std::endl;
	return 0;
}
#endif // 0