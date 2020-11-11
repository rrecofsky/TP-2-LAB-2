#include "interfaz.h"
#include <limits>
#include <iostream>
#include "usuario.h"
#include "archivo.h"
#include "validaciones.h"

extern const char *FILE_USUARIOS;
extern const char *FILE_PACIENTES;
extern const char *FILE_PROFESIONALES;
extern Usuario usr_lgd;


using namespace std;

/// INTERFAZ USUARIO

void  InterfazUsuario :: Mostrar(){

        cout<<"USER: "<<usr_lgd.GetUserName()<<endl;
        cout<<"PASS: "<<usr_lgd.GetUserPass()<<endl;
        cout<<strcat("PERFIL: ",usr_lgd.GetPerfilUser() == 1 ? "PROFESIONAL" : "PACIENTE")<<endl;
        cout<<"USUARIO RELACIONADO: "<<"##DESARRROLLAR##"<<endl;
        if (usr_lgd.GetPerfilUser()==Perfil_Administrador){
            cout<<"FECHA DE ALTA: "<<usr_lgd.GetFechaAlta().GetFechaConFormato()<<endl;
            cout<<"FECHA DE BAJA: "<<usr_lgd.GetFechaBaja().GetFechaConFormato()<<endl;
            cout<<strcat("ESTADO: ",usr_lgd.GetEstado() == true ? "ACTIVO" : "INAVTIVO")<<endl;
            cout<<"ID: "<<usr_lgd.GetId()<<endl;
        }
        getchar();
        return;
}

void  InterfazUsuario :: Cargar()
{
        char usr[50], pas[50];
        cout<<"USER: ";
        cin.clear(); // unset failbit
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); // skip bad input
        cin.getline(usr,50);
        usr_lgd.ChangeUserName(usr);
        cout<<endl;
        cout<<"PASS: ";
        cin.getline(pas,50);
        usr_lgd.ChangeUserPass(pas);
        cout<<"FALTA RELACIONAR A UN USUARIO"<<endl;
}

void InterfazUsuario :: CambiarPasswrd(){
        char usr[50], pas[50];
        cout<<"NUEVO USUARIO ";
        cin.clear(); // unset failbit
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); // skip bad input
        cin.getline(usr,50);
        usr_lgd.ChangeUserName(usr);
        cout<<endl;
        cout<<"NUEVA CONTRASENIA: ";
        cin.getline(pas,50);
        usr_lgd.ChangeUserPass(pas);
}

void  InterfazUsuario :: BajaDeUsuario(){
//Se da de baja el usuario, y a la Persona relacionada
/*
       Archivo archUsuarios(FILE_USUARIOS,sizeof(Usuario));
       ValidacionesGenerales validaciones;
       Usuario usrAux;
       char salir;
       char usrName[50];//var aux
       int tipoDeUsuario=-1; //tipo de usuario que se desea dar de baja
       do{
            cout << "INGRESE EL PERFIL DEL USUARIO QUE DESEA DESHABILITAR:"<<endl<<endl;
            cout << "1 - Profesional"<<endl;
            cout << "2 - Paciente"<<endl;

            tipoDeUsuario = validaciones.ValidarPerfilDeUsuario();

            cout << "INGRESE UN USUARIO: ";
            cout << endl << "> ";
            cin.getline(usrName,50);
            usrAux.ChangeUserName(usrName);
            int posUser = archUsuarios.buscarRegistro(usrAux);

            if ( archUsuarios.leerRegistro(usrAux, posUser) != -1)
                if(tipoDeUsuario == Perfil_Profesional){
                    Archivo archProfesionales(FILE_PROFESIONALES,sizeof(Usuario));
                    int posProfesional = archProfesionales.buscarRegistro(usrAux.GetId());


                }else
                    if(tipoDeUsuario == Perfil_Paciente){
                    Archivo archPacientes(FILE_PACIENTES,sizeof(Usuario));

                    }
            else{
                cout<<"NO SE ENCONTRO EL USUARIO: "<<usrName<<", DESEA VOLVER A CARGAR? S/N"<<endl;
                salir = validaciones.leer_SoN();
                if (salir) return;
                }
       }while(true);
    return;
    */
}

