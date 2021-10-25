#include<iostream>
#include"stack.h"
using namespace std;

class A
{   
public:
	int getNum()
	{
		return num;
	}
	int num;
};

void stack_test_01()
{
	stack<int> stack;
	for (int i = 1; i <= 20; i++)
	{
		stack.push(i);
	}
	int ret = stack.top();
	cout << ret << endl;
	for (int i = 0; i < 5; i++)
	{
		stack.pop();
	}
	ret = stack.top();
	cout << ret << endl;
	if (stack.empty())
	{
		cout << "Õ»¿Õ" << endl;
	}
	else
	{
		cout << "Õ»²»¿Õ" << endl;

	}
	
	stack.clear();
	if (stack.empty())
	{
		cout << "Õ»¿Õ" << endl;
	}
	else
	{
		cout << "Õ»²»¿Õ" << endl;

	}

}

void stack_test_02()
{
	stack<A> stack(5);
	A a1;
	A a2;
	A a3;
	a1.num = 5;
	a2.num = 6;
	a3.num = 7;
	stack.push(a1);
	stack.push(a2);
	stack.pop();
	cout<<stack.size() << endl;
	A a4=stack.top();
	cout << a4.getNum() << endl;
	stack.push(a3);
	cout << stack.size() << endl;
	if (stack.empty())
	{
		cout << "Õ»¿Õ" << endl;
	}
	else
	{
		cout << "Õ»²»¿Õ" << endl;

	}

	stack.clear();
	A a5=stack.top();
	cout << a5.getNum() << endl;
	if (stack.empty())
	{
		cout << "Õ»¿Õ" << endl;
	}
	else
	{
		cout << "Õ»²»¿Õ" << endl;

	}
	
	

}

void stack_test_03()
{
	stack<int> stack1;
	stack<int> stack2;
	stack1.push(1);
	stack1.push(2);
	stack1.push(3);
	stack2.push(5);
	stack2.push(6);
	stack2.push(7);
	stack1 = stack2;
	cout << stack1.top() << endl;
}

void stack_test_04()
{
	stack<int> stack(5);
	cout << "stack.size()="<<stack.size() << endl;
	cout << "stack.length()="<<stack.logic_size() << endl;
	for (int i = 0; i < 7; i++)
	{
		stack.push(i + 5);
	}
	cout << "stack.size()=" << stack.size() << endl;
	cout << "stack.length()=" << stack.logic_size() << endl;

	for (int i = 0; i < 50; i++)
	{
		stack.push(i + 8);
	}
	cout << "stack.size()=" << stack.size() << endl;
	cout << "stack.length()=" << stack.logic_size() << endl;

	stack.clear();
	cout << "stack.size()=" << stack.size() << endl;
	cout << "stack.length()=" << stack.logic_size() << endl;

	stack.top();
}





int main()
{
	/*Õ»²âÊÔ*/
	stack_test_01();
	stack_test_02();
	stack_test_03();
	stack_test_04();
	return 0;
}