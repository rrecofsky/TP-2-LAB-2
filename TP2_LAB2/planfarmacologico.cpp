#include "planfarmacologico.h"
#include "paciente.h"
#include "profesional.h"
#include <iostream>
#include "fecha.h"
#include "archivo.h"

extern const char *FILE_PACIENTES;
extern const char *FILE_PROFESIONALES;

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
      Archivo archPacientes(FILE_PACIENTES,sizeof(Paciente));
      Paciente pacienteSistema;
      int DNI;

      cout<<"Ingrese el DNI del paciente: ";
      cin>>DNI;
      //le setio el DNI al registro para que lo busque por ese campo
      pacienteSistema.SetDNI(DNI);

      //retorna la pos del paciente en el archivo, si es que lo encontro y modifica el registro con el paciente
      int pos_paciente = archPacientes.buscarRegistro(pacienteSistema);

      if (pos_paciente != -1) //--> encontro el registro en el archivo
      {
          ID_Profesional = _idProfesional;
          ID_Paciente = pacienteSistema.GetId();
          cout<<"Ingrese la fecha de emision del plan: ";
          emision.CargarFecha();
          cout<<endl;
          cout<<"Ingrese las Notas del Plan: ";
          cin.ignore();
          cin.getline(notas,500);
      }else{
                cout<<"No se ha encontrado un paciente con el DNI: "<<DNI<<endl;
           }
      return;
}


void  PlanFarmacologico :: Mostrar(){

      Archivo archPacientes(FILE_PACIENTES,sizeof(Paciente));
      Paciente pacienteSistema;
      pacienteSistema.SetId(ID_Paciente);

      Archivo archProfesionales(FILE_PROFESIONALES,sizeof(Profesional));
      Profesional profesionalSistema;
      profesionalSistema.SetId(ID_Profesional);

      //retorna el paciente que encontro en el archivo, si es que lo hizo.
      int pos_paciente = archPacientes.buscarRegistro(pacienteSistema);
      int pos_profesional = archPacientes.buscarRegistro(profesionalSistema);

      cout<<"Fecha de Emision: ";
      emision.GetFecha();
      cout<<endl;
      cout<<"Fecha de Actualizacion: ";
      actualizacion.GetFecha();
      cout<<endl;
      cout<<"Datos del Paciente: "<<pacienteSistema.GetNombres()<<" - "<<pacienteSistema.GetApellidos()<<endl;
      cout<<"Datos del Profesional: "<<profesionalSistema.GetNombres()<<" - "<<profesionalSistema.GetApellidos()<<endl;
      cout<<"Notas: "<<notas<<endl;


      return;
}

///SETs

void  PlanFarmacologico :: SetEmision(Fecha _fechaEmision){emision = _fechaEmision;}
void  PlanFarmacologico :: SetActualizacion(Fecha _fechaActualizacion){ actualizacion = _fechaActualizacion; }
void  PlanFarmacologico :: SetIdPaciente(int _idPaciente){ ID_Paciente = _idPaciente;}
void  PlanFarmacologico :: SetIdProfesional(int _idProfesional){ ID_Profesional = _idProfesional;}
void  PlanFarmacologico :: SetNotas(const char* _notas){strcpy(notas,_notas);}

