#ifndef EX12_27_H
#define EX12_27_H

#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>
#include <fstream>
#include <memory>
#include <string>

using namespace std;

class QueryResult;
class TextQuery
{
public:
	using line_no = vector<string>::size_type;
	TextQuery(ifstream &is);
	QueryResult query(const string&) const;
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;
};

class QueryResult
{
	friend ostream &printResult(ostream &, const QueryResult &);

public:
	QueryResult(string sought_,
		shared_ptr<set<TextQuery::line_no>> lines_,
		shared_ptr<vector<string>> file_) :
		sought(sought_), lines(lines_), file(file_)
	{
	}

private:
	string sought;
	shared_ptr<set<TextQuery::line_no>> lines;
	shared_ptr<vector<string>> file;
};

ostream &printResult(ostream &, const QueryResult &);

#endif // !EX12_27_H
