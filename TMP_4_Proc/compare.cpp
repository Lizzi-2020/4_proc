#include"compare.h"
// Cравнение ключей двух программных объектов
bool Compare(Transport *first, Transport *second)
{
	return Ratio(first) < Ratio(second);
}