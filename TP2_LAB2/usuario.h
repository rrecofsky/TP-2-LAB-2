#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#include "registro.h"

class Usuario {
    private:
       char user[50];
       char pass[50];
       int ID_Persona;
       int ID_Perfil; //1 - 2 - 3 o Enum
    public:
        Usuario(const char *u ,const char* p )
        {
            strcpy(user,u);
            strcpy(pass,p);
        }
        ~Usuario(){};
        //GETs
        char *GetUser(){return user;}
        char *GetPass(){return pass;}
        //SETs
        void  ChangeUserName(const char*);
        void  ChangeUserPass(const char*);
};


#endif // USUARIO_H_INCLUDED
