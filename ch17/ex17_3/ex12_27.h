#ifndef EX12_27_H
#define EX12_27_H

#include <map>
#include <set>
#include <string>
#include <sstream>
#include <fstream>
#include <memory>
#include <string>

#include "StrVec.h"

using namespace std;

//class QueryResult;
class TextQuery
{
public:
	typedef tuple<string, shared_ptr<set<size_t>>, shared_ptr<StrVec>> QueryResultTuple;
	TextQuery(ifstream &is);
	//QueryResult query(const string&) const;
	QueryResultTuple query_v2(const string&) const;
private:
	shared_ptr<StrVec> file;
	map<string, shared_ptr<set<size_t>>> wm;
};

string make_plural(size_t ctr, const string &word, const string &ending);
ostream& printQueryResultTuple(ostream &, const TextQuery::QueryResultTuple &);

//class QueryResult
//{
//	friend ostream &printResult(ostream &, const QueryResult &);
//
//public:
//	QueryResult(string sought_,
//		shared_ptr<set<size_t>> lines_,
//		shared_ptr<StrVec> file_) :
//		sought(sought_), lines(lines_), file(file_)
//	{
//	}
//
//private:
//	string sought;
//	shared_ptr<set<size_t>> lines;
//	shared_ptr<StrVec> file;
//};
//
//ostream &printResult(ostream &, const QueryResult &);

#endif // !EX12_27_H
