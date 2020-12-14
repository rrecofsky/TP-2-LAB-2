#ifndef INTERFAZPLANFARMACOLOGICO_H_INCLUDED
#define INTERFAZPLANFARMACOLOGICO_H_INCLUDED

#include "../modelos/registro.h"
#include "../modelos/profesional.h"
#include "../modelos/paciente.h"
#include "../modelos/archivo.h"
#include "../modelos/paciente.h"
#include "../modelos/planfarmacologico.h"
#include "../modelos/detalleplanfarmacologico.h"
#include "../modelos/medicamento.h"

class InterfazPlanFarmacologico : public InterfazGeneral {
    public:
        bool CargarPlanFarmacologico(PlanFarmacologico &);
        void MostrarPlanFarmacologico(PlanFarmacologico);
        bool AgregarPlanFarmacologicoAArchivo(PlanFarmacologico);
        void ListarPlanesFarmacologicos();
        bool AsociarPlanFarmacologico(PlanFarmacologico &);
        int  ObtenerPlanFarmacologico(PlanFarmacologico &, bool);
        void MostrarPlanConDetallePlanFarmacologicoCombinado(PlanFarmacologico, DetallePlanFarmacologico, Medicamento);
        void ListarPlanesFarmacosCombinados();
        int  GetCantidadPlanes();
};


class InterfazDetallePlanFarmacologico : public InterfazGeneral  {
    public:
        int  ObtenerDetalleDelPlanFarmacologico(DetallePlanFarmacologico &, bool);
        bool CargarDetallePlanFarmacologico(DetallePlanFarmacologico &);
        void MostrarDetallePlanFarmacologico(DetallePlanFarmacologico );
        void AgregarDetallePlanFarmacologicoAArchivo(DetallePlanFarmacologico);
        void ListarDetallesDePlanesFarmacologicos();
        bool AsociarDetalleDePlanFarmacologico(DetallePlanFarmacologico &);
         int GetCantidadDetallesPlanes();
        void ModificarDetallePlan(DetallePlanFarmacologico & );
        bool ActualizarDetallePlan(DetallePlanFarmacologico , int );
        void ModificarDetalleEnArchivo(DetallePlanFarmacologico );
};


#endif // INTERFAZPLANFARMACOLOGICO_H_INCLUDED
