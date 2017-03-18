/*
* ��ϰ6.33����дһ���ݹ麯������� vector ��������ݡ�
* �˴���ͨ����������ʵ�֡�
*/

#include <iostream>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::cout;
using std::endl;

void printVector (vector<string>::iterator sbeg, vector<string>::iterator send)
{
	if (sbeg == send)
	{
		cout << endl;
		return;
	}
		cout << *sbeg << " ";
	sbeg += 1;
	printVector (sbeg, send);
}

int main ()
{
	vector<string> sv = { "hello", "world", "wow", "hey" };
	printVector (sv.begin (), sv.end ());
	return 0;
}

/*

hello world wow hey
�밴���������. . .

*/