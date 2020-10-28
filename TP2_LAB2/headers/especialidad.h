#ifndef ESPECIALIDAD_H_INCLUDED
#define ESPECIALIDAD_H_INCLUDED

#include "iostream"
#include "cstring"
#include "iostream"
#include "cstring"

class Especialidad{
    private:
       int ID;
       char nombre[50];
    public:
        Especialidad(const char *n)
        {
            ID = 0; //buscar en base al nro en los archivos
            strcpy(nombre,n);
        }
        ~Especialidad(){};
        //GETs
        int GetId();
        char *GetNombre();
        void SetId(int);
        void SetNombre(const char*);
};



#endif // ESPECIALIDAD_H_INCLUDED
