#include "Especialidad.h"

Especialidad::Especialidad(){
	especialidad = "Indefinido";
	COD = NULL;
}

Especialidad::Especialidad(string esp) {
	especialidad = esp;
	COD = NULL;
}

Especialidad::Especialidad(string esp,ContenedorDoctor* codn){
	especialidad = esp;
	COD = codn;
}

Especialidad:: ~Especialidad(){
		delete COD;
}

string Especialidad::getEspecialidad() { return especialidad; }
ContenedorDoctor* Especialidad::getContenedor() { return COD; }

void Especialidad::setEspecialidad(string esp) { especialidad = esp; }
void Especialidad::setContenedorDoctor(ContenedorDoctor* codn) { COD = codn; }

bool Especialidad::yaExisEsp(string idn){
	return COD->yaExisteDoctor(idn);
}

bool Especialidad::ingresarEsp(Doctor& docNue){
	return COD->ingresarDoctor(docNue);	
}

string Especialidad::toStringEspe() {
	stringstream s;

	s << "----- Especialidades ------" << endl;
	s << "Especialidad: " << especialidad << endl;
	s << endl;

	return s.str();
}

string Especialidad::toString(){
	stringstream s;
	
	s << "----- Informacion de la especialidad y sus doctores ------" << endl;
	s << "Especialidad: " << especialidad << endl;
	s << endl;
	s << "-----DOCTORES-----" << endl;
	if (COD != NULL) {
		s << COD->toString() << endl;
	}
	else
		s << "No existe algun veterinario con esa especialidad" << endl;

	return s.str();
}