/*
练习 13.17：分别编写前三题中所描述的 numbered 和 f，验证你是否正确预测了输出结果
练习 13.14
*/

#include <iostream>

using std::cout;
using std::endl;

class numbered
{
public:
	numbered()
	{
		mysn = unique++;
	}

	int mysn;
	static int unique;
};

int numbered::unique = 10;

void f(numbered s)
{
	cout << s.mysn << endl;
}

int main()
{
	numbered a, b = a, c = b;

	f(a), f(b), f(c);

	return 0;
}

/*

10
10
10
Press any key to continue . . .

*/