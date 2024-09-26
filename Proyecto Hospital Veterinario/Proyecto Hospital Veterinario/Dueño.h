#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "ContenedorMascota.h"

class Dueno {
private:
	string nombre;
	string contacto;
	string pago;
	ContenedorMascota* COM;

public:

	Dueno();
	Dueno(string, string, string);
	Dueno(string, string, string, ContenedorMascota*);
	virtual ~Dueno();

	string getNombre();
	string getContacto();
	string getMetodoPago();
	ContenedorMascota* getContenedorMascota();

	void setNombre(string);
	void setContacto(string);
	void setMetodoPago(string);
	void setContenedora(ContenedorMascota*);

	string toString();

	bool yaExisMasc(string);
	bool ingresarMasc(Mascota&);



};