#include <iostream>
#include <limits>
#include "../util/rlutil.h"
#include "../modelos/paciente.h"

using namespace rlutil;
using namespace std;

//GETs

int Paciente :: GetNroAfiliado(){return nro_Afiliado;}
int Paciente :: GetIdCobertura(){return ID_Cobertura;}
int Paciente :: GetIdInforme(){return ID_Informe;}
int Paciente :: GetIdPlanFarmacologico(){return ID_PlanFarmacologico;}

//SETs

void Paciente :: SetNroAfiliado(int _nroAfiliado){nro_Afiliado = _nroAfiliado;}
void Paciente :: SetIdCObertura(int _idCobertura){ID_Cobertura = _idCobertura;}
void Paciente :: SetIdInforme(int _idInforme){ ID_Informe = _idInforme;}

//VIRTUALES
int Paciente :: getSize(){return sizeof *this;}

bool  Paciente :: comparaID(Registro *temp){
        Paciente *aux=(Paciente *)temp;
        if(DNI != -1 && aux->DNI != -1 && DNI == aux->DNI ) return true;
        if (nro_Afiliado != -1 && aux->nro_Afiliado != -1 && nro_Afiliado == aux->nro_Afiliado ) return true;
        if (ID_Informe != -1 && aux->ID_Informe != -1 && ID_Informe != -1 == aux->ID_Informe ) return true;
        if( ID == aux->ID  ) return true;

        return false;
}

