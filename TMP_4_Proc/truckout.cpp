// ����� ���������� ������������ � �����
#include"truckout.h"
void Out(Truck &t, std::ofstream &ofst) {
	ofst << "It is TRUCK: Power = "
		<< t.power;
}