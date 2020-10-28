#ifndef DETALLEPLANFARMACOLOGICO_H_INCLUDED
#define DETALLEPLANFARMACOLOGICO_H_INCLUDED

//registra lo que un medico le receta a un paciente
class DetallePlanFarmacologico{
    private:
        int  ID;
        int  Id_CodigoPlan;
        int  Id_CodigoMedicacion;
        int  dosisdiaria;
        bool estado;
        int  cantidad;
    public:
        DetallePlanFarmacologico(int cp, int cm, int d){
            ID                  = 0;
            Id_CodigoPlan       = cp;
            Id_CodigoMedicacion = cm;
            dosisdiaria         = d;
            estado              = true;
        }
        ~DetallePlanFarmacologico(){};
        //GETs
        int  GetId();
        int  GetCodigoPlan();
        int  GetCodigoMedicacion();
        int  GetDosisdiaria();
        bool GetEstado();
        int  GetCantidad();
        //SETs
        void  SetId(int);
        void  SetCodigoPlan(int);
        void  SetCodigoMedicacion(int);
        void  SetDosisdiaria(int);
        void  SetEstado(bool);
        void  SetCantidad(); //cantidad de pastillas x cantididad de mg
};

#endif // DETALLEPLANFARMACOLOGICO_H_INCLUDED
