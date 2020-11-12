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
#include "interfaz.h"

extern const char *FILE_PACIENTES;
extern const char *FILE_PROFESIONALES;
extern const char *FILE_USUARIOS;

const char *user_adm = "admin";
const char *pass_adm = "admin";
Usuario     usr_lgd(user_adm,pass_adm,Perfil_Administrador);

using namespace std;

void MenuLogin()
{
    Archivo archUsuarios(FILE_USUARIOS,sizeof(Usuario));
    int  tipoDeUsuario=2;
    ValidacionesGenerales validacionLogin;
    char user[50], pass[50];
    bool  salir=false;
    Usuario usrAxuLogin; //Se usa para copiar en el objeto, el registro del archivo.

    cout << "INGRESE EL PERFIL DEL USUARIO:"<<endl<<endl;
    cout << "0 - Administrador"<<endl;
    cout << "1 - Profesional"<<endl;
    cout << "2 - Paciente"<<endl;


        tipoDeUsuario = validacionLogin.ValidarPerfilDeUsuario();

    cout << "INGRESE UN USUARIO: ";
    cout << endl << "> ";
    cin  >> user;
    cout << "INGRESE UNA CONTRASENIA: ";
    cout << endl << "> ";
    cin  >> pass;

    do{
        if (tipoDeUsuario == usr_lgd.GetPerfilUser() &&
             strcmp(user,usr_lgd.GetUserName()) == 0 &&
             strcmp(pass,usr_lgd.GetUserPass()) == 0  )
            { //si es ADMIN
               MenuAdministrador();
               return;
            }
            else{
                    //cambio de forma temporal el user del reg de usuario
                    usrAxuLogin.ChangeUserName(user);
                    //Cambio el paciente encontrado en el registro
                    int posUserLdg = archUsuarios.buscarRegistro(usrAxuLogin);
                    if ( archUsuarios.leerRegistro(usrAxuLogin, posUserLdg) != -1 && strcmp(usrAxuLogin.GetUserPass(),pass) == 0 )
                        if (usrAxuLogin.GetPerfilUser() == Perfil_Profesional){
                                usr_lgd = usrAxuLogin;
                                MenuProfesional();
                                return;
                        }
                        else{
                                usr_lgd = usrAxuLogin;
                                MenuPaciente();
                                return;
                            }
                }
        cout<<"USUARIO O CONTRASENIA INCORRECTOS. DESEA SALIR? S - N"<<endl;
        salir = validacionLogin.leer_SoN();
        if (!salir){
            cout << "INGRESE UN USUARIO: ";
            cin.clear(); // unset failbit
            cin.ignore(); // skip bad input
            cout << endl << "> ";
            cin.getline(user,50);
            cout << "INGRESE UNA CONTRASENIA: ";
            cout << endl << "> ";
            cin.getline(pass,50);
        }else return;
    }
    while(true);

    return;
}

/*

{
//USO DE POLIMORFISMO PARA DEJAR EN REGISTRO UNA COPIA DEL ENCONTRADO EN EL ARCHIVO

        //cambio de forma temporal el user del reg paciente, para buscarlo por comparacion con el usuario
        pacienteSistema.ChangeUserName(user);
        //Cambio el paciente encontrado en el registro
        posPaciente = archPacientes.buscarRegistro(pacienteSistema);
        MenuProfesional();

    }
    if ( archPacientes.leerRegistro(pacienteSistema, posPaciente) != -1 && strcmp(pacienteSistema.GetPass(),pass) == 0 )
    {   //si es paciente y coincide la clave ingresada con la que posee el registro --> OK
        MenuPaciente();
        return;
    }

*/

