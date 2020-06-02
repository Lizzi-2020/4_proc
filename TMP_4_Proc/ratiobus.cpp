#include "ratiobus.h"
double Ratio(Bus &b, Transport *data)
{
	return (b.size * 75) / data->powerEngine;
}