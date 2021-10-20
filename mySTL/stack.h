#pragma once
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
private:
	type *data;
	int len;
};

/*默认构造*/
template<class type>
stack<type>::stack()
{
	/*默认大小为1024*/
	this->data = new type[1024];
	this->len = 0;
}

/*有参构造*/
template<class type>
stack<type>::stack(int num)
{
	this->data = new type[num];
	this->len = 0;
}

/*入栈*/
template<class type>
void stack<type>::push(type num)
{
	this->data[this->len] = num;
	this->len++;
}

/*出栈*/
template<class type>
void stack<type>::pop()
{
	this->len--;
}

/*清空栈*/
template<class type>
void stack<type>::clear()
{
	this->len = 0;
}

/*获取栈顶元素*/
template<class type>
type stack<type>::top()
{
	return this->data[this->len - 1];
}

/*栈空*/
template<class type>
bool stack<type>::empty()
{
	if (this->len)
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