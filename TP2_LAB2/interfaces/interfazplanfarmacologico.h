#ifndef INTERFAZPLANFARMACOLOGICO_H_INCLUDED
#define INTERFAZPLANFARMACOLOGICO_H_INCLUDED

#include "../modelos/registro.h"
#include "../modelos/profesional.h"
#include "../modelos/paciente.h"
#include "../modelos/archivo.h"
#include "../modelos/paciente.h"
#include "../modelos/planfarmacologico.h"

class InterfazPlanFarmacologico  {
    public:
        bool CargarPlanFarmacologico(PlanFarmacologico &);
        void MostrarPlanFarmacologico(PlanFarmacologico);
        void AgregarPlanFarmacologicoAArchivo(PlanFarmacologico);
        void ListarPlanesFarmacologicos();
        bool AsociarPlanFarmacologico(PlanFarmacologico &);
        int  ObtenerPlanFarmacologico(PlanFarmacologico &);
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
