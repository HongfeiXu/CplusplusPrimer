/*

There are two special member assignment operators which typically have the signatures:

HasPtr& operator=(const HasPtr& rhs);  // copy assignment operator
HasPtr& operator=(HasPtr&& rhs);       // move assignment operator
It is possible to implement both move assignment and copy assignment with a single assignment operator with what is called the copy/swap idiom:

HasPtr& operator=(HasPtr rhs);
This single assignment operator can not be overloaded with the first set.

Is it better to implement two assignment operators (copy and move), or just one, using the copy/swap idiom?
This is what Exercise 13.53 is asking. To answer, you must try both ways, and measure both copy assignment and move assignment.
And smart, well meaning people get this wrong by guessing, instead of testing/measuring. You have picked a good exercise to study.


然后程序测试发现两者的时间差不多。。。不是很明白。

*/

#include "HasPtr.h"
#include <algorithm>
#include <vector>
#include <string>
#include <chrono>

using namespace std;

int main()
{
	HasPtr hp1("Lebron", 1);
	HasPtr hp2("Kobe", 10);
	HasPtr hp3("Jordan", 2);

	auto t0 = std::chrono::high_resolution_clock::now();

	//////////////////////////////////////////////////////////////////////////
	// test 1, between copy-swap assignment operator and copy assignment operator
	// copy-swap 660ms
	// copy assignment 685ms
	
	for (int i = 0; i < 200000; ++i)
		hp1 = hp2;

	//////////////////////////////////////////////////////////////////////////
	// test 2, between copy-swap assignment opeartor and move assignment operator
	// copy-swap 1198ms
	// move assignment 1079ms

	//for (int i = 0; i < 200000; ++i)
	//{
	//	hp1 = std::move(HasPtr("IceMj"));
	//}


	auto t1 = std::chrono::high_resolution_clock::now();

	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0).count() << "ms\n";

	return 0;
}

