/*
* ��ϰ6.4����дһ���û�����������Ҫ���û�����һ�����֣��������ɸ����ֵĽ׳ˡ���main�����е��øú�����
*/
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int fact (int val)
{
	int ret = 1;
	while (val > 1)
		ret *= val--;
	return ret;
}

int askuser ()
{
	int val;
	cout << "Please enter a number: ";
	cin >> val;
	return val;
}

int main ()
{
	int val = askuser ();
	cout << fact (val) << endl;

	return 0;
}

/*

Please enter a number: 5
120
�밴���������. . .

*/