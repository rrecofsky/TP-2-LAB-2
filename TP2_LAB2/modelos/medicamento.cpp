#include "../modelos/medicamento.h"

///GETs

int                  Medicamento :: GetDosis(){return dosis;}
Fecha                Medicamento :: GetFechaVecimiento(){return vencimiento;}
int                  Medicamento :: GetIdPresentacion(){return ID_Presentacion;}
bool                 Medicamento :: GetNoSeFabricaMas(){return NoSeFabricaMas;}
const char *         Medicamento :: GetaccionTerapeutica(){return accionTerapeutica;}

///SETs

void  Medicamento :: SetDosis(int _dosis){dosis = _dosis;}
void  Medicamento :: SetFechaVencimiento(Fecha _fechaVencimiento){vencimiento = _fechaVencimiento;}
void  Medicamento :: SetIdPresentacion(int _idPresentacion){ID_Presentacion = _idPresentacion;}
void  Medicamento :: SetNoSeFabricaMas(bool _NoSeFabricaMas){NoSeFabricaMas = NoSeFabricaMas;}
void  Medicamento :: SetaccionTerapeutica(const char * _accionTerapeutica){strcpy(accionTerapeutica,accionTerapeutica);}

///GETS PLM
int   Medicamento :: getSize(){return sizeof *this;}

bool  Medicamento :: comparaID(Registro *temp){
            Medicamento *aux=(Medicamento *)temp;
            if(aux->ID == ID) return true;
            return false;
}
