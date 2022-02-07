#include "StrBlob.h"
#include <iostream>
#include <algorithm>


//==================================================================
//
//		StrBlob members
//
//==================================================================

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	return data->pop_back();
}

string& StrBlob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
}

const string& StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

const string& StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

StrBlobPtr StrBlob::begin()
{
	return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end()
{
	return StrBlobPtr(*this, data->size());
}

ConstStrBlobPtr StrBlob::cbegin() const
{
	return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::cend() const
{
	return ConstStrBlobPtr(*this, data->size());
}

string& StrBlob::operator[](size_t n)
{
	check(n, "out of range");
	return data->at(n);
}

const string& StrBlob::operator[](size_t n) const
{
	check(n, "out of range");
	return data->at(n);
}

void StrBlob::check(size_type i, const string& msg) const // 如果 data[i]不合法，则抛出一个异常
{
	if (i >= data->size())
		throw out_of_range(msg);
}

//==================================================================
//
//		StrBlobPtr members
//
//==================================================================

string& StrBlobPtr::deref() const // 解引用
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];  // (*p)是对象所指向的 vector
}

StrBlobPtr& StrBlobPtr::incr() // 前缀递增 StrBlobPtr（通过递增 curr 实现）
{
	// 如果 curr 已经指向容器的尾后位置，就不能再递增它
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr& StrBlobPtr::operator++()
{
	// 如果 curr 已经指向容器的尾后位置，就不能再递增它
	check(curr, "increment past end of StrBlobPtr");
	++curr;		// 将curr在当前状态下向前移动一个元素
	return *this;
}

StrBlobPtr& StrBlobPtr::operator--()
{
	// 如果curr是0，递减它将产生一个无效下标
	--curr;		// 将curr在当前状态下向后移动一个元素
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}

StrBlobPtr& StrBlobPtr::operator+=(size_t n)
{
	curr += n;
	check(curr, "increment past end of StrBlobPtr");
	return *this;
}

StrBlobPtr& StrBlobPtr::operator-=(size_t n)
{
	curr -= n;
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}

StrBlobPtr StrBlobPtr::operator+(size_t n)
{
	StrBlobPtr ret = *this;
	ret += n;
	return ret;
}

StrBlobPtr StrBlobPtr::operator-(size_t n)
{
	StrBlobPtr ret = *this;
	ret -= n;
	return ret;
}


StrBlobPtr StrBlobPtr::operator++(int)
{
	// 递增对象的值，但是返回原值

	StrBlobPtr ret = *this;	// 记录当前的值
	++* this;				// 向前移动一个元素，前置++需要检查递增的有效性
	return ret;				// 返回之前记录的值
}

StrBlobPtr StrBlobPtr::operator--(int)
{
	StrBlobPtr ret = *this;
	--* this;
	return ret;
}

string& StrBlobPtr::operator[](size_t n)
{
	auto p = check(n, "dereference out of range");
	return (*p)[n];
}

const string& StrBlobPtr::operator[](size_t n) const
{
	auto p = check(n, "dereference out of range");
	return (*p)[n];
}

std::string& StrBlobPtr::operator*() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];	// (*p)是对象所指的vector
}

std::string* StrBlobPtr::operator->() const
{
	// 将实际工作委托给解引用运算符
	return &this->operator*();
}

std::shared_ptr<std::vector<string>> StrBlobPtr::check(size_t i, const string& msg) const
{
	auto ret = wptr.lock();  // vector 还存在吗？
	if (!ret)
		throw runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}

//==================================================================
//
//		StrBlobPtrPtr members
//
//==================================================================

StrBlobPtr& StrBlobPtrPtr::operator*() const
{
	return *pointer;
}

StrBlobPtr* StrBlobPtrPtr::operator->() const
{
	return pointer;
}

//==================================================================
//
//		ConstStrBlobPtr members
//
//==================================================================

string& ConstStrBlobPtr::deref() const // 解引用
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];  // (*p)是对象所指向的 vector
}

ConstStrBlobPtr& ConstStrBlobPtr::incr() // 前缀递增 ConstStrBlobPtr（通过递增 curr 实现）
{
	// 如果 curr 已经指向容器的尾后位置，就不能再递增它
	check(curr, "increment past end of ConstStrBlobPtr");
	++curr;
	return *this;
}

const string& ConstStrBlobPtr::operator[](size_t n) const
{
	auto p = check(n, "dereference out of range");
	return (*p)[n];
}

