#ifndef PLANFARMACOLOGICO_H_INCLUDED
#define PLANFARMACOLOGICO_H_INCLUDED

#include "../modelos/registro.h"
#include "../modelos/fecha.h"
#include <iostream>
#include <cstring>

class PlanFarmacologico:public Registro
{
    private:
        Fecha emision;
        int   ID_Paciente;
        int   ID_Profesional;
        int   ID_DetallePlan;
        char  notas[500];
        Fecha FechaFinDelPlan;
    public:
        PlanFarmacologico(int _idPaciente = -1, int _idProfesional = -1, const char * _notas = "", int _idDetallePLan = -1):Registro()
        {
            ID_Paciente       = _idPaciente;
            ID_Profesional    = _idProfesional;
            ID_DetallePlan    = _idDetallePLan;
            strcpy(notas,_notas);
        }
        ~PlanFarmacologico(){};
        //GETS
        Fecha GetEmision();
        Fecha GetActualizacion();
        int   GetIdPaciente();
        int   GetIdProfesional();
        const char *GetNotas();
        int   GetIdDetallePlan();
        Fecha GetFechaFinDelPlan();
        //SETs
        void  SetEmision(Fecha);
        void  SetActualizacion(Fecha);
        void  SetIdPaciente(int);
        void  SetIdProfesional(int);
        void  SetNotas(const char*);
        void  SetIdDetallePlan(int);
        void  SetFechaFinDelPlan(Fecha);
        //METODOS REDEFINIDOS HEREDADOS DE REGISTRO
        int getSize();
        bool comparaID(Registro *temp);
         PlanFarmacologico& operator = (Registro *temp){
            PlanFarmacologico *aux=(PlanFarmacologico *)temp;
            emision = aux->emision;
            ID_Paciente = aux->ID_Paciente;
            ID_Profesional = aux->ID_Profesional;
            ID_DetallePlan = aux->ID_DetallePlan;
            FechaFinDelPlan = aux->FechaFinDelPlan;
            strcpy(this->notas,aux->notas);
            estado           = aux->estado;
            ID               = aux->ID;
            fechaAlta        = aux->fechaAlta;
            fechaBaja        = aux->fechaBaja;
        }

};





#endif // PLANFARMACOLOGICO_H_INCLUDED
