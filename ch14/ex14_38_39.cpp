/*

练习14.38
Write a class that tests whether the length of a given string matches a given bound. 
Use that object to write a program to report how many words in an input file are of sizes 1 through 10 inclusive.

练习14.39
Revise the previous program to report the count of words that are sizes 1 through 9 and 10 or more.

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

class IsInRange {
public:
	IsInRange(std::size_t lower, std::size_t upper) : lower_limit(lower), upper_limit(upper) { }
	bool operator()(const std::string& s) const
	{
		std::size_t sz = s.size();
		return sz >= lower_limit && sz <= upper_limit;
	}
private:
	std::size_t lower_limit{ 0 };
	std:: size_t upper_limit{ 0 };
};

int main()
{
	std::string fileName = "testfile.txt";
	std::ifstream in(fileName);

	IsInRange isInRange(1, 10);
	IsInRange isInRange2(1, 9);
	std::size_t count = 0;
	std::size_t count2 = 0;
	std::size_t count3 = 0;
	for (std::string word; in >> word;)
	{
		if (isInRange(word))
			++count;
		if (isInRange2(word))
			++count2;
		else
			++count3;
	}
	std::cout << "there are " << count << " words in the input file are of sizes 1 through 10 inclusive" << std::endl;
	std::cout << "there are " << count2 << " words in the input file are of size 1 through 9, \nthere are " << count3 << " words are of size 10 or more" << std::endl;

	return 0;
}

/*
there are 104 words in the input file are of sizes 1 through 10 inclusive
there are 103 words in the input file are of size 1 through 9,
there are 3 words are of size 10 or more

E:\BooksLearn\CPP\CplusplusPrimer\project\CplusplusPrimer\Debug\CplusplusPrimer.exe (进程 23416)已退出，代码为 0。
按任意键关闭此窗口. . .
*/
