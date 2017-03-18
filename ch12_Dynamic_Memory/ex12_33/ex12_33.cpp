#include <algorithm>
#include <iterator>
#include "ex12_33.h"

TextQuery::TextQuery(ifstream & is)
{

	string text;
	while(getline(is, text))
	{
		file.push_back(text);
		int n = file.size() - 1;  // ��ǰ�к�
		istringstream line(text);
		string word, text;
		while(line >> text)
		{
			// avoid read a word follow by punctuation(such as: world!)
			remove_copy_if(text.begin(), text.end(), back_inserter(word), ispunct);
			auto &lines = wm[word];  // lines ��һ�� shared_ptr
			if(!lines)  // �����ǵ�һ�������������ʱ����ָ��Ϊ��
				lines.reset(new set<StrBlob::size_type>);  // ����һ���µ� set
			lines->insert(n);
			word.clear();
		}
	}
}

QueryResult TextQuery::query(const string& sought) const
{
	// ���δ�ҵ� sought �����ǽ�����һ��ָ��� set ��ָ�루set Ϊ�գ�
	static shared_ptr<set<StrBlob::size_type>> nodata(new set<StrBlob::size_type>);
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
		ConstStrBlobPtr p(qr.file, num);
		os << "\t(line " << num + 1 << ") " << p.deref() << endl;
	}
	return os;
}

