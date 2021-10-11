#if 0


#include<iostream>
#include<string>
using namespace std;

class student {
public:
	virtual void speak() = 0;
	virtual ~student() = 0;

};

student::~student()
{

}
class student_boy :public student {
public:
	student_boy()
	{

	}
	virtual void speak()
	{

	}
};

int main()
{
	//大小为4,64位为8,这是因为继承了父类的虚函数指针
	cout << "student size=" << sizeof(student) << endl;
	cout << "student_boy size=" << sizeof(student_boy) << endl;
	return 0;
}

#endif // 0