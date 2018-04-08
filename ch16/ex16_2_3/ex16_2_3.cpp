/*
*
*  练习 16.2：编写并测试你自己版本的 compare 函数
*  练习 16.3：对两个 Sales_data 对象调用你的 compare 函数，观察编译器在实例化过程中如何处理错误。
*
*/

#include <vector>
#include "ex7_41.h"

template <typename T>
inline int compare(const T &lhs, const T &rhs)
{
	if (lhs < rhs) return -1;
	if (rhs < lhs) return 1;
	return 0;
}


int main()
{
	std::vector<int> vec_0 = { 1,2,3,4 };
	std::vector<int> vec_1 = { 2,3,4 };
	
	std::cout << compare(vec_0, vec_1) << std::endl;

	Sales_data data_0(string("0x121314"), 10, 12.0);
	Sales_data data_1(string("1x31123"), 20, 11.0);

	// Error	C2676	binary '<': 'const Sales_data' does not define this operator or a conversion to a type acceptable to the predefined operator
	std::cout << compare(data_0, data_1) << std::endl;

	return 0;
}