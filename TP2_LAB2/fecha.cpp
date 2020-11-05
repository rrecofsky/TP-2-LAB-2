#include "fecha.h"
#include <ctime>
#include <iostream>

using namespace std;

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
    cout<<endl;
    cout<<"Ingrese el mes: ";
    cin>>mes;
    cout<<endl;
    cout<<"Ingrese el anio: ";
    cin>>anio;
    cout<<endl;
    return;
}

void Fecha :: GetFecha(){
    cout<<dia<<"/"<<mes<<"/"<<anio;
}


