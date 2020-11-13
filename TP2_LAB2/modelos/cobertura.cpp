#include "cobertura.h"
#include "registro.h"

///GETS

const  char * Cobertura :: GetNombre(){return nombre;}

///SETS

void  Cobertura :: SetNombre(const char* _nombre){strcpy(nombre,_nombre);}

///VIRTUAL
void Cobertura :: Cargar(){};
void Cobertura :: Mostrar(){};
void Cobertura :: Modificar(){};

bool Cobertura :: comparaID(Registro *temp){
    Cobertura *aux=(Cobertura *)temp;
    if( ID == aux->ID  ) return true;
    return false;
}

int   Cobertura :: getSize(){return sizeof *this;}
