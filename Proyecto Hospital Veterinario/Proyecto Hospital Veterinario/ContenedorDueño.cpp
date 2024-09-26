#include "ContenedorDueño.h"

ContenedorDueno::ContenedorDueno(int n) {
	vec = new Dueno * [n];
	can = 0;
	tam = n;

	for (int i = 0; i < tam; i++)
		vec[i] = NULL;
}

ContenedorDueno:: ~ContenedorDueno() {
	for (int i = 0; i < can; i++) {
		if (vec[i] != NULL)
			delete vec[i];
	}
	delete[] vec;
}

bool ContenedorDueno::yaExisteDueno(string cont) {
	for (int i = 0; i < can; i++) {
		if (vec[i]->getContacto() == cont)
			return true;
	}
	return false;
}

bool ContenedorDueno::ingresarDueno(Dueno& due) {
	if (yaExisteDueno(due.getContacto()) == false) {
		if (can < tam) {
			vec[can++] = (Dueno*)&due;
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

Dueno* ContenedorDueno::getDueno(string contDue) {
	for (int i = 0; i < can; i++) {
		if (vec[i]->getContacto()==contDue)
			return vec[i];
	}
	return NULL;

}


string ContenedorDueno::toString() {
	stringstream s;

	for (int i = 0; i < can; i++) {
		s << vec[i]->toString() << endl;
	}
	return s.str();
}