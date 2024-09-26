//#pragma once
//#include "ContenedorMascota.h"
//#include "ContenedorDueño.h"
//#include "ContenedorDoctor.h"
//#include "ContenedorEspecialidad.h"
//#include "ContenedorCita.h"
//
//class Veterinaria {
//private:
//	
//	ContenedorMascota* COM;
//	ContenedorDueno* CODUE;
//	ContenedorDoctor* CODOC;
//	ContenedorEspecialidad* COE;
//	ContenedorCitas* COCIT;
//
//
//public:
//	Veterinaria();
//
//	ContenedorMascota* getContenedorMascota();
//	ContenedorDueno* getContenedorDueno();
//	ContenedorDoctor* getContenedorDoctor();
//	ContenedorEspecialidad* getContenedorEspecialidad();
//	ContenedorCitas* getContenedorCitas();
//
//
//	//Contenedor Mascota
//	bool yaExisteMascota(string);
//	bool ingresarMascota(Mascota&);
//	string toStringMascota();
//	
//
//	//Contenedor Dueno
//	bool yaExisteDueno(string);
//	bool ingresarDueno(Dueno&);
//	Dueno* getDueno(string);
//	string toStringDueno();
//
//	//Conteneddor Doctor
//	bool yaExisteDoctor(string);
//	bool ingresarDoctor(Doctor&);
//	string toStringDoctor();
//
//	//Contenedor Especialidad
//	bool yaExisteEspecialidad(string);
//	bool ingresarEspecialidad(Especialidad&);
//	string toStringEspecialidad();
//	
//	//Contenedor Cita
//	bool yaExisteCita(string);
//	bool yaExisteCitaHorario(string, int);
//	bool ingresarCita(Citas&);
//	int posiCita(string);
//	bool eliminarCita(string);
//	string toStringCita();
//
//
//};