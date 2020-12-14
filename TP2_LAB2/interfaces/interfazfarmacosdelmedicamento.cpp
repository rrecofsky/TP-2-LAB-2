
#include "../interfaces/interfazfarmacosdelmedicamento.h"
#include "../modelos/farmaco.h"
#include "../interfaces/interfazfarmaco.h"

extern const char *FILE_FARMACOSDELMEDICAMENTO;

void InterfazFarmacosDelMedicamento :: AgregarFarmacosDelMedicamentoAArchivo(farmacos_del_medicamento _farmacos_del_medicamento){
    Archivo farmacosdelmedicamento(FILE_FARMACOSDELMEDICAMENTO,sizeof(farmacos_del_medicamento));
    farmacosdelmedicamento.grabarRegistro(_farmacos_del_medicamento,-1);
}

int InterfazFarmacosDelMedicamento :: ObtenerFarmacosDelMedicamento(farmacos_del_medicamento & _farmacoDelMedicamento){
    Archivo farmacosdelosmedicamentos(FILE_FARMACOSDELMEDICAMENTO,sizeof(farmacos_del_medicamento));
    return farmacosdelosmedicamentos.leerRegistro(_farmacoDelMedicamento);
};

string InterfazFarmacosDelMedicamento :: ObtenerStrFarmacosSeparadosPorComa(int _idMedicamento){
    farmacos_del_medicamento farmacoDelMedicamento;
    Farmaco farmaco;
    InterfazFarmaco itfzFmc;
    Archivo farmacosDelMedicamento(FILE_FARMACOSDELMEDICAMENTO,sizeof(farmacos_del_medicamento),true);
    string strFarmDelMed;
    while(fread(&farmacoDelMedicamento,sizeof(farmacos_del_medicamento),1,farmacosDelMedicamento.GetPF())){
        if (farmacoDelMedicamento.getIdMedicamento() == _idMedicamento){
                farmaco.SetId(farmacoDelMedicamento.getIdFarmaco());
                itfzFmc.ObtenerFarmaco(farmaco);
                strFarmDelMed += (string)farmaco.GetNombre() + ", ";
        }
    }

    return strFarmDelMed.substr(0,strFarmDelMed.size()-2 );
}
