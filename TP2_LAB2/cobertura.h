#ifndef COBERTURA_H_INCLUDED
#define COBERTURA_H_INCLUDED
#include "registro.h"

class Cobertura:public Registro{
    private:
       char nombre[50];
    public:
        Cobertura(const char *_nombre)
        {
            strcpy(nombre,_nombre);
        }
        ~Cobertura(){};
        //GETs
        int   GetId();
        const char *GetNombre();
        void  SetId(int);
        void  SetNombre(const char*);
};


#endif // COBERTURA_H_INCLUDED
