/*
* ��ϰ3.3����дһ�γ���ӱ�׼�����ж������ַ�����������������һ��������ӳɵĴ��ַ�����
* ��д���������ÿո������Ķ���ַ����ָ�������
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
	string str;
	cin >> str;
	string temp;
	while (cin >> temp)
	{
		// ����ַ�����������������һ��
		//str += temp;
		// �ÿո������Ķ���ַ����ָ�������
		str += (" " + temp);
	}
	cout << str << endl;

	return 0;
}

/*


hello
world
haha
^Z
helloworldhaha
�밴���������. . .


hello
world
haha
^Z
hello world haha
�밴���������. . .



*/