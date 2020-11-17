#include <iostream>
#include <string.h>
#include "../util/ui.h"
#include "../util/rlutil.h"

#include "../modelos/especialidad.h"
#include "../modelos/fecha.h"
#include "../menues/informes.h"
#include "../modelos/paciente.h"
#include "../modelos/profesional.h"
#include "../modelos/medicacion.h"
#include "../modelos/planfarmacologico.h"
#include "../modelos/registro.h"
#include "../modelos/archivo.h"
#include "../modelos/detalleplanfarmacologico.h"
#include "../menues/menuesprofesional.h"
//TEMPORAL!
#include "../menues/menuesadministrador.h"

using namespace rlutil;
using namespace std;

void MenuProfesional(){

    initUI();
    title("", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);

    while(true){
        cls();
        title("PROFESIONAL", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);

        cout<<"1) PACIENTE"<<endl;
        cout<<"2) ALTA DE PLANE FARMACOLOGICO"<<endl;
        cout<<"3) ESTUDIOS "<<endl;
        cout<<"4) INFORMES "<<endl;
        cout<<"5) MODIFICAR DATOS DE USUARIO"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"0) REGRESAR"<<endl;

        int opcion;
        cout << endl << "> ";
        cin >> opcion;

        switch(opcion){
            case 1:
                   MenuEntidad("PACIENTE");
                   break;
            case 2:
                  AltaPlanFarmacologico();
                  break;
            case 3:
                   MostrarEstudiosDelProfesional();
                   break;
            case 4:
                   MostrarInformesDelProfesional();
                   break;
            case 5:
                   ModificarDatosDeUsuarioLogueado();
                   break;
            case 0:
                   return;
            break;
        }
        cin.ignore();
    }
    return;
}

/******************* FUNCIONES BASICAS PACIENTE *************************/

void AltaPlanFarmacologico(){
    cls();
    InterfazPlanFarmacologico IPF;
    PlanFarmacologico planFarmaco;
    IPF.CargarPlanFarmacologico(planFarmaco);
    IPF.AgregarPlanFarmacologicoAArchivo(planFarmaco);
}

void MostrarPacientesDelProfesional(){
    cout<<"NO IMPLEMENTADO"<<endl;
    system("PAUSE");
    return;
}

void MostrarPlanesFarmacologicosDelProfesional(){
    cout<<"NO IMPLEMENTADO"<<endl;
    system("PAUSE");
    return;
}

void MostrarEstudiosDelProfesional(){
    cout<<"NO IMPLEMENTADO"<<endl;
    system("PAUSE");
    return;
}

void MostrarInformesDelProfesional(){
    cout<<"NO IMPLEMENTADO"<<endl;
    system("PAUSE");
    return;
}

void PlanesFarmacologicos(){

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
    return;
}


void ReportePacientes(){
    cls();
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

}

void ReportesPlanesFarmacologicos(){
        cls();
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
}

void ReportesEstudios(){
    cls();
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
}

void ReportesInformes(){
    cls();
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
}


void ModificarDatosDeUsuarioLogueado(){
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO..."<<endl;
    system("PAUSE");
    return;
    cls();
    InterfazUsuario IU;
    IU.ModificarUsuario(usr_lgd);
}
