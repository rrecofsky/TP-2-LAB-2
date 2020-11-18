#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED
#include <iomanip>
#include "../modelos/persona.h"
#include "../modelos/fecha.h"

class Paciente:public Persona
{
    private:
        int nro_Afiliado; //nro de afiliado
        int ID_Cobertura; //0 es sin cobertura
        int ID_PlanFarmacologico; //R FUERTE A N, no pueden existir sin un paciente
        int ID_Informe; //R FUERTE A 1, no puede existir si un paciente
        int ProfesionalOwnerID;
    public:

        Paciente(const char * _nombre = "", const char *  _apellido = "",int _dni = -1, int _nroAfiliado =-1, int _cobertura =-1, int p =0, int i =0):Persona(_nombre,_apellido,_dni)
        {
            nro_Afiliado         = _nroAfiliado;
            ID_Cobertura         = _cobertura;
            ID_PlanFarmacologico = -1;
            ID_Informe           = -1;
            ID                   = -1;
            ProfesionalOwnerID   = -1;
        }

        ~Paciente(){};
        ///GETs
        int GetNroAfiliado();
        int GetIdCobertura();
        int GetIdInforme();
        int GetIdPlanFarmacologico();
        int GetProfesionalOwnerID();
        ///SETs
        void SetNroAfiliado(int);
        void SetIdCObertura(int);
        void SetIdInforme(int);
        void SetProfesionalOwnerID(int);
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
             ProfesionalOwnerID   = aux->ProfesionalOwnerID;
            }
        bool comparaID(Registro *temp);
};





#endif // PACIENTE_H_INCLUDED
