#ifndef INTERFAZMEDICACION_H_INCLUDED
#define INTERFAZMEDICACION_H_INCLUDED

#include "../modelos/medicacion.h"
#include "../modelos/archivo.h"
#include <vector>

class InterfazMedicamento : public InterfazGeneral  {
    public:
        int  ObtenerMedicamento(Medicamento&);
        void CargarMedicamento(Medicamento &);
        void MotrarMedicamento(Medicamento);
        void ModificarMedicamento(Medicamento &); //SOLO DEJAR INHABILITADA PERO SIEMPRE ACTIVA
        void ListarMedicamentos();
        void ListarMedicamentosConFiltro(vector<int> & _vec){};
};

#endif // INTERFAZMEDICACION_H_INCLUDED
