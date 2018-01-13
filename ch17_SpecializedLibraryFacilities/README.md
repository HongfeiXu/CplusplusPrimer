# 第 17 章 标准库特殊设施

## 17.1 tuple 类型

## 17.2 bitset 类型

## 17.3 正则表达式

## 17.4 随机数

>随机数引擎类 + 随机数分布类

### 例子
```c++
#include <random>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

vector<unsigned>  randVec();

int main()
{
	auto vec1 = randVec();
	auto vec2 = randVec();

	for (size_t i = 0; i < 10; ++i)
		cout << vec1[i] << " ";
	cout << endl;

	for (size_t i = 0; i < 10; ++i)
		cout << vec2[i] << " ";
	cout << endl;

	return 0;
}

// 生成一个 vector，包含100个均匀分布在 0 到 9 之间的随机数
vector<unsigned>  randVec()
{
	// 由于我们希望引擎和分布对象保持状态，因此应该讲它们
	// 定义为 static 的，从而每次 “调用” 都生成新的数
	static default_random_engine e(time(nullptr));		// 设置随机数发生器的种子，使得每次 “运行程序” 都生成不同的随机结果
													// 由于 time 返回以秒计的时间，因此这种方式只适用于生成种子间隔为秒级或更长的应用
	static uniform_int_distribution<unsigned> u(0, 9);
	vector<unsigned> ret;
	for (size_t i = 0; i < 10; ++i)
		ret.push_back(u(e));
	return ret;
}

/*

0 6 3 3 7 0 9 5 1 4
3 6 1 2 5 2 0 2 9 2
请按任意键继续. . .

7 9 6 4 2 3 2 9 3 7
3 3 7 3 5 4 2 4 6 4
请按任意键继续. . .

*/

```
