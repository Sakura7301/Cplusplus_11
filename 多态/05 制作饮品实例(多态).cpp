//#include<iostream>
//using namespace std;
//#include<string>
////����������Ʒ
//class AbstractDrinking {
//public:
//	//��ˮ
//	virtual void Boil() = 0;
//	//����
//	virtual void Brew() = 0;
//	//���뱭��
//	virtual void PourInCup() = 0;
//	//���븨��
//	virtual void PutSomething() = 0;
//	//�涨����
//	void MakeDrink() {
//		Boil();
//		Brew();
//		PourInCup();
//		PutSomething();
//	}
//};
//
////��������
//
////�������жԸ���Ĵ��麯��������д
//
//class Coffee : public AbstractDrinking {
//public:
//	//��ˮ
//	virtual void Boil() {
//		cout << "��ũ��ɽȪ!" << endl;
//	}
//	//����
//	virtual void Brew() {
//		cout << "���ݿ���!" << endl;
//	}
//	//���뱭��
//	virtual void PourInCup() {
//		cout << "�����ȵ��뱭��!" << endl;
//	}
//	//���븨��
//	virtual void PutSomething() {
//		cout << "����ţ��!" << endl;
//	}
//};
//
////������ˮ
//
////�������жԸ���Ĵ��麯��������д
//
//class Tea : public AbstractDrinking {
//public:
//	//��ˮ
//	virtual void Boil() {
//		cout << "�����ɽ!" << endl;
//	}
//	//����
//	virtual void Brew() {
//		cout << "���ݲ�Ҷ!" << endl;
//	}
//	//���뱭��
//	virtual void PourInCup() {
//		cout << "����ˮ���뱭��!" << endl;
//	}
//	//���븨��
//	virtual void PutSomething() {
//		cout << "�������!" << endl;
//	}
//};
//
////���������
//class madaiTea : public AbstractDrinking {
//public:
//	//��ˮ
//	virtual void Boil() {
//		cout << "�������Ȫ!" << endl;
//	}
//	//����
//	virtual void Brew() {
//		cout << "����2��������Ҷ!" << endl;
//	}
//	//���뱭��
//	virtual void PourInCup() {
//		cout << "������赹�뱭��!" << endl;
//	}
//	//���븨��
//	virtual void PutSomething() {
//		cout << "��������!" << endl;
//	}
//};
//
////ҵ����
//void DoWork(AbstractDrinking* drink) //����ָ��ָ����������Դ�ʵ�ֶ�̬
//{
//	drink->MakeDrink();
//	delete drink;				//ʹ�ú��ͷŶ���
//}
//
//void test01() {
//	cout << "��ʼ��������~" << endl;
//	cout << "--------------" << endl;
//	DoWork(new Coffee);
//	cout << "����������ɣ�" << endl;
//	cout << "--------------" << endl;
//	cout <<  endl;
//	cout << "��ʼ������~" << endl;
//	cout << "--------------" << endl;
//	DoWork(new Tea);
//	cout << "��������ɣ�" << endl;
//	cout << "--------------" << endl;
//	cout << endl;
//	cout << "��ʼ���������~" << endl;
//	cout << "--------------" << endl;
//	DoWork(new madaiTea);
//	cout << "�����������ɣ�" << endl;
//	cout << "--------------" << endl;
//}
//
//
//int main() {
//
//	test01();
//
//	system("pause");
//
//	return 0;
//}