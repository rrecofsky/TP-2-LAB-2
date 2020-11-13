#include "medicacion.h"

///GETs

const char* Medicacion :: GetFarmaco(){return farmaco;}
int         Medicacion :: GetDosis(){return dosis;}
Fecha       Medicacion :: GetFechaVecimiento(){return vencimiento;}
int         Medicacion :: GetIdPresentacion(){return ID_Presentacion;}

///SETs

void  Medicacion :: SetFarmaco(const char* _farmaco){strcpy(farmaco,_farmaco);}
void  Medicacion :: SetDosis(int _dosis){dosis = _dosis;}
void  Medicacion :: SetFechaVencimiento(Fecha _fechaVencimiento){vencimiento = _fechaVencimiento;}
void  Medicacion :: SetIdPresentacion(int _idPresentacion){ID_Presentacion = _idPresentacion;}
