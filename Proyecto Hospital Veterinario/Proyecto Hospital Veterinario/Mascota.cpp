#include "Mascota.h"

Mascota::Mascota() {
	iden = "Desconocido";
	especie = "Desconocido";
	raza = "Desconocido";
	sexo = "Desconocido";
	nombre = "Desconocido";
	edad = 0;
}

Mascota::Mascota(string id, string esp, string raz, string se, string nom, int ed){
	iden = id;
	especie = esp;
	raza = raz;
	sexo = se;
	nombre = nom;
	edad = ed;
}

Mascota:: ~Mascota(){}

string Mascota::getIden() { return iden; }
string Mascota::getEspecie() { return especie; }
string Mascota::getRaza() { return raza; }
string Mascota::getSexo() { return sexo; }
string Mascota::getNombre() { return nombre; }
int Mascota::getEdad() { return edad; }

void Mascota::setIden(string id) { iden = id; }
void Mascota::setEspecie(string esp) { especie = esp; }
void Mascota::setRaza(string raz) { raza = raz; }
void Mascota::setSexo(string se) { sexo = se; }
void Mascota::setNombre(string nom) { nombre = nom; }
void Mascota::setEdad(int ed) { edad = ed; }

string Mascota::toString(){
	stringstream s;
	s << "------- Informacion de la mascota ------" << endl;
	s << "Identificador de la mascota: " << iden << endl;
	s << "Especie de la mascota: " << especie << endl;
	s << "Raza de la mascota: " << raza << endl;
	s << "Sexo de la mascota: " << sexo << endl;
	s << "Nombre de la mascota: " << nombre << endl;
	s << "Edad de la mascota: " << edad <<" años." << endl;

	return s.str();
}