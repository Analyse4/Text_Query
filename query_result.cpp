#include"query_result.h"



QueryResult::QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f):
	sought(s), lines(p), file(f){}
