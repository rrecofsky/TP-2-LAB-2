#ifndef FARMACOS_DEL_MEDICAMENTO_H_INCLUDED
#define FARMACOS_DEL_MEDICAMENTO_H_INCLUDED

#include "../modelos/registro.h"

class farmacos_del_medicamento :public Registro{
    private:
       int ID_Medicamento;
       int ID_farmaco;
    public:
        farmacos_del_medicamento(int _ID_Medicamento = -1, int _ID_farmaco = -1 ):Registro()
        {
            ID_Medicamento = _ID_Medicamento;
            ID_farmaco = _ID_farmaco;
        }
        ~farmacos_del_medicamento(){};
        //GETs
        int getIdMedicamento();
        int getIdFarmaco();
        //SETs
        void setIdMedicamento(int);
        void setIdFarmaco(int);
        //METODOS REDEFINIDOS HEREDADOS DE REGISTRO
        int getSize();
        bool comparaID(Registro *temp);
         farmacos_del_medicamento& operator = (Registro *temp){
            farmacos_del_medicamento *aux=(farmacos_del_medicamento *)temp;
            ID_Medicamento   = aux->ID_Medicamento;
            ID_farmaco       = aux->ID_farmaco;

            estado           = aux->estado;
            ID               = aux->ID;
            fechaAlta        = aux->fechaAlta;
            fechaBaja        = aux->fechaBaja;
        }
};

#endif // FARMACOS_DEL_MEDICAMENTO_H_INCLUDED
