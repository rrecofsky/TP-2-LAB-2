#include <iostream>
#include <typeinfo>
#include <string.h>
#include "menuesadministrador.h"
#include "menuespaciente.h"
#include "menuesprofesional.h"
#include "paciente.h"
#include "profesional.h"
#include "archivo.h"
#include "login.h"

extern const char *FILE_PACIENTES;
extern const char *FILE_PROFESIONALES;

using namespace std;

void MenuLogin(const char* usr,const char* pas)
{
    char user[50], pass[50];
    int  salir= 0;
    int posPaciente=0;
    int posProfesional=0;
    Archivo archPacientes(FILE_PACIENTES,sizeof(Paciente));
    Paciente pacienteSistema;
    Archivo archProfesional(FILE_PROFESIONALES,sizeof(Profesional));
    Profesional profesionalSistema;

    cout<<"Ingrese un usuario: ";
    cin>>user;
    cout<<"Ingrese su contrasenia: ";
    cin>>pass;

     //NO ANDA EL PASAJE POR REFERENCIA
    //NoAnda(user);

    do{
        if (strcmp(usr,user) == 0 && strcmp(pass,pas)  ==  0)
        { //si es ADMIN
           MenuAdministrador();
           return;
        }else
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

void NoAnda(const char* user){

    Archivo archProfesional(FILE_PROFESIONALES,sizeof(Profesional));
    Profesional profesionalSistema;
    //cambio de forma temporal el user del reg profesional, para buscarlo por comparacion con el usuario
    profesionalSistema.ChangeUserName(user);
    int posProfesional = archProfesional.buscarRegistro(profesionalSistema);
    int regLeido = archProfesional.leerRegistro(profesionalSistema, posProfesional);
    cout<<"PASS p: "<<profesionalSistema.GetPass()<<endl;
    cout<<"USER p: "<<profesionalSistema.GetUser()<<endl;
    cout<<"NOMBRES: "<<profesionalSistema.GetDNI()<<endl;
    cout<<"NOMBRES: "<<profesionalSistema.GetGenero()<<endl;
    cout<<"Posicion de postProf: "<<posProfesional<<endl;
    cout<<"regLeido: 1-->SI "<<regLeido<<endl;
    system("PAUSE");

}
