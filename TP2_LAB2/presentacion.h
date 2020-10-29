#ifndef PRESENTACION_H_INCLUDED
#define PRESENTACION_H_INCLUDED
#include "../headers/registro.h"

class Presentacion:public Registro{
    private:
       char  nombre[50]; //nombre de la presentacion
       int   cantidad; //cantidad de pastillas de la presentacion
       float mg; //miligramos de cada pastilla
    public:
        Presentacion(const char *n)
        {
            strcpy(nombre,n);
        }
        ~Presentacion(){};
        //GETs
        char *GetNombre();
        int   GetCantidad();
        float GetMg();
        //SET's
        void SetNombre(const char*);
        void SetCantidad(int);
        void SetMg(float);
};

#endif // PRESENTACION_H_INCLUDED
