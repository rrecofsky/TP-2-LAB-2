#include "registro.h"
#include "fecha.h"

//Gets
int   Registro :: GetId(){ return ID; }
bool  Registro :: GetEstado(){ return estado; }
Fecha Registro :: GetFechaAlta(){ return fechaAlta; }
Fecha Registro :: GetFechaBaja(){ return fechaBaja; }

//SETS

void  Registro :: SetEstado(bool _estado){ estado = _estado;}
void  Registro :: SetFechaAlta(){ Fecha fecha; fechaAlta = fecha.GetFechaActual(); }
void  Registro :: SetFechaBaja(){ Fecha fecha; fechaAlta = fecha.GetFechaActual(); }


