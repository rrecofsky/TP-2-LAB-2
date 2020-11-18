#ifndef INTERFAZGENENAL_H_INCLUDED
#define INTERFAZGENENAL_H_INCLUDED

#include "../modelos/registro.h"

 enum TipoObjeto{
   Tipo_Paciente,
   Tipo_Profesional,
   Tipo_Usuario,
   Tipo_PlanFarmaco
};

class InterfazGeneral{
    public:
        TipoObjeto ObtenerTipoDeObjeto(Registro &_registro);
        bool  CompararForeignKey(Registro *_registro);
        int   ObtenerRegistro(Registro &);

};

#endif // INTERFAZGENENAL_H_INCLUDED
