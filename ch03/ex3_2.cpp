/*
* ��ϰ3.2����дһ�γ���ӱ�׼������һ�ζ���һ���У�Ȼ���޸ĸĳ���ʹ��һ�ζ���һ���ʡ�
*/

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;


int main ()
{
	string line;
	// һ�ζ���һ����
	while (getline (cin, line))
		cout << line << endl;

	// һ�ζ���һ����
	//while (cin >> line)
	//	cout << line << endl;

	return 0;
}