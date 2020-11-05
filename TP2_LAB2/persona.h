#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include "fecha.h"
#include "registro.h"
#include "iostream"
#include "string.h"


class Persona:public Registro{
    protected:
        char  nombres[50];
        char  apellidos[50];
        char  genero;
        Fecha fecha_nacimiento;
        int   DNI;
        bool  estado;

        char user[50];
        char pass[50];
    public:
        Persona(const char *, const char *, Fecha, int);
        //GETS
        int   GetId(); //PLM
        bool  GetEstado(); //PLM
        const char *GetNombres();
        const char *GetApellidos();
        Fecha GetFechaNacimiento();
        int   GetDNI();
        char  GetGenero();

        const char *GetUser();
        const char *GetPass();
        //SETS
        void  SetIDPersona();
        void  SetNombres(const char *);
        void  SetApellidos(const char *);
        void  SetFechaNacimiento(Fecha );
        void  SetDNI(int);
        void  SetEstado(bool);
        void  SetGenero(char);

        void  ChangeUserName(const char*);
        void  ChangeUserPass(const char*);

        ~Persona(){}
};



#endif // PERSONA_H_INCLUDED
