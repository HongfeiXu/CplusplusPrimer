/*
* 练习6.14：举一个形参应该是引用类型的例子，在举一个形参不能使引用类型的例子。
*/

// a parameter should be a reference type :

void reset (int &i)
{
	i = 0;
}
 
// a parameter should not be a reference :

void print (std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	for (std::vector<int>::iterator iter = begin; iter != end; ++iter)
		std::cout << *iter << std::endl;
}