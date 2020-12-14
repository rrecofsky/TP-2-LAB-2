#ifndef DETALLEPLANFARMACOLOGICO_H_INCLUDED
#define DETALLEPLANFARMACOLOGICO_H_INCLUDED
#include "registro.h"

//registra lo que un medico le receta a un paciente
class DetallePlanFarmacologico : public Registro
{
    private:
        int  Id_PlanFarmacologico;
        int  Id_Medicacion;
        int  dosisdiaria; //cantidad de pastillas que debe consumir por dia
        int  mgpordosis; //mg que debe consumir por dosis
        int  cantcomprimidos; //cantidad de pastillas en stock
        int  miligramos; //mg por pastilla en stock

    public:
        DetallePlanFarmacologico(int _IdPlanFarmacologico = -1, int _codigoMedicacion = -1, int _dosisDiaria = 0, int _cantComprimidos = 0, int _miligramos = 0, int _mgpordosis = 0):Registro()
        {
            Id_PlanFarmacologico = _IdPlanFarmacologico;
            Id_Medicacion        = _codigoMedicacion;
            dosisdiaria          = _dosisDiaria;
            cantcomprimidos      = _cantComprimidos;
            miligramos           = _miligramos;
            mgpordosis           = _mgpordosis;
         }

        ~DetallePlanFarmacologico(){};
        ///GETs
        int  GetIdPlanMedicamento();
        int  GetDosisdiaria();
        int  GetCantidadMgDisponibles();
        int  GetCantidadDiasCubiertos();
        int  GetCantComprimidos();
        int  GetIdPlanFarmacologico();
        int  GetCantMiligramos();
        int  GetMgPorDosis();
        ///SETs
        void  SetIdPlanMedicamento(int);
        void  SetDosisdiaria(int);
        void  SetCantComprimidos(int);
        void  SetCantMiligramos(int);
        void  SetIdPlanFarmacologico(int);
        void  SetMgPorDosis(int);

        //METODOS REDEFINIDOS HEREDADOS DE REGISTRO

        bool comparaID(Registro *);
        int getSize();
        DetallePlanFarmacologico& operator = (Registro *temp){
            DetallePlanFarmacologico *aux=(DetallePlanFarmacologico *)temp;
            Id_PlanFarmacologico = aux->Id_PlanFarmacologico;
            Id_Medicacion =aux->Id_Medicacion;
            dosisdiaria = aux->dosisdiaria;
            mgpordosis = aux->mgpordosis;
            cantcomprimidos = aux->cantcomprimidos;
            miligramos = aux->miligramos;

            estado           = aux->estado;
            ID               = aux->ID;
            fechaAlta        = aux->fechaAlta;
            fechaBaja        = aux->fechaBaja;
         }

};

#endif // DETALLEPLANFARMACOLOGICO_H_INCLUDED
