#if 0


#include<iostream>
#include<string>
using namespace std;
#include <vector>	//����������ͷ�ļ�
#include <algorithm>//�㷨������ͷ�ļ�

void MyPrint(int val)
{
	cout << val << endl;
}

void test01() {

	//����vector�������󣬲���ͨ��ģ�����ָ�������д�ŵ����ݵ�����
	vector<int> v;
	//�������з�����
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	//ÿһ�����������Լ��ĵ����������������������������е�Ԫ��
	//vector<int>::iterator �õ�vector<int>���������ĵ���������

	vector<int>::iterator pBegin = v.begin();//v.begin()���ص����������������ָ�������е�һ������
	vector<int>::iterator pEnd = v.end();//v.end()���ص����������������ָ������Ԫ�ص����һ��Ԫ�ص���һ��λ��

	//��һ�ֱ�����ʽ��
	while (pBegin != pEnd) {
		cout << *pBegin << endl;
		pBegin++;
	}


	//�ڶ��ֱ�����ʽ��
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}
	cout << endl;

	//�����ֱ�����ʽ��
	//ʹ��STL�ṩ��׼�����㷨  ͷ�ļ� algorithm
	for_each(v.begin(), v.end(), MyPrint);
}

int main() {

	test01();

	system("pause");

	return 0;
}
#endif // 0