#include "presentacion.h"

///GETS

const char* Presentacion :: GetNombre(){return nombre;}
int         Presentacion :: GetCantidad(){return cantidad;}
int         Presentacion :: GetMg(){return mg;}

///SETs

void Presentacion :: SetNombre(const char* _nombre){strcpy(nombre,_nombre);}
void Presentacion :: SetCantidad(int _cantidad){cantidad = _cantidad;}
void Presentacion :: SetMg(int _mg){mg = _mg;}
