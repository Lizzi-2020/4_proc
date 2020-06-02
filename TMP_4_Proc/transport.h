#pragma once
#include "bus.h"
#include "truck.h"
#include "car.h"
#include <fstream>
#include <iostream>
enum key { BUS, TRUCK, CAR};
struct Transport {
	key k; // ����
	int powerEngine;
	double fuelConsumption;
	union { // ���������� ������ ���������
		Bus b;
		Truck t;
		Car c;
	};
};