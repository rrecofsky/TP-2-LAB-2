#include "iostream"
#include "string.h"
#include "../headers/ui.h"
#include "../headers/rlutil.h"

#include "../headers/especialidad.h"
#include "../headers/persona.h"
#include "../headers/fecha.h"
#include "../headers/informes.h"
#include "../headers/paciente.h"
#include "../headers/profesional.h"
#include "../headers/medicacion.h"
#include "../headers/planfarmacologico.h"
#include "../headers/registro.h"
#include "../headers/archivo.h"
#include "../headers/detalleplanfarmacologico.h"

#include "../headers/menuesadministrador.h"

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
        cout<<"----------------------"<<endl;
        cout<<"0) REGRESAR"<<endl;

        int opcion;
        cout << endl << "> ";
        cin >> opcion;

        switch(opcion){
            case 1:
                      strcmp("PROFESIONAL",entidad) == 0 ? cout<<"ingresa a alta de profesional"<<endl : cout<<"ingresa a alta de paciente"<<endl;
                      anykey();
            break;
            case 2:

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


