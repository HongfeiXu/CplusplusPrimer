/*
* ��ϰ5.25����дһ�γ��򣬴ӱ�׼�����ȡ���������������һ�������Եڶ������Ľ����
* ʹ��try����ȥ�����쳣��catch�Ӿ�Ӧ��Ϊ�û����һ����ʾ��Ϣ��ѯ�����Ƿ��������������ִ��try��������ݡ�
*/
#include <iostream>
#include <stdexcept>

using std::runtime_error;
using std::cin;
using std::cout;
using std::endl;

int main ()
{
	int a, b;
	while (cin >> a >> b)
	{
		try 
		{
			if (b == 0)		// �������Ϊ0���׳��쳣
				throw runtime_error ("��������Ϊ0��");
			cout << a << " / " << b << " = " << a / b << endl;
		}
		catch (runtime_error err)	// �����쳣
		{
			cout << err.what()	// ����쳣��Ϣ
				<< "\nTry again? Enter y or n" << endl;		// ѯ���Ƿ����
			char c;
			cin >> c;
			if (!cin || c == 'n')
				break;		// ����whileѭ��
		}
	}

	return 0;
}

/*

12 3
12 / 3 = 4
12 0
��������Ϊ0��
Try again? Enter y or n
y
9 19
9 / 19 = 0
1 0
��������Ϊ0��
Try again? Enter y or n
n
�밴���������. . .

*/