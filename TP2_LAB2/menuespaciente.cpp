#include <iostream>
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


void MenuPacienteListado(){
    while(true){
        rlutil::cls();
        title("PACIENTE - LISTADO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);
        cout<<"1) MEDICACION ACTUAL"<<endl;
        cout<<"2) PROFESIONALES"<<endl;
        cout<<"3) ESTUDIOS REALIZADOS"<<endl;
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