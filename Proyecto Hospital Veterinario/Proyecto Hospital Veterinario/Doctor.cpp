#include "Doctor.h"

Doctor::Doctor(){
	nombre = "Indefinido";
	iden = "Indefinido";
}
Doctor::Doctor(string nom, string id){
	nombre = nom;
	iden = id;
}

Doctor::~Doctor(){}

string Doctor::getNombre() { return nombre; }
string Doctor::getIden() { return iden; }

void Doctor::setNombre(string nom) { nombre = nom; }
void Doctor::setIden(string id) { iden = id; }

string Doctor::toString(){
	stringstream s;
	s << "-----Informacion del Doctor------" << endl;
	s << "Nombre completo: " << nombre << endl;
	s << "Identificacion: " << iden << endl;

	return s.str();

}