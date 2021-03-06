#include<sstream>
#include"query_result.h"
#include"text_query.h"
using namespace std;



TextQuery::TextQuery(ifstream &is):file(new vector<string>)
{
	string text;
	while(getline(is, text))
	{
		file->push_back(text);
		int n = file->size() - 1;
		istringstream line(text);
		string word;

		while(line >> word)
		{
			auto& lines = wm[word];
			if (!lines)
			{
				lines.reset(new set<line_no>);
			}
			lines->insert(n);   //由于该set为有序为重复的，所以如果同一行有相同的词那么只取一次
		}
	}
}

QueryResult TextQuery::query(const string& sought) const
{
	static shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}
