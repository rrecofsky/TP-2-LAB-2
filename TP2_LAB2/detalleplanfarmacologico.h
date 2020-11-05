#ifndef DETALLEPLANFARMACOLOGICO_H_INCLUDED
#define DETALLEPLANFARMACOLOGICO_H_INCLUDED
#include "registro.h"

//registra lo que un medico le receta a un paciente
class DetallePlanFarmacologico:public Registro{
    private:
        int  Id_PlanFarmacologico;
        int  Id_Medicacion;
        int  dosisdiaria;
        bool estado;
        int  cantcomprimidos;
        int  miligramos;
    public:
        DetallePlanFarmacologico(int _codigoPlan = 0, int _codigoMedicacion = 0, int _dosisDiaria = 0, int _cantComprimidos = 0, int _miligramos = 0){
            Id_PlanFarmacologico = _codigoPlan;
            Id_Medicacion        = _codigoMedicacion;
            dosisdiaria          = _dosisDiaria;
            cantcomprimidos      = _cantComprimidos;
            miligramos           = _miligramos;
            estado               = true;
        }
        ~DetallePlanFarmacologico(){};
        //GETs
        int  GetCodigoPlan();
        int  GetCodigoMedicacion();
        int  GetDosisdiaria();
        bool GetEstado();
        int  GetCantidadMgDisponibles();
        int  GetCantidadDiasCubiertos();
        //SETs
        void  SetCodigoPlan(int);
        void  SetCodigoMedicacion(int);
        void  SetDosisdiaria(int);
        void  SetEstado(bool);
        void  SetCantComprimidos(int); //cantidad de pastillas x cantididad de mg
};

#endif // DETALLEPLANFARMACOLOGICO_H_INCLUDED
