#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include <cstring>
#include <iostream>

using namespace std;

enum Perfil{//MODOS DE APERTURA DE UN ARCHIVO
   Admin, // 0
   Profesional, // 1
   Paciente // 2
};

class Usuario {
    private:
       char user[50];
       char pass[50];
       int ID_Persona;
       int ID_Perfil;
    public:
        ///Constructor
        Usuario(const char * ,const char*,int);
        ///GETs
        const char* GetUserName();
        const char* GetUserPass();
        int   GetPerfilUser();
        ///SETs
        void  ChangeUserName(const char*);
        void  ChangeUserPass(const char*);
        void  ChangePerfilUser(Perfil _perfil);
        ///Destructor
        ~Usuario(){};
};


#endif // USUARIO_H_INCLUDED
