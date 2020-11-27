#ifndef FARMACO_H_INCLUDED
#define FARMACO_H_INCLUDED

#include "../modelos/registro.h"

class Farmaco:public Registro{
    private:
       char nombre[50];
    public:
        Farmaco(const char *_nombre = ""):Registro()
        {
            strcpy(nombre,_nombre);
        }
        ~Farmaco(){};
        //GETs
        const char *GetNombre();
        void  SetNombre(const char*);
        //METODOS REDEFINIDOS HEREDADOS DE REGISTRO
        int getSize();
        bool comparaID(Registro *temp);
         Farmaco& operator = (Registro *temp){
            Farmaco *aux=(Farmaco *)temp;
            strcpy(nombre,aux->nombre);
            estado           = aux->estado;
            ID               = aux->ID;
            fechaAlta        = aux->fechaAlta;
            fechaBaja        = aux->fechaBaja;
        }
};

#endif // FARMACO_H_INCLUDED
