#ifndef PROFESIONAL_H_INCLUDED
#define PROFESIONAL_H_INCLUDED

#include "registro.h"
#include "especialidad.h"
#include "iostream"
#include "cstring"

class Profesional{
    private:
        int matricula;
        int ID_especialidad;
    public:
        Profesional(int mat, int esp){
          matricula       = mat;
          ID_especialidad = esp;
        }
        ~Profesional(){};
        //GETs
        int GetMatricula();
        int GetEspecialidad();
        //SETs
        void SetMatricula(int);
        void SetEspecialidad(int );

};

#endif // PROFESIONAL_H_INCLUDED
