/*

练习 13.18: 定义一个 Empolyee 类，包含雇员的姓名和唯一的雇员证号。
为这个类定义默认构造函数，以及接受一个表示雇员姓名的 string 的构造
函数。每个构造函数应该通过递增一个 static 数据成员来生成一个唯一的证号。

练习 13.19: 你的 Empolyee 类需要定义它自己的拷贝控制成员吗？
答：不需要，因为拷贝一个员工不符合逻辑。所以这里把拷贝构造函数和拷贝赋值运算符均声明为 delete。

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
    Employee& operator= (const Employee&) = delete;

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
