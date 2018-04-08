/*

练习 12.22：为了能让 ConstStrBlobPtr 使用 const StrBlob，你觉得应该如何修改？
定义一个名为 ConstStrBlobPtr 的类，使其能够指向 const Strblob。

*/

#ifndef STR_BOLB_H
#define STR_BLOB_H

#include <string>
#include <vector>
#include <memory>
#include <initializer_list>

using namespace std;

class ConstStrBlobPtr;

class StrBlob
{
	friend class ConstStrBlobPtr;
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

	ConstStrBlobPtr cbegin() const;  // add const
	ConstStrBlobPtr cend() const;  // add const


private:
	shared_ptr<vector<string>> data;

	void StrBlob::check(size_type i, const string &msg) const  // 如果 data[i]不合法，则抛出一个异常
	{
		if(i >= data->size())
			throw out_of_range(msg);
	}
};

class ConstStrBlobPtr
{
public:
	ConstStrBlobPtr() : curr(0) { }
	ConstStrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) { }

	bool operator != (const ConstStrBlobPtr& p) { return p.curr != curr; }

	string &deref() const  // 解引用
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];  // (*p)是对象所指向的 vector
	}

	ConstStrBlobPtr &incr()  // 前缀递增 ConstStrBlobPtr（通过递增 curr 实现）
	{
		// 如果 curr 已经指向容器的尾后位置，就不能再递增它
		check(curr, "increment past end of StrBlobPtr");
		++curr;
		return *this;
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
