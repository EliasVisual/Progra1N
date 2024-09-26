#pragma once
#include "Especialidad.h"

class ContenedorEspecialidad {
private:
	Especialidad** vec;
	int can;
	int tam;

public:
	ContenedorEspecialidad(int);
	virtual ~ContenedorEspecialidad();
	bool yaExisteEspecialidad(string);
	bool ingresarEspecialidad(Especialidad&);
	Especialidad* getEspecialidad(string);
	string toStringEsp(string);
	string toStringSoloEsp();
	string toString();
};