#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED

#include "persona.h"
#include "fecha.h"
#include <iomanip>

class Paciente:public Persona
{
    private:
        int nro_Afiliado; //nro de afiliado
        int ID_Cobertura; //0 es sin cobertura
        int ID_PlanFarmacologico; //R FUERTE A N, no pueden existir sin un paciente
        int ID_Informe; //R FUERTE A 1, no puede existir si un paciente
    public:

        Paciente(const char * _nombre = "", const char *  _apellido = "",int _dni = 0, int n =0, int c=0, int p =0, int i =0):Persona(_nombre,_apellido,_dni)
        {
            nro_Afiliado         = n;
            ID_Cobertura         = c;
            ID_PlanFarmacologico = 0;
            ID_Informe           = 0;
        }

        ~Paciente(){};
        ///GETs
        int GetNroAfiliado();
        int GetIdCobertura();
        int GetIdInforme();
        int GetIdPlanFarmacologico();
        ///SETs
        void SetNroAfiliado(int);
        void SetIdCObertura(int);
        void SetIdInforme(int);
        ///Carga
        void Cargar();
        void Mostrar();
        void Modificar();
        int getSize();
        ///VIRTUAL
         Paciente& operator = (Registro *temp){
            Paciente *aux=(Paciente *)temp;
            strcpy(this->apellidos,aux->apellidos);
            strcpy(this->nombres, aux->nombres);
            genero           = aux->genero;
            fecha_nacimiento = aux->fecha_nacimiento;
            DNI              = aux->DNI;
            estado           = aux->estado;
            ID               = aux->ID;
            fechaAlta        = aux->fechaAlta;
            fechaBaja        = aux->fechaBaja;
            nro_Afiliado         = aux->nro_Afiliado;
            ID_Cobertura         = aux->ID_Cobertura;
            ID_PlanFarmacologico = aux->ID_PlanFarmacologico;
            ID_Informe           = aux->ID_Informe;
            }
        bool comparaID(Registro *temp);
};





#endif // PACIENTE_H_INCLUDED
