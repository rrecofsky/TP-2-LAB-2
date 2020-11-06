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

const char* Persona ::GetUser(){return user;}
const char* Persona ::GetPass(){return pass;}

//Sets

void  Persona :: SetNombres(const char * _nombres){strcpy(nombres,_nombres);}
void  Persona :: SetApellidos(const char *_apellidos){ strcpy(apellidos,_apellidos);}
void  Persona :: SetFechaNacimiento(Fecha _fechaNacimiento){fecha_nacimiento = _fechaNacimiento;}
void  Persona :: SetDNI(int _dni){ DNI = _dni;}
void  Persona :: SetGenero(char _genero){ genero = _genero;}

void  Persona :: ChangeUserName(const char*_userName){strcpy(user,_userName);}
void  Persona :: ChangeUserPass(const char*_password){strcpy(pass,_password);}

//Busquedas

//Compara las personas por ID o DNI

bool  Persona :: comparaID(Registro *temp){
        Persona *aux=(Persona *)temp;
        if(ID==aux->ID ||DNI == aux->DNI || strcmp(user,aux->user) == 0) return true;
        return false;
}

void  Persona :: Mostrar(){
        cout<<"Nombres: "<<nombres<<endl;
        cout<<"Apellidos: "<<apellidos<<endl;
        cout<<"Genero: "<<genero<<endl;
        cout<<"Fecha Nacimiento: ";
        fecha_nacimiento.GetFecha();
        cout<<endl;
        cout<<"DNI: "<<DNI<<endl;
        cout<<"user: "<<user<<endl;
        cout<<"pass: "<<pass<<endl;
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
        cin.clear(); // unset failbit
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); // skip bad input
        cout<<"Nombre Usuario del sistema: ";
        cin.getline(user,50);
        cout<<endl;
        cin.clear(); // unset failbit
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); // skip bad input
        cout<<"Password Usuario del sistema: ";
        cin.getline(pass,50);
        cout<<endl;
        system("PAUSE");
        cout<<"user: "<<user<<endl;
        cout<<"pass: "<<pass<<endl;
        system("PAUSE");
        return;
}


int   Persona :: getSize(){return sizeof *this;}


