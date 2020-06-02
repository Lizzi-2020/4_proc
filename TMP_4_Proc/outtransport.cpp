
#include "outtransport.h"
#include "ratiofun.h"
void OutTransport(Transport* data, std::ofstream &ofst) {
	key k = data->k;
	switch (data->k)
	{
	case key::BUS:
		Out(data->b, ofst);
		ofst << ", PowerEngine = " << data->powerEngine << ", Fuel Consumption = " << data->fuelConsumption << ", Ratio = " << Ratio(data) << std::endl;
		break;
	case key::TRUCK:
		Out(data->t, ofst);
		ofst << ", PowerEngine = " << data->powerEngine << ", Fuel Consumption = " << data->fuelConsumption << ", Ratio = " << Ratio(data) << std::endl;
		break;
	case key::CAR:
		Out(data->c, ofst);
		ofst << ", PowerEngine = " << data->powerEngine << ", Fuel Consumption = " << data->fuelConsumption << ", Ratio = " << Ratio(data) << std::endl;
		break;
	default:
		ofst << "Incorrect figure!" << std::endl;
	}
}