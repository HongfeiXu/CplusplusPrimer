/*

练习 17.11：定义一个数据结构，包含一个整型对象，记录一个包含10个问题的真/假测验的解答。
如果测验包含100道题，你需要对数据结构做出什么改变？如果需要的话。

练习 17.12：使用前一题的数据结构，编写一个函数，它接受一个问题编号和一个表示真/假解答的值，
函数根据这两个参数更新测验的解答。

练习 17.13：编写一个整型对象，包含真/假测验的正确答案。使用它来为前两题中的数据结构生成测验成绩。

*/

#include <bitset>
#include <string>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

template<size_t N>
class Quiz {
private:
	bitset<N> bitquiz;

public:
	// constructors
	Quiz() = default;
	Quiz(const string& s) : bitquiz(s) { }

	// updata bitquiz
	void update(const pair<int, bool>& answer)
	{
		bitquiz.set(answer.first, answer.second);
	}

	// generate grade
	template<size_t M>
	friend size_t grade(const Quiz<M>&, const Quiz<M>&);


	// print
	template<size_t M>
	friend ostream& operator<< (ostream&, const Quiz<M>&);
};

template<size_t M>
size_t grade(const Quiz<M>& correctAns, const Quiz<M>& studentAns)
{
	auto result = correctAns.bitquiz ^ studentAns.bitquiz;	// 异或，答案不同的位置1，答案相同的位置0
	result.flip();											// 非，将答案不同的位置0，答案相同的位置1
	return result.count();	// 统计置位1的位数，即为答案正确的个数
}

template<size_t M>
ostream& operator<< (ostream& os, const Quiz<M>& quiz)
{
	os << quiz.bitquiz;
	return os;
}


int main()
{
	Quiz<8> studentAns(string("11011100"));
	studentAns.update(make_pair(0, false));
	cout << "studentAns: " << studentAns << endl;

	Quiz<8> correctAns(string("10101010"));
	cout << "correctAns: " << correctAns << endl;
	cout << "grade: " << grade(correctAns, studentAns) << endl;


	return 0;
}

/*

studentAns: 11011100
correctAns: 10101010
grade: 3
请按任意键继续. . .

*/