#pragma once
#include "node.h"
struct List //описание узла списка
{
	Node *head = NULL; //указатель на первый элемент списка
	Node *endList = NULL; //указатель 
	int data = 0; //информационное поле
};