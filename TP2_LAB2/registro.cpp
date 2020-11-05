#include "registro.h"
#include "fecha.h"

//Cada vez que se crea un registro debe tener una fecha de alta

Registro::Registro(){
    fechaAlta = fechaAlta.GetFechaActual();
}

//Gets
int   Registro :: GetId(){ return ID; }
bool  Registro :: GetEstado(){ return estado; }
Fecha Registro :: GetFechaAlta(){ return fechaAlta; }
Fecha Registro :: GetFechaBaja(){ return fechaBaja; }

//SETS

//Si doy de baja el registro, se debe setear la fecha de baja
void  Registro :: SetEstado(bool _estado){
     estado = _estado;
     if(!_estado){
        Fecha fecha;
        fechaBaja = fecha.GetFechaActual();
     }
}

void  Registro :: SetId(int _ID){ID = _ID;}








