#include "interfaz.h"
#include <limits>
#include <iostream>
#include "usuario.h"


extern Usuario usr_lgd;


using namespace std;

/// InterfazUsuario

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

