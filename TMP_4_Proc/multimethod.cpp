#include "multimethod.h"
void MultiMethod(List &c, std::ofstream &ofst) {
	ofst << "Multimethod." << std::endl;
	Node* iteam = c.head;
	key k = iteam->data->k;
	Node* iteam2 = c.head;
	key k2 = iteam->data->k;
		for (int i = 0; i < c.data - 1; i++) {
			for (int j = i + 1; j < c.data; j++) {
				iteam2 = iteam2->next;
				k2 = iteam2->data->k;
				switch (k) {
				case key::BUS:
					switch (k2) {
					case key::BUS:
						ofst << "BUS and BUS." << std::endl;
						break;
					case key::TRUCK:
						ofst << "BUS and TRUCK." << std::endl;
						break;
					case key::CAR:
						ofst << "CAR and BUS." << std::endl;
						break;
					default:
						ofst << "Unknown type" << std::endl;
					}
					break;
				case key::TRUCK:
					switch (k2) {
					case key::TRUCK:
						ofst << "TRUCK and TRUCK." << std::endl;
						break;
					case key::BUS:
						ofst << "TRUCK and BUS." << std::endl;
						break;
					case key::CAR:
						ofst << "TRUCK and CAR." << std::endl;
						break;
					default:
						ofst << "Unknown type" << std::endl;
					}
					break;
				case key::CAR:
					switch (k2) {
					case key::BUS:
						ofst << "CAR and BUS." << std::endl;
						break;
					case key::TRUCK:
						ofst << "CAR and TRUCK." << std::endl;
						break;
					case key::CAR:
						ofst << "CAR and CAR." << std::endl;
						break;
					default:
						ofst << "Unknown type" << std::endl;
					}
					break;
				default:
					ofst << "Unknown type" << std::endl;
				}
				OutTransport(iteam->data, ofst);
				OutTransport(iteam2->data, ofst);
				
				//Out(*(c.cont[i]), ofst);
				//Out(*(c.cont[j]), ofst);
			}
			iteam = iteam->next;
			k = iteam->data->k;
			//
			iteam2 = iteam;
			k2 = k;
		}
}