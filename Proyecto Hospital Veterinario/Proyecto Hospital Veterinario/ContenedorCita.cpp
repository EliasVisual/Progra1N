#include "ContenedorCita.h"



ContenedorCitas::ContenedorCitas(int n){
	vec = new Citas * [n];
	can = 0;
	tam = n;

	for (int i = 0; i < tam; i++)
		vec[i] = NULL;
}

ContenedorCitas:: ~ContenedorCitas(){
	for (int i = 0; i < can; i++) {
		if (vec[i] != NULL)
			delete vec[i];
	}
	delete[] vec;
}

bool ContenedorCitas::yaExisteCita(string cod){
	for (int i = 0; i < can; i++) {
		if (vec[i]->getCodigo() == cod)
			return true;
	}
	return false;
}

bool ContenedorCitas::yaExisteCitaHorario(string di, int hor){
	for (int i = 0; i < can; i++) {
		if (vec[i]->getDia() == di && vec[i]->getHora() == hor)
			return true;
	}
	return false;
}


bool ContenedorCitas::ingresarCita(Citas& citn){
	if (yaExisteCita(citn.getCodigo()) == false && yaExisteCitaHorario(citn.getDia(), citn.getHora()) == false) {
		int cantCitas = 0;
		for (int i = 0; i < can; i++) {
			if (vec[i]->getDia() == citn.getDia()) {
				cantCitas++;
			}
		}

		if (cantCitas >= 11) {
			return false;
		}

		if (can < tam) {
			vec[can++] = (Citas*)&citn;
			return true;
		}
		else
			return false;
	}
	else
		return false;

}

int ContenedorCitas::posiCita(string cod) {
	for (int i = 0; i < can; i++)
		if (cod == vec[i]->getCodigo())
			return i;
	return -1;
}

bool ContenedorCitas::eliminarCita(string cod) {
	int posCita;
	if (yaExisteCita(cod) == true) {
		posCita = posiCita(cod);
		for (int i = posCita; i < can; i++)
			vec[i] = vec[i + 1];
		can--;

		return true;
	}
	else
		return false;
}

string ContenedorCitas::toString(){
	stringstream s;
	for (int i = 0; i < can; i++)
		if (vec[i] != NULL)
			s << vec[i]->toString() << endl;
	return s.str();
}


