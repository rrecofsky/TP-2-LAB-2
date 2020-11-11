#include "iostream"
#include "string.h"
#include "ui.h"
#include "rlutil.h"

#include "especialidad.h"
#include "archivo.h"
#include "fecha.h"
#include "informes.h"
#include "paciente.h"
#include "profesional.h"
#include "medicacion.h"
#include "menuesadministrador.h"
#include "validaciones.h"

using namespace std;
using namespace rlutil;

extern const char *FILE_PACIENTES;
extern const char *FILE_PROFESIONALES;

void MenuAdministrador()
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

        switch(opcion)
        {
            case 1: strcmp("PROFESIONAL",entidad) == 0 ? AltaProfesional() : AltaPaciente();
                    break;
            case 2:
                    strcmp("PROFESIONAL",entidad) == 0 ? ModificarProfesional() : ModificarPaciente();
                    break;
            case 3:
                    strcmp("PROFESIONAL",entidad) == 0 ? BajaProfesional() : BajaPaciente();
                    break;
            case 4:
                    strcmp("PROFESIONAL",entidad) == 0 ? MostrarProfesionales() : MostrarPacientes();
                    system("PAUSE");
                    break;
            case 5:
                    strcmp("PROFESIONAL",entidad) == 0 ? ConsultaProfesional() : ConsultaPaciente();
                    break;
            case 0:
                    return;
            break;
        }
        cin.ignore();
    }
    return ;
}

/******************* FUNCIONES BASICAS PROFESIONAL *************************/

void AltaProfesional()
{
    Archivo profesionales(FILE_PROFESIONALES,sizeof(Profesional));
    Profesional prof;
    prof.Cargar();
    //damos de alta un nuevo profesional, por ello utiliza -1
    if(profesionales.grabarRegistro(prof,-1) == 1)
        cout<<"SE GRABO SATISFACTORIAMENTE EL PROFESIONAL CARGADO"<<endl;
    else
        cout<<"NO SE PUDO GRABAR SATISFACTORIAMENTE EL PROFESIONAL CARGADO"<<endl;
    anykey();
}

void MostrarProfesionales()
{
    Archivo profesionales(FILE_PROFESIONALES,sizeof(Profesional));
    Profesional prof;
    if(!profesionales.listarArchivo(prof)){
        cout<<"NO HAY REGISTROS PARA LISTAR"<<endl;
        anykey();
        system("cls");
    }
}

void ModificarProfesional(){
    ValidacionesGenerales validaciones;
    Archivo profesionales(FILE_PROFESIONALES,sizeof(Profesional));
    Profesional prof;
    char rta;
    int idProfesional;
    cout<<"DESEA VER LA LISTA DE PROFESIONALES? S/N"<<endl;
    rta = validaciones.leer_SoN();
         if (rta) MostrarProfesionales();
    cout<<"INGRESE EL ID DEL PROFESIONAL: ";
    cout << endl << "> ";
    cin>>idProfesional;
    prof.SetId(idProfesional);
    int posProf = profesionales.buscarRegistro(prof);
    if ( profesionales.leerRegistro(prof, posProf) != -1){ //si encontro el profesional
        prof.Modificar();
        if(profesionales.grabarRegistro(prof,posProf) == 1)
            cout<<"SE ACTUALIZO SATISFACTORIAMENTE EL PROFESIONAL CARGADO"<<endl;
        else
            cout<<"NO SE PUDO ACTUALIZAR SATISFACTORIAMENTE EL PROFESIONAL CARGADO"<<endl;
        anykey();
        return;
    }
}

void BajaProfesional(){
    return;
}

void ConsultaProfesional(){
    return;
}

/******************* FUNCIONES BASICAS PACIENTE *************************/

void AltaPaciente(){
    Archivo pacientes(FILE_PACIENTES,sizeof(Paciente));
    Paciente pac;
    pac.Cargar();
    //damos de alta un nuevo paciente, por ello utiliza -1
    if(pacientes.grabarRegistro(pac,-1) == 1)
        cout<<"SE GRABO SATISFACTORIAMENTE EL PROFESIONAL CARGADO"<<endl;
    else
        cout<<"NO SE PUDO GRABAR SATISFACTORIAMENTE EL PROFESIONAL CARGADO"<<endl;
    anykey();
}

void MostrarPacientes()
{
    Archivo pacientes(FILE_PACIENTES,sizeof(Paciente));
    Paciente pac;
    if(!pacientes.listarArchivo(pac)){
        cout<<"NO HAY REGISTROS PARA LISTAR"<<endl;
        anykey();
        system("cls");
    }
}

void ModificarPaciente(){
    return;
}

void BajaPaciente(){
    return;
}

void ConsultaPaciente(){
    return;
}
