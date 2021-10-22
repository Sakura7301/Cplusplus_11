#pragma once
#define SIZE 8
template<class type>
class stack
{
public:
	/*Ĭ�Ϲ���*/
	stack();
	/*�вι���*/
	stack(int num);
	/*��ջ*/
	void push(type num);
	/*��ջ*/
	void pop();
	/*���ջ*/
	void clear();
	/*��ȡջ��Ԫ��*/
	type top();
	/*�ж�ջ�Ƿ�Ϊ��*/
	bool empty();
	/*ջ��С��ȡ*/
	int size();
	/*ջ�߼���С��ȡ*/
	int logic_size();
	/*����=*/
	void operator=(stack m_stack)
	{
		for (int i = 0; i < m_stack.len; i++)
		{
			this->clear();
			this->push(m_stack.data[i]);
		}
	}

	void operator&()
	{

	}
private:
	type *data;
	int logic_len;/*ջ�߼�����*/
	int len;/*ջʵ�ʳ���*/
};

/*Ĭ�Ϲ���*/
template<class type>
stack<type>::stack()
{
	/*Ĭ�ϴ�СΪ1024*/
	this->data = new type[SIZE];
	this->logic_len=SIZE;
	this->len = 0;
}

/*�вι���*/
template<class type>
stack<type>::stack(int num)
{
	this->data = new type[num];
	this->logic_len=num;
	this->len = 0;
}

/*��ջ*/
template<class type>
void stack<type>::push(type num)
{
	/* ��̬���ٿռ�(�ռ���ʱ����һ����) */
	if (this->len!=0 && this->len%this->logic_len==0)
	{
		type* temp = new type[this->logic_len*2];
		for (int i = 0; i < this->len; i++)
		{
			temp[i]=this->data[i];
		}
		delete this->data;
		this->data = temp;
		temp = nullptr;
		this->logic_len *= 2;
	}

	this->data[this->len] = num;
	this->len++;
}

/*��ջ*/
template<class type>
void stack<type>::pop()
{
	if (this->len <= 0)
	{
		return;
	}

	this->len--;
}

/*���ջ*/
template<class type>
void stack<type>::clear()
{
	if (this->len == 0)
	{
		return;
	}

	type* temp = new type[SIZE];
	delete this->data;
	this->data = temp;
	temp = nullptr;
	this->len = 0;
	this->logic_len = SIZE;
}

/*��ȡջ��Ԫ��*/
template<class type>
type stack<type>::top()
{
	if (this->len == 0)
	{
		return type();
	}
	return this->data[this->len - 1];
}

/*ջ��*/
template<class type>
bool stack<type>::empty()
{
	if (this->len != 0)
	{
		return false;
	}
	return true;
}

/*ջ��С*/
template<class type>
int stack<type>::size()
{
	return this->len;
}

/*��ȡջ�߼���С*/
template<class type>
int stack<type>::logic_size()
{
	return this->logic_len;
}
