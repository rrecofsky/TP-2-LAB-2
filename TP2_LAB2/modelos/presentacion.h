#ifndef PRESENTACION_H_INCLUDED
#define PRESENTACION_H_INCLUDED

#include "../modelos/registro.h"

class Presentacion:public Registro{
    private:
       char  nombre[50]; //nombre de la presentacion
       int   cantidad; //cantidad de pastillas de la presentacion
       float mg; //miligramos de cada pastilla
    public:
        Presentacion(const char *n):Registro()
        {
            strcpy(nombre,n);
        }
        ~Presentacion(){};
        //GETs
        const char *GetNombre();
        int   GetCantidad();
        int   GetMg();
        //SET's
        void SetNombre(const char*);
        void SetCantidad(int);
        void SetMg(int);
};

#endif // PRESENTACION_H_INCLUDED
