#ifndef INTERFAZPLANFARMACOLOGICO_H_INCLUDED
#define INTERFAZPLANFARMACOLOGICO_H_INCLUDED

#include "planfarmacologico.h"
#include "detalleplanfarmacologico.h"

class InterfazPlanFarmacologico  {
    public:
        void CargarPlanFarmacologico(PlanFarmacologico &);
        void MostrarPlanFarmacologico(PlanFarmacologico);
        void ModificarPlanFarmacologico(PlanFarmacologico &);
        void AgregarUPlanFarmacologicoAArchivo(PlanFarmacologico);
        void ModificarUPlanFarmacologicoEnArchivo(PlanFarmacologico);
        void ListarPlanesFarmacologicos();
        bool AsociarUPlanFarmacologico(PlanFarmacologico &);
};

class InterfazDetallePlanFarmacologico  {
    public:
        void CargarDetallePlanFarmacologico(DetallePlanFarmacologico &);
        void MostrarDetallePlanFarmacologico(DetallePlanFarmacologico);
        void ModificarDetallePlanFarmacologico(DetallePlanFarmacologico &);
        void AgregarDetallePlanFarmacologicoAArchivo(DetallePlanFarmacologico);
        void ModificarDetallePlanFarmacologicoEnArchivo(DetallePlanFarmacologico);
        void ListarDetallesDePlanesFarmacologicos();
        bool AsociarDetalleDePlanFarmacologico(DetallePlanFarmacologico &);
};

#endif // INTERFAZPLANFARMACOLOGICO_H_INCLUDED
