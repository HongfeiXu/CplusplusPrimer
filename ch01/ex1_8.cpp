/*
* Indicate which, if any, of the following output statements are legal:
* After you’ve predicted what will happen, test your answers by compiling 
* a program with each of these statements. Correct any errors you encounter.
*/
#include <iostream>
int main ()
{
//	std::cout << "/*";
//	std::cout << "*/";
	std::cout << /* "*/" */;
//	std::cout << /* "*/" /* "/*" */;	

	return 0;
}




// 1. Legal

// [alex@EX ch1]$ g++ -Wall ex1_8.cpp 
// [alex@EX ch1]$ ./a.out 
// /*[alex@EX ch1]$ 

// 2.

// [alex@EX ch1]$ g++ -Wall ex1_8.cpp 
// [alex@EX ch1]$ ./a.out 
// */[alex@EX ch1]$ 

// 3.

// [alex@EX ch1]$ g++ -Wall ex1_8.cpp 
// ex1_8.cpp:6:21: 警告：缺少结尾的 " 字符
//   std::cout << /* "*/" */;
//                      ^
// ex1_8.cpp:6:2: 错误：缺少结尾的 " 字符
//   std::cout << /* "*/" */;
//   ^
// ex1_8.cpp: 在函数‘int main()’中:
// ex1_8.cpp:9:2: 错误：expected primary-expression before ‘return’
//   return 0;
//   ^
// [alex@EX ch1]$ 

// Correct by add a quote
// std::cout << /* "*/" */";


// 4. Legal

// [alex@EX ch1]$ g++ -Wall ex1_8.cpp 
// [alex@EX ch1]$ ./a.out 
//  /* [alex@EX ch1]$ 
