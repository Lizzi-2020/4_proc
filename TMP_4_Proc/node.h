#pragma once
#include "transport.h"
struct Node
{
	Transport* data;
	Node *next; //указатель на следующий элемент
};