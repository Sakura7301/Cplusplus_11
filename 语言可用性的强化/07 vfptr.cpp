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
	//��СΪ4,64λΪ8,������Ϊ�̳��˸�����麯��ָ��
	cout << "student size=" << sizeof(student) << endl;
	cout << "student_boy size=" << sizeof(student_boy) << endl;
	return 0;
}

#endif // 0