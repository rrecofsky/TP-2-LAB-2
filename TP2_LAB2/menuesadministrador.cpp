#include "iostream"
#include "string.h"
#include "ui.h"
#include "rlutil.h"

#include "especialidad.h"
#include "persona.h"
#include "fecha.h"
#include "informes.h"
#include "paciente.h"
#include "profesional.h"
#include "medicacion.h"
#include "planfarmacologico.h"
#include "registro.h"
#include "archivo.h"
#include "detalleplanfarmacologico.h"

#include "menuesadministrador.h"
#include "menuesprofesional.h"
#include "menuespaciente.h"
using namespace std;
using namespace rlutil;

void MenuPrincipal()
{
    initUI();
    title("", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);

    while(true)
    {
        cls();
        title("MENU PRINCIPAL", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);
        cout<<"1) PROFESIONALES"<<endl;
        cout<<"2) PACIENTES"<<endl;
        cout<<"3) REPORTES"<<endl;
        cout<<"4) CONFIGURACION"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"0) SALIR DEL PROGRAMA"<<endl;

        int opcion;
        cout << endl << "> ";
        cin >> opcion;

        switch(opcion){
            case 1:
                     MenuEntidad("PROFESIONAL");
                    break;
            case 2:
                     MenuEntidad("PACIENTE");
                    break;
            break;
            case 3:

            break;
            case 4:
            break;
            case 0:
                return;
            break;
        }
        cin.ignore();
    }
    return ;
}

void MenuEntidad(char * entidad)
{
    while(true)
    {
        cls();
        title(entidad, APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);
        cout<<"1) ALTA"<<endl;
        cout<<"2) MODIFICACION"<<endl;
        cout<<"3) BAJA"<<endl;
        cout<<"4) LISTADO"<<endl;
        cout<<"5) CONSULTA"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"0) REGRESAR"<<endl;

        int opcion;
        cout << endl << "> ";
        cin >> opcion;

        switch(opcion){
            case 1:
                if (strcmp("PROFESIONAL",entidad) == 0) {
                        cout<<"ingresa a alta de profesional"<<endl;
                        anykey();
                }
                else {
                cout<<"ingresa a alta de paciente"<<endl;
                      anykey();
                }
            break;
            case 2:

            break;
            case 3:

            break;
            case 4:
                if (strcmp("PROFESIONAL",entidad) == 0) {
                    MenuProfesionalListado();
                }
                else {
                    MenuPacienteListado();

                }
            break;
            case 5:
            if (strcmp("PROFESIONAL",entidad) == 0) {
                MenuProfesionalConsulta();
                }
            else {
                MenuPacienteConsulta();

                }

            break;
            case 0:
                return;
            break;
        }
        cin.ignore();
    }
    return ;
}


