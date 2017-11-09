/*

练习 13.18: 定义一个 Empolyee 类，包含雇员的姓名和唯一的雇员证号。
为这个类定义默认构造函数，以及接受一个表示雇员姓名的 string 的构造
函数。每个构造函数应该通过递增一个 static 数据成员来生成一个唯一的证号。

*/

#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    string name;
    int id;
public:
    static int id_maker;

public:
    Employee() : name(), id(id_maker++) { }
    Employee(string name_) :name(name_), id(id_maker++) { }

    Employee(const Employee&) = delete;

    void PrintEmpolyee()
    {
        cout << id << " "<< name << endl;
    }
};

int Employee::id_maker = 10;

int main()
{
    Employee A(string("Alex"));
    Employee B(string("Roger"));

    A.PrintEmpolyee();
    B.PrintEmpolyee();

    return 0;
}

/*

10 Alex
11 Roger
Press any key to continue . . .

*/
