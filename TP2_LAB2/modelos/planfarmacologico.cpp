#include "planfarmacologico.h"
#include <iostream>


extern const char *FILE_PACIENTES;
extern const char *FILE_PROFESIONALES;

using namespace std;

///GETS

Fecha PlanFarmacologico :: GetEmision(){return emision;}
int   PlanFarmacologico :: GetIdPaciente(){return ID_Paciente;}
int   PlanFarmacologico :: GetIdProfesional(){return ID_Profesional;}
const char* PlanFarmacologico :: GetNotas(){return notas;}

///GETS PLM
int   PlanFarmacologico :: getSize(){return sizeof *this;}

bool  PlanFarmacologico :: comparaID(Registro *temp){
            PlanFarmacologico *aux=(PlanFarmacologico *)temp;
            if(aux->ID_Paciente != -1 && ID_Paciente != -1 && aux->ID_Paciente == ID_Paciente ) return true;
            if(aux->ID_Profesional != -1 && ID_Profesional != -1 && aux->ID_Profesional == ID_Profesional ) return true;
            if(aux->ID == ID) return true;
            return false;
}

///SE VAN A ELIMINAR
void  PlanFarmacologico :: Cargar(){}
void  PlanFarmacologico :: Mostrar(){}

///SETs

void  PlanFarmacologico :: SetEmision(Fecha _fechaEmision){emision = _fechaEmision;}
void  PlanFarmacologico :: SetIdPaciente(int _idPaciente){ ID_Paciente = _idPaciente;}
void  PlanFarmacologico :: SetIdProfesional(int _idProfesional){ ID_Profesional = _idProfesional;}
void  PlanFarmacologico :: SetNotas(const char* _notas){strcpy(notas,_notas);}


