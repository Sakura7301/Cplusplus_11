//#include <iostream>
//class Base {
//public:
//	int value1;
//	int value2;
//	Base() {
//		std::cout << "Base无参构造" << std::endl;
//		value1 = 1;
//	}
//	Base(int value) : Base() { 
//		/*委托 Base() 构造函数*/
//		std::cout << "Base有参构造" << std::endl;
//		value2 = value;
//	}
//};
//
//int main() {
//
//	/*使用有参构造初始化对象*/
//	Base b(2);
//	std::cout << b.value1 << std::endl;
//	std::cout << b.value2 << std::endl;
//
//	/*使用无参构造初始化对象*/
//
//	Base c;
//	return 0;
//}