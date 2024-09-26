#include "Citas.h"

Citas::Citas(){
	codigo = "Indefinido";
	motivo = "Indefinido";
	dia = "Indefinido";
	hora = 0;
	dueno = NULL;
	animal = NULL;
	veterinario = NULL;
	especialidad = NULL;
}


Citas::Citas(string cod, string mot, string di, int hor, Dueno* due, Mascota* ani,Doctor* vet, Especialidad* esp) {
	codigo = cod;
	motivo = mot;
	dia = di;
	hora = hor;
	dueno = due;
	animal = ani;
	veterinario = vet;
	especialidad = esp;
}

Citas:: ~Citas(){
	if (dueno != NULL && especialidad != NULL){
		delete dueno;
		delete especialidad;
	}

}

string Citas::getCodigo() { return codigo; }
string Citas::getMotivo() { return motivo; }
string Citas::getDia() { return dia; }
int Citas::getHora() { return hora; }
Mascota* Citas::getMascota() { return animal; }
Dueno* Citas::getDueno() { return dueno; }
Doctor* Citas::getDoctor() { return veterinario; }
Especialidad* Citas::getEspecialidad() { return especialidad; }

void Citas::setCodigo(string cod) { codigo = cod; }
void Citas::setMotivo(string mot) { motivo = mot; }
void Citas::setDia(string d) { dia = d; }
void Citas::setHora(int hor) { hora = hor; }

void Citas::setMascota(Mascota* ani){
	if (animal != NULL) {
		delete animal;
}
	animal = ani;
}

void Citas::setDueno(Dueno* due){
	if (dueno != NULL) {
		delete dueno;
}
	dueno = due;
}

void Citas::setDoctor(Doctor* doc) {
	if (veterinario != NULL) {
		delete veterinario;
	}
	veterinario = doc;
}

void Citas::setEspecialidad(Especialidad* esp){
	if (especialidad != NULL) {
		delete especialidad;
}
	especialidad = esp;
}

string Citas::toString(){
	stringstream s;
	s << "----- Informacion de la cita -----" << endl;
	s << "Codigo de la cita: " << codigo << endl;
	s << "Motivo de la cita: " << motivo << endl;
	s << "Dia de la cita: " << dia << endl;
	s << "Hora de la cita: " << hora << endl;
	s << endl;
	s << "   ----- Paciente -----" << endl;
	if (animal != NULL && especialidad != NULL) {
		s << dueno->toString() << endl;
		s << especialidad->toString() << endl;
	}
	return s.str();
}