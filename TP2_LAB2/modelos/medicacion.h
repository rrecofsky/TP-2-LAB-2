#ifndef MEDICACION_H_INCLUDED
#define MEDICACION_H_INCLUDED

#include "../modelos/registro.h"
#include "../modelos/fecha.h"
#include <cstring>

enum Presentacion{
    Capsulas,
    Comprimidos
};

class Medicamento : public Registro{
    private:
        char           farmaco[50];
        Presentacion   ID_Presentacion;
        int            dosis;
        Fecha          vencimiento;
        bool           NoSeFabricaMas;
    public:
        Medicamento( const char* _farmaco = "", float _dosis=0):Registro(){
            strcpy(farmaco,_farmaco);
            dosis               = _dosis;
            strcpy(farmaco,"");
            NoSeFabricaMas = false;
        }
        ~Medicamento(){};
        //GETs
        const char *   GetFarmaco();
        int            GetDosis();
        Fecha          GetFechaVecimiento();
        Presentacion   GetIdPresentacion();
        bool           GetNoSeFabricaMas();
        //SETs
        void           SetFarmaco(const char*);
        void           SetDosis(int);
        void           SetFechaVencimiento(Fecha);
        void           SetIdPresentacion(Presentacion);
        void           SetNoSeFabricaMas(bool);
        //METODOS REDEFINIDOS HEREDADOS DE REGISTRO
        int getSize();
        bool comparaID(Registro *temp);
         Medicamento& operator = (Registro *temp){
            Medicamento *aux=(Medicamento *)temp;
            strcpy(farmaco,aux->farmaco);
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
