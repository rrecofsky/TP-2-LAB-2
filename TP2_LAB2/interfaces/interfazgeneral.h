#ifndef INTERFAZGENENAL_H_INCLUDED
#define INTERFAZGENENAL_H_INCLUDED

#include "../modelos/registro.h"
#include <vector>
#include <algorithm> //find

 enum TipoObjeto{
   Tipo_Paciente,
   Tipo_Profesional,
   Tipo_Usuario,
   Tipo_Cobertura,
   Tipo_Especialidad,
   Tipo_farmaco,
   Tipo_Informe
};

enum Filtros{
    Sin_Filtro,
    Sin_Usuario
};

class InterfazGeneral{
    public:
        TipoObjeto ObtenerTipoDeObjeto(Registro &_registro);
        bool  CompararForeignKey(Registro *_registro);
        ///LE MANDO EL VECTOR CARGADO CON EL LISTAR_X Y BUSCA SI EL VALOR INGRESADO POR EL USUARIO ES CORRECTO
        /// SIEMPRE SE PASA POR REFERENCIA
        bool VerficicarOpcionListada(vector<int> &, int );
        void EliminarDuplicadosDelVector(vector<int> &);
};

#endif // INTERFAZGENENAL_H_INCLUDED
