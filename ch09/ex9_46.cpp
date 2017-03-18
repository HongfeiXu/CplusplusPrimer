/*
*	练习 9.45：编写一个函数，接受一个表示名字的 string 参数，和两个分别表示前缀（如"Mr."或"Mrs."）和后缀（如"Jr."或"III"）的字符串。
*	使用迭代器及 insert 和 append 函数将前缀和后缀添加到给定的名字中，将生成的新 string 返回。
*
*	练习 9.46：重写上一题函数，这次使用位置和长度来管理 string，并只使用 insert。
*/

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

string add_pre_and_suffix(const string &name, const char * prefix, const char * postfix);
string add_pre_and_suffix2(const string &name, const string &prefix, const string &postfix);


int main()
{
	string name = "Xu";
	string newName = add_pre_and_suffix(name, "Mr.", "Jr.");
	cout << newName << endl;

	name = "Zhu";
	newName = add_pre_and_suffix2(name, "Mrs.", "III");
	cout << newName << endl;

	return 0;
}


string add_pre_and_suffix(const string &name, const char * prefix, const char * postfix)
{
	string newName(name.cbegin(), name.cend());
	string temp(prefix);
	newName.insert(newName.begin(), temp.cbegin(), temp.cend());
	temp = postfix;
	return newName.append(temp.begin(), temp.end());
}

string add_pre_and_suffix2(const string &name, const string &prefix, const string &postfix)
{
	string newName(name);
	newName.insert(0, prefix, 0, prefix.size());
	return newName.append(postfix, 0, postfix.size());
}



/*

Mr.XuJr.
Mrs.ZhuIII
请按任意键继续. . .


*/