#include "especialidad.h"

const char * Especialidad :: GetNombre(){return nombre;}
void         Especialidad :: SetNombre(const char* _nombre){strcpy(nombre,_nombre);}
