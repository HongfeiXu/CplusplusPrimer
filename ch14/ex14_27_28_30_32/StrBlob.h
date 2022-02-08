#pragma once

#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <stdexcept>

using namespace std;

class StrBlobPtr;
class ConstStrBlobPtr;

class StrBlob
{
	using size_type = vector<string>::size_type;

	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;
	friend bool operator==(const StrBlob&, const StrBlob&);
	friend bool operator!=(const StrBlob&, const StrBlob&);
	friend bool operator<(const StrBlob&, const StrBlob&);
	friend bool operator>(const StrBlob&, const StrBlob&);
	friend bool operator<=(const StrBlob&, const StrBlob&);
	friend bool operator>=(const StrBlob&, const StrBlob&);
public:
	StrBlob() : data(make_shared<vector<string>>()) { }
	StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) { }

	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }

	void push_back(const string& t) { data->push_back(t); }
	void push_back(string&& s) { data->push_back(std::move(s)); }
	void pop_back();
	string& front();
	string& back();
	const string& front() const;
	const string& back() const;

	StrBlobPtr begin();
	StrBlobPtr end();
	ConstStrBlobPtr cbegin() const;
	ConstStrBlobPtr cend() const;

	string& operator[](size_t n);
	const string& operator[] (size_t n) const;

private:
	void check(size_type i, const string& msg) const;  // 如果 data[i]不合法，则抛出一个异常

private:
	shared_ptr<vector<string>> data;
};

bool operator==(const StrBlob&, const StrBlob&);
bool operator!=(const StrBlob&, const StrBlob&);
bool operator<(const StrBlob&, const StrBlob&);
bool operator>(const StrBlob&, const StrBlob&);
bool operator<=(const StrBlob&, const StrBlob&);
bool operator>=(const StrBlob&, const StrBlob&);


class StrBlobPtr
{
	friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator>(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator>=(const StrBlobPtr&, const StrBlobPtr&);
public:
	StrBlobPtr() : curr(0) { }
	StrBlobPtr(StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) { }

	string& deref() const;	// 解引用
	StrBlobPtr& incr();		// 前缀递增 StrBlobPtr（通过递增 curr 实现）

	string& operator[](size_t n);
	const string& operator[](size_t n) const;
	StrBlobPtr& operator++();
	StrBlobPtr& operator--();
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);
	StrBlobPtr& operator+=(size_t);
	StrBlobPtr& operator-=(size_t);
	StrBlobPtr operator+(size_t);
	StrBlobPtr operator-(size_t);
	std::string& operator*() const;
	std::string* operator->() const;

private:
	shared_ptr<vector<string>> check(size_t i, const string& msg) const;

private:
	weak_ptr<vector<string>> wptr;
	size_t curr;  // 保存当前对象所表示的元素的下标
};

bool operator==(const StrBlobPtr&, const StrBlobPtr&);
bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
bool operator<(const StrBlobPtr&, const StrBlobPtr&);
bool operator>(const StrBlobPtr&, const StrBlobPtr&);
bool operator<=(const StrBlobPtr&, const StrBlobPtr&);
bool operator>=(const StrBlobPtr&, const StrBlobPtr&);


class StrBlobPtrPtr {
public:
	StrBlobPtrPtr() = default;
	StrBlobPtrPtr(StrBlobPtr* p) : pointer(p) {}

	StrBlobPtr& operator*() const;
	StrBlobPtr* operator->() const;

private:
	StrBlobPtr* pointer{ nullptr };
};


class ConstStrBlobPtr
{
	friend bool operator==(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
	friend bool operator!=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
	friend bool operator<(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
	friend bool operator>(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
	friend bool operator<=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
	friend bool operator>=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);

public:
	ConstStrBlobPtr() : curr(0) { }
	ConstStrBlobPtr(const StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) { }

	string& deref() const;  // 解引用
	ConstStrBlobPtr& incr();  // 前缀递增 ConstStrBlobPtr（通过递增 curr 实现）

	const string& operator[](size_t n) const;
	ConstStrBlobPtr& operator++();
	ConstStrBlobPtr& operator--();
	ConstStrBlobPtr operator++(int);
	ConstStrBlobPtr operator--(int);
	ConstStrBlobPtr& operator+=(size_t);
	ConstStrBlobPtr& operator-=(size_t);
	ConstStrBlobPtr operator+(size_t);
	ConstStrBlobPtr operator-(size_t);
	const std::string& operator*() const;
	const std::string* operator->() const;

private:
	shared_ptr<vector<string>> check(size_t i, const string& msg) const;

private:
	weak_ptr<vector<string>> wptr;
	size_t curr;  // 保存当前对象所表示的元素的下标
};

bool operator==(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator!=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator<(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator>(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator<=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);
bool operator>=(const ConstStrBlobPtr&, const ConstStrBlobPtr&);


void test_str_blob();
