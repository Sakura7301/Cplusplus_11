#if 0


#include<iostream> 
using namespace std;

class Derived;

class Base {
private:
	virtual void fun()= 0;
	friend int main();
};

class Derived : public Base {
public:
	void fun() { cout << "Derived Fun"<<endl; }
};

class Test : public Base {
private:
	void fun() { cout << "Test Fun"<<endl; }
};


int main()
{
	Base *ptr = new Derived;
	ptr->fun();
	ptr = new Test;
	ptr->fun();
	return 0;
}
#endif // 0