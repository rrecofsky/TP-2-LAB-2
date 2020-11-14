#ifndef INTERFAZGENENAL_H_INCLUDED
#define INTERFAZGENENAL_H_INCLUDED

 enum TipoObjeto{
   Tipo_Paciente,
   Tipo_Profesional,
   Tipo_Usuario,
};

class InterfazGeneral{
    public:
        TipoObjeto ObtenerTipoDeObjeto(Registro &_registro);
        bool  CompararForeignKey(Registro &_registro);
};

#endif // INTERFAZGENENAL_H_INCLUDED
