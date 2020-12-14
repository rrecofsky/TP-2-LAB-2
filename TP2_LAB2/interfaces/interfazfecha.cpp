#include "../interfaces/interfazfecha.h"
#include "../validaciones/validaciones.h"

string InterfazFecha :: GetfechaFormateada(Fecha fecha){
    ValidacionesTipoDato valTDato;
    InterfazFecha IF;
    string dia(valTDato.intToStr(fecha.GetDia())), mes(valTDato.intToStr(fecha.GetMes())), anio(valTDato.intToStr(fecha.GetAnio()));
    return dia+"/"+mes+"/"+anio;
  }

bool InterfazFecha :: EsFechaPosterior(Fecha _fecha1, Fecha _fecha2){
    if (_fecha1.GetAnio() > _fecha2.GetAnio() )
        return true;
    else
        if (_fecha1.GetAnio() == _fecha2.GetAnio() && _fecha1.GetMes() > _fecha2.GetMes())
            return true;
            else
                if (_fecha1.GetAnio() == _fecha2.GetAnio() && _fecha1.GetMes() == _fecha2.GetMes() && _fecha1.GetDia() > _fecha2.GetDia())
                    return true;

    return false;
}

Fecha  InterfazFecha :: CargarFecha(bool validaAnio = true){

    Fecha fechaAux;
    ValidacionesTipoDato valTipoDato;
    ValidacionesGenerales valGeneral;
    do{
        cout<<"INGRESE EL DIA";
        fechaAux.SetDia(valGeneral.ValidarDia());
        cout<<"INGRESE EL MES";
        fechaAux.SetMes(valGeneral.ValidarMes());
        cout<<"INGRESE EL ANIO";
        if (validaAnio == true)
            fechaAux.SetAnio(valGeneral.ValidarAnio());
        else{
                int anio = 0;
                do{
                    cout <<endl;
                    cin >> anio;
                    if (anio > fechaAux.GetFechaActual().GetAnio() + 4 ){
                        valTipoDato.generar_Mensaje(0,strcat("EL ANIO NO PUEDE SER MAYOR A ", (char*)fechaAux.GetFechaActual().GetAnio() + 4 ));
                    }else{
                            fechaAux.SetAnio(anio);
                            return fechaAux;
                        }
                }
                while(true);
            }
        if (!valGeneral.EsBiciesto(fechaAux))
            valTipoDato.generar_Mensaje(0,"FECHA INVALIDA, INGRESE UNA FECHA VALIDA");
        else
            return fechaAux;
    }while(true);
}
