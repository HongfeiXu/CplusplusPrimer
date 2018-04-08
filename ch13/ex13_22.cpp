/*
练习 13.22: 假定我们希望 HasPtr 的行为像一个值。即，对于对象所指向的
string 成员，每个对象都有一份自己的拷贝。
*/

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class HasPtr {
private:
    int i = 0;
    shared_ptr<string> ps;

public:
    HasPtr() : i(0), ps(new string("")) { }
    HasPtr(int i_, const string& s) : i(i_), ps(new string(s)) { }
    HasPtr(const HasPtr& rhs) : i(rhs.i), ps(make_shared<string>(*rhs.ps)) { }
    HasPtr &operator= (const HasPtr& rhs)
    {
        i = rhs.i;
        ps = make_shared<string>(*rhs.ps);
        return *this;
    }

    long count()
    {
        return ps.use_count();
    }

    void Print()
    {
        cout << i << " \"" << *ps <<  "\"" << endl;
    }

    void SetI(int i_)
    {
        i = i_;
    }
};

int main()
{
    HasPtr hp1(2, string("Alex"));
    hp1.Print();

    HasPtr hp2(hp1);
    hp2.Print();
    
    hp1.SetI(10);
    hp1.Print();
    hp2.Print();
    cout << hp1.count() << endl;
    cout << hp2.count() << endl;

    
    return 0;
}

/*

2 "Alex"
2 "Alex"
10 "Alex"
2 "Alex"
1
1
Press any key to continue . . .

*/
