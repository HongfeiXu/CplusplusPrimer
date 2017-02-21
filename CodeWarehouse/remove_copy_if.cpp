#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	vector<string> words;
	ifstream inputFile("input.txt");
	string temp, word;
	
	while(inputFile >> temp)
	{
		remove_copy_if(temp.begin(), temp.end(), back_inserter(word), ispunct);
		words.push_back(word);
		word.clear();
	}

	for(auto it = words.begin(); it != words.end(); ++it)
		cout << *it << endl;

	return 0;
}

/*

input.txt:

Hello World!
What a nice day!
I love it.


Hello
World
What
a
nice
day
I
love
it
Press any key to continue . . .

*/