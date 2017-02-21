#ifndef EX12_32_H
#define EX12_32_H

#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <fstream>
#include <memory>
#include <string>

#include "ex12_22.h"

using namespace std;

class QueryResult;
class TextQuery
{
public:
	TextQuery(ifstream &is);
	QueryResult query(const string&) const;
private:
	StrBlob file;
	map<string, shared_ptr<set<StrBlob::size_type>>> wm;
};

class QueryResult
{
	using ResultIter = set<StrBlob::size_type>::iterator;
	friend ostream &printResult(ostream &, const QueryResult &);

public:
	QueryResult(const string sought_,
		shared_ptr<set<StrBlob::size_type>> lines_,
		const StrBlob &file_) :
		sought(sought_), lines(lines_), file(file_)
	{
	}

	ResultIter begin() const
	{
		return lines->begin();
	}
	ResultIter end() const
	{
		return lines->end();
	}
	shared_ptr<StrBlob> get_file() const
	{
		return make_shared<StrBlob>(file);
	}

private:
	string sought;
	shared_ptr<set<StrBlob::size_type>> lines;
	StrBlob file;
};

ostream &printResult(ostream &, const QueryResult &);

#endif // !EX12_32_H
