#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

#include "../headers/registro.h"

class Usuario:public Usuario{
    private:
       char user[10];
       char pass[10];
    public:
        Usuario(const char *u,const char* p)
        {
            strcpy(user,u);
            strcpy(pass,p);
        }
        ~Usuario(){};
        //GETs
        char *GetUser();
        char *GetPass();
        void  ChangeUserName(const *char);
        void  ChangeUserPass(const *char);
};


#endif // USUARIO_H_INCLUDED
