#pragma once
#include <iostream>
#include <string>

using namespace std;

#define COPYSWAP 0

class HasPtr {
    friend void swap(HasPtr& lhs, HasPtr& rhs);
private:
    string *ps;
    int i;
public:
	// default constructor 
    HasPtr(const string& s = string()) :
        ps(new string(s)), i(0)
    {
		//cout << "HasPtr::DefaultConstructor" << endl;
    }
	
	// constructor
    HasPtr(const string& s, int i_) :
        ps(new string(s)), i(i_)
    {
		//cout << "HasPtr::Constructor" << endl;
    }

	// copy constructor
    HasPtr(const HasPtr& rhs) :
        ps(new string(*rhs.ps)), i(rhs.i)
    {
        //cout << "HasPtr::CopyConstructor" << endl;
    }

	// move constructor
	HasPtr(HasPtr&& rhs) noexcept :
		ps(rhs.ps), i(rhs.i)
	{
		//cout << "HasPtr::MoveConstructor" << endl;
		rhs.ps = nullptr;	// �� rhs ���ڿ�����״̬
	}

#if COPYSWAP
	// copy-swap assignment operator
	HasPtr& operator= (HasPtr rhs);
#endif
	
#if !COPYSWAP
	// copy assignment operator
	HasPtr& operator= (const HasPtr& rhs);
#endif

#if !COPYSWAP
	// move assignment operator
	HasPtr& operator= (HasPtr&& rhs) noexcept;
#endif

	// destructor
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
    //cout << "HasPtr::swap()" << endl;
}

#if COPYSWAP
// copy-and-swap assignment operator
HasPtr& HasPtr::operator= (HasPtr rhs)
{
	//cout << "Hasptr::Copy-and-swapAssignmentOperator" << endl;
    swap(*this, rhs);
    return *this;
}
#endif

#if !COPYSWAP
HasPtr& HasPtr::operator= (const HasPtr& rhs)
{
	//cout << "CopyAssignmentOperator" << endl;
	auto new_ps = new string(*rhs.ps);  // �����ײ� string
    delete ps;      // �ͷž��ڴ�
    ps = new_ps;    // ���Ҳ�������󿽱����ݵ�������
    i = rhs.i;
    return *this;   // ���ر�����
}

HasPtr& HasPtr::operator= (HasPtr&& rhs) noexcept
{
	//cout << "MoveAssignmentOperator" << endl;
	// ֱ�Ӽ�����Ҹ�ֵ
	if (this != &rhs)
	{
		delete ps;	// �ͷ�ռ�õ��ڴ�
		ps = rhs.ps;	// �� rhs �ӹ���Դ
		i = rhs.i;
		rhs.ps = nullptr;
	}
	return *this;
}
#endif
