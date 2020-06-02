#include "ratiofun.h"
#include "ratiotruck.h"
#include "ratiobus.h"

double Ratio(Transport *s)
{
	switch (s->k) {
	case key::BUS:
		return Ratio(s->b, s);
	case key::TRUCK:
		return Ratio(s->t, s);
	case key::CAR:
		return Ratio(s->t, s);
	default:
		return -1;
	}
}