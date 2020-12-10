#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "../modelos/registro.h"
#include "../modelos/fecha.h"

class Informe : public Registro{
    private:
        Fecha fechaEmision;
        int   idPaciente;
        int   idProfesional;
        char  detalle[100];
    public:
         Informe(int _idPaciente = -1, int _idProfesional = -1, const char * _detalle = ""):Registro()
        {
            strcpy(detalle,_detalle);
            idPaciente = idPaciente;
            idProfesional = _idProfesional;
        }
        ~Informe(){};
        //gets
        Fecha GetFechaEmision();
        int   GetIdPaciente();
        int   GetIdProfesional();
        const char* GetDetalle();
        //sets
        void  SetFechaEmision(Fecha);
        void  SetIdPaciente(int);
        void  SetIdProfesional(int);
        void  SetDetalle(const char*);

        //heredadas
        int getSize();
        bool comparaID(Registro *temp);
         Informe& operator = (Registro *temp){
            Informe *aux=(Informe *)temp;
            strcpy(detalle,aux->detalle);
            idPaciente       = aux->idPaciente;
            idProfesional    = aux->idProfesional;
            fechaEmision     = aux->fechaEmision;

            estado           = aux->estado;
            ID               = aux->ID;
            fechaAlta        = aux->fechaAlta;
            fechaBaja        = aux->fechaBaja;
        }
};

#endif // INFORMES_H_INCLUDED
