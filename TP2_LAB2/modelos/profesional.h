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
        ///Carga
        void Cargar();
        void Mostrar();
        void Modificar();
        bool comparaID(Registro *temp);
        int getSize();

};

#endif // PROFESIONAL_H_INCLUDED
