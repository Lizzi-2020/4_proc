#include "sortfun.h"
void Sort(List &c)
{
	Node* fir = c.head;
	Node* sec = c.head->next;
	Node* tmp = new Node;
	while (fir->next)
	{
		while (sec)
		{
			if (Compare(fir->data, sec->data))
			{
				/*Node* time2 = fir->next->next;
				Node* time = fir;*/
				tmp->data = fir->data;
				fir->data = sec->data;
				sec->data = tmp->data;

			}
			sec = sec->next;
		}
		fir = fir->next;
		sec = fir->next;
	}
}