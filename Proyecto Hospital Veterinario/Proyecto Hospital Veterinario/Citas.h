#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Dueño.h"
#include "Especialidad.h"
#include "ContenedorMascota.h"

using namespace std;

class Citas {
private:
	string codigo;
	string motivo;
	string dia;
	int hora;
	Mascota* animal;
	Dueno* dueno;
	Doctor* veterinario;
	Especialidad* especialidad;

public:

	Citas();
	Citas(string, string, string, int, Dueno*, Mascota*,Doctor*, Especialidad*);
	virtual ~Citas();

	string getCodigo();
	string getMotivo();
	string getDia();
	int getHora();
	Mascota* getMascota();
	Dueno* getDueno();
	Doctor* getDoctor();
	Especialidad* getEspecialidad();

	void setCodigo(string);
	void setMotivo(string);
	void setDia(string);
	void setHora(int);
	void setMascota(Mascota*);
	void setDueno(Dueno*);
	void setDoctor(Doctor*);
	void setEspecialidad(Especialidad*);
		
	string toString();
};