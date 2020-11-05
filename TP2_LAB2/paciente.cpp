#include "paciente.h"
#include <iostream>
#include <limits>

using namespace std;

//GETs

int Paciente :: GetNroAfiliado(){return nro_Afiliado;}
int Paciente :: GetIdCobertura(){return ID_Conertura;}
int Paciente :: GetIdInforme(){return ID_Informe;}
int Paciente :: GetIdPlanFarmacologico(){return ID_PlanFarmacologico;}

//SETs

void Paciente :: SetNroAfiliado(int _nroAfiliado){nro_Afiliado = _nroAfiliado;}
void Paciente :: SetIdCObertura(int _idCobertura){ID_Conertura = _idCobertura;}
void Paciente :: SetIdInforme(int _idInforme){ ID_Informe = _idInforme;}


//Carga


void Paciente :: Cargar(){

    persona:Cargar();
    cout<<"Nro de Afiliado: ";
    cin>>nro_Afiliado;
    cout<<endl;
    cout<<"ID Cobertura: ";
    cin>>ID_Conertura;
    return;
}

void Paciente :: Mostrar(){

    Persona : Mostrar();
    cout<<"Nro de Afiliado: "<<nro_Afiliado<<endl;
    cout<<"ID Cobertura: "<<ID_Conertura<<endl;
    cout<<endl;
    cout<<endl;
}

