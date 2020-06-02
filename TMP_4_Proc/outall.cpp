// ¬ывод содержимого контейнера в указанный поток
#include "outall.h"
void Out(List &c, std::ofstream &ofst) {
	ofst << "Container contains " << c.data
		<< " elements." << std::endl;
	Node* nod = c.head;
	key k;
	//Transport* b = new Transport;

	while (0 < c.data)
	{
		OutTransport(nod->data, ofst);
		nod = nod->next;
		c.data--;
	}
}