#include <iostream>
#include <cstring>
#include "../menues/menuesadministrador.h"
#include "../menues/menuespaciente.h"
#include "../menues/menuesprofesional.h"
#include "../menues/login.h"
#include "../validaciones/validaciones.h"
#include "../modelos/archivo.h"
#include "../util/rlutil.h"
#include "../login/logo.h"
#include "../modelos/usuario.h"

using namespace    rlutil;
extern const char *FILE_PACIENTES;
extern const char *FILE_PROFESIONALES;
extern const char *FILE_USUARIOS;

const char *user_adm = "admin";
const char *pass_adm = "admin";
Usuario     usr_lgd(user_adm,pass_adm,Perfil_Administrador);

using namespace std;

void MenuLogin()
{
    // ------------> TEMPORAL
 //   MenuAdministrador();
 //   return;
    //  ------------> TEMPORAL
    Logo();

    Archivo archUsuarios(FILE_USUARIOS,sizeof(Usuario));
    Perfil  tipoDeUsuario=Perfil_Paciente;
    ValidacionesGenerales validacionLogin;
    char user[50], pass[50];
    bool  salir=false;
    Usuario usrAxuLogin; //Se usa para copiar en el objeto, el registro del archivo.

    cout << "                   INGRESE EL PERFIL DEL USUARIO:"<<endl<<endl;
    cout << "                        0 - Administrador"<<endl;
    cout << "                        1 - Profesional"<<endl;
    cout << "                        2 - Paciente"<<endl;


        tipoDeUsuario = validacionLogin.ValidarPerfilDeUsuario();

    cls();
    cin.clear();
    cin.ignore();
    cout << "INGRESE UN USUARIO: ";
    cout << endl << "> ";
    cin.getline(user,50);
    cout << "INGRESE UNA CONTRASENIA: ";
    cout << endl << "> ";
    cin.getline(pass,50);

    do{
        if (tipoDeUsuario == usr_lgd.GetPerfilUser() &&
             strcmp(user,usr_lgd.GetUserNamee()) == 0 &&
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
                    archUsuarios.leerRegistro(usrAxuLogin, posUserLdg);
                    if (  strcmp(usrAxuLogin.GetUserNamee(),user) == 0 && strcmp(usrAxuLogin.GetUserPass(),pass) == 0 ){
                       if ( usrAxuLogin.GetPerfilUser() == Perfil_Profesional && tipoDeUsuario == Perfil_Profesional){
                                usr_lgd = usrAxuLogin;
                                MenuProfesional();
                                return;
                        }
                        else
                            if ( usrAxuLogin.GetPerfilUser() == Perfil_Paciente && tipoDeUsuario == Perfil_Paciente) {
                                usr_lgd = usrAxuLogin;
                                MenuPaciente();
                                return;
                            }
                    }
                }
        cout<<"USUARIO O CONTRASENIA INCORRECTOS. DESEA SALIR? S - N"<<endl;
        salir = validacionLogin.leer_SoN();
        cls();
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


