#include "ratiotruck.h"
double Ratio(Truck &t, Transport *data)
{
	return t.power / data->powerEngine;
}