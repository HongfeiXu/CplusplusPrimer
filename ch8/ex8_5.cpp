/*
* 练习 8.4：编写函数，以读模式打开一个文件，将其内容读入到一个string的vector中，将每一行作为一个独立的元素存于vector中。
* 练习 8.5：重写上面的程序，将每个单词作为一个独立的元素进行存储。
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


int main(int argc, char *argv[])
{
	ifstream ifile(argv[1]);
	vector<string> vec;
	string current;		// 当前读入行

	while(ifile >> current)	// 每次读取一个单词
	{
		vec.push_back(current);
	}

	for(auto item : vec)
	{
		cout << item << endl;
	}
	
	return 0;
}

/*

I:\vs\cplusplus\cplusplus>cl /EHsc -W4 main.cpp
Microsoft (R) C/C++ Optimizing Compiler Version 19.00.24210 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

main.cpp
main.cpp(13): warning C4100: 'argc': unreferenced formal parameter
Microsoft (R) Incremental Linker Version 14.00.24210.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:main.exe
main.obj

I:\vs\cplusplus\cplusplus>main testfile.txt
1
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
一
对天生的尤物我们要求蕃盛，
以便美的玫瑰永远不会枯死，
但开透的花朵既要及时凋零，
就应把记忆交给娇嫩的后嗣；
但你，只和你自己的明眸定情，
把自己当燃料喂养眼中的火焰，
和自己作对，待自己未免太狠，
把一片丰沃的土地变成荒田。
你现在是大地的清新的点缀，
又是锦绣阳春的唯一的前锋，
为什么把富源葬送在嫩蕊里，
温柔的鄙夫，要吝啬，反而浪用？
可怜这个世界吧，要不然，贪夫，
就吞噬世界的份，由你和坟墓。

I:\vs\cplusplus\cplusplus>

*/