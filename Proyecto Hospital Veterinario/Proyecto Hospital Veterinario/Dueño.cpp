#include "Dueño.h"

Dueno::Dueno(){
	nombre = "Indefinido";
	contacto = "Indefinido";
	pago = "Indefinido";
	COM = NULL;
}

Dueno::Dueno(string nom, string cont, string pag) {
	nombre = nom;
	contacto = cont;
	pago = pag;
	COM = NULL;
}

Dueno::Dueno(string nom, string cont, string pag,ContenedorMascota* comnn){
	nombre = nom;
	contacto = cont;
	pago = pag;
	COM = comnn;
}

Dueno:: ~Dueno(){
	delete COM;
}

string Dueno::getNombre() { return nombre; }
string Dueno::getContacto() { return contacto; }
string Dueno::getMetodoPago() { return pago; }
ContenedorMascota* Dueno::getContenedorMascota() { return COM; }


void Dueno::setNombre(string nom) { nombre = nom; }
void Dueno::setContacto(string cont) { contacto = cont; }
void Dueno::setMetodoPago(string pag) { pago = pag; }
void Dueno::setContenedora(ContenedorMascota* COMN) { COM = COMN; }

bool Dueno::yaExisMasc(string iden){
	return COM->yaExisteMascota(iden);
}

bool Dueno::ingresarMasc(Mascota& mascNue){
	return COM->ingresarMascota(mascNue);
}


string Dueno::toString(){
	stringstream s;
	
	s << "----- Informacion del dueno -----" << endl;
	s << "Nombre completo: " << nombre << endl;
	s << "Contacto disponible: " << contacto << endl;
	s << "Metodo de pago: " << pago << endl;
	s << endl;
	s << "    ------ Mascotas -----" << endl;
	if (COM!=NULL)
		s << COM->toString() << endl;
	else
		s << "No tiene mascotas registradas" << endl;

	return s.str();
	
}

