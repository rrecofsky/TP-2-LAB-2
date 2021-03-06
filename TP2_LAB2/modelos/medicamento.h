#ifndef MEDICACION_H_INCLUDED
#define MEDICACION_H_INCLUDED

#include "../modelos/registro.h"
#include "../modelos/fecha.h"
#include <cstring>


class Medicamento : public Registro{
    private:
        int            ID_Presentacion; //cantidad de pastillas por caja
        int            dosis;
        Fecha          vencimiento;
        char           accionTerapeutica[50];
    public:
        Medicamento( float _dosis=0, int _idPresentacion = -1, const char * _accionTerapeutica = ""):Registro(){
            dosis               = _dosis;
            ID_Presentacion     = _idPresentacion;
            strcpy(accionTerapeutica,_accionTerapeutica);
        }
        ~Medicamento(){};
        //GETs
        const char *   GetFarmaco();
        int            GetDosis();
        Fecha          GetFechaVecimiento();
        int            GetIdPresentacion();
        const char *   GetaccionTerapeutica();
        //SETs
        void           SetDosis(int);
        void           SetFechaVencimiento(Fecha);
        void           SetIdPresentacion(int);
        void           SetaccionTerapeutica(const char *);
        //METODOS REDEFINIDOS HEREDADOS DE REGISTRO
        int getSize();
        bool comparaID(Registro *temp);
         Medicamento& operator = (Registro *temp){
            Medicamento *aux=(Medicamento *)temp;
            strcpy(accionTerapeutica,aux->accionTerapeutica);
            ID_Presentacion = aux->ID_Presentacion;
            dosis = aux->dosis;
            vencimiento = aux->vencimiento;
            estado           = aux->estado;
            ID               = aux->ID;
            fechaAlta        = aux->fechaAlta;
            fechaBaja        = aux->fechaBaja;
        }
};

#endif // MEDICACION_H_INCLUDED
