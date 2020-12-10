#ifndef DETALLEPLANFARMACOLOGICO_H_INCLUDED
#define DETALLEPLANFARMACOLOGICO_H_INCLUDED
#include "registro.h"

//registra lo que un medico le receta a un paciente
class DetallePlanFarmacologico:public Registro
{
    private:
        int  Id_PlanFarmacologico;
        int  Id_Medicacion;
        int  dosisdiaria;
        int  cantcomprimidos;
        int  miligramos;
    public:
        ///Constructor
        //DetallePlanFarmacologico(int , int , int , int , int );
        DetallePlanFarmacologico(int _IdPlanFarmacologico = -1, int _codigoMedicacion = -1, int _dosisDiaria = 0, int _cantComprimidos = 0, int _miligramos = 0):Registro()
        {
            Id_PlanFarmacologico = _IdPlanFarmacologico;
            Id_Medicacion        = _codigoMedicacion;
            dosisdiaria          = _dosisDiaria;
            cantcomprimidos      = _cantComprimidos;
            miligramos           = _miligramos;
         }

        ~DetallePlanFarmacologico(){};
        ///GETs
        int  GetIdPlanMedicamento();
        int  GetDosisdiaria();
        int  GetCantidadMgDisponibles();
        int  GetCantidadDiasCubiertos();
        int  GetCantComprimidos();
        int  GetIdPlanFarmacologico();
        ///SETs
        void  SetIdPlanMedicamento(int);
        void  SetDosisdiaria(int);
        void  SetCantComprimidos(int);
        void  SetCantMiligramos(int);
        void  SetIdPlanFarmacologico(int);

        //METODOS REDEFINIDOS HEREDADOS DE REGISTRO

        bool comparaID(Registro *); //Puede estar en una capa de logica
        int getSize();
        DetallePlanFarmacologico& operator = (Registro *temp){
            DetallePlanFarmacologico *aux=(DetallePlanFarmacologico *)temp;
            Id_PlanFarmacologico = aux->Id_PlanFarmacologico;
            Id_Medicacion =aux->Id_Medicacion;
            dosisdiaria = aux->dosisdiaria;
            cantcomprimidos = aux->cantcomprimidos;
            miligramos = aux->miligramos;
         }

};

#endif // DETALLEPLANFARMACOLOGICO_H_INCLUDED
