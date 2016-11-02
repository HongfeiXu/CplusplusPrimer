/*
*	练习 10.12：编写名为 compareIsbn 的函数，比较两个 Sales_data 对象的 isbn() 成员。
*	使用这个函数排序一个保存 Sales_data 对象的 vector。
*/

#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

class Sales_data
{
	friend istream &read(istream&, Sales_data&);		// 友元声明
	friend ostream &print(ostream&, const Sales_data&);
public:
	Sales_data() = default;
	Sales_data(const string &s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(p * n) { }
	string isbn() const { return bookNo; }		// const 表示此成员函数为常量成员函数，常量成员函数不能改变调用它的对象的内容
private:
	string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

// 从文件读取数据 到 Sales_data 对象
istream &read(istream& is, Sales_data& sd)
{
	double price = 0;
	is >> sd.bookNo >> sd.units_sold >> price;
	sd.revenue = price * sd.units_sold;
	return is;
}

// 输出 Sales_data 对象的数据
ostream &print(ostream& os, const Sales_data& sd)
{
	os << sd.isbn() << ' ' << sd.units_sold << ' ' << sd.revenue << '\n';
	return os;
}

bool compareIsbn(const Sales_data& sd1, const Sales_data& sd2)
{
	return sd1.isbn() < sd2.isbn();
}

int main()
{
	ifstream in("book_sales");
	
	Sales_data item;
	vector<Sales_data> sdVec;

	while(read(in, item))
	{
	//	print(cout, item);
		sdVec.push_back(item);
	}

	cout << "There are " << sdVec.size() << " items\n\n";

	for(auto &item : sdVec)
	{
		print(cout, item);
	}

	sort(sdVec.begin(), sdVec.end(), compareIsbn);

	cout << "\nAfter sorting by isbn()\n\n";

	for(auto &item : sdVec)
	{
		print(cout, item);
	}
	
	return 0;
}

/*

There are 10 items

0-201-70353-X 4 99.96
0-201-82470-1 4 181.56
0-201-88954-4 2 30
0-201-88954-4 5 60
0-201-88954-4 7 84
0-201-88954-4 2 24
0-399-82477-1 2 90.78
0-399-82477-1 3 136.17
0-201-78345-X 3 60
0-201-78345-X 2 50

After sorting by isbn()

0-201-70353-X 4 99.96
0-201-78345-X 3 60
0-201-78345-X 2 50
0-201-82470-1 4 181.56
0-201-88954-4 2 30
0-201-88954-4 5 60
0-201-88954-4 7 84
0-201-88954-4 2 24
0-399-82477-1 2 90.78
0-399-82477-1 3 136.17
请按任意键继续. . .


*/