#include <iostream>
#include <string.h>
#include "../util/ui.h"
#include "../util/rlutil.h"
#include "../menues/informes.h"
#include "../modelos/paciente.h"
#include "../modelos/profesional.h"
#include "../modelos/medicacion.h"
#include "../modelos/planfarmacologico.h"
#include "../modelos/detalleplanfarmacologico.h"
#include "../menues/menuespaciente.h"

using namespace std;

void MenuPaciente(){
    while(true){
        rlutil::cls();
        title("PACIENTE", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);
        cout<<"1) LISTADOS"<<endl;
        cout<<"2) CONSULTAS"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"0) REGRESAR"<<endl;

        int opcion;
        cout << endl << "> ";
        cin >> opcion;

        switch(opcion){
            case 1: MenuPacienteListados();
            break;
            case 2: MenuPacienteConsulta();
            break;
            case 0:
                return;
            break;
        }
        cin.ignore();
    }
    return ;
}

void MenuPacienteConsulta(){
    while(true){
        rlutil::cls();
        title("PACIENTE - CONSULTA", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);
        cout<<"1) MEDICACION"<<endl;
        cout<<"2) PROFESIONAL"<<endl;
        cout<<"3) ESTUDIOS REALIZADOS"<<endl;
        cout<<"4) PLAN FARMACOLOGICO"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"0) REGRESAR"<<endl;

        int opcion;
        cout << endl << "> ";
        cin >> opcion;

        switch(opcion){
            case 1:
            rlutil::anykey();
            break;
            case 2:
            rlutil::anykey();
            break;
            case 3:
            rlutil::anykey();
            break;
            case 4: MenuPlanFarmacologico();
            rlutil::anykey();
            case 0:
                return;
            break;
        }
        cin.ignore();
    }
    return ;
}

void MenuPlanFarmacologico(){
    while(true){
        rlutil::cls();
        title("PACIENTE - CONSULTA", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);
        cout<<"1) MEDICACION"<<endl;
        cout<<"2) PROFESIONAL"<<endl;
        cout<<"3) DETALLE DEL PLAN"<<endl;
        cout<<"4) STOCK"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"0) REGRESAR"<<endl;

        int opcion;
        cout << endl << "> ";
        cin >> opcion;

        switch(opcion){
            case 1:
            rlutil::anykey();
            break;
            case 2:
            rlutil::anykey();
            break;
            case 3:
            rlutil::anykey();
            break;
            case 4:
            rlutil::anykey();
            case 0:
                return;
            break;
        }
        cin.ignore();
    }
    return ;
}

void MenuPacienteListados(){
    while(true){
        rlutil::cls();
        title("PACIENTE - LISTADO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);
        cout<<"1) LISTADO DE MEDICACION ACTUAL"<<endl;
        cout<<"2) LISTADO DE PROFESIONALES"<<endl;
        cout<<"3) LISTADO DE ESTUDIOS REALIZADOS"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"0) REGRESAR"<<endl;

        int opcion;
        cout << endl << "> ";
        cin >> opcion;

        switch(opcion){
            case 1:
                rlutil::anykey();
            break;
            case 2:
            rlutil::anykey();
            break;
            case 3:
            rlutil::anykey();
            break;
            case 0:
                return;
            break;
        }
        cin.ignore();
    }
    return ;
}
