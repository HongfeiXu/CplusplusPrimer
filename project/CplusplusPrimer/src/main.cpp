#include <algorithm>
#include <vector>
#include <iostream>

int main()
{
	int x;
	auto c1 = [x](int y) {return x * y > 55; }; // c1是lambda产生的闭包的副本
	auto c2 = c1; // c2是c1的拷贝
	auto c3 = c2; // c3是c2的拷贝
}
