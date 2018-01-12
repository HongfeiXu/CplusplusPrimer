/*
* ��ϰ3.40����дһ�γ��򣬶��������ַ����鲢���ַ�������ֵ��ʼ�����ǣ�
* �����ڶ���һ���ַ�������ǰ�����������Ӻ�Ľ����
* ʹ��strcpy��strcat��ǰ������������ݿ����������������С�
*/

#include <iostream>
#include <cstring>

using std::cout; 
using std::endl;

constexpr size_t constexpr_strlen (const char *s)
{
	return sizeof (s) / sizeof (*s);			// sizeof����һ����������ʽ
}


constexpr size_t merge_size (const char* cs1, const char* cs2)
{
	return constexpr_strlen (cs1) + constexpr_strlen (" ") + constexpr_strlen (cs2) + 1;		// ʹ��strlen����
}

int main ()
{
	constexpr const char cs1[] = "Hi";
	constexpr const char cs2[] = "frank67";
	char cs3[merge_size (cs1, cs2)];
	strcpy (cs3, cs1);
	strcat (cs3, " ");
	strcat (cs3, cs2);
	cout << cs3 << endl;
	return 0;
}

/*

Hi frank67
�밴���������. . .

*/