#include "ina.h"
#include "busin.h"
#include "truckin.h"
#include "carin.h"
#include "checkcommon.h"
Transport* Ina(std::ifstream &ifst) {
	Transport *sp;
	int k;
	try
	{
		ifst >> k;
		if (k > 3 || k <= 0)
			throw 1;
	}
	catch (int a)
	{
		std::cerr << "Ќеверный формат типа транспортного средства!\n";
		exit(1);
	}

	switch (k) {
	case 1:
		sp = new Transport;
		sp->k = key::BUS;
		In(sp->b, ifst);
		CheckCommon(sp, ifst);
		//ifst >> sp->powerEngine;
		//ifst >> sp->fuelConsumption;
		return sp;
	case 2:
		sp = new Transport;
		sp->k = key::TRUCK;
		In(sp->t, ifst);
		CheckCommon(sp, ifst);
		//ifst >> sp->powerEngine;
		//ifst >> sp->fuelConsumption;
		return sp;
	case 3:
		sp = new Transport;
		sp->k = key::CAR;
		In(sp->c, ifst);
		CheckCommon(sp, ifst);
		//ifst >> sp->powerEngine;
		//ifst >> sp->fuelConsumption;
		return sp;
	default:
		return 0;
	}

}