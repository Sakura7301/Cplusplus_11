#include "Base.h"
Base::Base(int i)
{
	iBase = 1;
	cout << "Base_1::Base()" << endl;
}

Base::~Base(void)
{
	cout << "Base::~Base()" << endl;
}

void Base::print(void) const
{
	cout << "Base_1::print()£¬ iBase " << iBase << endl;
}