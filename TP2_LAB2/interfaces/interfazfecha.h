#ifndef INTERFAZFECHA_H_INCLUDED
#define INTERFAZFECHA_H_INCLUDED

#include "../modelos/fecha.h"

class InterfazFecha{
    public:
        Fecha CargarFecha();
        const char* GetfechaFormateada(Fecha);
};

#endif // INTERFAZFECHA_H_INCLUDED
