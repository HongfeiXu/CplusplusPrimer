#include "ex12_27.h"

TextQuery::TextQuery(ifstream & is) : file(new vector<string>)
{
	string text;
	while(getline(is, text))
	{
		file->push_back(text);
		int n = file->size() - 1;  // ��ǰ�к�
		istringstream line(text);
		string word;
		while(line >> word)
		{
			auto &lines = wm[word];  // lines ��һ�� shared_ptr
			if(!lines)  // �����ǵ�һ�������������ʱ����ָ��Ϊ��
				lines.reset(new set<line_no>);  // ����һ���µ� set
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const string& sought) const
{
	// ���δ�ҵ� sought �����ǽ�����һ��ָ��� set ��ָ�루set Ϊ�գ�
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if(loc == wm.end())
		return QueryResult(sought, nodata, file);  // δ�ҵ�
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

