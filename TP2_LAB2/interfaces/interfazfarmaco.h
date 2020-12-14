#ifndef INTERFAZFARMACO_H_INCLUDED
#define INTERFAZFARMACO_H_INCLUDED
#include "../modelos/farmaco.h"
#include <vector>

class InterfazFarmaco : public InterfazGeneral  {
    public:
        int  ObtenerFarmaco(Farmaco&);
        bool CargarFarmaco(Farmaco &);
        void MostrarFarmaco(Farmaco, bool );
        void ListarFarmacos();
        void ListarFarmacosConFiltro(vector<int> &);
        void AgregarFarmacoAArchivo(Farmaco);
        int  GetCantidadFarmacos();
};

#endif // INTERFAZFARMACO_H_INCLUDED
