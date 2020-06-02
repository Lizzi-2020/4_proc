#pragma once
#include "bus.h"
#include "truck.h"
#include "car.h"
#include <fstream>
#include <iostream>
enum key { BUS, TRUCK, CAR};
struct Transport {
	key k; // ключ
	int powerEngine;
	double fuelConsumption;
	union { // используем прямое включение
		Bus b;
		Truck t;
		Car c;
	};
};