#include <iostream>
#include <string>
#include "Veterinaria.h" // Asegúrate de incluir todas las dependencias necesarias
#include "ContenedorEspecialidad.h"
#include "ContenedorDoctor.h"
#include "ContenedorMascota.h"

using namespace std;

int main() {
    int opcion, opSA, canEs, canDoc, canMas, edad, canDue, opSCC, hora, opcSBL;
    string esp, nom, iden, contacto, pago, idMascota, raza, sexo, nombre, dia, motivo, codigo;
    Especialidad* espec = NULL;
    ContenedorEspecialidad* COE = NULL;
    Doctor* doct = NULL;
    ContenedorDoctor* COD = NULL;
    Dueno* due = NULL;
    Mascota* masc = NULL;
    Citas* cit = NULL;
    ContenedorMascota* COM = NULL;
    ContenedorDueno* CONDUE = NULL;
    ContenedorCitas* COCIT = NULL;
    //Veterinaria* vet = new Veterinaria();

    do {
        system("cls");
        cout << "*****************************************************" << endl;
        cout << "******** BIENVENIDOS AL HOSPITAL VETERINARIO ********" << endl;
        cout << "*****************************************************" << endl;

        cout << endl;

        cout << "********* MENU PRINCIPAL *********" << endl;
        cout << " 1- Submenu Administracion" << endl;
        cout << " 2- Submenu Control de Citas" << endl;
        cout << " 3- Submenu Busquedas y Listados" << endl;
        cout << "************************************" << endl;
        cout << "Ingrese la opcion:" << endl;
        cin >> opcion;

        switch (opcion) {
        case 1: {
            do {
                cout << "********* SUBMENU ADMINISTRACION *********" << endl;
                cout << " (1) - Ingresar Especialidad" << endl;
                cout << " (2) - Ingresar Doctor (por especialidad)" << endl;
                cout << " (3) - Ingresar Dueno" << endl;
                cout << " (4) - Ingresar Mascota (por dueno)" << endl;
                cout << " (5) - Regresar al Menu Principal" << endl;
                cout << "************************************" << endl;
                cout << "Ingrese la opcion:" << endl;
                cin >> opSA;

                switch (opSA) {
                case 1: {
                    cout << "1 - Ingresar Especialidad" << endl;
                    cout << "Indique la cantidad de especialidades que desea agregar: " << endl;
                    cin >> canEs;
                    COE = new ContenedorEspecialidad(canEs);

                    for (int i = 0; i < canEs; i++) {
                        cout << "Ingrese la especialidad #" << i + 1 << ": " << endl;
                        cin >> esp;

                        espec = new Especialidad(esp);

                        if (COE->ingresarEspecialidad(*espec)) {
                            cout << "Especialidad ingresada correctamente en el contenedor." << endl;
                        }
                        else {
                            cout << "No se pudo ingresar la especialidad en el contenedor, ya existe." << endl;
                        }
                    }
                }
                      break;

                case 2: {
                    cout << "2 - Ingresar Doctor (por especialidad)" << endl;
                    cout << "Digite la especialidad a la que desea agregar el doctor: " << endl;
                    cin >> esp;

                    if (COE->yaExisteEspecialidad(esp)) {
                        cout << "Indique la cantidad de doctores que desea agregar a la especialidad: " << esp << endl;
                        cin >> canDoc;

                        Especialidad* espec = COE->getEspecialidad(esp);
                        COD = new ContenedorDoctor(canDoc);

                        for (int i = 0; i < canDoc; i++) {
                            cout << "Ingrese el nombre del doctor #" << i + 1 << ": " << endl;
                            cin >> nom;
                            cout << "Ingrese la identificacion del doctor #" << i + 1 << ": " << endl;
                            cin >> iden;

                            doct = new Doctor(nom, iden);

                            if (COD->ingresarDoctor(*doct)) {
                                cout << "Doctor ingresado correctamente en la especialidad " << esp << endl;
                            }
                            else {
                                cout << "No se pudo ingresar el doctor en la especialidad, ya existe o no hay espacio." << endl;
                            }
                        }
                    }
                    else {
                        cout << "La especialidad no existe." << endl;
                    }

                }
                      break;
                case 3: {
                    cout << "3 - Ingresar Dueño" << endl;
                    cout << "Indique la cantidad de dueños que desea agregar: " << endl;
                    cin >> canDue;
                    CONDUE = new ContenedorDueno(canDue);

                    for (int i = 0; i < canDue; i++) {
                        cout << "Ingrese el nombre del dueño #" << i + 1 << ": " << endl;
                        cin >> nom;

                        cout << "Ingrese el contacto del dueño #" << i + 1 << ": " << endl;
                        cin >> contacto;

                        cout << "Ingrese el método de pago del dueño #" << i + 1 << ": " << endl;
                        cin >> pago;

                        Dueno* due = new Dueno(nom, contacto, pago);

                        if (CONDUE->ingresarDueno(*due)) {
                            cout << "Dueno ingresado correctamente al contenedor" << endl;
                        }
                        else {
                            cout << "No se pudo ingresar el dueno en el contenedor, ya existe" << endl;
                        }

                    }

                }
                      break;

                case 4: {
                    cout << "4 - Ingresar Mascota (por dueño)" << endl;
                    cout << "Ingrese el contacto del dueño: " << endl;
                    cin >> contacto;

                    if (CONDUE->yaExisteDueno(contacto)) {
                        cout << "Indique la cantidad de mascotas que desea agregar para el dueno: " << endl;
                        cin >> canMas;

                        Dueno* dueno = CONDUE->getDueno(contacto);
                        COM = new ContenedorMascota(canMas);

                        for (int i = 0; i < canMas; i++) {
                            cout << "Ingrese los datos de la mascota #" << i + 1 << ":" << endl;

                            cout << "Ingrese el ID de la mascota: " << endl;
                            cin >> idMascota;

                            cout << "Ingrese la especie de la mascota: " << endl;
                            cin >> esp;

                            cout << "Ingrese la raza de la mascota: " << endl;
                            cin >> raza;

                            cout << "Ingrese el sexo de la mascota: " << endl;
                            cin >> sexo;

                            cout << "Ingrese el nombre de la mascota: " << endl;
                            cin >> nombre;

                            cout << "Ingrese la edad de la mascota: " << endl;
                            cin >> edad;

                            Mascota* masc = new Mascota(idMascota, esp, raza, sexo, nombre, edad);

                            if (COM->ingresarMascota(*masc)) {
                                cout << "Mascota ingresada correctamente al dueño." << endl;
                                //if(vet->ingresarMascota(COM))
                            }
                            else {
                                cout << "No se pudo ingresar la mascota al dueño, ya existe o no hay espacio." << endl;
                            }
                        }
                    }
                    else {
                        cout << "El dueno no existe" << endl;
                    }

                }
                      break;

                case 5: {
                    cout << "Volviendo al menu principal..." << endl;
                }
                      break;

                default: {
                    cout << "Opción inválida. Por favor, intente de nuevo." << endl;
                }
                       break;
                };

            } while (opSA != 5);

        }
              break;

        case 2: {
            do {
                cout << "********* SUBMENU CONTROL CITAS *********" << endl;
                cout << " (1) - Sacar Cita" << endl;
                cout << " (2) - Cancelar cita" << endl;
                cout << " (3) - Mostrar Calendario de Citas por Doctor" << endl;
                cout << " (4) - Mostrar Citas por Dueno" << endl;
                cout << " (5) - Regresar al Menu Principal" << endl;
                cout << "************************************" << endl;
                cout << "Ingrese la opcion:" << endl;
                cin >> opSCC;

                switch (opSCC) {

                case 1: {
                    cout << "Ingrese el contacto del dueño: " << endl;
                    cin >> contacto;

                    due = CONDUE->getDueno(contacto);

                    if (due == NULL) {
                        cout << "Dueño no encontrado." << endl;
                        break;
                    }

                    if (due->getContenedorMascota() == NULL) {
                        cout << "El dueño no tiene mascotas registradas." << endl;
                        break;
                    }

                    cout << "Mascotas registradas para el dueño " << due->getNombre() << ":" << endl;
                    due->getContenedorMascota()->toString();

                    cout << "Ingrese el ID de la mascota para la cita: " << endl;
                    cin >> idMascota;

                    masc = due->getContenedorMascota()->getMascota(idMascota);
                    if (masc == NULL) {
                        cout << "Mascota no encontrada." << endl;
                        break;
                    }

                    cout << "Ingrese la especialidad deseada: " << endl;
                    cin >> esp;

                    if (!COE->yaExisteEspecialidad(esp)) {
                        cout << "Especialidad no encontrada." << endl;
                        break;
                    }

                    cout << "Doctores disponibles en la especialidad " << esp << ":" << endl;
                    COE->toStringEsp(esp);
                    /*vet->getContenedorDoctor()->mostrarDoctoresPorEspecialidad(especialidad);*/

                    cout << "Ingrese el ID del doctor para la cita: " << endl;
                    cin >> iden;

                    /*Doctor* doctor = vet->getDoctorPorId(idDoctor);*/
                    doct = COD->getDoctor(iden);

                    if (doct == NULL) {
                        cout << "Doctor no encontrado." << endl;
                        break;
                    }

                    // Mostrar el horario semanal del doctor
                    cout << "Horario disponible del doctor " << doct->getNombre() << ":" << endl;
                    //doct->mostrarHorario();

                    cout << "Ingrese el dia:" << endl;
                    cin >> dia;
                    cout << "Ingrese la hora:" << endl;
                    cin >> hora;
                    cout << "Ingresar el motivo de la cita" << endl;
                    cin >> motivo;
                    codigo = idMascota + " - " + contacto;

                    cit = new Citas(codigo, motivo, dia, hora, due, masc, doct, espec);
                    COCIT->ingresarCita(*cit);
                    if (COCIT->ingresarCita(*cit)) {
                        cout << "Cita agendada correctamente." << endl;
                    }
                    else {
                        cout << "No se pudo agendar la cita" << endl;
                    }

                }
                      break;

                case 2: {


                }
                      break;

                case 3: {


                }
                      break;

                case 4: {


                }
                      break;

                case 5: {
                    cout << "Volviendo al menu principal..." << endl;

                }
                      break;

                default: {
                    cout << "Opción inválida. Por favor, intente de nuevo." << endl;
                }
                       break;

                };


            } while (opSCC != 5);

        }
              break;

        case 3: {
            do {
                cout << "********* SUBMENU BUSQUEDAS Y LISTADOS *********" << endl;
                cout << " (1) - Mostrar listado de Especialidades" << endl;
                cout << " (2) - Mostrar Listado de Doctores por Especialidad" << endl;
                cout << " (3) - Mostrar Dueños con sus Mascotas" << endl;
                cout << " (4) - Mostrar Pacientes por Doctor" << endl;
                cout << " (5) - Regresar al Menú Principal" << endl;
                cout << "************************************" << endl;
                cout << "Ingrese la opcion:" << endl;
                cin >> opcSBL;

                switch (opcSBL) {

                case 1: {
                    cout << " 1 - Mostrar listado de Especialidades" << endl;
                    cout << COE->toStringSoloEsp() << endl;
                }
                      break;
                case 2: {
                    cout << " 2 - Mostrar Listado de Doctores por Especialidad" << endl;
                    cout << COE->toString() << endl;
                }
                      break;
                case 3: {
                    cout << " 3 - Mostrar Dueños con sus Mascotas" << endl;
                    cout << CONDUE->toString() << endl;
                }
                      break;
                case 4: {
                    cout << " 4 - Mostrar Pacientes por Doctor" << endl;
                }
                      break;
                case 5: {
                    cout << "Volviendo al menu principal..." << endl;
                }
                      break;

                default: {
                    cout << "Opción inválida. Por favor, intente de nuevo." << endl;
                }
                       break;

                };

            } while (opcSBL != 5);

        }
              break;

        default: {
            cout << "Opción inválida.Por favor, intente de nuevo." << endl;
        }
               break;

        };

    } while (opcion != 4);


	return 0;
}