/*
	练习 11.7：定义一个 map，关键字是家庭的姓，值是一个 vector，保存家中孩子（们）的名。
	编写程序，实现添加新的家庭以及向已有家庭中添加新的孩子。
	练习 11.14：扩展你在 11.2.1 节练习（第378页）中编写的孩子姓到名的 map，添加一个 pair 的 vector，保存孩子的名和生日。
*/


#include <vector>
#include <map>
#include <string>
#include <vector>
#include <utility>
#include <iostream>

using namespace std;

class Families
{
public:
	using Child = pair<string, string>;		// type atlias
	using Children = vector<Child>;
	using Data = map<string, Children>;

	auto add(const string & last_name, const string & first_name, const string & birthday)
	{
		auto child = make_pair(first_name, birthday);
		_data[last_name].push_back(child);
	}

	auto print() const
	{
		for(const auto & family : _data)
		{
			cout << family.first << ":\n";
			for(const auto & child : family.second)
				cout << child.first << " " << child.second << endl;
			cout << endl;
		}
	}


private:
	Data _data;
};

int main()
{
	Families families;
	auto msg = "Please enter first name, last name, and birthday:\n";
	for(string fstName, lstName, birthday; cout << msg, cin >> fstName >> lstName >> birthday; families.add(lstName, fstName, birthday));
	families.print();

	return 0;
}

/*

Please enter first name, last name, and birthday:
Roger Alex 1994.10.24
Please enter first name, last name, and birthday:
Bobo Zhu 1993.07.72
Please enter first name, last name, and birthday:
Qi Zhu 1969.10.1
Please enter first name, last name, and birthday:
Liangdong Xu 1969.10.2
Please enter first name, last name, and birthday:
^Z
Alex:
Roger 1994.10.24

Xu:
Liangdong 1969.10.2

Zhu:
Bobo 1993.07.72
Qi 1969.10.1

请按任意键继续. . .

*/