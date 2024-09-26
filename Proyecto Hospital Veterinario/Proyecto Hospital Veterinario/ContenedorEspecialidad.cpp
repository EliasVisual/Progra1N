#include "ContenedorEspecialidad.h"

ContenedorEspecialidad::ContenedorEspecialidad(int n) {
	vec = new Especialidad * [n];
	can = 0;
	tam = n;

	for (int i = 0; i < tam; i++)
		vec[i] = NULL;
}

ContenedorEspecialidad:: ~ContenedorEspecialidad() {
	for (int i = 0; i < can; i++) {
		if (vec[i] != NULL)
			delete vec[i];
	}
	delete[] vec;
}

bool ContenedorEspecialidad::yaExisteEspecialidad(string esp) {
	for (int i = 0; i < can; i++) {
		if (vec[i]->getEspecialidad() == esp)
			return true;
	}
	return false;
}

bool ContenedorEspecialidad::ingresarEspecialidad(Especialidad& espn) {
	if (yaExisteEspecialidad(espn.getEspecialidad()) == false) {
		if (can < tam) {
			vec[can++] = (Especialidad*)&espn;
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

Especialidad* ContenedorEspecialidad::getEspecialidad(string nomEsp) {
	for (int i = 0; i < can; i++) {
		if (vec[i]->getEspecialidad() == nomEsp)
			return vec[i];
	}
	return NULL;
}

string ContenedorEspecialidad::toStringEsp(string esp) {
	stringstream s;
	for (int i = 0; i < can; i++) {
		if (vec[i]->getEspecialidad() == esp)
			s << vec[i]->toString() << endl;
	}
	return s.str();
}

string ContenedorEspecialidad::toStringSoloEsp() {
	stringstream s;
	for (int i = 0; i < can; i++) {
		s << vec[i]->toStringEspe() << endl;
	}
	return s.str();
}

string ContenedorEspecialidad::toString() {
	stringstream s;

	for (int i = 0; i < can; i++) {
		s << vec[i]->toString() << endl;
	}
	return s.str();
}