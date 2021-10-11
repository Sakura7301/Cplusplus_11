#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
class Array
{
public:
	//构造
	Array(int capacity)
	{
		cout << "构造函数调用" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		pAddress = new T[this->m_Capacity];
		//在堆区开辟空间
	}

	//拷贝构造
	Array(const Array &arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		//如果T为对象，而且还包含指针，必须需要重载 = 操作符，因为这个等号不是 构造 而是赋值，
		// 普通类型可以直接= 但是指针类型需要深拷贝
		for (int i = 0; i < this->getSize();i++)
		{
			this->pAddress[i]=arr.pAddress[i];
		}
	}

	//operator=重载
	Array& operator=(const Array& arr)
	{
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		for (int i = 0; i < this->m_Size; i++) 
		{
			this->pAddress[i] = array[i];
		}
		return *this;//返回自身
	}
	//重载[]运算符
	T& operator[](int index)
	{
		return this->pAddress[index];
		//不考虑越界，用户自己处理
	}
	//尾插法
	void Push_back(const T & val)
	{
		//判断是否还有空间
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;//在数组末尾插入数据
		this->m_Size++;//更新插入后的数组大小
	}
	//尾删法
	void Pop_back()
	{
		if (this->m_Size == 0)
		{
			cout << "数组中没有元素无法删除" << endl;
			return;
		}
		this->m_Size--;//逻辑删除，访问不到即可
	}

	int  getCapacity()//获取数组容量
	{
		return this->m_Capacity;
	}
	int getSize()//获取数组大小
	{
		return this->m_Size;
	}
	//析构
	~Array()
	{
		cout << "析构函数调用" << endl;
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
	}
private:
	//属性：
	T *pAddress;//指向的空间为堆区
	int m_Capacity;//数组容量
	int m_Size;//数组当前空间
};

