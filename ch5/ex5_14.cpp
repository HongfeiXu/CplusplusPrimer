/*
* ��ϰ5.14����дһ�γ��򣬴ӱ�׼�����ж�ȡ����string���󲢲��������ظ����ֵĵ��ʡ�
* Ҫ���¼�ظ����ֵ��������Լ���Ӧ�ĵ��ʡ���������ĵ��ʴ��ڣ�����ظ����ֵ���������
* ��������ڣ����һ����Ϣ˵���κε��ʶ�û���������ֹ���
*/

#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main ()
{
	string repeat;				// ��¼��ĿǰΪֹ�ظ����������ַ���
	unsigned repeatCnt = 0;		// ��¼�ظ����������ַ����ظ��Ĵ���
	string now, pre;			// ��¼��ǰ������ַ�������¼ǰһ��������ַ���������ȷ���Ƿ�������
	unsigned nowCnt = 0;		// ��¼��ǰ������ַ����������ֵĴ���������ͬrepearCnt�Ƚϡ�

	while (cin >> now)
	{
		if (now == pre)
		{
			++nowCnt;
			if (nowCnt > repeatCnt)
			{
				repeat = now;
				repeatCnt = nowCnt;
			}
		}
		else
		{
			nowCnt = 1;
			pre = now;
		}
	}
	if (repeatCnt > 1)
		cout << repeat << ":\t" << repeatCnt << endl;
	else
		cout << "�κε��ʶ�û���������ֹ�" << endl;


	return 0;
}

/*

how now now now brown cow cow
^Z
now:    3
�밴���������. . .

*/