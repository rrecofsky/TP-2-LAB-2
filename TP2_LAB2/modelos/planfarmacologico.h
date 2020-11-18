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
    public:
        PlanFarmacologico(int _idPaciente = -1, int _idProfesional = -1, const char * _notas = "", int _idDetallePLan = -1):Registro()
        {   Fecha f;
            emision           = f;
            ID_Paciente       = _idPaciente;
            ID_Profesional    = _idProfesional;
            ID_DetallePlan    = _idDetallePLan;
            estado            = true;
            strcpy(notas,_notas);
            ID                = -1;
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
        void Cargar(); //BORRAR
        void Mostrar(); //BORRAR
        void Modificar(){}; //BORRAR
        int getSize();
        bool comparaID(Registro *temp);
         PlanFarmacologico& operator = (Registro *temp){
            PlanFarmacologico *aux=(PlanFarmacologico *)temp;
            emision = aux->emision;
            ID_Paciente = aux->ID_Paciente;
            ID_Profesional = aux->ID_Profesional;
            ID_DetallePlan = aux->ID_DetallePlan;
            strcpy(this->notas,aux->notas);
            estado           = aux->estado;
            ID               = aux->ID;
            fechaAlta        = aux->fechaAlta;
            fechaBaja        = aux->fechaBaja;
        }

};





#endif // PLANFARMACOLOGICO_H_INCLUDED
