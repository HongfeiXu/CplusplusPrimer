#pragma once

#include <string>
#include <iostream>

using namespace std;

class HasPtr {
private:
    string* ps;
    int i;
    size_t* use;        // 用来记录有多少个对象共享 *ps 成员
public:
    // 构造函数分配新的 string 和新的计数器，将计数器置为 1
    HasPtr(const string& s = string()) : ps(new string(s)), i(0), use(new size_t(1)) { }
    // 拷贝构造函数拷贝所有三个数据成员，并递增计数器
    HasPtr(const HasPtr& rhs) : ps(rhs.ps), i(rhs.i), use(rhs.use) { ++*use; }
    HasPtr& operator= (const HasPtr& rhs);
    ~HasPtr();
};

HasPtr& HasPtr::operator= (const HasPtr& rhs)
{
    ++*rhs.use;         // 递增右侧运算对象的引用计数，这样可以避免自赋值引发错误
    if (--*use == 0)    // 然后递减本对象的引用计数
    {
        delete ps;      // 如果没有其他用户
        delete use;     // 释放本对象分配的成员
    }

    use = rhs.use;      // 将数据从 rhs 拷贝到本对象
    ps = rhs.ps;
    i = rhs.i;

    return *this;
}

HasPtr::~HasPtr()
{
    if (--*use == 0)    // 如果引用计数变为 0
    {
        delete ps;      // 释放 string 内存
        delete use;     // 释放计数器内存
    }
}
