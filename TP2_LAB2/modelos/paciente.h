#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED
#include <iomanip>
#include "../modelos/persona.h"
#include "../modelos/fecha.h"

class Paciente:public Persona
{
    private:
        int nro_Afiliado; //nro de afiliado
        int ID_Cobertura;
        int ID_Informe; //R FUERTE A 1, no puede existir si un paciente
    public:

        Paciente(const char * _nombre = "", const char *  _apellido = "",int _dni = -1, int _nroAfiliado =-1, int _cobertura =-1, int p =0, int i =0):Persona(_nombre,_apellido,_dni)
        {
            nro_Afiliado         = _nroAfiliado;
            ID_Cobertura         = _cobertura;
            ID_Informe           = -1;
        }

        ~Paciente(){};
        ///GETs
        int GetNroAfiliado();
        int GetIdCobertura();
        int GetIdInforme();
        ///SETs
        void SetNroAfiliado(int);
        void SetIdCObertura(int);
        void SetIdInforme(int);
        ///Carga
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
            ID_Informe           = aux->ID_Informe;
            poseeUsuario     = aux->poseeUsuario;
            }
        bool comparaID(Registro *temp);
};

#endif // PACIENTE_H_INCLUDED
