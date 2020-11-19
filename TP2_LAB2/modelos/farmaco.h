#ifndef FARMACO_H_INCLUDED
#define FARMACO_H_INCLUDED

#include "registro.h"

class Farmaco:public Registro{
    private:
       char nombre[50];
    public:
        Farmaco(const char *_nombre):Registro()
        {
            strcpy(nombre,_nombre);
        }
        ~Farmaco(){};
        //GETs
        const char *GetNombre();
        void  SetNombre(const char*);
};

#endif // FARMACO_H_INCLUDED
