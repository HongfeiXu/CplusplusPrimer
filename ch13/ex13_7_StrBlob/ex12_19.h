/*

��ϰ12.19���������Լ��汾�� StrBlobPtr������ StrBlob �࣬����ǡ���� friend ������ begin �� end ��Ա

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

	StrBlobPtr begin();	// ʵ���� ex12_19.cpp �ļ���
	StrBlobPtr end();	// ͬ��

	long count()
	{
		return data.use_count();
	}

private:
	shared_ptr<vector<string>> data;

	void StrBlob::check(size_type i, const string &msg) const  // ��� data[i]���Ϸ������׳�һ���쳣
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

	string &deref() const  // ������
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];  // (*p)�Ƕ�����ָ��� vector
	}

	StrBlobPtr &incr()  // ǰ׺���� StrBlobPtr��ͨ������ curr ʵ�֣�
	{
		// ��� curr �Ѿ�ָ��������β��λ�ã��Ͳ����ٵ�����
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
		auto ret = wptr.lock();  // vector ��������
		if(!ret)
			throw runtime_error("unbound StrBlobPtr");
		if(i >= ret->size())
			throw out_of_range(msg);
		return ret;
	}
	weak_ptr<vector<string>> wptr;
	size_t curr;  // ���浱ǰ��������ʾ��Ԫ�ص��±�
};

#endif // !STR_BOLB_H
