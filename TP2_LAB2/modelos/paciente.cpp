#include "paciente.h"
#include <iostream>
#include <limits>
#include "../util/rlutil.h"

using namespace rlutil;
using namespace std;

//GETs

int Paciente :: GetNroAfiliado(){return nro_Afiliado;}
int Paciente :: GetIdCobertura(){return ID_Cobertura;}
int Paciente :: GetIdInforme(){return ID_Informe;}
int Paciente :: GetIdPlanFarmacologico(){return ID_PlanFarmacologico;}

//SETs

void Paciente :: SetNroAfiliado(int _nroAfiliado){nro_Afiliado = _nroAfiliado;}
void Paciente :: SetIdCObertura(int _idCobertura){ID_Cobertura = _idCobertura;}
void Paciente :: SetIdInforme(int _idInforme){ ID_Informe = _idInforme;}


//Carga


void Paciente :: Cargar(){

    persona:Cargar();
    cout<<"Nro de Afiliado: ";
    cin>>nro_Afiliado;
    cout<<endl;
    cout<<"ID Cobertura: ";
    cin>>ID_Cobertura;
    cout<<endl;
    return;
}

void Paciente :: Mostrar(){

    cout << left;
    cout << setw(12) << ID;
    cout << setw(12) << nombres;
    cout << setw(12) << apellidos;
    cout << setw(12) << genero;
    cout << setw(12) << DNI;
    cout << setw(12) << GetEdad();
    cout << setw(16) << ID_Cobertura;
    cout << setw(12) <<"SIN IMPLEMENTAR";
    cout<<endl;
}

void Paciente ::  Modificar(){return;}

istream & operator>>(istream &dato, Fecha &val)
{
  dato>>val;
  return dato;
}

int Paciente :: getSize(){return sizeof *this;}

bool  Paciente :: comparaID(Registro *temp){
        Paciente *aux=(Paciente *)temp;

        if(DNI != 0 && DNI == aux->DNI ) return true;
        if( ID == aux->ID  ) return true;

        return false;
}

