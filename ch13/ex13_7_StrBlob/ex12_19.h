/*

练习12.19：定义你自己版本的 StrBlobPtr，更新 StrBlob 类，加入恰当的 friend 声明及 begin 和 end 成员

*/

#ifndef STR_BOLB_H
#define STR_BLOB_H

#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <stdexcept>

using namespace std;

class StrBlobPtr;

class StrBlob
{
	friend class StrBlobPtr;
public:
	using size_type = vector<string>::size_type;
	StrBlob() : data(make_shared<vector<string>>()) { }
	StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) { }

	size_type size() const { return data->size(); }

	bool empty() const { return data->empty(); }

	void push_back(const string & t) 
	{ 
		data->push_back(t); 
	}

	void pop_back()
	{
		check(0, "pop_back on empty StrBlob");
		return data->pop_back();
	}

	string &front()
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}

	const string &front() const
	{
		check(0, "front on empty StrBlob");
		return data->front();
	}

	string &back()
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}

	const string &back() const
	{
		check(0, "back on empty StrBlob");
		return data->back();
	}

	StrBlobPtr begin();	// 实现在 ex12_19.cpp 文件中
	StrBlobPtr end();	// 同上

	long count()
	{
		return data.use_count();
	}

private:
	shared_ptr<vector<string>> data;

	void StrBlob::check(size_type i, const string &msg) const  // 如果 data[i]不合法，则抛出一个异常
	{
		if(i >= data->size())
			throw out_of_range(msg);
	}
};

class StrBlobPtr
{
public:
	StrBlobPtr() : curr(0) { }
	StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }

	bool operator != (const StrBlobPtr& p) { return p.curr != curr; }

	string &deref() const  // 解引用
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];  // (*p)是对象所指向的 vector
	}

	StrBlobPtr &incr()  // 前缀递增 StrBlobPtr（通过递增 curr 实现）
	{
		// 如果 curr 已经指向容器的尾后位置，就不能再递增它
		check(curr, "increment past end of StrBlobPtr");
		++curr;
		return *this;
	}

	long count()
	{
		return wptr.use_count();
	}

private:
	shared_ptr<vector<string>> check(size_t i, const string &msg) const
	{
		auto ret = wptr.lock();  // vector 还存在吗？
		if(!ret)
			throw runtime_error("unbound StrBlobPtr");
		if(i >= ret->size())
			throw out_of_range(msg);
		return ret;
	}
	weak_ptr<vector<string>> wptr;
	size_t curr;  // 保存当前对象所表示的元素的下标
};

#endif // !STR_BOLB_H
