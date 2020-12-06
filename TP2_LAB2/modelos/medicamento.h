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
        bool           NoSeFabricaMas;
        char           accionTerapeutica[50];
    public:
        Medicamento( float _dosis=0):Registro(){
            dosis               = _dosis;
            NoSeFabricaMas = false;
        }
        ~Medicamento(){};
        //GETs
        const char *   GetFarmaco();
        int            GetDosis();
        Fecha          GetFechaVecimiento();
        int            GetIdPresentacion();
        bool           GetNoSeFabricaMas();
        const char *   GetaccionTerapeutica();
        //SETs
        void           SetDosis(int);
        void           SetFechaVencimiento(Fecha);
        void           SetIdPresentacion(int);
        void           SetNoSeFabricaMas(bool);
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
