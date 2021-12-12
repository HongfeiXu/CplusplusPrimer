#pragma once

#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <stdexcept>

#include "..\util.h"

using namespace std;

// 前置声明
template<typename> class BlobPtr;
template<typename> class Blob;
template<typename T>
bool operator==(const Blob<T>&, const Blob<T>&);


template<typename T> class Blob {

	// 友元声明
	friend class BlobPtr<T>;	// 用Blob的模板形参作为自己的模板形参，则友好关系被限定在用相同类型实例化的Blob与BlobPtr

	// 输出运算符友元声明与定义（如果定义在外面，则会出现“友元与模板类的对应关系为多对多”的情况，虽然也可以，但感觉不太好）
	friend ostream& operator<<(ostream& os, const Blob<T>& blob)
	{
		for (auto it = blob.data->cbegin(); it != blob.data->cend(); ++it)
		{
			os << *it << " ";
		}
		return os;
	}
	// 相等运算符支持这种写法，则可以定义在类外面
	friend bool operator==<T>(const Blob<T>&, const Blob<T>&);

public:
	typedef T value_type;
	typedef typename vector<T>::size_type size_type;
	
	Blob();
	Blob(initializer_list<T> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const T& t) { data->push_back(t); }
	// 移动版本
	void push_back(T&& t) { data->push_back(move(t)); }
	void pop_back();
	T& front();
	//const T& front() const;
	T& back();
	//const T& back() const;
	T& operator[](size_type i);

private:
	shared_ptr<vector<T>> data;
	void check(size_type i, const string &msg) const;
};

template<typename T>
Blob<T>::Blob() : data(make_shared<vector<T>>()) { }

template<typename T>
Blob<T>::Blob(initializer_list<T> il) : data(make_shared<vector<T>>(il)) { }

template<typename T>
void Blob<T>::pop_back()
{
	check(0, "pop_back on empty Blob");
	data->pop_back();
}

template<typename T>
T& Blob<T>::back()
{
	check(0, "back on empty Blob");
	return data->back();
}

template<typename T>
T& Blob<T>::operator[](size_type i)
{
	check(i, "subscript out of range");
	return (*data)[i];
}

template<typename T>
void Blob<T>::check(size_type i, const string& msg) const
{
	if (i >= data->size())
		throw out_of_range(msg);
}

template<typename T>
bool operator==<T>(const Blob<T>& lhs, const Blob<T>& rhs)
{
	return lhs.data == rhs.data;
}



// 若试图访问一个不存在的元素，BlobPtr抛出一个异常
template<typename T>
class BlobPtr {
public:
	BlobPtr() : curr(0) {}
	BlobPtr(Blob<T>& a, size_t sz = 0) :
		wptr(a.data), curr(sz) { }
	T& operator*() const
	{
		auto p = check(curr, "dereference past end");
		return (*p)[curr];
	}
	BlobPtr& operator++();	// 前置运算符
	BlobPtr& operator--();

	BlobPtr operator++(int);	// 后置运算符
	BlobPtr operator--(int);

	long count() { return wptr.use_count(); }

private:
	// 若检查成功，check返回一个指向vector的shared_ptr
	shared_ptr<vector<T>>
		check(size_t, const std::string&) const;
	// 保存一个weak_ptr，表示底层vector可能被销毁
	weak_ptr<vector<T>> wptr;
	// 数组中的当前位置
	std::size_t curr;
};

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
	check(curr, "increment past end of BlobPtr");
	++curr;
	return *this;
}

template<typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
	check(0, "decrement past end of BlobPtr");
	--curr;
	return *this;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
	BlobPtr ret = *this;	// 进入类的作用于，无需填写模板实参
	++* this;
	return ret;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
	BlobPtr ret = *this;	// 进入类的作用于，无需填写模板实参
	--* this;
	return ret;
}

template<typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_t i, const string& msg) const
{
	auto ret = wptr.lock();
	if (!ret)
		throw runtime_error("unbound BlobPtr");
	if (i >= ret->size())
		throw out_of_range(msg);
	return ret;
}


typedef Blob<string> StrBlob;


void test()
{
	Blob<int> ia{1,2,4};
	Blob<int> ia2 = { 0,1,2,3,4 };
	cout << "ia = " << ia << endl;
	cout << "ia2 = " << ia2 << endl;
	cout << "ia == ia2 is " << boolalpha << (ia == ia2) << endl;

	Blob<string> names = { "paul", "mike", "zhu", "bobo" };
	cout << names << endl;

	BlobPtr<string> bp(names);
	cout << *bp << endl;
	cout << bp.count() << endl;

	StrBlob flowers = { "rose", "sfasdf" };
}


