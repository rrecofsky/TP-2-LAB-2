#include <iostream>
#include <string.h>
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


void MenuProfesional(){
    while(true){
        rlutil::cls();
        title("PROFESIONAL", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);
        cout<<"1) PLANES FARMACOLOGICOS"<<endl;
        cout<<"2) PACIENTES"<<endl;
        cout<<"3) CONSULTAS"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"0) REGRESAR"<<endl;

        int opcion;
        cout << endl << "> ";
        cin >> opcion;

        switch(opcion){
            case 1:
                rlutil::cls();
                title("PROFESIONAL - LISTADO - PLAN FARMACOLOGICO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
                gotoxy(1, 3);
                cout<<"1) Listar Plan Farmacologico por fecha"<<endl;
                cout<<"2) Listar Plan Farmacologico por apellido de paciente"<<endl;
                cout<<"----------------------"<<endl;
                cout<<"0) REGRESAR"<<endl;

                int opcion2;
                cout << endl << "> ";
                cin >> opcion2;

                switch(opcion2){

                case 1:
                    cout<<"Plan farmacologico para la fecha: "<<endl;
                break;
                case 2:

                default:
                    break;
                }
                break;
            break;

            case 2:
                    rlutil::cls();
                    title("PROFESIONAL - LISTADO - PACIENTE", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
                    gotoxy(1, 3);
                    cout<<"1) Listar paciente por apellido"<<endl;
                    cout<<"2) Listar paciente por DNI"<<endl;
                    cout<<"3) Listar paciente por obra social"<<endl;
                    cout<<"4) Listar paciente por n° afilidado"<<endl;
                    cout<<"----------------------"<<endl;
                    cout<<"0) REGRESAR"<<endl;
                int opcion3;
                cout << endl << "> ";
                cin >> opcion3;

                switch(opcion3){
                    case 1:
                    break;
                    case 2:
                    break;
                    case 3:
                    break;
                    case 4:
                    break;

                }
            break;

            case 3:
                rlutil::cls();
                title("PROFESIONAL - LISTADO - ESTUDIOS REALIZADOS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
                gotoxy(1, 3);
                cout<<"1) Listar estudio realizado por n° afilidado"<<endl;
                cout<<"----------------------"<<endl;
                cout<<"0) REGRESAR"<<endl;
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

void MenuProfesionalConsulta(){
    while(true){
        rlutil::cls();
        title("PROFESIONAL - CONSULTA", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);
        cout<<"1) PACIENTE"<<endl;
        cout<<"2) PLANES FARMACOLOGICOS REALIZADOS"<<endl;
        cout<<"3) ESTUDIOS REALIZADOS"<<endl;
        cout<<"4) INFORME"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"0) REGRESAR"<<endl;

        int opcion0;
        cout << endl << "> ";
        cin >> opcion0;

        switch(opcion0){
        case 1:
            rlutil::cls();
            title("PROFESIONAL - CONSULTA - PACIENTES", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
            gotoxy(1, 3);
            cout<<"1) Listar paciente por apellido"<<endl;
            cout<<"2) Listar paciente por DNI"<<endl;
            cout<<"3) Listar paciente por obra social/prepaga"<<endl;
            cout<<"4) Listar paciente por n° afilidado"<<endl;
            cout<<"5) Listar paciente por fecha"<<endl;
            cout<<"----------------------"<<endl;
            cout<<"0) REGRESAR"<<endl;
            cout << endl << "> ";
            int opcion4;
            cin >> opcion4;

            switch(opcion4){
                case 1:
                break;
                case 2:
                break;
                case 3:
                break;
                case 4:
                break;
                case 5:
                break;
            }

            break;
            case 2:
                rlutil::cls();
                title("PROFESIONAL - CONSULTA - PLANES FARMACOLOGICOS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
                gotoxy(1, 3);
                cout<<"1) Listar planes farmacologicos por apellido"<<endl;
                cout<<"2) Listar planes farmacologicos por DNI"<<endl;
                cout<<"3) Listar planes farmacologicos por obra social/prepaga"<<endl;
                cout<<"4) Listar planes farmacologicos por n° afilidado"<<endl;
                cout<<"5) Listar planes farmacologicos por fecha"<<endl;
                cout<<"----------------------"<<endl;
                cout<<"0) REGRESAR"<<endl;
                cout << endl << "> ";
                int opcion5;
                cin >> opcion5;

                switch(opcion5){
                    case 1:
                    break;
                    case 2:
                    break;
                    case 3:
                    break;
                    case 4:
                    break;
                    case 5:
                    break;
                }
            break;

            case 3:
            rlutil::cls();
                title("PROFESIONAL - CONSULTA - ESTUDIOS REALIZADOS", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
                gotoxy(1, 3);
                cout<<"1) Listar estudios realizados por apellido"<<endl;
                cout<<"2) Listar estudios realizados por DNI"<<endl;
                cout<<"3) Listar estudios realizados por obra social/prepaga"<<endl;
                cout<<"4) Listar estudios realizados por n° afilidado"<<endl;
                cout<<"5) Listar estudios realizados por fecha"<<endl;
                cout<<"----------------------"<<endl;
                cout<<"0) REGRESAR"<<endl;
                cout << endl << "> ";
                int opcion6;
                cin >> opcion6;

                switch(opcion6){
                    case 1:
                    break;
                    case 2:
                    break;
                    case 3:
                    break;
                    case 4:
                    break;
                    case 5:
                    break;
                }
            break;
            case 4:
            rlutil::cls();
            title("PROFESIONAL - CONSULTA - INFORMES", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
            gotoxy(1, 3);
            cout<<"1) Listar informes por apellido"<<endl;
            cout<<"2) Listar informes por DNI"<<endl;
            cout<<"3) Listar informes por obra social/prepaga"<<endl;
            cout<<"4) Listar informes por n° afilidado"<<endl;
            cout<<"5) Listar informes por fecha"<<endl;
            cout<<"----------------------"<<endl;
            cout<<"0) REGRESAR"<<endl;
            cout << endl << "> ";
            int opcion7;
            cin >> opcion7;

            switch(opcion7){
                case 1:
                break;
                case 2:
                break;
                case 3:
                break;
                case 4:
                break;
                case 5:
                break;
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
