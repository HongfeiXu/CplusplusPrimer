/*
*	练习 9.52：使用 stack 处理括号化表达式。
*	感觉题目的要求应该是类似于表达式求值。这里并没有实现，只是实现了去括号的操作，而且还只能处理一对括号。待改进。
*/
#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main(void)
{
	string expression("Hello, (World)!");
	bool bracketSeen = false;
	stack<char> stk;
	
	for(const auto c : expression)
	{
		if(c == '(')
		{
			bracketSeen = true;
			continue;
		}
		else if(c == ')')
		{
			bracketSeen = false;
		}

		if(bracketSeen)
			stk.push(c);
	}

	string repstr;
	while(!stk.empty())
	{
		repstr += stk.top();
		stk.pop();
	}

	expression.replace(expression.find("("), repstr.size() + 2, repstr);

	cout << expression << endl;

	return 0;
}


/*

Hello, dlroW!
请按任意键继续. . .

*/