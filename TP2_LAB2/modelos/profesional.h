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
        Profesional(const char * _nombre = "", const char * _apellido = "", int _dni = 0, int _matricula = 0, int _especialidad = 0):Persona(_nombre,_apellido,_dni)
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
        ///Sobrecarga con Friend
        friend istream & operator>>(istream &, int &);
        friend ostream & operator<<(ostream &, int &);

};

#endif // PROFESIONAL_H_INCLUDED
