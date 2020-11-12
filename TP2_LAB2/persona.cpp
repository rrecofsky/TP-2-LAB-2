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
int   Persona :: GetEdad(){

    int respFech , respMes;
    Fecha fecha_actual = fecha_actual.GetFechaActual();

    if ( fecha_actual.GetFechaActual().GetDia() < fecha_nacimiento.GetDia()  )
    {   //En caso de ser menor la fecha actual que el nacimiento
        fecha_actual.SetDia(fecha_actual.GetDia()+30); // Se le suma los 30 días (1 mes) a la fecha actual
        fecha_actual.SetMes(fecha_actual.GetMes()-1); // Se le resta un mes (30 días) al mes actual
        respFech =  fecha_actual.GetDia() - fecha_nacimiento.GetDia() ; //Se le resta fecha nacimiento al actual
    }
    else //En caso de ser mayor la fecha actual que el nacimiento
        respFech =  fecha_actual.GetDia() - fecha_nacimiento.GetDia();  //Se le resta fecha nacimiento al actual

    if( fecha_actual.GetMes() < fecha_nacimiento.GetMes() )
    {   //En caso de ser menor el mes actual que el nacimiento
        fecha_actual.SetMes(fecha_actual.GetMes()+12); // Se le suma los 12 meses (1 año) al mes actual
        fecha_actual.SetAnio(fecha_actual.GetAnio()-1); // Se le resta 1 año ( 12 meses) al año actual
        respMes = fecha_actual.GetMes() - fecha_nacimiento.GetMes() ; //Se le resta año nacimiento al actual
    }
    else //En caso de ser mayor el mes actual que el nacimiento
        respMes = fecha_actual.GetMes() - fecha_nacimiento.GetMes() ; //Se le resta año nacimiento al actual

    return fecha_actual.GetAnio() - fecha_nacimiento.GetAnio();

}

//Sets

void  Persona :: SetNombres(const char * _nombres){strcpy(nombres,_nombres);}
void  Persona :: SetApellidos(const char *_apellidos){ strcpy(apellidos,_apellidos);}
void  Persona :: SetFechaNacimiento(Fecha _fechaNacimiento){fecha_nacimiento = _fechaNacimiento;}
void  Persona :: SetDNI(int _dni){ DNI = _dni;}
void  Persona :: SetGenero(char _genero){ genero = _genero;}

//Comparaciones

bool  Persona :: comparaID(Registro *temp){
        Persona *aux=(Persona *)temp;

        if(DNI != 0 && DNI == aux->DNI ) return true;
        if( ID == aux->ID  ) return true;

        return false;
}

//Sobrecargas

istream & operator>>(istream &dato, Fecha &val)
{
  dato>>val;
  return dato;
}

void  Persona :: Mostrar(){
        cout<<"NOMBRES: "<<nombres<<endl;
        cout<<"APELLIDOS: "<<apellidos<<endl;
        cout<<"GENERO: "<<genero<<endl;
        cout<<"DNI: "<<DNI<<endl;
        cout<<"EDAD: "<<GetEdad()<<endl;
        cout<<"FECHA DE NACIMIENTO: ";
        fecha_nacimiento.GetFecha();
        cout<<endl;
        return;
}

void  Persona :: Cargar()
{
        cout<<"NOMBRES: ";
        cin.clear(); // unset failbit
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); // skip bad input
        cin.getline(nombres,50);
        cout<<endl;
        cout<<"APELLIDOS: ";
        cin.getline(apellidos,50);
        cout<<endl;
        cout<<"GENERO: ";
        cin>>genero;
        cout<<"FECHA DE NACIMIENTO: ";
        fecha_nacimiento.CargarFecha();
        cout<<endl;
        cout<<"DNI: ";
        cin>>DNI;
        cout<<endl;
        return;
}


int   Persona :: getSize(){return sizeof *this;}


