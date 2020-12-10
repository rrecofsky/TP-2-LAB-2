#ifndef COBERTURA_H_INCLUDED
#define COBERTURA_H_INCLUDED

#include "registro.h"
#include <iostream>
#include <cstring>

class Cobertura:public Registro
{
    private:
       char nombre[50];
    public:
        Cobertura(const char *_nombre = ""):Registro()
        {
            strcpy(nombre,_nombre);
        }
        ~Cobertura(){};
        ///GET
        const char *GetNombre();
        ///SET
        void  SetNombre(const char*);
        /// VIRTUALS
        int getSize();
         Cobertura& operator = (Registro *temp){
            Cobertura *aux=(Cobertura *)temp;
            strcpy(this->nombre, aux->nombre);
            estado           = aux->estado;
            ID               = aux->ID;
            fechaAlta        = aux->fechaAlta;
            fechaBaja        = aux->fechaBaja;
            }
        bool comparaID(Registro *temp);

};


#endif // COBERTURA_H_INCLUDED
