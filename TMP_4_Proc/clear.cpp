#include "clear.h"
void Clear(List &c) {
	Node *clear = c.head;
	Node *time = new Node;

	//clear = c.head;
	while (true)
	{
		time = clear->next;
		delete clear;
		clear = time;
		if (clear == NULL)
		{
			//delete(c.endList);
			//delete(c.head);
			break;
		}
	}

}