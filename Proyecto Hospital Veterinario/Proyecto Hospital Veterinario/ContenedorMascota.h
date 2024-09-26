#pragma once
#include "Mascota.h"

class ContenedorMascota {
private:
	Mascota** vec;
	int can;
	int tam;

public:

	ContenedorMascota(int);
	virtual ~ContenedorMascota();
	bool yaExisteMascota(string);
	bool ingresarMascota(Mascota&);
	Mascota* getMascota(string);
	string toString();
};