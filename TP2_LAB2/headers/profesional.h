#ifndef PROFESIONAL_H_INCLUDED
#define PROFESIONAL_H_INCLUDED

#include "../headers/especialidad.h"
#include "iostream"
#include "cstring"

class Profesional{
    private:
        int matricula;
        Especialidad especialidad;
    public:
        Profesional(int mat, Especialidad esp){
         //   this->matricula = mat;
         //   this->especialidad = esp;
        }
        ~Profesional(){};
        //GETs
        int GetMatricula();
        Especialidad GetEspecialidad();
        //SETs
        void SetMatricula(int);
        void SetEspecialidad(Especialidad);

};

#endif // PROFESIONAL_H_INCLUDED
