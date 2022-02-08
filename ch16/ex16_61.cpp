/*

练习16.61
定义你自己版本的 make_shared。

*/
#include <memory>
#include <iostream>
#include <vector>

template<typename T, typename... Args> // T为函数模板显示实参
auto my_make_shared(Args... args) -> std::shared_ptr<T>
{
	return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
}

int main()
{
	//auto pvec = std::make_shared<std::vector<int>>(3, 1);
	auto pvec = my_make_shared<std::vector<int>>(3, 1);

	for (auto it = pvec->cbegin(); it != pvec->cend(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;

	return 0;
}
