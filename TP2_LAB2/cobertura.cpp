#include "cobertura.h"
#include "registro.h"

///GETS
int    Cobertura :: GetId(){ return Registro :: GetId();}
const  char * Cobertura :: GetNombre(){return nombre;}

///SETS

void  Cobertura :: SetNombre(const char* _nombre){strcpy(nombre,_nombre);}
