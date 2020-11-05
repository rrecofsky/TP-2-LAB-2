#include "paciente.h"

//GETs

int Paciente :: GetNroAfiliado(){return nro_Afiliado;}
int Paciente :: GetIdCobertura(){return ID_Conertura;}
int Paciente :: GetIdInforme(){return ID_Informe;}
int Paciente :: GetIdPlanFarmacologico(){return ID_PlanFarmacologico;}

//SETs

void Paciente :: SetNroAfiliado(int _nroAfiliado){nro_Afiliado = _nroAfiliado;}
void Paciente :: SetIdCObertura(int _idCobertura){ID_Conertura = _idCobertura;}
void Paciente :: SetIdInforme(int _idInforme){ ID_Informe = _idInforme;}

///Busquedas --> capa logica

int  Paciente :: GetIdPorNroAfiliado(int _nroAfiliado){return 0;}
int  Paciente :: GetIdPorDNI(int _DNI){return 0;}
int  Paciente :: GetIdPorNombreApellido(const char* _nombreApellido){return 0;}
