#include "../interfaces/interfazfecha.h"
#include "../validaciones/validaciones.h"

string InterfazFecha :: GetfechaFormateada(Fecha fecha){
    ValidacionesTipoDato valTDato;
    InterfazFecha IF;
    string dia(valTDato.intToStr(fecha.GetDia())), mes(valTDato.intToStr(fecha.GetMes())), anio(valTDato.intToStr(fecha.GetAnio()));
    return dia+"/"+mes+"/"+anio;
  }

Fecha  InterfazFecha :: CargarFecha(){
    Fecha fechaAux;
    ValidacionesTipoDato valTipoDato;
    ValidacionesGenerales valGeneral;
    do{
        cout<<"INGRESE EL DIA";
        fechaAux.SetDia(valGeneral.ValidarDia());
        cout<<"INGRESE EL MES";
        fechaAux.SetMes(valGeneral.ValidarMes());
        cout<<"INGRESE EL ANIO";
        fechaAux.SetAnio(valGeneral.ValidarAnio());
        if (!valGeneral.EsBiciesto(fechaAux))
            cout<<"FECHA INVALIDA, INGRESE UNA FECHA VALIDA: "<<GetfechaFormateada(fechaAux)<<endl;
        else
            return fechaAux;
    }while(true);
}
