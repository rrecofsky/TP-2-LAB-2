#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include <cstring>
#include <iostream>
#include "registro.h"

using namespace std;

enum Perfil{//MODOS DE APERTURA DE UN ARCHIVO
   Admin, // 0
   Profesional, // 1
   Paciente // 2
};

class Usuario :public Registro {
    private:
       char user[50];
       char pass[50];
       int ID_Persona;
       int ID_Perfil;
    public:
        ///Constructor
        Usuario(const char * _user = "" ,const char* _pass = "",int _perfil = 2 ):Registro()
        {
            strcpy(user,_user);
            strcpy(pass,_pass);
            ID_Perfil = _perfil;
        }
        ///GETs
        const char* GetUserName();
        const char* GetUserPass();
        int   GetPerfilUser();
        ///SETs
        void  ChangeUserName(const char*);
        void  ChangeUserPass(const char*);
        void  ChangePerfilUser(Perfil _perfil);
        /// POLIMORFICAS
        void Cargar();
        void Mostrar();
        int getSize();

        Usuario& operator = (Registro *temp){
            Usuario *aux=(Usuario *)temp;
            strcpy(this->user,aux->user);
            strcpy(this->pass, aux->pass);
            ID_Persona = aux->ID_Persona;
            estado     = aux->estado;
            ID         = aux->ID;
            fechaAlta  = aux->fechaAlta;
            fechaBaja  = aux->fechaBaja;
            }
        bool comparaID(Registro *temp);
        ///Destructor
        ~Usuario(){};
};


#endif // USUARIO_H_INCLUDED
