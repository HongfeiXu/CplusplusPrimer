#pragma once

#include <string>
#include <iostream>

using namespace std;

class HasPtr {
private:
    string* ps;
    int i;
    size_t* use;        // ������¼�ж��ٸ������� *ps ��Ա
public:
    // ���캯�������µ� string ���µļ�����������������Ϊ 1
    HasPtr(const string& s = string()) : ps(new string(s)), i(0), use(new size_t(1)) { }
    // �������캯�����������������ݳ�Ա��������������
    HasPtr(const HasPtr& rhs) : ps(rhs.ps), i(rhs.i), use(rhs.use) { ++*use; }
    HasPtr& operator= (const HasPtr& rhs);
    ~HasPtr();
};

HasPtr& HasPtr::operator= (const HasPtr& rhs)
{
    ++*rhs.use;         // �����Ҳ������������ü������������Ա����Ը�ֵ��������
    if (--*use == 0)    // Ȼ��ݼ�����������ü���
    {
        delete ps;      // ���û�������û�
        delete use;     // �ͷű��������ĳ�Ա
    }

    use = rhs.use;      // �����ݴ� rhs ������������
    ps = rhs.ps;
    i = rhs.i;

    return *this;
}

HasPtr::~HasPtr()
{
    if (--*use == 0)    // ������ü�����Ϊ 0
    {
        delete ps;      // �ͷ� string �ڴ�
        delete use;     // �ͷż������ڴ�
    }
}
