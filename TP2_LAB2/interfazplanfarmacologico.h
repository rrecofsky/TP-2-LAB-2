#ifndef INTERFAZPLANFARMACOLOGICO_H_INCLUDED
#define INTERFAZPLANFARMACOLOGICO_H_INCLUDED

#include "registro.h"
#include "profesional.h"
#include "paciente.h"
#include "archivo.h"
#include "paciente.h"
#include "planfarmacologico.h"

class InterfazPlanFarmacologico  {
    public:
        void CargarPlanFarmacologico(PlanFarmacologico &);
        void MostrarPlanFarmacologico(PlanFarmacologico);
        void ModificarPlanFarmacologico(PlanFarmacologico &);
        void AgregarPlanFarmacologicoAArchivo(PlanFarmacologico);
        void ModificarPlanFarmacologicoEnArchivo(PlanFarmacologico);
        void ListarPlanesFarmacologicos();
        bool AsociarPlanFarmacologico(PlanFarmacologico &);
};
/*
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
*/

#endif // INTERFAZPLANFARMACOLOGICO_H_INCLUDED
