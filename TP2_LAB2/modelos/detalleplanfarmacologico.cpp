#include "detalleplanfarmacologico.h"
#include "registro.h"
#include <iostream>

using namespace std;

int  DetallePlanFarmacologico :: GetCodigoPlan(){return Id_PlanFarmacologico;}
int  DetallePlanFarmacologico :: GetCodigoMedicacion(){return Id_Medicacion;}
int  DetallePlanFarmacologico :: GetDosisdiaria(){return dosisdiaria;}
int  DetallePlanFarmacologico :: GetCantidadMgDisponibles(){return cantcomprimidos * miligramos ;}
int  DetallePlanFarmacologico :: GetCantidadDiasCubiertos(){return (cantcomprimidos * miligramos ) / dosisdiaria;}

//VIRTUALES
int   DetallePlanFarmacologico :: getSize(){return sizeof *this;}
bool  DetallePlanFarmacologico :: comparaID(Registro *temp){
            DetallePlanFarmacologico *aux=(DetallePlanFarmacologico *)temp;
            if(aux->ID == ID) return true;
            return false;
}

//SETs
void  DetallePlanFarmacologico :: SetCodigoPlan(int _idPlanFarmacologico){Id_PlanFarmacologico = _idPlanFarmacologico;}
void  DetallePlanFarmacologico :: SetCodigoMedicacion(int _idMedicacion){ Id_Medicacion = _idMedicacion;}
void  DetallePlanFarmacologico :: SetDosisdiaria(int _dosisDiaria){dosisdiaria = _dosisDiaria;}
void  DetallePlanFarmacologico :: SetCantComprimidos(int _cantComprimidos){cantcomprimidos = _cantComprimidos;}
void  DetallePlanFarmacologico :: SetCantMiligramos(int _cantMiligramos){miligramos = _cantMiligramos;}
