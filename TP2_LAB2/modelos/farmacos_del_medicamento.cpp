#include "../modelos/farmacos_del_medicamento.h"

int farmacos_del_medicamento :: getIdMedicamento(){return ID_Medicamento;}
int farmacos_del_medicamento :: getIdFarmaco(){return ID_farmaco;}
//SETs
void farmacos_del_medicamento :: setIdMedicamento(int _ID_Medicamento){ID_Medicamento = _ID_Medicamento;}
void farmacos_del_medicamento :: setIdFarmaco(int _ID_farmaco){ID_farmaco = _ID_farmaco;}

///GETS PLM
int   farmacos_del_medicamento :: getSize(){return sizeof *this;}

bool  farmacos_del_medicamento :: comparaID(Registro *temp){
            farmacos_del_medicamento *aux=(farmacos_del_medicamento *)temp;
            if(aux->ID == ID) return true;
            return false;
}
