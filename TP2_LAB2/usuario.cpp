#include "usuario.h"
#include <limits>
#include <iostream>

using namespace std;

///GETs
const char * Usuario :: GetUserName(){return user;}
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
void Usuario ::Mostrar(){return;}
void Usuario ::Modificar(){return;}

bool  Usuario :: comparaID(Registro *temp){
        Usuario *aux=(Usuario *)temp;
        if(ID==aux->ID || strcmp(user,aux->user) == 0) return true;
        return false;
}

int   Usuario :: getSize(){return sizeof *this;}



