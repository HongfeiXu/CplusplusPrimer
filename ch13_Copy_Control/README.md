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

int main()
{
    HasPtr hp1("Hello");

    hp1 = hp1;

    return 0;
}
```

