/*
* ��ϰ5.20����дһ�γ��򣬴ӱ�׼�����ж�ȡstring���������ֱ����������������ͬ�ĵ��ʻ������е��ʶ�����Ϊֹ��
* ʹ��whileѭ��һ�ζ�ȡһ�����ʣ���һ������������������ʱʹ��break�����ֹѭ������������ظ����ֵĵ��ʣ�����
* ���һ����Ϣ˵��û���κε����������ظ��ġ�
* ��ϰ5.21���޸�5.20����ʹ���ҵ����ظ����ʱ����Դ�д��ĸ��ͷ��
*/
#include <iostream>
#include <string>
#include <cctype>		// tolower()

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main ()
{
	string pre, now;
	bool find = false;
	while (cin >> now)
	{
		if (!isupper (now[0]))	// ��������ĸ���Ǵ�д�ĵ���
			continue;
		if (now == pre)
		{
			cout << now << endl;
			find = true;
			break;
		}
		else
		{
			pre = now;
		}
	}
	if (!find)
		cout << "û���κε����������ظ��ġ�" << endl;


	return 0;
}

/*

Hello world world World World Man Man
World
�밴���������. . .

*/