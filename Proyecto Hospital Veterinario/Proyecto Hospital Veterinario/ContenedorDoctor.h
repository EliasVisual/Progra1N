#pragma once
#include "Doctor.h"

class ContenedorDoctor {
private:
	Doctor** vec;
	int can;
	int tam;

public:
	ContenedorDoctor(int);
	virtual ~ContenedorDoctor();
	bool yaExisteDoctor(string);
	bool ingresarDoctor(Doctor&);
	Doctor* getDoctor(string);
	string toString();

};