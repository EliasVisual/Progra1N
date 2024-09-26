#include "ContenedorDoctor.h"
#include "Especialidad.h"

ContenedorDoctor::ContenedorDoctor(int n){
	vec = new Doctor * [n];
	can = 0;
	tam = n;

	for (int i = 0; i < tam; i++)
		vec[i] = NULL;
}

ContenedorDoctor:: ~ContenedorDoctor(){
	for (int i = 0; i < can; i++) {
		if (vec[i] != NULL)
			delete vec[i];
	}
	delete[] vec;
}

bool ContenedorDoctor::yaExisteDoctor(string idn){
	for (int i = 0; i < can; i++) {
		if (vec[i]->getIden()==idn)
			return true;
	}
	return false;
}

bool ContenedorDoctor::ingresarDoctor(Doctor& vet){
	if (yaExisteDoctor(vet.getIden())==false) {
		if (can < tam) {
			vec[can++] = (Doctor*)&vet;
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

Doctor* ContenedorDoctor::getDoctor(string iddoc) {
	for (int i = 0; i < can; i++) {
		if (vec[i]->getIden() == iddoc)
			return vec[i];
	}
	return NULL;
}


string ContenedorDoctor::toString(){
	stringstream s;
	for (int i = 0; i < can; i++)
		if (vec[i] != NULL)
			s << vec[i]->toString() << endl;
	return s.str();
}