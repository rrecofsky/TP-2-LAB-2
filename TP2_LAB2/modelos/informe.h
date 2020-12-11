#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "../modelos/registro.h"
#include "../modelos/fecha.h"

class Informe : public Registro{
    private:
        int   nroInforme;
        Fecha fechaEmision;
        int   idPaciente;
        int   idProfesional;
        char  detalle[100];
    public:
         Informe(int _idPaciente = -1, int _idProfesional = -1, const char * _detalle = "", int _nroInforme = 0):Registro()
        {
            strcpy(detalle,_detalle);
            idPaciente = idPaciente;
            idProfesional = _idProfesional;
            nroInforme = _nroInforme;
        }
        ~Informe(){};
        //gets
        Fecha GetFechaEmision();
        int   GetIdPaciente();
        int   GetIdProfesional();
        const char* GetDetalle();
        int   GetNroInforme();
        //sets
        void  SetFechaEmision(Fecha);
        void  SetIdPaciente(int);
        void  SetIdProfesional(int);
        void  SetDetalle(const char*);
        void  SetNroInforme(int);

        //heredadas
        int getSize();
        bool comparaID(Registro *temp);
         Informe& operator = (Registro *temp){
            Informe *aux=(Informe *)temp;
            strcpy(detalle,aux->detalle);
            idPaciente       = aux->idPaciente;
            idProfesional    = aux->idProfesional;
            fechaEmision     = aux->fechaEmision;
            nroInforme       = aux->nroInforme;

            estado           = aux->estado;
            ID               = aux->ID;
            fechaAlta        = aux->fechaAlta;
            fechaBaja        = aux->fechaBaja;
        }
};

#endif // INFORMES_H_INCLUDED
