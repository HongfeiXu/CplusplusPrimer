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

// ��д��ֵ������ĺõ�ģʽ
//HasPtr& HasPtr::operator= (const HasPtr& rhs)
//{
//    auto new_ps = new string(*rhs.ps);  // �����ײ� string
//    delete ps;      // �ͷž��ڴ�
//    ps = new_ps;    // ���Ҳ�������󿽱����ݵ�������
//    i = rhs.i;
//    return *this;   // ���ر�����
//}

// �ڸ�ֵ�������ʹ�� swap
HasPtr& HasPtr::operator= (HasPtr rhs)
{
    swap(*this, rhs);
    return *this;
}

