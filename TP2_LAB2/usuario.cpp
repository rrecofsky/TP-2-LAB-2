#include "usuario.h"
#include <limits>
#include <iostream>

#include "interfaz.h"



using namespace std;

///GETs
const char * Usuario :: GetUserNamee(){return user;}
const char * Usuario :: GetUserPass(){return pass;}
int          Usuario :: GetPerfilUser(){return ID_Perfil;}
int          Usuario :: GetIdPersona(){return ID_Persona;}

///SETs
void  Usuario :: ChangeUserName(const char* _user){strcpy(user,_user);}
void  Usuario :: ChangeUserPass(const char* _pass){strcpy(pass,_pass);}
void  Usuario :: ChangePerfilUser(Perfil _perfil){ID_Perfil = _perfil;}
void  Usuario :: ChangeIdPersona(int _idPersona){ID_Persona = _idPersona;}

///POLOMORFICAS

void Usuario ::Cargar(){return;}
void Usuario ::Mostrar(){ //TEMPORAL, HASTA QUE HAGA POLIMORFISMO CON LAS INTERFASES

    cout << left;

    if (usr_lgd.ID_Perfil == Perfil_Administrador){
        cout << setw(4)  << ID;
        cout << setw(12)  << pass;
    }
    cout << setw(12)  << user;
    if (ID_Perfil  == Perfil_Profesional )
        cout << setw(12)  << "PROFESIONAL";
    else
        cout << setw(12)  << "PACIENTE";
    Persona persona;
    InterfazPersona interPersona;
    interPersona.AsociarPersona(persona);
    cout << setw(6)  << persona.GetNombres();
    cout << setw(6)  << persona.GetApellidos();
    cout<<endl;

}

void Usuario ::Modificar(){return;}

bool  Usuario :: comparaID(Registro *temp){
        Usuario *aux=(Usuario *)temp;
        if(ID==aux->ID || strcmp(user,aux->user) == 0) return true;
        return false;
}

int   Usuario :: getSize(){return sizeof *this;}



