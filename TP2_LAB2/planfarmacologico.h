#ifndef PLANFARMACOLOGICO_H_INCLUDED
#define PLANFARMACOLOGICO_H_INCLUDED

#include "registro.h"
#include "fecha.h"
#include "iostream"
#include "cstring"

class PlanFarmacologico:public Registro
{
    private:
        Fecha emision;
        Fecha actualizacion;
        int   ID_Paciente;
        int   ID_Profesional;
        char  notas[500];
    public:
        PlanFarmacologico(Fecha fe, Fecha fa, int idpc, int idpf, const char * n = ""):Registro()
        {
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
        const char *GetNotas();
        //SETs
        void  SetEmision(Fecha);
        void  SetActualizacion(Fecha);
        void  SetIdPaciente(int);
        void  SetIdProfesional(int);
        void  SetNotas(const char*);
        //METODOS REDEFINIDOS HEREDADOS DE REGISTRO
        void Cargar(int); //Puede estar en una capa de logica
        void Mostrar(); //Puede estar en una capa de logica
        bool comparaID(Registro *); //Puede estar en una capa de logica
        int getSize();
        PlanFarmacologico& operator = (Registro *temp){

            PlanFarmacologico *aux=(PlanFarmacologico *)temp;
            emision = aux->emision;
            actualizacion =aux->actualizacion;
            ID_Paciente = aux->ID_Paciente;
            ID_Profesional = aux->ID_Profesional;
            strcpy(this->notas,aux->notas);
        }
};


#endif // PLANFARMACOLOGICO_H_INCLUDED
