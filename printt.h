#ifndef _PRINTT_H_
#define _PRINTT_H_
#include<iostream>
#include"query_result.h"

class QueryResult;
std::ostream& print(std::ostream& os, const QueryResult& qr);

#endif
