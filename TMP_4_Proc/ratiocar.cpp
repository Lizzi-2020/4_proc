#include "ratiocar.h"
double Ratio(Car &c, Transport *data)
{
	return c.maxSpeed / data->powerEngine;
}