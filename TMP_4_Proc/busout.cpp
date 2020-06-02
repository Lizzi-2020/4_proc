// Вывод параметров прямоугольника в форматируемый поток
#include "busout.h"
void Out(Bus &r, std::ofstream &ofst) {
	ofst << "It is BUS: Size = " << r.size;
}