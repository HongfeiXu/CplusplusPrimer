/*
*	练习 9.51：设计一个类，它有三个 unsigned 成员，分别表示年、月和日。为其编写构造函数，接受一个表示日期的 string 参数。
*	你的构造函数应该能处理不同数据格式，如 January 1, 1990、1/1/1990、Jan 1 1990 等。
*/


#include <string>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

const string digits("0123456789");
const string letters("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

const string months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
const string months_2[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

unsigned month2Number(string monthString)
{
	for(unsigned i = 1; i <= 12; ++i)
	{
		if(monthString.compare(months[i - 1]) == 0 || monthString.compare(months_2[i - 1]) == 0)
		{
			return i;
		}
	}
	return 0;
}

class Date
{
private:
	unsigned year;
	unsigned month;
	unsigned day;

public:
	Date(string dataString);
	void printDate(void);
};

Date::Date(string dateString)
{
	// 处理形如 1/1/1990 的日期
	if(dateString.find_first_of(digits) < dateString.find_first_of(letters))
	{
		month = stoul(dateString);
		string sub = dateString.substr(dateString.find_first_not_of(digits));
		sub = sub.substr(sub.find_first_of(digits));
		day = stoul(sub);
		sub = sub.substr(sub.find_first_not_of(digits));
		sub = sub.substr(sub.find_first_of(digits));
		year = stoul(sub);
	}
	// 处理形如 January 1, 1990、Jan 1 1990 的日期
	else if(dateString.find_first_of(letters) < dateString.find_first_of(digits))
	{
		istringstream is(dateString);		// 使用 istringstream 来读取一个单词（月份）
		string monthString;
		is >> monthString;
		//cout << monthString << endl;
		month = month2Number(monthString);
		is.clear();
		string sub = dateString.substr(dateString.find_first_of(digits));
		day = stoul(sub);
		sub = sub.substr(sub.find_first_not_of(digits));
		sub = sub.substr(sub.find_first_of(digits));
		year = stoul(sub);
	}
	else
	{
		cerr << "日期输入不正确，请输入格式为 January 1, 1990、1/1/1990、Jan 1 1990 的日期。\n";
		exit(EXIT_FAILURE);
	}
}

void Date::printDate(void)
{
	cout << "Month: \t" << month << endl;
	cout << "Day: \t" << day << endl;
	cout << "Year: \t" << year << endl;
	cout << endl;
}

int main()
{
	string dateString("9/1/1990");
	string dateString_2("12//3//1994");
	string dateString_3("Feb 12, 2001");
	string dateString_4("January 1 1990");

	Date date(dateString);
	Date date_2(dateString_2);
	Date date_3(dateString_3);
	Date date_4(dateString_4);

	date.printDate();
	date_2.printDate();
	date_3.printDate();
	date_4.printDate();

	return 0;
}


/*

Month:  9
Day:    1
Year:   1990

Month:  12
Day:    3
Year:   1994

Month:  2
Day:    12
Year:   2001

Month:  1
Day:    1
Year:   1990

请按任意键继续. . .

*/
