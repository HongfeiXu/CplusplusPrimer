#include "ex12_27.h"

TextQuery::TextQuery(ifstream & is) : file(new vector<string>)
{
	string text;
	while(getline(is, text))
	{
		file->push_back(text);
		int n = file->size() - 1;  // 当前行号
		istringstream line(text);
		string word;
		while(line >> word)
		{
			auto &lines = wm[word];  // lines 是一个 shared_ptr
			if(!lines)  // 当我们第一次遇到这个单词时，此指针为空
				lines.reset(new set<line_no>);  // 分配一个新的 set
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const string& sought) const
{
	// 如果未找到 sought ，我们将返回一个指向此 set 的指针（set 为空）
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if(loc == wm.end())
		return QueryResult(sought, nodata, file);  // 未找到
	else
		return QueryResult(sought, loc->second, file);
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}

ostream &printResult(ostream &os, const QueryResult &qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " "<< make_plural(qr.lines->size(), "time", "s") << endl;
	for(auto num : *qr.lines)
	{
		os << "\t(" << num + 1 << ") " << *(qr.file->begin() + num) << endl;
	}
	return os;
}

