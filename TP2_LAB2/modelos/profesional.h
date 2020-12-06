#ifndef PROFESIONAL_H_INCLUDED
#define PROFESIONAL_H_INCLUDED

#include "persona.h"
#include <iostream>
#include <iomanip>
using namespace std;



class Profesional: public Persona
{
    private:
        int matricula;
        int ID_especialidad;
    public:
        Profesional(const char * _nombre = "", const char * _apellido = "", int _dni = -1, int _matricula = -1, int _especialidad = -1):Persona(_nombre,_apellido,_dni)
        {
          matricula       = _matricula;
          ID_especialidad = _especialidad;
        }
        ~Profesional(){};
        ///GETs
        int GetMatricula();
        int GetEspecialidad();
        ///SETs
        void SetMatricula(int);
        void SetEspecialidad(int );
        ///Virtual
        bool comparaID(Registro *temp);
        int getSize();
        Profesional& operator = (Registro *temp){
            Profesional *aux=(Profesional *)temp;
            strcpy(this->apellidos,aux->apellidos);
            strcpy(this->nombres, aux->nombres);
            genero           = aux->genero;
            fecha_nacimiento = aux->fecha_nacimiento;
            DNI              = aux->DNI;
            estado           = aux->estado;
            ID               = aux->ID;
            fechaAlta        = aux->fechaAlta;
            fechaBaja        = aux->fechaBaja;
            matricula        = aux->matricula;
            ID_especialidad  = aux->ID_especialidad;
            }

};

#endif // PROFESIONAL_H_INCLUDED
