#include <iostream>
int main ()
{
	// curVal是我们正在统计的数；我们将读入的新值存入val
	int currVal = 0, val = 0;
	// 读取第一个数，并确保确实有数据可以处理
	if (std::cin >> currVal) {
		int cnt = 1;						// 保存我们正在处理的当前值的个数
		while (std::cin >> val) {				// 读取剩余的数
			if (val == currVal) {				// 如果值相同
				++cnt;					// 将cnt加1
			}
			else {							// 否则，打印前一个值的个数
				std::cout << currVal << " occurs "
					<< cnt << " times" << std::endl;
				currVal = val;				// 记住新值
				cnt = 1;					// 重置计数器
			}
		}  // while循环在这里结束
		// 记住打印文件最后一个值的个数
		std::cout << currVal << " occurs "
			<< cnt << " times" << std::endl;
	} // 最外层的if语句在这里结束
}

/*

42 42 42 42 42 42 42^Z
42 occurs 7 times
请按任意键继续. . .


1 2 3 4 5 6 7 ^Z
1 occurs 1 times
2 occurs 1 times
3 occurs 1 times
4 occurs 1 times
5 occurs 1 times
6 occurs 1 times
7 occurs 1 times
请按任意键继续. . .

*/