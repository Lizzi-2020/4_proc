#include "outtruck.h"
void OutTruck(List &c, ofstream &ofst) {
	ofst << "Only Truck." << endl;
	Node* nod = c.head;
	int count = c.data;
	key k;
	while (0 < count)
	{
		if (nod->data->k == key::TRUCK)
		{
			OutTransport(nod->data, ofst);
		}
		nod = nod->next;
		count--;
	}
}