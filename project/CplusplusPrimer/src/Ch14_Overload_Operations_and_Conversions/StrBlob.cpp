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

void StrBlob::check(size_type i, const string& msg) const // ��� data[i]���Ϸ������׳�һ���쳣
{
	if (i >= data->size())
		throw out_of_range(msg);
}

//==================================================================
//
//		StrBlobPtr members
//
//==================================================================

string& StrBlobPtr::deref() const // ������
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];  // (*p)�Ƕ�����ָ��� vector
}

StrBlobPtr& StrBlobPtr::incr() // ǰ׺���� StrBlobPtr��ͨ������ curr ʵ�֣�
{
	// ��� curr �Ѿ�ָ��������β��λ�ã��Ͳ����ٵ�����
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr& StrBlobPtr::operator++()
{
	// ��� curr �Ѿ�ָ��������β��λ�ã��Ͳ����ٵ�����
	check(curr, "increment past end of StrBlobPtr");
	++curr;		// ��curr�ڵ�ǰ״̬����ǰ�ƶ�һ��Ԫ��
	return *this;
}

StrBlobPtr& StrBlobPtr::operator--()
{
	// ���curr��0���ݼ���������һ����Ч�±�
	--curr;		// ��curr�ڵ�ǰ״̬������ƶ�һ��Ԫ��
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
	// ���������ֵ�����Ƿ���ԭֵ

	StrBlobPtr ret = *this;	// ��¼��ǰ��ֵ
	++* this;				// ��ǰ�ƶ�һ��Ԫ�أ�ǰ��++��Ҫ����������Ч��
	return ret;				// ����֮ǰ��¼��ֵ
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
	return (*p)[curr];	// (*p)�Ƕ�����ָ��vector
}

std::string* StrBlobPtr::operator->() const
{
	// ��ʵ�ʹ���ί�и������������
	return &this->operator*();
}

std::shared_ptr<std::vector<string>> StrBlobPtr::check(size_t i, const string& msg) const
{
	auto ret = wptr.lock();  // vector ��������
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

string& ConstStrBlobPtr::deref() const // ������
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];  // (*p)�Ƕ�����ָ��� vector
}

ConstStrBlobPtr& ConstStrBlobPtr::incr() // ǰ׺���� ConstStrBlobPtr��ͨ������ curr ʵ�֣�
{
	// ��� curr �Ѿ�ָ��������β��λ�ã��Ͳ����ٵ�����
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
	auto ret = wptr.lock();  // vector ��������
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

E:\BooksLearn\CPP\CplusplusPrimer\project\CplusplusPrimer\Debug\CplusplusPrimer.exe (���� 80792)���˳�������Ϊ 0��
��������رմ˴���. . .
*/


