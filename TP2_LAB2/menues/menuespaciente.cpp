#include <iostream>
#include <string.h>
#include "../util/ui.h"
#include "../util/rlutil.h"
#include "../modelos/profesional.h"
#include "../modelos/planfarmacologico.h"
#include "../modelos/detalleplanfarmacologico.h"
#include "../menues/menuespaciente.h"
#include "../validaciones/validaciones.h"

using namespace std;
using namespace rlutil;

void MenuPaciente(){
    initUI();
    ValidacionesTipoDato valTDato;
    title("PACIENTE", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    while(true){
        cls();
        title("MENU PRINCIPAL", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);
        cout<<"1) PLAN FARMACOLOGICO"<<endl;
        cout<<"2) PROFESIONALES"<<endl;
        cout<<"3) MODIFICAR DATOS DE USUARIO"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"0) REGRESAR"<<endl;

        int opcion;
        opcion = valTDato.cargar_Entero();

        switch(opcion){
            case 1: MostrarPlanesFarmacologicosDelPaciente();
            break;
            case 2: MostrarProfesionalesDelPaciente();
            break;
            case 3: ModificarUsuarioPaciente();
            case 0:
                    return;
            break;
        }
        cin.ignore();
    }
    return ;
}

void MostrarPlanesFarmacologicosDelPaciente(){
    cls();
    InterfazPlanFarmacologico IPF;
    IPF.ListarPlanesFarmacologicos();
    return;
}

void MostrarProfesionalesDelPaciente(){

    cls();
    InterfazProfesional IP;
    IP.ListarProfesionales();
}

void ModificarUsuarioPaciente(){
    cls();
    InterfazUsuario IU;
    IU.ModificarUsuario(usr_lgd);
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
