#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Foo {
public:
	Foo(initializer_list<int> il) : data(il)
	{
	}
	
	Foo sorted() &&
	{
		cout << "&&" << std::endl;
		sort(data.begin(), data.end());
		return *this;
	}
	//// ԭ�� sorted() const &
	//Foo sorted() const &
	//{
	//	cout << "const &" << std::endl;
	//	Foo ret(*this);
	//	sort(ret.data.begin(), ret.data.end());
	//	return ret;
	//}
	 //���޵ݹ�� sorted const &
	Foo sorted() const &
	{
		cout << "const &" << std::endl;
		Foo ret(*this);
		return ret.sorted();
	}
	// ���� sorted() && �� sorted() const &&
	//Foo sorted() const &
	//{
	//	cout << "const &" << std::endl;
	//	return Foo(*this).sorted();
	//}

	void Print()
	{
		copy(data.begin(), data.end(), ostream_iterator<int>(cout, " "));
	}

private:
	vector<int> data;
};

int main()
{
	Foo f({ 12,1,3,9,6 });
	Foo sorted_f = f.sorted();
	sorted_f.Print();
	cout << endl;
	return 0;
}

/*

1>  Main.cpp
1>f:\code\vs2015 projects\learncpp\src\main.cpp(34): warning C4717: ��Foo::sorted��: ��ݹ����пؼ�·������������������ʱ��ջ���

*/