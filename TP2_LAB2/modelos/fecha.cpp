#include "../modelos/fecha.h"
#include <ctime>
#include <iostream>
#include <cstring>
#include "../util/rlutil.h"

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

///SETS

void  Fecha :: SetDia(int _dia){dia = _dia;}
void  Fecha :: SetMes(int _mes){mes = _mes;}
void  Fecha :: SetAnio(int _anio){anio = _anio;}













