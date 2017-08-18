#include<iostream>
#include"runQueries.h"

using namespace std;

int main(int argc, char *argv[])
{
	ifstream file(argv[1]);

	if (!file.is_open())
	{
		cout << "Error open file." << endl;
		exit(1);
	}
	runQueries(file);
	return 0;
}
