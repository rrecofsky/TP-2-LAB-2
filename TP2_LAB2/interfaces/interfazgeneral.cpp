#include "../modelos/usuario.h"
#include "../modelos/profesional.h"
#include "../modelos/paciente.h"
#include "../interfaces/interfazgenenal.h"



/// VALIDACIONES GRALES

bool InterfazGeneral :: CompararForeignKey(Registro &_registro){

    switch(ObtenerTipoDeObjeto(_registro)){
            case 0: //Paciente
              //     return Archivo archUsuarios(FILE_PACIENTES,sizeof(_registro)).buscarRegistro(_registro) > 0;
                   break;
            case 1://Profesional
                  cout<<"profesional - REGISTRO NRO: "<<1<<endl;
                   system("PAUSE");
                   break;
            case 2://Usuario

                   break;
            case 4:

                   break;
            case 9:
                   return false;
            break;
        }

}

TipoObjeto InterfazGeneral :: ObtenerTipoDeObjeto(Registro &_registro)
{
  if (typeid(_registro) == typeid(Usuario)) return Tipo_Usuario;
  if (typeid(_registro) == typeid(Paciente)) return Tipo_Paciente;
  if (typeid(_registro) == typeid(Profesional)) return Tipo_Profesional;
}
