#include"busin.h"
#include <iostream>
void In(Bus &b, ifstream & ifst)
{
	try
	{
		ifst >> b.size;
		if (b.size <= 0 || b.size > 200)
			throw 1;
	}
	catch (int a)
	{
		std::cerr << "Вместимость транспортного средства, (Автобус) не может быть меньше 1, или, больше 200!\n";
		exit(1);
	}
	
}