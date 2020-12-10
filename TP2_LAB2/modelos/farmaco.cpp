#include "../modelos/farmaco.h"

const char * Farmaco :: GetNombre(){return nombre;}
void         Farmaco :: SetNombre(const char* _nombre){strcpy(nombre,_nombre);}

///VIRTUALES
int   Farmaco :: getSize(){return sizeof *this;}
bool  Farmaco :: comparaID(Registro *temp){
            Farmaco *aux=(Farmaco *)temp;
            if (nombre != "" && aux->nombre != "" && nombre == aux->nombre) return true;
            if(aux->ID == ID) return true;
            return false;
}
