#ifndef MEDICACION_H_INCLUDED
#define MEDICACION_H_INCLUDED

#include "../headers/registro.h"
#include "../headers/fecha.h"
#include "iostream"
#include "cstring"

class Medicacion:public Registro{
    private:
        char  farmaco[50];
        int   ID_Presentacion;
        float dosis;
        Fecha vencimiento;
        bool  estado;
    public:
        Medicacion(Fecha fv, const char* f, float d=0){
            strcpy(farmaco,f);
            dosis               = d;
            estado              = true;
            vencimiento         = fv;
        }
        ~Medicacion(){};
        //GETs
        char *GetFarmaco();
        float GetDosis();
        Fecha GetFechaVecimiento();
        bool  GetEstado();
        int   GetIdPresentacion();
        //SETs
        void  SetFarmaco(const char*);
        void  SetDosis(float);
        void  SetFechaVencimiento(Fecha);
        void  SetEstado();
        void  SetIdPresentacion(int);
};

#endif // MEDICACION_H_INCLUDED
