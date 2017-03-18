// 练习 7.55：第266页的 Data 类是字面值常亮类吗？请解释其原因。

#include <string>
#include <iostream>
#include <type_traits>

struct Data {
	int ival;
	std::string s;
};

int main ()
{
	std::cout << std::boolalpha;
	std::cout << std::is_literal_type<Data>::value << std::endl;
	return 0;
}

/*

false
请按任意键继续. . .

*/