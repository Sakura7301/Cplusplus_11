#if 0


#include<iostream>
using namespace std;
#include<string>

class Animal
{
public:
	virtual void speak()//�麯��
	{
		cout << "������˵��" << endl;
	}
	virtual void speak2()//�麯��
	{
		cout << "������˵��" << endl;
	}
};

class Cat :public Animal 
{	
public:
	void speak()//����Ը����е��麯��������д
	{
		cout << "Сè��˵��" << endl;
	}
};

class Dog :public Animal
{
public:
	void speak()//����Ը����е��麯��������д
	{
		cout << "С����˵��" << endl;
	}
};
void doSpeak(Animal &animal)//�ø��������ȥ
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
