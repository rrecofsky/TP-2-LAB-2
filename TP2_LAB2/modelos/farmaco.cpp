#include "../modelos/farmaco.h"

const char * Farmaco :: GetNombre(){return nombre;}
void         Farmaco :: SetNombre(const char* _nombre){strcpy(nombre,_nombre);}

///GETS PLM
int   Farmaco :: getSize(){return sizeof *this;}

bool  Farmaco :: comparaID(Registro *temp){
            Farmaco *aux=(Farmaco *)temp;
            if(aux->ID == ID) return true;
            return false;
}
