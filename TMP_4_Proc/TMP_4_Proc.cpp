#include <iostream>
#include <fstream>
#include "list.h"
#include "inall.h"
#include "outall.h"
#include "clear.h"
#include "multimethod.h"
using namespace std;
#include "outtruck.h"
#include "sortfun.h"
#include <iostream>

int main(int argc, char* argv[]) {	
	cout << argc << endl;
	setlocale(LC_CTYPE, "rus");
	if (argc != 3)
	{
		cout << "Wrong command line arguments\n";
		return 1;
	}
	ifstream ifst(argv[1]);
	if (!ifst.is_open())
	{
		std::cerr << "Не корректный входной файл!\n";
		exit(1);
	}

	ofstream ofst(argv[2]);
	if (!ofst.is_open())
	{
		std::cerr << "Не корректный выходной файл!\n";
		exit(1);
	}
	//ifstream ifst(argv[1]);
	//ofstream ofst(argv[2]);
	cout << "Start" << endl;
	List c;
	In(c, ifst);
	//OutTruck(c, ofst);
	MultiMethod(c, ofst);
	Sort(c);
	Out(c, ofst);
	Clear(c);
	return 0;
}