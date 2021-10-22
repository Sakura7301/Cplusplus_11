#pragma once
#define SIZE 8
template<class type>
class stack
{
public:
	/*默认构造*/
	stack();
	/*有参构造*/
	stack(int num);
	/*入栈*/
	void push(type num);
	/*出栈*/
	void pop();
	/*清空栈*/
	void clear();
	/*获取栈顶元素*/
	type top();
	/*判断栈是否为空*/
	bool empty();
	/*栈大小获取*/
	int size();
	/*栈逻辑大小获取*/
	int logic_size();
	/*重载=*/
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
	int logic_len;/*栈逻辑长度*/
	int len;/*栈实际长度*/
};

/*默认构造*/
template<class type>
stack<type>::stack()
{
	/*默认大小为1024*/
	this->data = new type[SIZE];
	this->logic_len=SIZE;
	this->len = 0;
}

/*有参构造*/
template<class type>
stack<type>::stack(int num)
{
	this->data = new type[num];
	this->logic_len=num;
	this->len = 0;
}

/*入栈*/
template<class type>
void stack<type>::push(type num)
{
	/* 动态开辟空间(空间满时开辟一倍大) */
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

/*出栈*/
template<class type>
void stack<type>::pop()
{
	if (this->len <= 0)
	{
		return;
	}

	this->len--;
}

/*清空栈*/
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

/*获取栈顶元素*/
template<class type>
type stack<type>::top()
{
	if (this->len == 0)
	{
		return type();
	}
	return this->data[this->len - 1];
}

/*栈空*/
template<class type>
bool stack<type>::empty()
{
	if (this->len != 0)
	{
		return false;
	}
	return true;
}

/*栈大小*/
template<class type>
int stack<type>::size()
{
	return this->len;
}

/*获取栈逻辑大小*/
template<class type>
int stack<type>::logic_size()
{
	return this->logic_len;
}
