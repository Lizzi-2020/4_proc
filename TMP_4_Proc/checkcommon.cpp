#include "checkcommon.h";
void* CheckCommon(Transport *sp, std::ifstream &ifst) 
{
	try
	{
		ifst >> sp->powerEngine;
		if (sp->powerEngine <= 0 || sp->powerEngine > 1000)
			throw 1;
	}
	catch (int a)
	{
		std::cerr << "Мощность двигателя ТС должна быть не меньше 0 и не больше 1000";
		exit(1);
	}

	try
	{
		ifst >> sp->fuelConsumption;
		if (sp->fuelConsumption <= 0 || sp->fuelConsumption > 1000)
			throw 1;
	}
	catch (int a)
	{
		std::cerr << "Расход топлива ТС должен быть не меньше 0 и не больше 1000";
		exit(1);
	}
}
