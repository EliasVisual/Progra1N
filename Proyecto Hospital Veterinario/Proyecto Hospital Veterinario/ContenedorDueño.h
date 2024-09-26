#pragma once
#include "Dueño.h"

class ContenedorDueno {
private:
	Dueno** vec;
	int can;
	int tam;

public:
	ContenedorDueno(int);
	virtual ~ContenedorDueno();
	bool yaExisteDueno(string);
	bool ingresarDueno(Dueno&);
	Dueno* getDueno(string);
	string toString();

};