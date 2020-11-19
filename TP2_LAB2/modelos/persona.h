#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include "../modelos/fecha.h"

#include <iostream>
#include <cstring>
#include "../modelos/registro.h"

using namespace std;

class Persona:public Registro{
    protected:
        char  nombres[50];
        char  apellidos[50];
        char  genero;
        Fecha fecha_nacimiento;
        int   DNI;
        bool  estado;
    public:

        Persona(const char *_nombre = "", const char *_apellido = "", int _dni = -1):Registro()
        {
            strcpy(nombres,_nombre);
            strcpy(apellidos,_apellido);
            DNI              = _dni;
         }

        //GETS
        const char *GetNombres();
        const char *GetApellidos();
        Fecha GetFechaNacimiento();
        int   GetDNI();
        char  GetGenero();
        //GETS de usuarios
        const char *GetUser();
        const char *GetPass();
        int   GetEdad();
        //SETS
        void  SetIDPersona();
        void  SetNombres(const char *);
        void  SetApellidos(const char *);
        void  SetFechaNacimiento(Fecha );
        void  SetDNI(int);
        void  SetGenero(char);
        //SETS DE USUARIO
        void  ChangeUserName(const char*);
        void  ChangeUserPass(const char*);
        /// POLIMORFICAS
        void Cargar();
        void Mostrar();
        void Modificar(){};
        int getSize();


         Persona& operator = (Registro *temp){
            Persona *aux=(Persona *)temp;
            strcpy(this->apellidos,aux->apellidos);
            strcpy(this->nombres, aux->nombres);
            genero           = aux->genero;
            fecha_nacimiento = aux->fecha_nacimiento;
            DNI              = aux->DNI;
            estado           = aux->estado;
            ID               = aux->ID;
            fechaAlta        = aux->fechaAlta;
            fechaBaja        = aux->fechaBaja;
            }
        bool comparaID(Registro *temp);
        ///Destructor
        ~Persona(){}
};



#endif // PERSONA_H_INCLUDED
