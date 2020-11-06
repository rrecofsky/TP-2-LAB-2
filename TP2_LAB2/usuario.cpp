#include "usuario.h"
//

Usuario :: Usuario(const char * _user = "" ,const char* _pass = "",int _perfil = 2 )
        {
            strcpy(user,_user);
            strcpy(pass,_pass);
            ID_Perfil = _perfil;
        }

//GETs
const char *Usuario :: GetUserName(){return user;}
const char *Usuario :: GetUserPass(){return pass;}
int         Usuario :: GetPerfilUser(){return ID_Perfil;}

//SETs
void  Usuario :: ChangeUserName(const char* _user){strcpy(user,_user);}
void  Usuario :: ChangeUserPass(const char* _pass){strcpy(pass,_pass);}
void  Usuario :: ChangePerfilUser(Perfil _perfil){ID_Perfil = _perfil;}

