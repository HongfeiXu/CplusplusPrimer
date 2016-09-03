/*
* 练习 9.24：编写程序，分别使用 at、下标运算符、front和begin提取一个 vector 中的第一个元素。在一个空 vector 上测试你的程序。
*/

#include <vector>
#include <iostream>
#include <stdexcept>

using std::vector;
using std::cout;
using std::endl;

int main()
{
	vector<int> iv;
	try {
		auto value1 = iv.at(0);				// 可编译，throw out_of_range 异常
	//	auto value2 = iv[0];				// 可编译，segmentation fault
	//	auto value3 = iv.front();			// 可编译，segmentation fault
	//	auto value4 = *(iv.begin());		// 可编译，segmentation fault
	}
	catch (std::out_of_range err){
		cout << err.what() << endl;
		cout << "out of range" << endl;
	}
	

	return 0;
}
