#ifndef ESPECIALIDAD_H_INCLUDED
#define ESPECIALIDAD_H_INCLUDED

#include "../modelos/registro.h"
#include <cstring>

class Especialidad:public Registro{
    private:
       char nombre[50];
    public:
        Especialidad(const char *n):Registro()
        {
            strcpy(nombre,n);
        }
        ~Especialidad(){};
        //GETs
        const char *GetNombre();
        void SetNombre(const char*);
};



#endif // ESPECIALIDAD_H_INCLUDED
