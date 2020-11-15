#include <iostream>
#include <cstring>
#include "../util/ui.h"
#include "../util/rlutil.h"

#include "../modelos/especialidad.h"
#include "../modelos/archivo.h"
#include "../modelos/fecha.h"
#include "../menues/informes.h"
#include "../modelos/paciente.h"
#include "../modelos/profesional.h"
#include "../modelos/medicacion.h"
#include "../menues/menuesadministrador.h"
#include "../validaciones/validaciones.h"
#include "../interfaces/interfazentidades.h"

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
        cout<<"3) USUARIOS"<<endl;
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
                    MenuEntidad("USUARIO");
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

void MenuEntidad(const char * entidad)
{
    while(true)
    {
        cls();
        title(entidad, APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);
        cout<<"1) ALTA"<<endl;
        cout<<"2) MODIFICAR"<<endl;
        cout<<"3) LISTAR"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"0) REGRESAR"<<endl;

        int opcion;
        cout << endl << "> ";
        cin >> opcion;

        switch(opcion)
        {
            case 1: if (strcmp("PROFESIONAL",entidad) == 0)
                        AltaProfesional();
                    else
                        if(strcmp("PACIENTE",entidad) == 0)
                            AltaPaciente();
                        else
                            AltaUsuario();
                    break;
            case 2:
                    if (strcmp("PROFESIONAL",entidad) == 0)
                        ModificarProfesional();
                    else
                        if(strcmp("PACIENTE",entidad) == 0)
                            ModificarPaciente();
                        else
                            ModificarUsuario();
                    break;
            case 3:
                    if (strcmp("PROFESIONAL",entidad) == 0)
                        MostrarProfesionales();
                    else
                        if(strcmp("PACIENTE",entidad) == 0)
                            MostrarPacientes();
                        else
                            MostrarUsuarios();
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

void AltaProfesional(){
    cls();
    InterfazProfesional IP;
    Profesional prof;
    if (IP.CargarProfesional(prof))
        IP.AgregarAArchivo(prof);
    return;
}

void MostrarProfesionales()
{
    cls();
    InterfazProfesional IP;
    IP.ListarProfesionales();
}

void ModificarProfesional(){

    cls();
    ValidacionesTipoDato valTipoDato;
    ValidacionesGenerales valGeneral;
    InterfazProfesional IP;
    Profesional prof;
    cout<<"DESEA VER LA LISTA DE PROFESIONALES? S/N"<<endl;
    if (valGeneral.leer_SoN()) IP.ListarProfesionales();
    cout<<"INGRESE EL ID DEL PROFESIONAL QUE DESEA MODIFICAR: ";
    prof.SetId(valTipoDato.cargar_Entero());
    IP.ModificarEnArchivo(prof);
}

/******************* FUNCIONES BASICAS USUARIO  *************************/

void AltaUsuario(){
    cls();
    InterfazUsuario IU;
    Usuario usr;
    if (IU.CargarUsuario(usr))
        IU.AgregarUsuarioAArchivo(usr);
    return;
}

void MostrarUsuarios(){
    cls();
    InterfazUsuario IU;
    IU.ListarUsuarios();
}

void ModificarUsuario(){
    //a desarrollar
}


/******************* FUNCIONES BASICAS PACIENTE *************************/

void AltaPaciente(){
    cls();
    InterfazPaciente IP;
    Paciente paciente;
    if (IP.CargarPaciente(paciente))
        IP.AgregarPacienteAArchivo(paciente);
    return;
}


void MostrarPacientes(){
    cls();
    InterfazPaciente IP;
    IP.ListarPacientes();
}

void ModificarPaciente(){
    cls();
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
