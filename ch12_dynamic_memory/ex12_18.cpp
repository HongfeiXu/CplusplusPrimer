/*
练习 12.17：下面的 unique_ptr 声明中，哪些是合法的，哪些可能导致后续的程序错误？解释每个错误的问题在哪里。
*/

#include <memory>

using namespace std;

int main()
{
	int ix = 1024, *pi = &ix, *pi2 = new int(2048);
	using IntP = unique_ptr<int>;

	// (a)
	// error: Invalid conversion from 'int' to 'std::unique_ptr<int>::pointer{ aka int* }'
//	IntP p0(ix);

	// (b)
	// error:	The code below can compile, but will cause error at run time.
	//			the reason is that when the unique_ptr p1 is out of scope, delete will be called
	//			to free the object. But the object is not allocate using new. Thus, an error
	//			would be thrown by operating system.
//	IntP p1(pi);

	// (c)
	// badcode: The code below can compile, but cause a dangling pointer at run time.
	//			The reason is that the unique_ptr will free the object the raw pointer is pointing to.
//	IntP p2(pi2);

	// (d)
	// error:	similar to case (b)
//	IntP p3(&ix);

	// (e)
	// Recommended
	IntP p4(new int(2048));

	// (f)
	// error:	double free or corruption at run time
	//			two unique_ptr are pointing to the same object.
	//			Thus, when both are out of scope, OS will throw double free or corruption.
//	IntP p2(new int(555));
//	IntP p5(p2.get());

	return 0;
}