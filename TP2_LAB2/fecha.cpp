#include "fecha.h"
#include <ctime>
#include <iostream>
#include <cstring>
#include "rlutil.h"

using namespace std;
using namespace rlutil;

///GETS

int   Fecha :: GetDia(){return dia;}
int   Fecha :: GetMes(){return mes;}
int   Fecha :: GetAnio(){return anio;}

Fecha Fecha :: GetFechaActual()
{
     Fecha fecha;
     time_t t = time(0);   // get time now
     struct tm * now = localtime( & t );
     fecha.anio = (now->tm_year + 1900);
     fecha.dia =  now->tm_mday;
     fecha.mes = (now->tm_mon + 1);
     return fecha;
}

const char * Fecha ::  GetFechaConFormato(){
    //Consultar por que no funciona!
    char str[10];//itoa para convertir., val,str,base 10. **** string.c_str() --> convertir a string.
    return strcat(strcat(strcat(strcat(strcat(str,(char*)dia),"/"),(char*)mes),"/"),(char*)anio);
}

///SETS

void  Fecha :: SetNuevaFecha(int _dia,int _mes,int _anio){
    dia = _dia;
    mes = _mes;
    anio = _anio;
}

void  Fecha :: SetDia(int _dia){dia = _dia;}
void  Fecha :: SetMes(int _mes){mes = _mes;}
void  Fecha :: SetAnio(int _anio){anio = _anio;}

///CARGAS y CONSULTAS

void  Fecha :: CargarFecha(){
    cout<<"Ingrese el dia: ";
    cin>>dia;
    cout<<"Ingrese el mes: ";
    cin>>mes;
    cout<<"Ingrese el anio: ";
    cin>>anio;
    return;
}

void Fecha :: GetFecha(){
    cout<<dia<<"/"<<mes<<"/"<<anio;
}





