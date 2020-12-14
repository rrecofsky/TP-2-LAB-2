#include "medicacion.h"

///GETs

const char*          Medicamento :: GetFarmaco(){return farmaco;}
int                  Medicamento :: GetDosis(){return dosis;}
Fecha                Medicamento :: GetFechaVecimiento(){return vencimiento;}
Presentacion         Medicamento :: GetIdPresentacion(){return ID_Presentacion;}
bool                 Medicamento :: GetNoSeFabricaMas(){return NoSeFabricaMas;}

///SETs

void  Medicamento :: SetFarmaco(const char* _farmaco){strcpy(farmaco,_farmaco);}
void  Medicamento :: SetDosis(int _dosis){dosis = _dosis;}
void  Medicamento :: SetFechaVencimiento(Fecha _fechaVencimiento){vencimiento = _fechaVencimiento;}
void  Medicamento :: SetIdPresentacion(Presentacion _idPresentacion){ID_Presentacion = _idPresentacion;}
void  Medicamento :: SetNoSeFabricaMas(bool _NoSeFabricaMas){NoSeFabricaMas = NoSeFabricaMas;}

///GETS PLM
int   Medicamento :: getSize(){return sizeof *this;}

bool  Medicamento :: comparaID(Registro *temp){
            Medicamento *aux=(Medicamento *)temp;
            if(aux->ID == ID) return true;
            return false;
}
