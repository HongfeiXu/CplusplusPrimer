#include <iostream>

struct absInt {
	int operator()(int val) const
	{
		return val < 0 ? -val : val;
	}
};

int main()
{
	int i = -42;
	absInt absObj;
	int ui = absObj(i);
	std::cout << ui << std::endl;

	return 0;
}