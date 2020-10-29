#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include "Fecha.h"
#include "Registro.h"
#include "iostream"
#include "string.h"


class Persona:public Registro{
    protected:
        char  nombres[50];
        char  apellidos[50];
        char  Genero;
        Fecha fecha_nacimiento;
        int   DNI;
        bool  estado;
    public:
        Persona(const char *n, const char *a, const Fecha f, int d)
        {
            strcpy(nombres,n);
            strcpy(apellidos,a);
            fecha_nacimiento = f;
            DNI              = d;
            estado           = true;
        }
        ~Persona(){}
        int   GetIdPersona();
        char *GetNombres();
        char *GetApellidos();
        Fecha GetFechaNacimiento();
        int   GetDNI();
        char  GetGenero();
        bool  GetEstado();
        void  SetIDPersona();
        void  SetNombres(const char *);
        void  SetApellidos(const char *);
        void  SetFechaNacimiento(Fecha );
        void  SetDNI(int);
        void  SetEstado(bool);
        void  SetGenero(char);
};



#endif // PERSONA_H_INCLUDED
