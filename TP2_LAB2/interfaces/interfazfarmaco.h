#ifndef INTERFAZFARMACO_H_INCLUDED
#define INTERFAZFARMACO_H_INCLUDED
#include "../modelos/farmaco.h"

class InterfazFarmaco : public InterfazGeneral  {
    public:
        int  ObtenerFarmaco(Farmaco&);
        bool CargarFarmaco(Medicamento &);
        void MostrarFarmaco(Medicamento, bool );
        void ListarFarmacos();
        void AgregarFarmacoAArchivo(Medicamento);
};

#endif // INTERFAZFARMACO_H_INCLUDED