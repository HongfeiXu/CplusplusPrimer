/*
练习 12.16：
Compilers don’t always give easy-to-understand error messages if we attempt to
copy or assign a unique_ptr. Write a program that contains these errors to see
how your compiler diagnoses them.


*/
#include <memory>

using namespace std;

int main()
{
	unique_ptr<int> p1(new int(42));
	unique_ptr<int> p2(p1);
//	Error	C2280	'std::unique_ptr<int,std::default_delete<_Ty>>::unique_ptr(const std::unique_ptr<_Ty,std::default_delete<_Ty>> &)': attempting to reference a deleted function

	unique_ptr<int> p3;
	p3 = p1;
//	Error	C2280	'std::unique_ptr<int,std::default_delete<_Ty>>::unique_ptr(const std::unique_ptr<_Ty,std::default_delete<_Ty>> &)': attempting to reference a deleted function


	return 0;
}