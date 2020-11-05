#include "detalleplanfarmacologico.h"

int  DetallePlanFarmacologico :: GetCodigoPlan(){return Id_PlanFarmacologico;}
int  DetallePlanFarmacologico :: GetCodigoMedicacion(){return Id_Medicacion;}
int  DetallePlanFarmacologico :: GetDosisdiaria(){return dosisdiaria;}
bool DetallePlanFarmacologico :: GetEstado(){return estado;}
int  DetallePlanFarmacologico :: GetCantidadMgDisponibles(){return cantcomprimidos * miligramos ;}
int  DetallePlanFarmacologico :: GetCantidadDiasCubiertos(){return (cantcomprimidos * miligramos ) / dosisdiaria;}

//SETs
void  DetallePlanFarmacologico :: SetCodigoPlan(int _idPlanFarmacologico){Id_PlanFarmacologico = _idPlanFarmacologico;}
void  DetallePlanFarmacologico :: SetCodigoMedicacion(int _idMedicacion){ Id_Medicacion = _idMedicacion;}
void  DetallePlanFarmacologico :: SetDosisdiaria(int _dosisdiaria){dosisdiaria = _dosisdiaria;}
void  DetallePlanFarmacologico :: SetEstado(bool _estado){estado = _estado;}
void  DetallePlanFarmacologico :: SetCantComprimidos(int _cantcomprimidos){cantcomprimidos = _cantcomprimidos;}
