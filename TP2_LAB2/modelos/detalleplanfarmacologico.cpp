#include "detalleplanfarmacologico.h"
#include "registro.h"
#include <iostream>

using namespace std;

int  DetallePlanFarmacologico :: GetCodigoPlan(){return Id_PlanFarmacologico;}
int  DetallePlanFarmacologico :: GetCodigoMedicacion(){return Id_Medicacion;}
int  DetallePlanFarmacologico :: GetDosisdiaria(){return dosisdiaria;}
int  DetallePlanFarmacologico :: GetCantidadMgDisponibles(){return cantcomprimidos * miligramos ;}
int  DetallePlanFarmacologico :: GetCantidadDiasCubiertos(){return (cantcomprimidos * miligramos ) / dosisdiaria;}

//GETS PLM
int   DetallePlanFarmacologico :: getSize(){return sizeof *this;}
bool  DetallePlanFarmacologico :: comparaID(Registro *temp){
            DetallePlanFarmacologico *aux=(DetallePlanFarmacologico *)temp;
            if(aux->ID == ID) return true;
            return false;
}


void  DetallePlanFarmacologico :: Cargar(){
      cout<<"Ingrese la dosis diaria que se debe consumir: ";
      cin>>dosisdiaria;
      cout<<endl;
      cout<<"Ingrese la cantidad de comprimidos que posee la caja: ";
      cin>>cantcomprimidos;
      cout<<endl;
      cout<<"Ingrese el la cantidad de miligramos de cada pastilla: ";
      cin>>miligramos;
      cout<<endl;
      return;
}

void  DetallePlanFarmacologico :: Mostrar(){
      cout<<"Dosis diaria que se debe consumir: "<<dosisdiaria<<endl;
      cout<<"Cantidad de comprimidos que posee la caja: "<<cantcomprimidos<<endl;
      cout<<"Cantidad de miligramos de cada pastilla: "<<miligramos<<endl;
      return;
}

//SETs
void  DetallePlanFarmacologico :: SetCodigoPlan(int _idPlanFarmacologico){Id_PlanFarmacologico = _idPlanFarmacologico;}
void  DetallePlanFarmacologico :: SetCodigoMedicacion(int _idMedicacion){ Id_Medicacion = _idMedicacion;}
void  DetallePlanFarmacologico :: SetDosisdiaria(int _dosisDiaria){dosisdiaria = _dosisDiaria;}
void  DetallePlanFarmacologico :: SetCantComprimidos(int _cantComprimidos){cantcomprimidos = _cantComprimidos;}
void  DetallePlanFarmacologico :: SetCantMiligramos(int _cantMiligramos){miligramos = _cantMiligramos;}
