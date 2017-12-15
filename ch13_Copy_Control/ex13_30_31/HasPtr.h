#pragma once
#include <iostream>
#include <string>

using namespace std;

class HasPtr {
    friend void swap(HasPtr& lhs, HasPtr& rhs);
private:
    string *ps;
    int i;
public:
    HasPtr(const string& s = string()) :
        ps(new string(s)), i(0)
    {
    }
    HasPtr(const string& s, int i_) :
        ps(new string(s)), i(i_)
    {
    }
    HasPtr(const HasPtr& rhs) :
        ps(new string(*rhs.ps)), i(rhs.i)
    {
        cout << "HasPtr::CopyConstructor" << endl;
    }
    HasPtr& operator= (HasPtr rhs);
    ~HasPtr() { delete ps; }

    void Print()
    {
        cout << i << " " << *ps << endl;
    }

    bool operator< (const HasPtr& rhs)
    {
        return i < rhs.i;
    }
};

void swap(HasPtr& lhs, HasPtr& rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    cout << "HasPtr::swap()" << endl;
}

// 编写赋值运算符的好的模式
//HasPtr& HasPtr::operator= (const HasPtr& rhs)
//{
//    auto new_ps = new string(*rhs.ps);  // 拷贝底层 string
//    delete ps;      // 释放旧内存
//    ps = new_ps;    // 从右侧运算对象拷贝数据到本对象
//    i = rhs.i;
//    return *this;   // 返回本对象
//}

// 在赋值运算符中使用 swap
HasPtr& HasPtr::operator= (HasPtr rhs)
{
    swap(*this, rhs);
    return *this;
}

