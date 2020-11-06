#include <iostream>
#include <cstring>
#include "menuesadministrador.h"
#include "menuespaciente.h"
#include "menuesprofesional.h"
#include "login.h"
#include "usuario.h"
#include "validaciones.h"

#include "archivo.h"
#include "paciente.h"
#include "profesional.h"

extern const char *FILE_PACIENTES;
extern const char *FILE_PROFESIONALES;
const char *user_adm = "admin";
const char *pass_adm = "admin";
Usuario     usr_lgd(user_adm,pass_adm,Admin);

using namespace std;

void MenuLogin()
{
    /*

    int posPaciente=0;
    int posProfesional=0;
    Archivo archPacientes(FILE_PACIENTES,sizeof(Paciente));
    Paciente pacienteSistema;
    Archivo archProfesional(FILE_PROFESIONALES,sizeof(Profesional));
    Profesional profesionalSistema;
    */
    int  tipoDeUsuario=2;
    ValidacionesGenerales validacionLogin;
    char user[50], pass[50];
    int  salir= 0;

    cout << "INGRESE EL PERFIL DEL USUARIO:"<<endl<<endl;
    cout << "0 - Administrador"<<endl;
    cout << "1 - Profesional"<<endl;
    cout << "2 - Paciente"<<endl;

    tipoDeUsuario = validacionLogin.ValidarPerfilDeUsuario();

    cout << "Ingrese un usuario: ";
    cin  >> user;
    cout << "Ingrese su contrasenia: ";
    cin  >> pass;

    do{
        if (tipoDeUsuario == usr_lgd.GetPerfilUser() &&
             strcmp(user,usr_lgd.GetUserName()) == 0 &&
             strcmp(pass,usr_lgd.GetUserPass()) == 0  )
            { //si es ADMIN
               MenuAdministrador();
               return;
            }/*
                else
                 {
                     //cambio de forma temporal el user del reg paciente, para buscarlo por comparacion con el usuario
                     pacienteSistema.ChangeUserName(user);
                     //Cambio el paciente encontrado en el registro
                     posPaciente = archPacientes.buscarRegistro(pacienteSistema);
                     MenuProfesional();

                 }
                 if ( archPacientes.leerRegistro(pacienteSistema, posPaciente) != -1 && strcmp(pacienteSistema.GetPass(),pass) == 0 )
                  { //si es paciente y coincide la clave ingresada con la que posee el registro --> OK
                      MenuPaciente();
                      return;
                  }
                  else{
                        //cambio de forma temporal el user del reg profesional, para buscarlo por comparacion con el usuario
                        profesionalSistema.ChangeUserName(user);
                        //Cambio el profesional encontrado en el registro
                         posProfesional = archPacientes.buscarRegistro(profesionalSistema);
                      }
                    if (archProfesional.leerRegistro(profesionalSistema, posProfesional) == 1 && strcmp(profesionalSistema.GetPass(),pass) == 0)
                    {//si es profesional y coincide la clave imgresada con la del registro
                        MenuProfesional();
                        return;
                    }
                    */
        cout<<"Usuario o password incorrectos, 1 -> volver intentar - 0 -> salir";
        cin>>salir;
        if (salir != 0){
            cout<<"Ingrese un usuario: ";
            cin>>user;
            cout<<"Ingrese su contrasenia: ";
            cin>>pass;
        }else return;

    }
    while(true);

    return;
}

