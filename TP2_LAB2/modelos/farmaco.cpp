#include "farmaco.h"

const char * Farmaco :: GetNombre(){return nombre;}
void         Farmaco :: SetNombre(const char* _nombre){strcpy(nombre,_nombre);}
