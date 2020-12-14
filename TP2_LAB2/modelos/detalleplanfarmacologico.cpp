#include "../modelos/detalleplanfarmacologico.h"
#include <iostream>

using namespace std;

int  DetallePlanFarmacologico :: GetCantComprimidos(){return cantcomprimidos;};
int  DetallePlanFarmacologico :: GetIdPlanMedicamento(){return Id_Medicacion;}
int  DetallePlanFarmacologico :: GetDosisdiaria(){return dosisdiaria;}
int  DetallePlanFarmacologico :: GetCantidadMgDisponibles(){return cantcomprimidos * miligramos ;}
int  DetallePlanFarmacologico :: GetCantidadDiasCubiertos(){return (cantcomprimidos * miligramos ) / (dosisdiaria * mgpordosis);}
int  DetallePlanFarmacologico :: GetIdPlanFarmacologico(){return Id_PlanFarmacologico;}
int  DetallePlanFarmacologico :: GetCantMiligramos(){return miligramos;}
int  DetallePlanFarmacologico :: GetMgPorDosis(){return mgpordosis;}

//GETS PLM
int   DetallePlanFarmacologico :: getSize(){return sizeof *this;}

bool  DetallePlanFarmacologico :: comparaID(Registro *temp){
            DetallePlanFarmacologico *aux=(DetallePlanFarmacologico *)temp;
            if (Id_PlanFarmacologico != -1 && aux->Id_PlanFarmacologico != -1 && Id_PlanFarmacologico == aux->Id_PlanFarmacologico ) return true;
            if(aux->ID == ID) return true;
            return false;
}

//SETs
void  DetallePlanFarmacologico :: SetIdPlanFarmacologico(int _idPlanFarma){Id_PlanFarmacologico = _idPlanFarma;}
void  DetallePlanFarmacologico :: SetIdPlanMedicamento(int _idMedicacion){ Id_Medicacion = _idMedicacion;}
void  DetallePlanFarmacologico :: SetDosisdiaria(int _dosisDiaria){dosisdiaria = _dosisDiaria;}
void  DetallePlanFarmacologico :: SetCantComprimidos(int _cantComprimidos){cantcomprimidos = _cantComprimidos;}
void  DetallePlanFarmacologico :: SetCantMiligramos(int _cantMiligramos){miligramos = _cantMiligramos;}
void  DetallePlanFarmacologico :: SetMgPorDosis(int _mgpordosis){ mgpordosis = _mgpordosis;}
