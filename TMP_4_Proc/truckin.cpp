#include"truckin.h"
void In(Truck &t, ifstream &ifst)
{
	try
	{
		ifst >> t.power;
		if (t.power <= 0 || t.power > 1000)
			throw 1;
	}
	catch (int a)
	{
		std::cerr << "Мощность ТС, не может быть меньше 1, или, больше 1000!\n";
		exit(1);
	}

}