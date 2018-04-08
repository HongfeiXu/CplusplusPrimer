/*
练习 13.17：分别编写前三题中所描述的 numbered 和 f，验证你是否正确预测了输出结果
练习 13.16
*/

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class numbered
{
public:
	numbered()
	{
		mysn = unique++;
	}
	numbered(const numbered& rhs)
	{
		mysn = unique++;
		sateliteInfo = rhs.sateliteInfo;
	}

	int mysn;
	string sateliteInfo;
	static int unique;
};

int numbered::unique = 10;

void f(const numbered& s)
{
	cout << s.mysn << endl;
}

int main()
{
	numbered a, b = a, c = b;  // call copy constructor not copy-assignment operator

	f(a), f(b), f(c);

	return 0;
}

/*

10
11
12
Press any key to continue . . .

*/