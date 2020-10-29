#ifndef COBERTURA_H_INCLUDED
#define COBERTURA_H_INCLUDED
#include "../headers/registro.h"

class Cobertura:public Registro{
    private:
       char nombre[50];
    public:
        Cobertura(const char *n)
        {
            strcpy(nombre,n);
        }
        ~Cobertura(){};
        //GETs
        int   GetId();
        char *GetNombre();
        void  SetId(int);
        void  SetNombre(const char*);
};


#endif // COBERTURA_H_INCLUDED
