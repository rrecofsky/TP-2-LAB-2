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
        int   ID_Paciente;
        int   ID_Profesional;
        char  notas[500];
    public:
        PlanFarmacologico(int idpc = 0, int idpf = 0, const char * n = ""):Registro()
        {   Fecha f;
            emision           = f;
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
            strcpy(this->notas,aux->notas);
        }

};





#endif // PLANFARMACOLOGICO_H_INCLUDED
