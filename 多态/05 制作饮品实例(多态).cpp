//#include<iostream>
//using namespace std;
//#include<string>
////抽象制作饮品
//class AbstractDrinking {
//public:
//	//烧水
//	virtual void Boil() = 0;
//	//冲泡
//	virtual void Brew() = 0;
//	//倒入杯中
//	virtual void PourInCup() = 0;
//	//加入辅料
//	virtual void PutSomething() = 0;
//	//规定流程
//	void MakeDrink() {
//		Boil();
//		Brew();
//		PourInCup();
//		PutSomething();
//	}
//};
//
////制作咖啡
//
////在子类中对父类的纯虚函数进行重写
//
//class Coffee : public AbstractDrinking {
//public:
//	//烧水
//	virtual void Boil() {
//		cout << "煮农夫山泉!" << endl;
//	}
//	//冲泡
//	virtual void Brew() {
//		cout << "冲泡咖啡!" << endl;
//	}
//	//倒入杯中
//	virtual void PourInCup() {
//		cout << "将咖啡倒入杯中!" << endl;
//	}
//	//加入辅料
//	virtual void PutSomething() {
//		cout << "加入牛奶!" << endl;
//	}
//};
//
////制作茶水
//
////在子类中对父类的纯虚函数进行重写
//
//class Tea : public AbstractDrinking {
//public:
//	//烧水
//	virtual void Boil() {
//		cout << "煮百岁山!" << endl;
//	}
//	//冲泡
//	virtual void Brew() {
//		cout << "冲泡茶叶!" << endl;
//	}
//	//倒入杯中
//	virtual void PourInCup() {
//		cout << "将茶水倒入杯中!" << endl;
//	}
//	//加入辅料
//	virtual void PutSomething() {
//		cout << "加入枸杞!" << endl;
//	}
//};
//
////制作马黛茶
//class madaiTea : public AbstractDrinking {
//public:
//	//烧水
//	virtual void Boil() {
//		cout << "煮秦岭冰泉!" << endl;
//	}
//	//冲泡
//	virtual void Brew() {
//		cout << "加入2茶匙马黛茶叶!" << endl;
//	}
//	//倒入杯中
//	virtual void PourInCup() {
//		cout << "将马黛茶倒入杯中!" << endl;
//	}
//	//加入辅料
//	virtual void PutSomething() {
//		cout << "插入吸管!" << endl;
//	}
//};
//
////业务函数
//void DoWork(AbstractDrinking* drink) //父类指针指向子类对象，以此实现多态
//{
//	drink->MakeDrink();
//	delete drink;				//使用后释放堆区
//}
//
//void test01() {
//	cout << "开始制作咖啡~" << endl;
//	cout << "--------------" << endl;
//	DoWork(new Coffee);
//	cout << "咖啡制作完成！" << endl;
//	cout << "--------------" << endl;
//	cout <<  endl;
//	cout << "开始制作茶~" << endl;
//	cout << "--------------" << endl;
//	DoWork(new Tea);
//	cout << "茶制作完成！" << endl;
//	cout << "--------------" << endl;
//	cout << endl;
//	cout << "开始制作马黛茶~" << endl;
//	cout << "--------------" << endl;
//	DoWork(new madaiTea);
//	cout << "马黛茶制作完成！" << endl;
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