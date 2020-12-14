#ifndef INTERFAZFECHA_H_INCLUDED
#define INTERFAZFECHA_H_INCLUDED
#include <iostream>
#include "../modelos/fecha.h"

using namespace std;

class InterfazFecha{
    public:
        Fecha CargarFecha(bool );
        string GetfechaFormateada(Fecha);
        bool EsFechaPosterior(Fecha , Fecha );
};

#endif // INTERFAZFECHA_H_INCLUDED
