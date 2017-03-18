/*
* 练习 8.10：编写程序，将来自一个文件中的行保存在一个 vector<string>中，
* 然后使用一个 istringstream 从 vector 读取数据元素，每次读取一个单词。
*/

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

int main()
{
	ifstream infile("testfile.txt");
	vector<string> lines;
	string line;
	string word;

	// 将来自一个文件中的行保存在一个 vector<string>中
	while(getline(infile, line))
	{
		lines.push_back(line);
	}
	for(auto item : lines)	// 使用一个 istringstream 从 vector 读取数据元素
	{
		istringstream is(item);	
		while(is >> word)	// 每次读取一个单词
			cout << word << endl;
	}


	return 0;
}

/*

From
fairest
creatures
we
desire
increase,
That
thereby
beauty's
rose
might
never
die,
But
as
the
riper
should
by
time
decease,
His
tender
heir
might
bear
his
memory:
But
thou
contracted
to
thine
own
bright
eyes,
Feed'st
thy
light's
flame
with
self-substantial
fuel,
Making
a
famine
where
abundance
lies,
Thy
self
thy
foe,
to
thy
sweet
self
too
cruel:
Thou
that
art
now
the
world's
fresh
ornament,
And
only
herald
to
the
gaudy
spring,
Within
thine
own
bud
buriest
thy
content,
And
tender
churl
mak'st
waste
in
niggarding:
Pity
the
world,
or
else
this
glutton
be,
To
eat
the
world's
due,
by
the
grave
and
thee.
请按任意键继续. . .

*/

/*
testfile.txt:

From fairest creatures we desire increase,
That thereby beauty's rose might never die,
But as the riper should by time decease,
His tender heir might bear his memory:
But thou contracted to thine own bright eyes,
Feed'st thy light's flame with self-substantial fuel,
Making a famine where abundance lies,
Thy self thy foe, to thy sweet self too cruel:
Thou that art now the world's fresh ornament,
And only herald to the gaudy spring,
Within thine own bud buriest thy content,
And tender churl mak'st waste in niggarding:
Pity the world, or else this glutton be,
To eat the world's due, by the grave and thee.

*/