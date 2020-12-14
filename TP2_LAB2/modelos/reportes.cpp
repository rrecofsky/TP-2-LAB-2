#include <iostream>
#include <cstdlib>
#include "../modelos/reportes.h"
#include "../modelos/archivo.h"
#include "../util/rlutil.h"
#include "../interfaces/interfazentidades.h"
#include "../validaciones/validaciones.h"

using namespace std;
using namespace rlutil;

extern const char *FILE_PACIENTES;
extern const char *FILE_PROFESIONALES;

///PROFESIONALES
void Reporte :: MostrarProfesionalesOrdenadosPorApellido(){
    cls();
    cout<<"LISTAR PROFESIONALES ORDENADOS ALFABETICAMENTE"<<endl<<endl<<endl;
    Archivo profesionales(FILE_PROFESIONALES,sizeof(Profesional),true);
    ValidacionesTipoDato validaTDato;
    Profesional prof, aux, *profe;
    int cantReg, i=0, j, posmin;
    cantReg=profesionales.getCantidadRegistros();
    if( cantReg!= 0){
        InterfazPersona IP;
        InterfazProfesional IPF;
        IP.MostrarCabeceraPersona();
        cout << left;
        cout << setw(12)  << "MATRICULA";
        cout << setw(12)  << "ESPECIALIDAD";
        cout << endl;

        profe = (Profesional *) malloc(cantReg * sizeof(Profesional));
        if (profe == NULL) {
            free(profe);
            return;
        }
        while (fread(&prof,sizeof(Profesional),1,profesionales.GetPF())){
                    if (i<cantReg) profe[i++]=prof;
            }
         for(i=0;i<cantReg-1;i++){///Ordena el vector
            posmin=i;
            for(j=i+1;j<cantReg;j++){
              if(strcmp(profe[j].GetApellidos(),profe[posmin].GetApellidos())<0) posmin=j;
              }
            aux=profe[i];
            profe[i]=profe[posmin];
            profe[posmin]=aux;
        }
        for(i=0;i<cantReg;i++){ ///muestro el vector ordenado
           IPF.MostrarProfesional(profe[i]);
        }
        free(profe);

    }else  validaTDato.generar_Mensaje(1,"NO EXISTEN USUARIOS CARGADOS EN EL SISTEMA");
    cout<<endl<<endl;
    system("PAUSE");
    return;
}

void Reporte::MostrarProfesionalesOrdenadosPorEspecialidad(){}

///PACIENTES
void Reporte :: MostrarPacientesOrdenadosPorApellido(){
cls();
    cout<<"LISTAR PACIENTES ORDENADOS ALFABETICAMENTE"<<endl<<endl<<endl;
    Archivo pacientes(FILE_PACIENTES,sizeof(Paciente),true);
    ValidacionesTipoDato validaTDato;
    Paciente pac, aux, *paci;
    int cantReg, i=0, j, posmin;
    cantReg=pacientes.getCantidadRegistros();
    if( cantReg!= 0){
        InterfazPersona IP;
        InterfazPaciente IPA;
        IP.MostrarCabeceraPersona();
        cout << left;
        cout << setw(16)  << "NRO AFILIADO";
        cout << setw(12)  << "COBERTURA";
        cout << endl;

        paci = (Paciente *) malloc(cantReg * sizeof(Paciente));
        if (paci == NULL) {
            free(paci);
            return;
        }
        while (fread(&pac,sizeof(Paciente),1,pacientes.GetPF())){
                    if (i<cantReg) paci[i++]=pac;
            }
         for(i=0;i<cantReg-1;i++){///Ordena el vector
            posmin=i;
            for(j=i+1;j<cantReg;j++){
              if(strcmp(paci[j].GetApellidos(),paci[posmin].GetApellidos())<0) posmin=j;
              }
            aux=paci[i];
            paci[i]=paci[posmin];
            paci[posmin]=aux;
        }
        for(i=0;i<cantReg;i++){ ///muestro el vector ordenado
           IPA.MostrarPaciente(paci[i]);
        }
        free(paci);

    }else  validaTDato.generar_Mensaje(1,"NO EXISTEN USUARIOS CARGADOS EN EL SISTEMA");
    cout<<endl<<endl;
    system("PAUSE");
    return;
}

void MostrarPacientesOrdenadosPorNroHistoria(){}
