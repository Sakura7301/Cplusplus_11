#include"Yuan.h"

	void Yuan::setR(int r)
	{
		m_R = r;
	}
	int  Yuan::getR()
	{
		return m_R;
	}

	void Yuan::setCenter(Point center)//设置圆心

	{
		m_Center = center;
	}
	Point Yuan::getCenter()//获取圆心
	{
		return m_Center;//因为是一个点，因此返回值的类型必须也是Point
	}

