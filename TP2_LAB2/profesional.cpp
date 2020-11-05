#include "profesional.h"
#include <iostream>
#include <limits>

using namespace std;

int  Profesional :: GetMatricula(){return matricula;}
int  Profesional :: GetEspecialidad(){return ID_especialidad;}
//SETs
void Profesional :: SetMatricula(int _matricula){matricula = _matricula;}
void Profesional :: SetEspecialidad(int _idEspecialidad){ID_especialidad = _idEspecialidad;}

///MOSTRAR Y CARGAR

int matricula;
int ID_especialidad;

void Profesional :: Cargar(){

    Persona::Cargar();
    cout<<"Nro de matricula: ";
    cin>>matricula;
    cout<<endl;
    cout<<"ID ID_especialidad: ";
    cin>>ID_especialidad;
    return;
}

void Profesional :: Mostrar(){

    Persona :: Mostrar();
    cout<<"Nro de matricula: "<<matricula<<endl;
    cout<<"ID ID_especialidad: "<<ID_especialidad<<endl;
    cout<<endl;
    cout<<endl;
}
