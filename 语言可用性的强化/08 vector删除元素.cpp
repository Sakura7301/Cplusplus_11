//#include<iostream>
//#include<vector>
//using namespace std;
//
//int main()
//{
//	/*���²�����vectorɾ��Ԫ�صĴ���,��������*/
//	cout << "vector delete:" << endl;
//	vector<int> arr = { 1,0,3,0,5 };
//	for (auto i : arr)
//	{
//		cout << i << " " ;
//	}
//	for (vector<int>::iterator it = arr.begin(); it != arr.end();)
//	{
//		if (*it == 0)
//		{
//			arr.erase(it);
//			it = arr.begin();
//		}
//		else
//		{
//			it++;
//		}
//	}
//	cout << endl;
//	for (auto i : arr)
//	{
//		cout << i << " ";
//	}
//	cout << endl;
//
//	//����string����
//	cout <<endl<< "string:" << endl;
//	string csss;
//	int len = sizeof(csss);
//	int len2 = csss.length();
//	cout << "len=" << len << " len2=" << len2 << endl;
//
//	csss = "hello";
//	len = sizeof(csss);
//	len2 = csss.length();
//	cout << "len=" << len << " len2=" << len2 << endl;
//
//	csss += "abcdefghijklmnopqrstuvwxyz";
//	len = sizeof(csss);
//	len2 = csss.length();
//	cout << "len=" << len << " len2=" << len2 << endl;
//	return 0;
//}