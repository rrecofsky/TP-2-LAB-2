#include "../modelos/registro.h"
#include "../modelos/fecha.h"
#include <iostream>

using namespace std;

Registro::Registro(){
    fechaAlta = fechaAlta.GetFechaActual();
    estado = true;
    ID = -1;
}

//Gets
int   Registro :: GetId(){ return ID; }
bool  Registro :: GetEstado(){ return estado; }
Fecha Registro :: GetFechaAlta(){ return fechaAlta; }
Fecha Registro :: GetFechaBaja(){ return fechaBaja; }
void  Registro :: GetInformacionGeneral(){
        cout<<"FECHA DE ALTA: ";
       // fechaAlta.GetFecha();
        cout<<endl;
        cout<<"FECHA DE BAJA: ";
       // fechaBaja.GetFecha();
        cout<<endl;
        cout<<"ID: "<<ID<<endl;
}

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










