#include "planfarmacologico.h"
#include "paciente.h"
#include "profesional.h"
#include <iostream>
#include "fecha.h"
#include "archivo.h"

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
            if(aux->ID == ID) return true;
            return false;
}


void  PlanFarmacologico :: Cargar(){
}


void  PlanFarmacologico :: Mostrar(){
}

///SETs

void  PlanFarmacologico :: SetEmision(Fecha _fechaEmision){emision = _fechaEmision;}
void  PlanFarmacologico :: SetIdPaciente(int _idPaciente){ ID_Paciente = _idPaciente;}
void  PlanFarmacologico :: SetIdProfesional(int _idProfesional){ ID_Profesional = _idProfesional;}
void  PlanFarmacologico :: SetNotas(const char* _notas){strcpy(notas,_notas);}


