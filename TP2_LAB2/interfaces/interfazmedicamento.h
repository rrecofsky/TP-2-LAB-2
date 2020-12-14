#ifndef INTERFAZMEDICACION_H_INCLUDED
#define INTERFAZMEDICACION_H_INCLUDED

#include "../modelos/medicamento.h"
#include "../modelos/archivo.h"
#include <vector>

class InterfazMedicamento : public InterfazGeneral  {
    public:
        int  ObtenerMedicamento(Medicamento&);
        bool CargarMedicamento(Medicamento &, vector<int> &);
        void MostrarMedicamento(Medicamento);
        void ListarMedicamentos();
        void ListarMedicamentosConFiltro(vector<int> &);
        void AgregarMedicamentoAArchivo(Medicamento, vector<int>);
        int  GetCantidadMedicamentos();
};

#endif // INTERFAZMEDICACION_H_INCLUDED
