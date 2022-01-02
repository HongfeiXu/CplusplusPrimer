#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

template<typename T>
ostream& print_container(const T& container, ostream& os=cout)
{
	for (typename T::size_type i = 0; i != container.size(); ++i)
		os << container[i] << " ";
	return os;
}

template<typename T>
ostream& print_container_by_iter(const T& container, ostream& os = cout)
{
	for (auto curr = container.cbegin(); curr != container.cend(); ++curr)
	{
		os << *curr << " ";
	}
	return os;
}

int main()
{
	auto vi = vector<int>{ 1,2,3,4,5 };
	print_container(vi) << endl;

	auto li = list<string>{ "hello", "world" };
	print_container_by_iter(li) << endl;
	return 0;
}