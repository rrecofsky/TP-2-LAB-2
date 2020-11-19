#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include <cstring>
#include "../modelos/registro.h"


using namespace std;

enum Perfil{//perfiles de usuario
   Perfil_Administrador, // 0
   Perfil_Profesional, // 1
   Perfil_Paciente, // 2
};

class Usuario :public Registro {
    private:
       char user[50];
       char pass[50];
       int ID_Persona;
       Perfil ID_Perfil;
    public:
        ///Constructor
        Usuario(const char * _user = "" ,const char* _pass = "",Perfil _perfil = Perfil_Paciente ):Registro()
        {
            strcpy(user,_user);
            strcpy(pass,_pass);
            ID_Perfil = _perfil;
            ID_Persona = -1;
        }
        ///GETs
        const char* GetUserNamee();
        const char* GetUserPass();
        Perfil   GetPerfilUser();
        int   GetIdPersona();
        ///SETs
        void  ChangeUserName(const char*);
        void  ChangeUserPass(const char*);
        void  ChangePerfilUser(Perfil _perfil);
        void  ChangeIdPersona(int);
       // void  ChangeUserOwnerId(int ow){userOwner = -1;};
        /// POLIMORFICAS
        void Cargar();
        void Mostrar();
        int getSize();
        void Modificar();

        Usuario& operator = (Registro *temp){
            Usuario *aux=(Usuario *)temp;
            strcpy(this->user,aux->user);
            strcpy(this->pass, aux->pass);
            ID_Persona = aux->ID_Persona;
            estado     = aux->estado;
            ID         = aux->ID;
            fechaAlta  = aux->fechaAlta;
            fechaBaja  = aux->fechaBaja;
            ID_Perfil  = aux->ID_Perfil;
            }
        bool comparaID(Registro *temp);
        ///Destructor
        ~Usuario(){};
};

extern Usuario usr_lgd;

#endif // USUARIO_H_INCLUDED
