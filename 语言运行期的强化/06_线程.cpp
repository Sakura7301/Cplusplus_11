#if 1

#include<iostream>
#include<thread>
using namespace std;

void myprint()
{
	cout << "working..." << endl;
	cout << "working..." << endl;
	cout << "working..." << endl;
	cout << "working..." << endl;
	cout << "working..." << endl;
	cout << "working..." << endl;
}

int main()
{
	thread th_1(myprint);
	cout << "main working..." << endl;
	th_1.join();
	return 0;
}





#endif // 1
