/*

练习 12.2：编写你自己的 StrBlob 类，包含 const 版本的 front 和 back。

*/

#ifndef STR_BOLB_H
#define STR_BLOB_H

#include <string>
#include <vector>
#include <memory>
#include <initializer_list>

using namespace std;

class StrBlob
{
public:
	using size_type = vector<string>::size_type;
	StrBlob();
	StrBlob(initializer_list<string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const string & t) { data->push_back(t); }
	void pop_back();
	string & front();
	const string &front() const;
	string & back();
	const string &back() const;
private:
	shared_ptr<vector<string>> data;
	void check(size_type i, const string &msg) const;	// 如果 data[i]不合法，则抛出一个异常
};

StrBlob::StrBlob() : data(make_shared<vector<string>>()) { }

StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) { }

void StrBlob::check(size_type i, const string &msg) const
{
	if(i >= data->size())
		throw out_of_range(msg);
}

string &StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

const string &StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

string &StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

const string &StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	return data->pop_back();
}

#endif // !STR_BOLB_H
