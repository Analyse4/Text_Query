#include"runQueries.h"
#include<string>
#include<iostream>
#include"text_query.h"
#include"printt.h"

void runQueries(ifstream &infile)
{
	TextQuery tq(infile);

	while(1)
	{
		cout << "enter word to look for, or q to quit: ";
		string s;

		if (!(cin >> s) || s == "q")
			break;

		print(cout, tq.query(s)) << endl;
		
	}

}

