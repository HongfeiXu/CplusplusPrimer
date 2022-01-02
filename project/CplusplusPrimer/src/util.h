#pragma once

#include <vector>
#include <iostream>

using namespace std;

template<typename T>
void print_vector(const vector<T> &vec)
{
	copy(cbegin(vec), cend(vec), ostream_iterator<T>(cout, " "));
}



template<typename T, unsigned N>
void print_array(const T(&arr)[N])
{
	copy(std::cbegin(arr), std::cend(arr), ostream_iterator<T>(cout, " "));
}

template<typename T>
ostream& print_container(const T& container, ostream& os=cout)
{
	for (auto curr = container.cbegin(); curr != container.cend(); ++curr)
	{
		os << *curr << " ";
	}
	return os;
}


