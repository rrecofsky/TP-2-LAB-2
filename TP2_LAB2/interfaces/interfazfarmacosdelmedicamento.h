#ifndef INTERFAZARMACOSDELMEDICAMENTO_H_INCLUDED
#define INTERFAZARMACOSDELMEDICAMENTO_H_INCLUDED

#include "../modelos/farmacos_del_medicamento.h"
#include "../modelos/archivo.h"


class InterfazFarmacosDelMedicamento : public InterfazGeneral {
    public:
        void    AgregarFarmacosDelMedicamentoAArchivo(farmacos_del_medicamento);
        int     ObtenerFarmacosDelMedicamento(farmacos_del_medicamento &);
        string  ObtenerStrFarmacosSeparadosPorComa(int );
};


#endif // INTERFAZARMACOSDELMEDICAMENTO_H_INCLUDED
