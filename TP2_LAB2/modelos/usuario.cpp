#include "../modelos/usuario.h"
#include <limits>
#include <iostream>
#include "../validaciones/validaciones.h"



using namespace std;

///GETs
const char * Usuario :: GetUserNamee(){return user;}
const char * Usuario :: GetUserPass(){return pass;}
Perfil       Usuario :: GetPerfilUser(){return ID_Perfil;}
int          Usuario :: GetIdPersona(){return ID_Persona;}

///SETs
void  Usuario :: ChangeUserName(const char* _user){strcpy(user,_user);}
void  Usuario :: ChangeUserPass(const char* _pass){strcpy(pass,_pass);}
void  Usuario :: ChangePerfilUser(Perfil _perfil){ID_Perfil = _perfil;}
void  Usuario :: ChangeIdPersona(int _idPersona){ID_Persona = _idPersona;}

///POLOMORFICAS

bool  Usuario :: comparaID(Registro *temp){
        Usuario *aux=(Usuario *)temp;

        if (strlen(user) > 0 && strlen(aux->user) > 0 )
            if ( strlen(user) == strlen(aux->user) && compararCadenas(user,aux->user) )
                 return true;

        if (ID_Persona != -1 && aux->ID_Persona != -1 &&
            ID_Persona == aux->ID_Persona &&
            ID_Perfil  == aux->ID_Perfil ) return true;

        if (ID==aux->ID)
            return true;
        return false;


}

int   Usuario :: getSize(){return sizeof *this;}



