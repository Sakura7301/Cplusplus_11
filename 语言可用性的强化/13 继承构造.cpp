#if 0


#include <iostream>
class Base {
public:
	int value1;
	int value2;
	Base() {
		std::cout << "������޲ι���" << std::endl;
		value1 = 1;
	}
	Base(int value) : Base() { 
		/*ί�� Base() ���캯��*/
		std::cout << "������вι���" << std::endl;
		value2 = value;
	}
};
class Subclass : public Base {
public:
	using Base::Base; // �̳й���
};


int main() {
	Subclass s(3);
	std::cout << s.value1 << std::endl;
	std::cout << s.value2 << std::endl;
	return 0;
}
#endif // 0