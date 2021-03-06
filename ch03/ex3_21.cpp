/*
* 练习3.21：请使用迭代器重做练习3.16。
*/

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using std::vector;
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main ()
{
	vector<int> v1;
	cout << "{\n \"v1\":{\"size\":\"" << v1.cend () - v1.cbegin () << "\",\"value\":[";
	for (auto it = v1.cbegin (); it != v1.cend (); ++it)
		cout << *it << ",";
	if (v1.cbegin () != v1.cend ())
		cout << "\b";
	cout << "]}" << endl;
	vector<int> v2 (10);
	cout << "{\n \"v2\":{\"size\":\"" << v2.cend() - v2.cbegin() << "\",\"value\":[";
	for (auto it = v2.cbegin(); it != v2.cend(); ++it)
		cout << *it << " ,";
	if (v2.cbegin() != v2.cend())
		cout << "\b";
	cout << "]}" << endl;
	vector<int> v3 (10, 42);
	cout << "{\n \"v3\":{\"size\":\"" << v3.cend() - v3.cbegin() << "\",\"value\":[";
	for (auto it = v3.cbegin(); it != v3.cend(); ++it)
		cout << *it << " ,";
	if (v3.cbegin() != v3.cend())
		cout << "\b";
	cout << "]}" << endl;
	vector<int> v4 (10);
	cout << "{\n \"v4\":{\"size\":\"" << v4.cend() - v4.cbegin() << "\",\"value\":[";
	for (auto it = v4.cbegin(); it != v4.cend(); ++it)
		cout << *it << " ,";
	if (v4.cbegin() != v4.cend())
		cout << "\b";
	cout << "]}" << endl;
	vector<int> v5 (10, 42);
	cout << "{\n \"v5\":{\"size\":\"" << v5.cend() - v5.cbegin() << "\",\"value\":[";
	for (auto it = v5.cbegin(); it != v5.cend(); ++it)
		cout << *it << " ,";
	if (v5.cbegin() != v5.cend())
		cout << "\b";
	cout << "]}" << endl;
	vector<string> v6{ 10 };
	cout << "{\n \"v6\":{\"size\":\"" << v6.cend() - v6.cbegin() << "\",\"value\":[";
	for (auto it = v6.cbegin(); it != v6.cend(); ++it)
	{
		if (it->cbegin() == it->cend())		// *it 为迭代器所指的对象，字符串。若字符串为空
			cout << "(null)" << ",";
		else
			cout << *it << ",";
	}
	if (v6.cbegin() != v6.cend())
		cout << "\b";
	cout << "]}" << endl;
	vector<string> v7 (10, "hi");
	cout << "{\n \"v7\":{\"size\":\"" << v7.cend() - v7.cbegin() << "\",\"value\":[";
	for (auto it = v7.cbegin(); it != v7.cend(); ++it)
	{
		if (it->cbegin() == it->cend())
			cout << "(null)" << ",";
		else
			cout << *it << ",";
	}
	if (v7.cbegin() != v7.cend())
		cout << "\b";
	cout << "]}" << endl;

	return 0;
}

/*

{
"v1":{"size":"0","value":[]}
{
"v2":{"size":"10","value":[0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ]}
{
"v3":{"size":"10","value":[42 ,42 ,42 ,42 ,42 ,42 ,42 ,42 ,42 ,42 ]}
{
"v4":{"size":"10","value":[0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ]}
{
"v5":{"size":"10","value":[42 ,42 ,42 ,42 ,42 ,42 ,42 ,42 ,42 ,42 ]}
{
"v6":{"size":"10","value":[(null),(null),(null),(null),(null),(null),(null),(null),(null),(null)]}
{
"v7":{"size":"10","value":[hi,hi,hi,hi,hi,hi,hi,hi,hi,hi]}
请按任意键继续. . .

*/