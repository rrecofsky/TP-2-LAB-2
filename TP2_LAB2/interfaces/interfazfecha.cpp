#include "../interfaces/interfazfecha.h"
#include "../validaciones/validaciones.h"

const char* InterfazFecha :: GetfechaFormateada(Fecha fecha){
    char str[10]={};//dd/mm/aaaa
    char dd[2], mm[2], aaaa[4];
    return strcat(strcat(strcat(strcat(strcat(str,itoa(fecha.GetDia(),dd,10)),"/"),itoa(fecha.GetMes(),mm,10)),"/"),itoa(fecha.GetAnio(),aaaa,10));
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
            cout<<"FECHA INVALIDA, INGRESE UNA FECHA VALIDA: "<<valGeneral.GetFechaConFormato(fechaAux)<<endl;
        else
            return fechaAux;
    }while(true);
}
