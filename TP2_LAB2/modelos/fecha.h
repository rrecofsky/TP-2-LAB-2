#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include <iostream>
//#include <string.h>
//#include <ctime>
//#include <cstdio>
//#include <cstdlib>

using namespace std;

class Fecha{
    private:
        int dia;
        int mes;
        int anio;
    public:
         Fecha(int _dia = 0, int _mes = 0, int _anio = 0){
            dia  = _dia;
            mes  = _mes;
            anio = _anio;
        }
        ~Fecha(){
            dia  = 0;
            mes  = 0;
            anio = 0;
        }
        ///GETS
        int   GetDia();
        int   GetMes();
        int   GetAnio();
        Fecha GetFechaActual();
        ///SETS
        void  SetDia(int);
        void  SetMes(int);
        void  SetAnio(int);
};



#endif // FECHA_H_INCLUDED
