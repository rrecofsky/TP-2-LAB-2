#include "../modelos/especialidad.h"

const char * Especialidad :: GetNombre(){return nombre;}
void         Especialidad :: SetNombre(const char* _nombre){strcpy(nombre,_nombre);}

///VIRTUAL

bool Especialidad :: comparaID(Registro *temp){
    Especialidad *aux=(Especialidad *)temp;
    if (nombre != "" && aux->nombre != "" && nombre == aux->nombre) return true;
    if( ID == aux->ID  ) return true;
    return false;
}

int   Especialidad :: getSize(){return sizeof *this;}
