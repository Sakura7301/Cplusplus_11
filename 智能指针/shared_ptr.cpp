#include<iostream>
#include<string>
#include<memory>
#include<functional>
using namespace std;
using callback = void(*)();


//����ģ��ķ���ֵ���ͺ��õı�׼д��(װ�Ʊر�����)
template<typename T, typename U>
auto func(T t, U u)->decltype(t + u)
{
	return t + u;
}


class Test
{
public:
	Test()
	{
		cout << "-----------test Ĭ�Ϲ��캯������-----------" << endl;
	}
	Test(int a):num(a)
	{
		cout << "-----------test �вι��캯������-----------" << endl;
	}
	int getNum()
	{
		return num;
		//cout << "getNum called" << endl;
	}
	~Test()
	{
		cout << "-----------test ������������---------------" << endl;
	}
private:
	int num;
};





void test_01(shared_ptr<Test> &ptr)//ʹ�����õķ�ʽ��������ָ��,������use_count++
{
	cout << "-----------test_01 start called.-----------" << endl;
	cout << "---->��������(ptr)" << endl;
	cout << "ptr.use_count()=" << ptr.use_count() << endl;

	cout << "---->ptr1=ptr" << endl;
	shared_ptr<Test> ptr1=ptr;
	weak_ptr<Test> w_ptr = ptr;//��ʼ��������ָ��(������ʵ�ʹ����ڴ�,use_count��������)
	cout << "w_ptr.use_count()=" << w_ptr.use_count() << endl;
	cout << "ptr1.use_count()=" << ptr1.use_count() << endl;
	cout << "ptr.use_count()=" << ptr.use_count() << endl;

	cout << "---->ptr2=move(ptr1)" << endl;
	//ʹ��move������Ȩ��ת��,������ʹuse_conut����
	shared_ptr<Test> ptr2=move(ptr1);
	cout << "ptr2.use_count()=" << ptr2.use_count() << endl;
	cout << "ptr.use_count()=" << ptr.use_count() << endl;
	cout << "w_ptr.use_count()=" << w_ptr.use_count() << endl;

	cout << "---->ptr3=ptr2" << endl;
	shared_ptr<Test> ptr3 = ptr2;
	cout << "ptr.use_count()=" << ptr.use_count() << endl;
	cout << "w_ptr.use_count()=" << w_ptr.use_count() << endl;

	cout << "---->ptr2.reset()" << endl;
	ptr2.reset();
	cout << "ptr.use_count()=" << ptr.use_count() << endl;
	cout << "w_ptr.use_count()=" << w_ptr.use_count() << endl;

	cout << "---->ptr3.reset()" << endl;
	ptr3.reset();
	cout << "ptr.use_count()=" << ptr.use_count() << endl;
	cout << "w_ptr.use_count()=" << w_ptr.use_count() << endl;
	cout << "-----------test_01 end called.-------------" << endl;
}

void test_02(unique_ptr<Test> &ptr)
{
	cout << "-----------test_02 start called.-----------" << endl;
	cout << "ptr->getNum()=" << ptr->getNum() << endl;

	//unique_ptr<Test> ptr2 = ptr;//��ռ����ָ���޷�ͨ����ֵ�����
	unique_ptr<Test> ptr2 = move(ptr);//���ǿ���ת����Դ

	ptr.reset(new Test(456));//ͨ��reset����ָ��ptr������ڴ�
	cout << "-----------test_02 end called.-------------" << endl;
}

int main()
{
	cout << "-----------main start called---------------" << endl << endl;

	cout << "----------------[unique_prt]---------------" << endl;

	//ʹ�ù��캯����ʼ��
	unique_ptr<Test> ptr_unique(new Test(188));

	//Test* t = ptr_unique.get();//����ͨ��get������ȡָ�������ڴ�
	test_02(ptr_unique);
	cout << "ptr_unique->getNum()=" << ptr_unique->getNum() << endl;
	ptr_unique.reset(new Test(500));//�ٴ����³�ʼ��ptr_unique������ڴ�
	cout << "ptr_unique->getNum()=" << ptr_unique->getNum() << endl<<endl;
	ptr_unique.reset();


	cout << "----------------[shared_prt]---------------" << endl;
	shared_ptr<Test> ptr = make_shared<Test>(250);
	cout << "ptr.use_count()=" << ptr.use_count() << endl;
	cout << "ptr.use_count()="<<ptr.use_count() << endl;
	cout << "ptr->getNum()="<<ptr->getNum() << endl << endl;


	test_01(ptr);

	/*��ʵ����ָ��ʹ����������ָͨ��һ��*/
	//unique_ptr<int> ptr3(new int(10));
	//cout << endl << *ptr3 << endl;


	cout << "ptr.use_count()=" << ptr.use_count() << endl;
	ptr.reset();
	cout << "ptr.use_count()=" << ptr.use_count() << endl;

	cout << endl << "-------------------------------------------" << endl << endl;

	//shared_ptr<Test> p(new Test[5]);//���ṩɾ��������,ֻ���ͷ������е���Ԫ��
	//p.reset();//���,���ǻ���ҪΪ����ָ���ṩɾ��������

	cout << endl << "--> [�ṩɾ��������]" << endl;
	cout << "shared_ptr lambda:" << endl;
	//�ֶ���дɾ��������
	/*��ʵ������дһ��lambda���ʽ*/
	cout << endl << "shared_ptr���ֶ�ɾ����ִ��:" << endl;
	shared_ptr<Test> p1(new Test[5], [](Test* t) {
		
		delete[]t;
	});
	//shared_ptr<Test> p_p = p1;
	p1.reset();
	
	cout << endl << "shared_ptr��Ĭ��ɾ����ִ��(1):" << endl;
	//ʹ��Ĭ��ɾ��������
	shared_ptr<Test> p2(new Test[5],default_delete<Test[]>());
	p2.reset();

	cout << endl << "shared_ptr��Ĭ��ɾ����ִ��(2):" << endl;
	shared_ptr<Test[]> p5(new Test[5]);
	p5.reset();

	/*  ת��Ϊ����ָ��:  */
	cout <<endl<< "unique_ptr lambda:" << endl;
	cout << endl << "unique_ptr���ֶ�ɾ����ִ��:" << endl;
	using unique_func = void(*)(Test*);//�ṩ����ָ��
	unique_ptr<Test, unique_func> ptr_s(new Test[5], [](Test* u) {
		delete[]u;
	});
	ptr_s.reset();

	/*
	���Ҫʹ��=�����ⲿ����
	�� lambda ���ʽû�в����κ��ⲿ����ʱ������ֱ��ת��Ϊ����ָ�룬
	һ�������˾��޷�ת���ˣ������Ҫ�ñ������ɹ�ͨ�����룬
	��ô��Ҫʹ�ÿɵ��ö����װ�������������ĺ���ָ��;
	*/
	cout <<endl<< "unique_ptr���ֶ�ɾ����ִ��:" << endl;
	unique_ptr<Test, function<void(Test*)>> ptr_s1(new Test[5], [=](Test* u) {
		delete[]u;
	});


	ptr_s1.reset();
	cout << endl << "unique_ptr��Ĭ��ɾ����ִ��:" << endl;
	/*Ҫʹ��Ĭ��ɾ����,ֻ��Ҫ�������������� Ϊ[]����*/
	unique_ptr<Test[]> ptr_s2(new Test[5]);
	ptr_s2.reset();

	cout << endl << "����ģ��ʹ��:" << endl;
	cout<<"template:"<<func(2,3.14)<<endl<<endl;
	

	cout << endl << "-----------main end called-----------------" << endl;

	return 0;
}