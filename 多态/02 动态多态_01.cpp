#if 0


#include<iostream>
using namespace std;
#include<string>

class Animal
{
public:
	virtual void speak()//虚函数
	{
		cout << "动物在说话" << endl;
	}
	virtual void speak2()//虚函数
	{
		cout << "动物在说话" << endl;
	}
};

class Cat :public Animal 
{	
public:
	void speak()//子类对父类中的虚函数进行重写
	{
		cout << "小猫在说话" << endl;
	}
};

class Dog :public Animal
{
public:
	void speak()//子类对父类中的虚函数进行重写
	{
		cout << "小狗在说话" << endl;
	}
};
void doSpeak(Animal &animal)//用父类的引用去
{
	animal.speak();
}
void test01()
{
	Cat cat;
	doSpeak(cat);
	Dog dog;
	doSpeak(dog);
}
int main()
{
	test01();
}

#endif // 0