std::shared_ptr<std::vector<string>> ConstStrBlobPtr::check(size_t i, const string& msg) const
{
	auto ret = wptr.lock();  // vector 还存在吗？
	if (!ret)
		throw runtime_error("unbound ConstStrBlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}

ConstStrBlobPtr& ConstStrBlobPtr::operator++()
{
	check(curr, "increment past end of ConstStrBlobPtr");
	++curr;
	return *this;
}

ConstStrBlobPtr& ConstStrBlobPtr::operator--()
{
	--curr;
	check(curr, "decrement past begin of ConstStrBlobPtr");
	return *this;
}

ConstStrBlobPtr ConstStrBlobPtr::operator++(int)
{
	ConstStrBlobPtr ret = *this;
	++* this;
	return ret;
}

ConstStrBlobPtr ConstStrBlobPtr::operator--(int)
{
	ConstStrBlobPtr ret = *this;
	--* this;
	return ret;
}

ConstStrBlobPtr& ConstStrBlobPtr::operator+=(size_t n)
{
	curr += n;
	check(curr, "increment past end of ConstStrBlobPtr");
	return *this;
}

ConstStrBlobPtr& ConstStrBlobPtr::operator-=(size_t n)
{
	curr -= n;
	check(curr, "decrement past begin of ConStrBlobPtr");
	return *this;
}

ConstStrBlobPtr ConstStrBlobPtr::operator+(size_t n)
{
	ConstStrBlobPtr ret = *this;
	ret += n;
	return ret;
}

ConstStrBlobPtr ConstStrBlobPtr::operator-(size_t n)
{
	ConstStrBlobPtr ret = *this;
	ret -= n;
	return ret;
}

const std::string& ConstStrBlobPtr::operator*() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

const std::string* ConstStrBlobPtr::operator->() const
{
	return &this->operator*();
}


//==================================================================
//
//		operators
//
//==================================================================

bool operator==(const StrBlob& lhs, const StrBlob& rhs)
{
	return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob& lhs, const StrBlob& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrBlob& lhs, const StrBlob& rhs)
{
	return std::lexicographical_compare(lhs.data->begin(), lhs.data->end(), rhs.data->begin(), rhs.data->end());
}

bool operator>(const StrBlob& lhs, const StrBlob& rhs)
{
	return rhs < lhs;
}

bool operator>=(const StrBlob& lhs, const StrBlob& rhs)
{
	return !(lhs < rhs);
}

bool operator<=(const StrBlob& lhs, const StrBlob& rhs)
{
	return !(rhs < lhs);
}

bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return lhs.curr < rhs.curr;
}

bool operator>(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return rhs < lhs;
}

bool operator<=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return !(rhs < lhs);
}

bool operator>=(const StrBlobPtr& lhs, const StrBlobPtr& rhs)
{
	return !(lhs < rhs);
}

bool operator==(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
	return lhs.curr == rhs.curr;
}

bool operator!=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
	return !(lhs == rhs);
}

bool operator<(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
	return lhs.curr < rhs.curr;
}

bool operator>(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
	return rhs < lhs;
}

bool operator<=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
	return !(rhs < lhs);
}

bool operator>=(const ConstStrBlobPtr& lhs, const ConstStrBlobPtr& rhs)
{
	return !(lhs < rhs);
}

void test_str_blob()
{
	StrBlob sb1{ "a", "b", "c" };
	StrBlob sb2 = sb1;

	sb2[2] = "b";

	if (sb1 > sb2) {
		for (ConstStrBlobPtr iter = sb1.cbegin(); iter < sb1.cend(); iter.incr())
			std::cout << iter.deref() << " ";
		std::cout << std::endl;
	}

	StrBlobPtr iter(sb2);
	std::cout << iter.deref() << std::endl;
	std::cout << iter[2] << std::endl;
	auto iter2 = iter++;
	std::cout << iter.deref() << std::endl;
	std::cout << iter2.deref() << std::endl;

	StrBlob a1 = { "hi", "bye", "now" };
	StrBlobPtr p(a1);
	std::cout << "*p = " << *p << std::endl;
	*p = "okay";
	std::cout << "*p = " << *p << std::endl;
	std::cout << p->size() << std::endl;
	std::cout << (*p).size() << std::endl;

	StrBlobPtrPtr pp{ &p };
	std::cout << pp->deref() << std::endl;

}

/*
a
b
b
a
*p = hi
*p = okay
4
4
okay

E:\BooksLearn\CPP\CplusplusPrimer\project\CplusplusPrimer\Debug\CplusplusPrimer.exe (进程 80792)已退出，代码为 0。
按任意键关闭此窗口. . .
*/


