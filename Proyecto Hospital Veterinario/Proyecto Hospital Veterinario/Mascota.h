#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Mascota {
private:
	string iden;
	string especie;
	string raza;
	string sexo;
	string nombre;
	int edad;

public:

	Mascota();
	Mascota(string, string, string, string, string, int);
	virtual ~Mascota();

	string getIden();
	string getEspecie();
	string getRaza();
	string getSexo();
	string getNombre();
	int getEdad();

	void setIden(string);
	void setEspecie(string);
	void setRaza(string);
	void setSexo(string);
	void setNombre(string);
	void setEdad(int);

	string toString();

};
