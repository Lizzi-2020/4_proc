#include"carin.h"
#include <iostream>
void In(Car &c, ifstream & ifst)
{
	try
	{
		ifst >> c.maxSpeed;
		if (c.maxSpeed <= 0 || c.maxSpeed > 1000)
			throw 1;
	}
	catch (int a)
	{
		std::cerr << "Max �������� ��, �� ����� ���� ������ 1, ���, ������ 1000!\n";
		exit(1);
	}

}