#include"compare.h"
// C�������� ������ ���� ����������� ��������
bool Compare(Transport *first, Transport *second)
{
	return Ratio(first) < Ratio(second);
}