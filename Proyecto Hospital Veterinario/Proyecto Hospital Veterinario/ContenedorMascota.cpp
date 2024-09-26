#include "ContenedorMascota.h"

ContenedorMascota::ContenedorMascota(int n){
	vec = new Mascota * [n];
	can = 0;
	tam = n;

	for (int i = 0; i < tam; i++)
		vec[i] = NULL;
}


ContenedorMascota:: ~ContenedorMascota(){
	for (int i = 0; i < can; i++) {
		if (vec[i] != NULL)
			delete vec[i];
	}
	delete[] vec;
}


bool ContenedorMascota::yaExisteMascota(string idn){
	for (int i = 0; i < can; i++) {
		if (vec[i]->getIden() == idn)
			return true;
	}
	return false;
}


bool ContenedorMascota::ingresarMascota(Mascota& masc){
	if (yaExisteMascota(masc.getIden()) == false) {
		if (can < tam) {
			vec[can++] = (Mascota*)&masc;
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

Mascota* ContenedorMascota::getMascota(string idmas) {
	for (int i = 0; i < can; i++) {
		if (vec[i]->getIden() == idmas)
			return vec[i];
	}
	return NULL;
}


string ContenedorMascota::toString(){
	stringstream s;
	for (int i = 0; i < can; i++)
		if (vec[i] != NULL)
			s << vec[i]->toString() << endl;
	return s.str();
}