#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TMP_4_Proc/bus.h"
#include "../TMP_4_Proc/busin.h"
#include "../TMP_4_Proc/truck.h"
#include "../TMP_4_Proc/truckin.h"
#include "../TMP_4_Proc/car.h"
#include "../TMP_4_Proc/carin.h"
#include "../TMP_4_Proc/transport.h"
#include "../TMP_4_Proc/ratiobus.h"
#include "../TMP_4_Proc/ratiotruck.h"
#include "../TMP_4_Proc/ratiocar.h"
#include "../TMP_4_Proc/ina.h"
#include "../TMP_4_Proc/compare.h"
#include "../TMP_4_Proc/busout.h"
#include "../TMP_4_Proc/truckout.h"
#include "../TMP_4_Proc/carout.h"
#include "../TMP_4_Proc/outtransport.h"

////
#include <iostream>
#include <fstream>
#include "../TMP_4_Proc/list.h"
#include "../TMP_4_Proc/inall.h"
#include "../TMP_4_Proc/outall.h"
#include "../TMP_4_Proc/clear.h"
using namespace std;
#include "../TMP_4_Proc/outtruck.h"
#include "../TMP_4_Proc/sortfun.h"
//#include "../TMP_4_Proc/ratiobus.h"
//#include "clear.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestTMP4
{
	TEST_CLASS(UnitTest1)
	{
	public:
		//var a = {"1", "2", "3"}




		TEST_METHOD(TestInBus)
		{
			ifstream in("testInBus.txt");
			Bus b1;
			In(b1, in);
			int actual = b1.size;
			int expected = 123;
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestInTruck)
		{
			ifstream in("testInTruck.txt");
			Truck t;
			In(t, in);
			int actual = t.power;
			int expected = 7;
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestInCar)
		{
			ifstream in("testInCar.txt");
			Car c;
			In(c, in);
			int actual = c.maxSpeed;
			int expected = 110;
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestInTransport)// Правильно или нет!?
		{
			ifstream in("testInTransport.txt");
			Transport* x = Ina(in);

			double actual1 = x->fuelConsumption;
			double expected1 = 1;
			Assert::AreEqual(expected1, actual1);

			int actual2 = x->powerEngine;
			int expected2 = 1;
			Assert::AreEqual(expected2, actual2);

		}

		TEST_METHOD(TestInList)// Должен сравнить ссылки, а сравниваю значения по ссылкам. (ссылки сравнить не возможно)
		{
			ifstream in("testInList.txt");
			List list;
			In(list, in);


			int actual = list.head->data->powerEngine;
			int expected = 1;
			Assert::AreEqual(expected, actual);
			int actual1 = list.endList->data->powerEngine;
			int expected1 = 3;
			Assert::AreEqual(expected1, actual1);
		}

		TEST_METHOD(TestBusRatio)
		{
			Transport* d = new Transport;
			d->powerEngine = 150;
			Bus *x = new Bus;
			x->size = 50;
			int actual = Ratio(*x, d);
			int expected = 25;
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestTruckRatio)
		{
			Transport* d = new Transport;
			d->powerEngine = 100;
			Truck *t = new Truck;
			t->power = 100;
			int actual = Ratio(*t, d);
			int expected = 1;
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestCarRatio)
		{
			Transport* d = new Transport;
			d->powerEngine = 10;
			Car *c = new Car;
			c->maxSpeed = 100;
			int actual = Ratio(*c, d);
			int expected = 10;
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestSortList)
		{

			ifstream in("TestSortList.txt");
			List test;
			In(test, in);

			ifstream ifst("In.txt");
			List c;
			In(c, ifst);
			Sort(c);
			Node *index1, *index2;
			if (test.data == c.data)
			{
				index1 = c.head;
				index2 = test.head;
				for (size_t i = 0; i < test.data; i++)
				{
					//Assert::AreEqual(index1->data->b, index2->data->b);
					Assert::AreEqual(index1->data->b.size, index2->data->b.size);
					Assert::AreEqual(index1->data->fuelConsumption, index2->data->fuelConsumption);
					Assert::AreEqual(index1->data->powerEngine, index2->data->powerEngine);
					index1 = index1->next;
					index2 = index2->next;
				}
			}
		}

		TEST_METHOD(TestOnlyTruckOut)
		{

			ifstream inn("TestInOnlyTruck.txt");
			List c;
			In(c, inn);
			inn.close();

			ofstream Out("TestOutOnlyTruck.txt");
			OutTruck(c, Out);
			Out.close();

			ifstream trueFile("TestOutOnlyTruckTrueFile.txt");
			string expected;
			char temp;
			trueFile.unsetf(ios::skipws);
			while (trueFile >> temp)
				expected += temp;

			ifstream testFile("TestOutOnlyTruck.txt");
			string actual;
			char temp1;
			testFile.unsetf(ios::skipws);
			while (testFile >> temp1)
				actual += temp1;

			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestCompare)
		{
			Transport *a = new Transport;
			a->powerEngine = 150;
			Bus *x = new Bus;
			x->size = 50;

			Transport *b = new Transport;
			b->powerEngine = 5;
			Car *y = new Car;
			y->maxSpeed = 50;

			bool actual = Compare(a, b);
			bool expected = false;
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestOutBus)//Правильно ли провожу тест? 
		{
			ofstream OutBus("TestOutBus.txt");
			Bus *b = new Bus;
			b->size = 111;
			Out(*b, OutBus);
			OutBus.close();
			ifstream in("TestOutBus.txt");

			string actual;
			while (!in.eof()) {
				in >> actual;
			}
			string expected = "111";
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestOutTruck)//Правильно ли провожу тест? 
		{
			ofstream OutTruck("TestOutTruck.txt");
			Truck *t = new Truck;
			t->power = 225;
			Out(*t, OutTruck);
			OutTruck.close();
			ifstream in("TestOutTruck.txt");

			string actual;
			while (!in.eof()) {
				in >> actual;
			}
			string expected = "225";
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestOutCar)//Правильно ли провожу тест? 
		{
			ofstream OutCar("TestOutCar.txt");
			Car *c = new Car;
			c->maxSpeed = 555;
			Out(*c, OutCar);
			OutCar.close();
			ifstream in("TestOutCar.txt");

			string actual;
			while (!in.eof()) {
				in >> actual;
			}
			string expected = "555";
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestOutTransport)//Правильно ли провожу тест? 
		{
			ofstream OutTr("TestOutTransport.txt");
			ifstream in("TestOutTransport.txt");
			Transport *a = new Transport;
			Bus x;
			x.size = 50;
			a->k = BUS;
			a->b = x;
			a->fuelConsumption = 100;
			a->powerEngine = 150;

			OutTransport(a, OutTr);
			OutTr.close();


			string actual;
			while (!in.eof()) {
				string q;
				in >> q;
				actual = actual + ' ' + q;// кривое считывание, получается два лишних пробела (в начале и в конце)
			}
			string expected = " It is BUS: Size = 50, PowerEngine = 150, Fuel Consumption = 100, Ratio = 25 ";// добавляю в конец и начало ожидаемой строки по пробелу, особенность считывания!
			Assert::AreEqual(expected, actual);
		}
		//in car
		//in Truck
		//in transport
		//in list
		//ratio car
		//ratio Truck
		//ratio transport
		//sort list
		//compare

		//out car
		//out Truck
		//out Bus
		//out transport
		//out list
	};
}