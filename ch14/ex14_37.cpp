/*
练习14.37
编写一个类令其检查两个值是否相等。使用该对象及标准库算法编写程序，令其替换某个序列中具有给定值的所有实例。
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct IsEqual {
	IsEqual(int v) : value(v) { }
	bool operator()(int elem)
	{
		return elem == value;
	}

private:
	int value;
};

int main()
{
	std::vector<int> vi{ 1,2,3,4,5,1 };
	std::replace_if(vi.begin(), vi.end(), IsEqual(1), 9);
	for_each(vi.cbegin(), vi.cend(), [](int i) {std::cout << i << " "; });
	std::cout << std::endl;
}

/*
9 2 3 4 5 9

E:\BooksLearn\CPP\CplusplusPrimer\project\CplusplusPrimer\Debug\CplusplusPrimer.exe (进程 72484)已退出，代码为 0。
按任意键关闭此窗口. . .
*/
