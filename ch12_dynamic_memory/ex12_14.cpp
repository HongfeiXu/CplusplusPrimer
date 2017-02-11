/*

练习 12.14：编写你自己版本的用 shared_ptr 管理的 connection 的函数。

*/

#include <memory>
#include <string>
#include <iostream>

using namespace std;

struct destination
{
	string ip;
	int port;
	destination(string ip_, int port_) : ip(ip_), port(port_) { }
};
struct connection
{
	string ip;
	int port;
	connection(string ip_, int port_) : ip(ip_), port(port_) { }
};

connection connect(destination *pDest)
{
	shared_ptr<connection> pConn(new connection(pDest->ip, pDest->port));		// new 分配的内存，不必另外的删除器。
	cout << "creating connection(" << pConn.use_count() << ")" << endl;
	return *pConn;
}

void disconnect(connection pConn)
{
	cout << "connect close(" << pConn.ip << ":" << pConn.port << ")" << endl;
}

void end_connection(connection *pConn) 
{ 
	disconnect(*pConn); 
}

void f(destination &d)
{
	connection conn = connect(&d);
	shared_ptr<connection> p(&conn, end_connection);	// 不是用 new 分配的内存，传递一个删除器。
														// 这样当f退出时（即使是由于异常而退出），
														//connection也会被正常关闭，因为p销毁时，c的引用计数变为0，
														// 从而会调用 end_connection 函数。在
	cout << "connection now(" << p.use_count() << ")" << endl;
}

int main()
{
	destination dest("202.118.176.67", 8080);
	f(dest);
}

/*

creating connection(1)
connection now(1)
connect close(202.118.176.67:8080)			// 退出程序之前，调用了 end_connection 函数来释放由智能指针管理的内存。
Press any key to continue . . .

*/