#include <iostream>
#include <string.h>
#include "../util/ui.h"
#include "../util/rlutil.h"

#include "../validaciones/validaciones.h"
#include "../menues/informes.h"
#include "../modelos/paciente.h"
#include "../modelos/planfarmacologico.h"
#include "../modelos/archivo.h"
#include "../menues/menuesprofesional.h"
#include "../interfaces/interfazentidades.h"
#include "../interfaces/interfazplanfarmacologico.h"




using namespace rlutil;
using namespace std;

void MenuProfesional(){
    initUI();
    title("", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    ValidacionesTipoDato valTDato;
    while(true){
        cls();
        title("PROFESIONAL", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);
        cout<<"1) USUARIOS"<<endl;
        cout<<"2) PACIENTES"<<endl;
        cout<<"3) PLANES FARMACOLOGICOS"<<endl;
        cout<<"4) INFORMES "<<endl;
        cout<<"5) MODIFICAR DATOS DE USUARIO"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"0) REGRESAR"<<endl;

        int opcion;
        opcion = valTDato.cargar_Entero();

        switch(opcion){
            case 1:
                   MenuGeneral("USUARIOS");
                   break;
            case 2:
                   MenuGeneral("PACIENTES");
                   break;
            case 3:
                   MenuGeneral("PLANES FARMACOLOGICOS");
                   break;
            case 4:
                   MenuGeneral("INFORMES");
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

/******************* MENU GENERAL **************************************/

void MenuGeneral(const char * _objeto)
{
    ValidacionesTipoDato valTDato;
    while(true)
    {
        cls();
        title(_objeto, APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);
        cout<<"1) ALTA"<<endl;
        cout<<"2) MODIFICAR"<<endl;
        cout<<"3) LISTAR"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"0) REGRESAR"<<endl;

        int opcion;
        opcion = valTDato.cargar_Entero();

        switch(opcion)
        {
            case 1: if(strcmp("PACIENTES",_objeto) == 0)
                            AltaPacienteDelProfesional();
                        else
                            if(strcmp("USUARIOS",_objeto) == 0)
                                AltaDeUsuariosPaciente();
                            else
                                if(strcmp("PLANES FARMACOLOGICOS",_objeto) == 0)
                                    AltaPlanFarmacologico();
                                else
                                    if(strcmp("INFORMES",_objeto) == 0)
                                        AltaDeInformes();
                    break;
            case 2:
                    if(strcmp("PACIENTES",_objeto) == 0)
                            ModificarPacienteDelProfesional();
                        else
                            if(strcmp("USUARIOS",_objeto) == 0){
                                cout<<"NO ES POSIBLE MODIFICAR LOS USUARIOS DADOS DE ALTA"<<endl<<endl;
                                system("PAUSE");
                            }
                            else
                                if(strcmp("PLANES FARMACOLOGICOS",_objeto) == 0)
                                    AltaPlanFarmacologico();
                                else
                                    if(strcmp("INFORMES",_objeto) == 0)
                                        AltaDeInformes();
                    break;
            case 3:
                    if(strcmp("PACIENTES",_objeto) == 0)
                            MostrarPacientesDelProfesional(); ///SE DEBEN VER SUS PACIENTES!
                        else
                            if(strcmp("USUARIOS",_objeto) == 0){
                                MostrarUsuariosPaciente();
                            }
                            else
                                if(strcmp("PLANES FARMACOLOGICOS",_objeto) == 0)
                                    MostrarPlanesFarmacologicosDelProfesional();
                                else
                                    if(strcmp("INFORMES",_objeto) == 0)
                                        MostrarInformesDelProfesional();
            case 0:
                    return;
            break;
        }
        cin.ignore();
    }
    return ;
}

/******************* FUNCIONES BASICAS PACIENTE *************************/

void AltaPacienteDelProfesional(){
    cls();
    InterfazPaciente IP;
    Paciente paciente;
    if (IP.CargarPaciente(paciente))
        IP.AgregarPacienteAArchivo(paciente);
    return;
}

void MostrarPacientesDelProfesional(){
    system("cls");
    InterfazPaciente IP;
    IP.ListarPacientes();
}

void ModificarPacienteDelProfesional(){
    system("cls");
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO..."<<endl;
    system("PAUSE");
    return;

    ValidacionesTipoDato valTipoDato;
    ValidacionesGenerales valGeneral;
    InterfazPaciente IP;
    Paciente pac;
    cout<<"DESEA VER LA LISTA DE PACIENTES? S/N"<<endl;
    if (valGeneral.leer_SoN()) IP.ListarPacientes();
    cls();
    cout<<"INGRESE EL ID DEL PACIENTE QUE DESEA MODIFICAR: ";
    pac.SetId(valTipoDato.cargar_Entero());
    cls();
    IP.ModificarPacienteEnArchivo(pac);
}

/******************* MENUES PLAN FARMA *****************************/

void AltaPlanFarmacologico(){
    system("cls");
    InterfazPlanFarmacologico IPF;
    PlanFarmacologico planFarmaco;
    if (IPF.CargarPlanFarmacologico(planFarmaco))
        IPF.AgregarPlanFarmacologicoAArchivo(planFarmaco);
    return;
}

void MostrarPlanesFarmacologicosDelProfesional(){
    system("cls");
    InterfazPlanFarmacologico IPF;
    IPF.ListarPlanesFarmacologicos();
    return;
}

/********************** ESTUDIOS ********************/
void MostrarEstudiosDelProfesional(){
    system("cls");
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO..."<<endl;
    system("PAUSE");
    return;
}

/******************** INFORMES ***********************/
void MostrarInformesDelProfesional(){
    system("cls");
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO..."<<endl;
    system("PAUSE");
    return;
}

void AltaDeInformes(){
    system("cls");
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO..."<<endl;
    system("PAUSE");
    return;
};

/********************* DATOS DEL USUARIO *****************/
void ModificarDatosDeUsuarioLogueado(){
    system("cls");
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO..."<<endl;
    system("PAUSE");
    return;
    cls();
    InterfazUsuario IU;
    IU.ModificarUsuario(usr_lgd);
}

/********************* USUARIOS *********************/

void AltaDeUsuariosPaciente(){
    cls();
    InterfazUsuario IU;
    Usuario usr;
    if (IU.CargarUsuario(usr))
        IU.AgregarUsuarioAArchivo(usr);
    return;
}

void MostrarUsuariosPaciente(){
    cls();
    InterfazUsuario IU;
    IU.ListarUsuarios();
}


































































































































































































































/// POSBILES REPORTES
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



