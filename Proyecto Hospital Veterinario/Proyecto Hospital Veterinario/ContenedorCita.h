#pragma once
#include "Citas.h"

class ContenedorCitas {
private:
	Citas** vec;
	int can;
	int tam;

public:

	ContenedorCitas(int);
	virtual ~ContenedorCitas();
	bool yaExisteCita(string);
	bool yaExisteCitaHorario(string, int);
	bool ingresarCita(Citas&);
	int posiCita(string);
	string toStringMascDoc(string,string);
	bool eliminarCita(string);
	string toString();
	
};