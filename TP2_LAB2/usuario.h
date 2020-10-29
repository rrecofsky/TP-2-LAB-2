#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#include "registro.h"

class Usuario {
    private:
       char user[10];
       char pass[10];
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
        void  ChangeUserName(const char*);
        void  ChangeUserPass(const char*);
        //SETs
};


#endif // USUARIO_H_INCLUDED
