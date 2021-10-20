#pragma once
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
private:
	type *data;
	int len;
};

/*Ĭ�Ϲ���*/
template<class type>
stack<type>::stack()
{
	/*Ĭ�ϴ�СΪ1024*/
	this->data = new type[1024];
	this->len = 0;
}

/*�вι���*/
template<class type>
stack<type>::stack(int num)
{
	this->data = new type[num];
	this->len = 0;
}

/*��ջ*/
template<class type>
void stack<type>::push(type num)
{
	this->data[this->len] = num;
	this->len++;
}

/*��ջ*/
template<class type>
void stack<type>::pop()
{
	this->len--;
}

/*���ջ*/
template<class type>
void stack<type>::clear()
{
	this->len = 0;
}

/*��ȡջ��Ԫ��*/
template<class type>
type stack<type>::top()
{
	return this->data[this->len - 1];
}

/*ջ��*/
template<class type>
bool stack<type>::empty()
{
	if (this->len)
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