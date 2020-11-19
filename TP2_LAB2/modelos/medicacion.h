#ifndef MEDICACION_H_INCLUDED
#define MEDICACION_H_INCLUDED

#include "registro.h"
#include "fecha.h"
#include "iostream"
#include "cstring"

class Medicacion:public Registro{
    private:
        char  farmaco[50];
        int   ID_Presentacion;
        int   dosis;
        Fecha vencimiento;
        bool  estado;
    public:
        Medicacion(Fecha _fechaVencimento, const char* _farmaco, float _dosis=0):Registro(){
            strcpy(farmaco,_farmaco);
            dosis               = _dosis;
            estado              = true;
            vencimiento         = _fechaVencimento;
        }
        ~Medicacion(){};
        //GETs
        const char *GetFarmaco();
        int   GetDosis();
        Fecha GetFechaVecimiento();
        int   GetIdPresentacion();
        //SETs
        void  SetFarmaco(const char*);
        void  SetDosis(int);
        void  SetFechaVencimiento(Fecha);
        void  SetIdPresentacion(int);
};

#endif // MEDICACION_H_INCLUDED
