#if 0




#include<iostream>
using namespace std;
//�����쳣�����׳�ȥ��������������
void fun(int x) {
	try {
		if (x == 0)
			throw "�쳣";
	}
	catch (...) {
		cout << "in fun" << endl;
		throw 1;
	}
}

int main(int argc, char const *argv[])
{

	try {
		fun(0);
	}
	catch (int n) {
		cout << "in main" << endl;
	}

	system("pause");
	return 0;
}

#endif // 0