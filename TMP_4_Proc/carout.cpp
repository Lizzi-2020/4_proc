
#include "carout.h"
void Out(Car &c, std::ofstream &ofst) {
	ofst << "It is CAR: Max Speed = " << c.maxSpeed;
}