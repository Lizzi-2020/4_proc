#include"truckin.h"
void In(Truck &t, ifstream &ifst)
{
	try
	{
		ifst >> t.power;
		if (t.power <= 0 || t.power > 1000)
			throw 1;
	}
	catch (int a)
	{
		std::cerr << "�������� ��, �� ����� ���� ������ 1, ���, ������ 1000!\n";
		exit(1);
	}

}