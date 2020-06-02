// Ввод содержимого контейнера из указанного потока
#include "inall.h"
void In(List &c, std::ifstream &ifst) {

	//std::ifstream &a = ifst;
	//bool isRead = a.is_open();

	//if (isRead)
	//{
	//	a.seekg(0, std::ios_base::end);
	//	isRead = (a.tellg() > 0);
	//}
	//if (!isRead)
	//{
	//	std::cerr << "Задан пустой файл!";
	//	exit(1);
	//}
	//a.close();

	while (!ifst.eof()) {
		Transport* x = Ina(ifst);
		c.data++;
		Node* a = new Node;
		if (c.head == NULL)
		{
			c.head = a;
		}
		else
		{
			Node * e = c.endList;
			e->next = a;
		}
		a->next = NULL;
		c.endList = a;
		a->data = x;
	}
}