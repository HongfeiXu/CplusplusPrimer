// 练习 8.1
// Write a function that takes and returns an istream&.
// The function should read the stream until it hits end - of - file.
// The function should print what it reads to the standard output.
// Reset the stream so that it is valid before returning the stream.

#include <iostream>
#include <string> 

using std::istream;
using std::string;
using std::cout;
using std::endl;
using std::cin;

istream& func(istream& is)
{
	string buf;
	while(is >> buf)
	{
		std::cout << buf << endl;
	}
	is.clear();
	return is;
}

int main()
{
	istream& is = func(cin);
	cout << is.rdstate() << endl;
	return 0;
}