#pragma once
#include<iostream>
#include<string>
using namespace std;

template<class T>
class Array
{
public:
	//����
	Array(int capacity)
	{
		cout << "���캯������" << endl;
		this->m_Capacity = capacity;
		this->m_Size = 0;
		pAddress = new T[this->m_Capacity];
		//�ڶ������ٿռ�
	}

	//��������
	Array(const Array &arr)
	{
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		this->pAddress = new T[this->m_Capacity];
		//���TΪ���󣬶��һ�����ָ�룬������Ҫ���� = ����������Ϊ����ȺŲ��� ���� ���Ǹ�ֵ��
		// ��ͨ���Ϳ���ֱ��= ����ָ��������Ҫ���
		for (int i = 0; i < this->getSize();i++)
		{
			this->pAddress[i]=arr.pAddress[i];
		}
	}

	//operator=����
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
		return *this;//��������
	}
	//����[]�����
	T& operator[](int index)
	{
		return this->pAddress[index];
		//������Խ�磬�û��Լ�����
	}
	//β�巨
	void Push_back(const T & val)
	{
		//�ж��Ƿ��пռ�
		if (this->m_Capacity == this->m_Size)
		{
			return;
		}
		this->pAddress[this->m_Size] = val;//������ĩβ��������
		this->m_Size++;//���²����������С
	}
	//βɾ��
	void Pop_back()
	{
		if (this->m_Size == 0)
		{
			cout << "������û��Ԫ���޷�ɾ��" << endl;
			return;
		}
		this->m_Size--;//�߼�ɾ�������ʲ�������
	}

	int  getCapacity()//��ȡ��������
	{
		return this->m_Capacity;
	}
	int getSize()//��ȡ�����С
	{
		return this->m_Size;
	}
	//����
	~Array()
	{
		cout << "������������" << endl;
		if (this->pAddress != NULL)
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
	}
private:
	//���ԣ�
	T *pAddress;//ָ��Ŀռ�Ϊ����
	int m_Capacity;//��������
	int m_Size;//���鵱ǰ�ռ�
};

