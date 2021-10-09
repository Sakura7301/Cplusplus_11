#include<iostream>
#include<string>
#include<memory>
#include<functional>
using namespace std;
using callback = void(*)();


//函数模板的返回值类型后置的标准写法(装逼必备技能)
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
		cout << "-----------test 默认构造函数调用-----------" << endl;
	}
	Test(int a):num(a)
	{
		cout << "-----------test 有参构造函数调用-----------" << endl;
	}
	int getNum()
	{
		return num;
		//cout << "getNum called" << endl;
	}
	~Test()
	{
		cout << "-----------test 析构函数调用---------------" << endl;
	}
private:
	int num;
};





void test_01(shared_ptr<Test> &ptr)//使用引用的方式传递智能指针,不会让use_count++
{
	cout << "-----------test_01 start called.-----------" << endl;
	cout << "---->参数传递(ptr)" << endl;
	cout << "ptr.use_count()=" << ptr.use_count() << endl;

	cout << "---->ptr1=ptr" << endl;
	shared_ptr<Test> ptr1=ptr;
	weak_ptr<Test> w_ptr = ptr;//初始化弱引用指针(并不会实际管理内存,use_count不会增加)
	cout << "w_ptr.use_count()=" << w_ptr.use_count() << endl;
	cout << "ptr1.use_count()=" << ptr1.use_count() << endl;
	cout << "ptr.use_count()=" << ptr.use_count() << endl;

	cout << "---->ptr2=move(ptr1)" << endl;
	//使用move是所有权的转换,并不会使use_conut增加
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

	//unique_ptr<Test> ptr2 = ptr;//独占智能指针无法通过赋值运算符
	unique_ptr<Test> ptr2 = move(ptr);//但是可以转移资源

	ptr.reset(new Test(456));//通过reset重新指定ptr管理的内存
	cout << "-----------test_02 end called.-------------" << endl;
}

int main()
{
	cout << "-----------main start called---------------" << endl << endl;

	cout << "----------------[unique_prt]---------------" << endl;

	//使用构造函数初始化
	unique_ptr<Test> ptr_unique(new Test(188));

	//Test* t = ptr_unique.get();//可以通过get方法获取指针管理的内存
	test_02(ptr_unique);
	cout << "ptr_unique->getNum()=" << ptr_unique->getNum() << endl;
	ptr_unique.reset(new Test(500));//再次重新初始化ptr_unique管理的内存
	cout << "ptr_unique->getNum()=" << ptr_unique->getNum() << endl<<endl;
	ptr_unique.reset();


	cout << "----------------[shared_prt]---------------" << endl;
	shared_ptr<Test> ptr = make_shared<Test>(250);
	cout << "ptr.use_count()=" << ptr.use_count() << endl;
	cout << "ptr.use_count()="<<ptr.use_count() << endl;
	cout << "ptr->getNum()="<<ptr->getNum() << endl << endl;


	test_01(ptr);

	/*其实智能指针使用起来和普通指针一样*/
	//unique_ptr<int> ptr3(new int(10));
	//cout << endl << *ptr3 << endl;


	cout << "ptr.use_count()=" << ptr.use_count() << endl;
	ptr.reset();
	cout << "ptr.use_count()=" << ptr.use_count() << endl;

	cout << endl << "-------------------------------------------" << endl << endl;

	//shared_ptr<Test> p(new Test[5]);//不提供删除器函数,只会释放数组中的首元素
	//p.reset();//因此,我们还需要为智能指针提供删除器函数

	cout << endl << "--> [提供删除器函数]" << endl;
	cout << "shared_ptr lambda:" << endl;
	//手动书写删除器函数
	/*其实就是手写一个lambda表达式*/
	cout << endl << "shared_ptr的手动删除器执行:" << endl;
	shared_ptr<Test> p1(new Test[5], [](Test* t) {
		
		delete[]t;
	});
	//shared_ptr<Test> p_p = p1;
	p1.reset();
	
	cout << endl << "shared_ptr的默认删除器执行(1):" << endl;
	//使用默认删除器函数
	shared_ptr<Test> p2(new Test[5],default_delete<Test[]>());
	p2.reset();

	cout << endl << "shared_ptr的默认删除器执行(2):" << endl;
	shared_ptr<Test[]> p5(new Test[5]);
	p5.reset();

	/*  转换为函数指针:  */
	cout <<endl<< "unique_ptr lambda:" << endl;
	cout << endl << "unique_ptr的手动删除器执行:" << endl;
	using unique_func = void(*)(Test*);//提供函数指针
	unique_ptr<Test, unique_func> ptr_s(new Test[5], [](Test* u) {
		delete[]u;
	});
	ptr_s.reset();

	/*
	如果要使用=捕获外部变量
	在 lambda 表达式没有捕获任何外部变量时，可以直接转换为函数指针，
	一旦捕获了就无法转换了，如果想要让编译器成功通过编译，
	那么需要使用可调用对象包装器来处理声明的函数指针;
	*/
	cout <<endl<< "unique_ptr的手动删除器执行:" << endl;
	unique_ptr<Test, function<void(Test*)>> ptr_s1(new Test[5], [=](Test* u) {
		delete[]u;
	});


	ptr_s1.reset();
	cout << endl << "unique_ptr的默认删除器执行:" << endl;
	/*要使用默认删除器,只需要将数据类型声明 为[]即可*/
	unique_ptr<Test[]> ptr_s2(new Test[5]);
	ptr_s2.reset();

	cout << endl << "函数模板使用:" << endl;
	cout<<"template:"<<func(2,3.14)<<endl<<endl;
	

	cout << endl << "-----------main end called-----------------" << endl;

	return 0;
}