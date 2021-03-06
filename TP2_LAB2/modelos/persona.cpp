#include "persona.h"
#include <iostream>
#include <limits>
#include "fecha.h"

using namespace std;

//Gets


const char * Persona :: GetNombres(){return nombres;}
const char * Persona :: GetApellidos(){return apellidos; }
Fecha Persona :: GetFechaNacimiento(){ return fecha_nacimiento; }
int   Persona :: GetDNI(){return DNI;}
char  Persona :: GetGenero(){ return genero; }
bool  Persona :: PoseeUsuario(){return poseeUsuario;}

int   Persona :: GetEdad(){

    int respFech , respMes;
    Fecha fecha_actual = fecha_actual.GetFechaActual();

    if ( fecha_actual.GetFechaActual().GetDia() < fecha_nacimiento.GetDia()  )
    {   //En caso de ser menor la fecha actual que el nacimiento
        fecha_actual.SetDia(fecha_actual.GetDia()+30); // Se le suma los 30 d�as (1 mes) a la fecha actual
        fecha_actual.SetMes(fecha_actual.GetMes()-1); // Se le resta un mes (30 d�as) al mes actual
        respFech =  fecha_actual.GetDia() - fecha_nacimiento.GetDia() ; //Se le resta fecha nacimiento al actual
    }
    else //En caso de ser mayor la fecha actual que el nacimiento
        respFech =  fecha_actual.GetDia() - fecha_nacimiento.GetDia();  //Se le resta fecha nacimiento al actual

    if( fecha_actual.GetMes() < fecha_nacimiento.GetMes() )
    {   //En caso de ser menor el mes actual que el nacimiento
        fecha_actual.SetMes(fecha_actual.GetMes()+12); // Se le suma los 12 meses (1 a�o) al mes actual
        fecha_actual.SetAnio(fecha_actual.GetAnio()-1); // Se le resta 1 a�o ( 12 meses) al a�o actual
        respMes = fecha_actual.GetMes() - fecha_nacimiento.GetMes() ; //Se le resta a�o nacimiento al actual
    }
    else //En caso de ser mayor el mes actual que el nacimiento
        respMes = fecha_actual.GetMes() - fecha_nacimiento.GetMes() ; //Se le resta a�o nacimiento al actual

    return fecha_actual.GetAnio() - fecha_nacimiento.GetAnio();

}

//Sets

void  Persona :: SetNombres(const char * _nombres){strcpy(nombres,_nombres);}
void  Persona :: SetApellidos(const char *_apellidos){ strcpy(apellidos,_apellidos);}
void  Persona :: SetFechaNacimiento(Fecha _fechaNacimiento){fecha_nacimiento = _fechaNacimiento;}
void  Persona :: SetDNI(int _dni){ DNI = _dni;}
void  Persona :: SetGenero(char _genero){ genero = _genero;}
void  Persona :: SetPoseeUsuario(){poseeUsuario = true;}

//VIRTUAL


int   Persona :: getSize(){return sizeof *this;}
bool  Persona :: comparaID(Registro *temp){
        Persona *aux=(Persona *)temp;

        if( (DNI != -1 && aux->DNI != -1 )&& DNI == aux->DNI ) return true;
        if(ID == aux->ID ) return true;

        return false;
}


