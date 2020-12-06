#include "especialidad.h"

const char * Especialidad :: GetNombre(){return nombre;}
void         Especialidad :: SetNombre(const char* _nombre){strcpy(nombre,_nombre);}

//VIRTUALES
int   Especialidad :: getSize(){return sizeof *this;}
bool  Especialidad :: comparaID(Registro *temp){
            Especialidad *aux=(Especialidad *)temp;
            if(aux->ID == ID) return true;
            return false;
}
