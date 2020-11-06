#include "persona.h"
#include <iostream>
#include <limits>



using namespace std;

//Gets

const char * Persona :: GetNombres(){return nombres;}
const char * Persona :: GetApellidos(){return apellidos; }
Fecha Persona :: GetFechaNacimiento(){ return fecha_nacimiento; }
int   Persona :: GetDNI(){return DNI;}
char  Persona :: GetGenero(){ return genero; }

//Sets

void  Persona :: SetNombres(const char * _nombres){strcpy(nombres,_nombres);}
void  Persona :: SetApellidos(const char *_apellidos){ strcpy(apellidos,_apellidos);}
void  Persona :: SetFechaNacimiento(Fecha _fechaNacimiento){fecha_nacimiento = _fechaNacimiento;}
void  Persona :: SetDNI(int _dni){ DNI = _dni;}
void  Persona :: SetGenero(char _genero){ genero = _genero;}

//Busquedas

//Compara las personas por ID o DNI

bool  Persona :: comparaID(Registro *temp){
        Persona *aux=(Persona *)temp;
        if(ID==aux->ID ||DNI == aux->DNI ) return true;
        return false;
}

void  Persona :: Mostrar(){
        cout<<"Nombres: "<<nombres<<endl;
        cout<<"Apellidos: "<<apellidos<<endl;
        cout<<"Genero: "<<genero<<endl;
        cout<<"DNI: "<<DNI<<endl;
        cout<<"Fecha Alta: "<<fechaAlta.GetFechaConFormato()<<endl;
        cout<<"Fecha Alta: "<<fechaBaja.GetFechaConFormato()<<endl;
        return;
}

void  Persona :: Cargar()
{
        cout<<"Nombres: ";
        cin.clear(); // unset failbit
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); // skip bad input
        cin.getline(nombres,50);
        cout<<endl;
        cout<<"Apellidos: ";
        cin.getline(apellidos,50);
        cout<<endl;
        cout<<"Genero: ";
        cin>>genero;
        cout<<"Fecha de Nacimiento: ";
        fecha_nacimiento.CargarFecha();
        cout<<endl;
        cout<<"DNI: ";
        cin>>DNI;
        cout<<endl;
        return;
}


int   Persona :: getSize(){return sizeof *this;}


