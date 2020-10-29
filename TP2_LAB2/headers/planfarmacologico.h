#ifndef PLANFARMACOLOGICO_H_INCLUDED
#define PLANFARMACOLOGICO_H_INCLUDED

#include "../headers/registro.h"
#include "../headers/fecha.h"
#include "iostream"
#include "cstring"

class PlanFarmacologico:public Registro{
    private:
        Fecha emision;
        Fecha actualizacion;
        int   ID_Paciente;
        int   ID_Profesional;
        char  notas[500];
        bool  estado;
    public:
        PlanFarmacologico(Fecha fe, Fecha fa, int idpc, int idpf, const char * n = ""){
            emision           = fe;
            actualizacion     = fa;
            ID_Paciente       = idpc;
            ID_Profesional    = idpf;
            estado            = true;
            strcpy(notas,n);
        }
        ~PlanFarmacologico(){};
        //GETS
        Fecha GetEmision();
        Fecha GetActualizacion();
        int   GetIdPaciente();
        int   GetIdProfesional();
        char *GetNotas();
        bool  GetEstado();
        //SETs
        void  SetEmision(Fecha);
        void  SetActualizacion(Fecha);
        void  SetIdPaciente(int);
        void  SetIdProfesional(int);
        void  SetNotas(const char*);
        void  SetEstado(bool);
};


#endif // PLANFARMACOLOGICO_H_INCLUDED
