#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Doctor.h"
#include "ContenedorDoctor.h"

class Especialidad {
private:
	string especialidad;
	ContenedorDoctor* COD;

public:

	Especialidad();
	Especialidad(string);
	Especialidad(string,ContenedorDoctor*);
	virtual ~Especialidad();

	string getEspecialidad();
	ContenedorDoctor* getContenedor();

	void setEspecialidad(string);
	void setContenedorDoctor(ContenedorDoctor*);

	bool yaExisEsp(string);
	bool ingresarEsp(Doctor&);

	string toStringEspe();
	string toString();


};