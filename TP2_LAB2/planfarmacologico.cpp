#include "planfarmacologico.h"
#include "paciente.h"
#include <iostream>

using namespace std;

///GETS

Fecha PlanFarmacologico :: GetEmision(){return emision;}
Fecha PlanFarmacologico :: GetActualizacion(){return actualizacion;}
int   PlanFarmacologico :: GetIdPaciente(){return ID_Paciente;}
int   PlanFarmacologico :: GetIdProfesional(){return ID_Profesional;}
const char* PlanFarmacologico :: GetNotas(){return notas;}

///GETS PLM
int   PlanFarmacologico :: getSize(){return sizeof *this;}
bool  PlanFarmacologico :: comparaID(Registro *temp){
            PlanFarmacologico *aux=(PlanFarmacologico *)temp;
            if(aux->ID == ID) return true;
            return false;
}

//El plan farmacologico es cargado por un Profesional, con dicho
//ID se carga el src de la relacion y el profesional setea el
//tgt de la relacion si es que encuentra un paciente, sino se descarta el plan
void  PlanFarmacologico :: Cargar(int _idProfesional){
      Fecha f;
      int nroAfiliado;
      Paciente pcte;
      //PRIMERO SE BUSCA EL AFILIADO, SI EXISTE, SE CARGA EL PLAN.
      cout<<"Ingrese el numero de afiliado del paciente: "<<nroAfiliado;
      ///IMPLEMENTAR UN METODO EN PACIENTE QUE BUSQUE EL REGISTRO POR NRO AFILIADO, DNI, APELLIDO Y NOMBRE
      pcte.GetIdPorNroAfiliado(nroAfiliado);
      if (pcte.GetIdPorNroAfiliado(nroAfiliado)!=0)
      {
          ID_Paciente = pcte.GetIdPorNroAfiliado(nroAfiliado);
          cout<<"Ingrese la fecha de emision del plan: ";
          f.CargarFecha();
          emision = f;

          cout<<endl;
          cout<<"Ingrese el nombre: ";
          cin.ignore();
          cin.getline(notas,500);
      }else{
                cout<<"No se ha encontrado un paciente con el Nro de afiliado: "<<nroAfiliado<<endl;
           }
      return;
}


void  PlanFarmacologico :: Mostrar(){

      cout<<"Fecha de Emision: ";
      emision.GetFecha();
      cout<<endl;
      cout<<"Fecha de Actualizacion: ";
      actualizacion.GetFecha();
      cout<<endl;
      cout<<"Datos del Paciente: "<<ID_Paciente<<endl; ///HACER METODO QUE BUSQUE EL PACIENTE POR ID
      cout<<"Datos del Profesional: "<<ID_Profesional<<endl; ///HACER FX QUE BUSQUE EL PROFESIONAL POR ID
      cout<<"Notas: "<<notas<<endl;
      return;
}

///SETs

void  PlanFarmacologico :: SetEmision(Fecha _fechaEmision){emision = _fechaEmision;}
void  PlanFarmacologico :: SetActualizacion(Fecha _fechaActualizacion){ actualizacion = _fechaActualizacion; }
void  PlanFarmacologico :: SetIdPaciente(int _idPaciente){ ID_Paciente = _idPaciente;}
void  PlanFarmacologico :: SetIdProfesional(int _idProfesional){ ID_Profesional = _idProfesional;}
void  PlanFarmacologico :: SetNotas(const char* _notas){strcpy(notas,_notas);}

