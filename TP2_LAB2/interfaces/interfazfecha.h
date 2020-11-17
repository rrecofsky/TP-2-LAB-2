#ifndef INTERFAZFECHA_H_INCLUDED
#define INTERFAZFECHA_H_INCLUDED
#include <iostream>
#include "../modelos/fecha.h"

using namespace std;

class InterfazFecha{
    public:
        Fecha CargarFecha();
        string GetfechaFormateada(Fecha);
};

#endif // INTERFAZFECHA_H_INCLUDED
