#include "../modelos/profesional.h"
#include <iostream>
#include <limits>
#include "../validaciones/validaciones.h"
#include "../util/rlutil.h"
#include "../modelos/usuario.h"

using namespace std;
using namespace rlutil;

extern Usuario usr_lgd;

int  Profesional :: GetMatricula(){return matricula;}
int  Profesional :: GetEspecialidad(){return ID_especialidad;}
//SETs
void Profesional :: SetMatricula(int _matricula){matricula = _matricula;}
void Profesional :: SetEspecialidad(int _idEspecialidad){ID_especialidad = _idEspecialidad;}

///pol

bool  Profesional :: comparaID(Registro *temp){
        Profesional *aux=(Profesional *)temp;
        if( (matricula != -1 && aux->matricula != -1 )&& matricula == aux->matricula ) return true;
        if( (DNI != -1 && aux->DNI != -1 )&& DNI == aux->DNI ) return true;
        if(ID == aux->ID )  return true;
        return false;
}
int   Profesional :: getSize(){return sizeof *this;}

