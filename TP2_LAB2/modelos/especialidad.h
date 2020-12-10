#ifndef ESPECIALIDAD_H_INCLUDED
#define ESPECIALIDAD_H_INCLUDED

#include "../modelos/registro.h"
#include <cstring>

class Especialidad:public Registro{
    private:
       char nombre[50];
    public:
        Especialidad(const char *_nombre = ""):Registro()
        {
            strcpy(nombre,_nombre);
        }
        ~Especialidad(){};
        //GETs
        const char *GetNombre();
        void SetNombre(const char*);
        /// VIRTUALS
        int getSize();
         Especialidad& operator = (Registro *temp){
            Especialidad *aux=(Especialidad *)temp;
            strcpy(this->nombre, aux->nombre);
            estado           = aux->estado;
            ID               = aux->ID;
            fechaAlta        = aux->fechaAlta;
            fechaBaja        = aux->fechaBaja;
            }
        bool comparaID(Registro *temp);
};



#endif // ESPECIALIDAD_H_INCLUDED
