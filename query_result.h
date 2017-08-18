#ifndef _QUERY_RESULT_H_
#define _QUERY_RESULT_H_
#include<iostream>
#include<string>
#include<memory>
#include<vector>
#include<set>
#include"printt.h"

using namespace std;

class QueryResult
{
	friend ostream& print(ostream&, const QueryResult&);
	public:
		using line_no = vector<string>::size_type;
		QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f);
	private:
		string sought;
		shared_ptr<set<line_no>> lines;
		shared_ptr<vector<string>> file;
};
#endif
