# 第 13 章 拷贝控制

## 13.1 拷贝、赋值与销毁

### 13.1.6 阻止拷贝

```c++
struct NoCopy {
	NoCopy() = default;     // 使用合成的构造函数
	NoCopy(const NoCopy&) = delete;	            // 阻止拷贝
	NoCopy &operator= (const NoCopy&) = delete; // 阻止赋值
	~NoCopy() = default;    // 使用合成的析构函数
};
```

## 13.2 拷贝控制和资源管理

### 13.2.1 行为像值的类

> 为了提供类值的行为，对于类管理资源，每个对象都应该拥有一份自己的拷贝。

```c++
#pragma once
#include <iostream>
#include <string>

using namespace std;

class HasPtr {
private:
    string *ps;
    int i;
public:
    HasPtr(const string& s = string()) :
        ps(new string(s)), i(0) { }
    HasPtr(const HasPtr& rhs) : 
        ps(new string(*rhs.ps)), i(rhs.i) { }
    HasPtr& operator= (const HasPtr& rhs);
    ~HasPtr() { delete ps; }
};

// 编写赋值运算符的好的模式
HasPtr& HasPtr::operator= (const HasPtr& rhs)
{
    auto new_ps = new string(*rhs.ps);  // 拷贝底层 string
    delete ps;      // 释放旧内存
    ps = new_ps;    // 从右侧运算对象拷贝数据到本对象
    i = rhs.i;
    return *this;   // 返回本对象
}

// 这样的编写赋值运算符是错误的
//HasPtr& HasPtr::operator= (const HasPtr& rhs)
//{
//    delete ps;      // 释放对象指向的 string
//    // 如果 rhs 和 *this 是同一对象，我们就将从已释放的内存中拷贝数据，显然会出错
//    ps = new string(*rhs.ps);
//    i = rhs.i;
//    return *this;
//}
```

### 13.2.2 定义行为像指针的类

```c++
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
```



