#ifndef FARMACO_H_INCLUDED
#define FARMACO_H_INCLUDED
#include "../headers/registro.h"

class Farmaco:public Registro{
    private:
       char nombre[50];
    public:
        Farmaco(const char *n)
        {
            strcpy(nombre,n);
        }
        ~Farmaco(){};
        //GETs
        char *GetNombre();
        void  SetId(int);
        void  SetNombre(const char*);
};

#endif // FARMACO_H_INCLUDED
