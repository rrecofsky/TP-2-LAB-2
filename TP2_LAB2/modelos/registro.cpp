#include "../modelos/registro.h"
#include "../modelos/fecha.h"
#include "../interfaces/interfazfecha.h"
#include <iostream>

using namespace std;

//Gets
int   Registro :: GetId(){ return ID; }
bool  Registro :: GetEstado(){ return estado; }
Fecha Registro :: GetFechaAlta(){ return fechaAlta; }
Fecha Registro :: GetFechaBaja(){ return fechaBaja; }
void  Registro :: GetInformacionGeneral(){
        InterfazFecha IF;
        cout<<"FECHA DE ALTA: ";
        IF.GetfechaFormateada(fechaAlta);
        cout<<endl;
        cout<<"FECHA DE BAJA: ";
        IF.GetfechaFormateada(fechaBaja);
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










