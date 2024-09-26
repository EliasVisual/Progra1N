#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Doctor {
private:
	string nombre;
	string iden;


public:
	Doctor();
	Doctor(string, string);
	virtual ~Doctor();

	string getNombre();
	string getIden();

	void setNombre(string);
	void setIden(string);

	string toString();

};