#include <iostream>
int main ()
{
	// curVal����������ͳ�Ƶ��������ǽ��������ֵ����val
	int currVal = 0, val = 0;
	// ��ȡ��һ��������ȷ��ȷʵ�����ݿ��Դ���
	if (std::cin >> currVal) {
		int cnt = 1;						// �����������ڴ���ĵ�ǰֵ�ĸ���
		while (std::cin >> val) {				// ��ȡʣ�����
			if (val == currVal) {				// ���ֵ��ͬ
				++cnt;					// ��cnt��1
			}
			else {							// ���򣬴�ӡǰһ��ֵ�ĸ���
				std::cout << currVal << " occurs "
					<< cnt << " times" << std::endl;
				currVal = val;				// ��ס��ֵ
				cnt = 1;					// ���ü�����
			}
		}  // whileѭ�����������
		// ��ס��ӡ�ļ����һ��ֵ�ĸ���
		std::cout << currVal << " occurs "
			<< cnt << " times" << std::endl;
	} // ������if������������
}

/*

42 42 42 42 42 42 42^Z
42 occurs 7 times
�밴���������. . .


1 2 3 4 5 6 7 ^Z
1 occurs 1 times
2 occurs 1 times
3 occurs 1 times
4 occurs 1 times
5 occurs 1 times
6 occurs 1 times
7 occurs 1 times
�밴���������. . .

*/