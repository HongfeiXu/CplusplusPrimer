/*
* 练习1.6：解释下面程序是否合法。
*/

#include <iostream>

int main ()
{
    int v1 = 10, v2 = 3;
    std::cout << "The sum of " << v1;
    	<< " and " << v2;
    	<< " is " << v1 + v2 << std::endl;

    return 0;
}
/*

[alex@EX ch1]$ g++ -std=c++0x -Wall ex1_6.cpp 
ex1_6.cpp: 在函数‘int main()’中:
ex1_6.cpp:11:6: 错误：expected primary-expression before ‘<<’ token
      << " and " << v2;
      ^
ex1_6.cpp:12:6: 错误：expected primary-expression before ‘<<’ token
      << " is " << v1 + v2 << std::endl;
      ^

*/

