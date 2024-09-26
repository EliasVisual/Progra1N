#include "Veterinaria.h"

Veterinaria::Veterinaria() {
	nombreVet = "";
	telefono = "";
	COM = NULL;
	CODUE = NULL;
	CODOC = NULL;
	COE = NULL;
	COCIT = NULL;

}

Veterinaria::Veterinaria(string nom, string tel){
	nombreVet = nom;
	telefono = tel;
	COM = NULL;
	CODUE = NULL;
	CODOC = NULL;
	COE = NULL;
	COCIT = NULL;
}

ContenedorMascota* Veterinaria::getContenedorMascota() { return COM; }
ContenedorDueno* Veterinaria::getContenedorDueno() { return CODUE; }
ContenedorDoctor* Veterinaria::getContenedorDoctor() { return CODOC; }
ContenedorEspecialidad* Veterinaria::getContenedorEspecialidad() { return COE; }
ContenedorCitas* Veterinaria::getContenedorCitas() { return COCIT; }



//Contenedor Mascota
bool Veterinaria::yaExisteMascota(string id){
	return COM->yaExisteMascota(id);
}

bool Veterinaria::ingresarMascota(Mascota& masc){
	if (yaExisteMascota(masc.getIden()) == true)
		return COM->ingresarMascota(masc);
	else
		return false;
}

string Veterinaria::toStringMascota(){
	stringstream s;
	s << COM->toString() << endl;
	return s.str();
}


//Contenedor Dueno
bool Veterinaria::yaExisteDueno(string cont){
	return CODUE->yaExisteDueno(cont);
}

bool Veterinaria::ingresarDueno(Dueno& due){
	if (yaExisteDueno(due.getContacto()) == true)
		return CODUE->ingresarDueno(due);
	else
		return false;
}

Dueno* Veterinaria::getDueno(string cont) {
	return CODUE->getDueno(cont);
}

string Veterinaria::toStringDueno(){
	stringstream s;
	s << CODUE->toString() << endl;
	return s.str();
}

//Conteneddor Doctor
bool Veterinaria::yaExisteDoctor(string id){
	return CODOC->yaExisteDoctor(id);
}

bool Veterinaria::ingresarDoctor(Doctor& doc){
	if (yaExisteDoctor(doc.getIden()) == true)
		return CODOC->ingresarDoctor(doc);
	else
		return false;
}

string Veterinaria::toStringDoctor(){
	stringstream s;
	s << CODOC->toString() << endl;
	return s.str();
}

//Contenedor Especialidad


bool Veterinaria::yaExisteEspecialidad(string esp){
	return COE->yaExisteEspecialidad(esp);
}

bool Veterinaria::ingresarEspecialidad(Especialidad& esp){
	if (yaExisteEspecialidad(esp.getEspecialidad()) == true)
		return COE->ingresarEspecialidad(esp);
	else
		return false;
}

string Veterinaria::toStringEspecialidad(){
	stringstream s;
	s << COE->toString() << endl;
	return s.str();
}


//Contenedor Cita
bool Veterinaria::yaExisteCita(string cod){
	return COCIT->yaExisteCita(cod);
}

bool Veterinaria::yaExisteCitaHorario(string di, int hor){
	return COCIT->yaExisteCitaHorario(di, hor);
}

bool Veterinaria::ingresarCita(Citas& citan) {
	if (yaExisteCita(citan.getCodigo()) && yaExisteCitaHorario(citan.getDia(), citan.getHora()) == true)
		return COCIT->ingresarCita(citan);
	else
		return false;
}

int Veterinaria::posiCita(string cod){
	return COCIT->posiCita(cod);
}

bool Veterinaria::eliminarCita(string cod){
	return COCIT->eliminarCita(cod);
}

string Veterinaria::toStringCita(){
	stringstream s;
	s << COCIT->toString() << endl;
	return s.str();
}



