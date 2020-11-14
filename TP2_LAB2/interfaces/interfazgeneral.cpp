#include "../modelos/usuario.h"
#include "../modelos/profesional.h"
#include "../modelos/paciente.h"
#include "../interfaces/interfazgeneral.h"
#include "../modelos/archivo.h"

#include "../interfaces/interfazentidades.h"

extern const char *FILE_USUARIOS;
extern const char *FILE_PACIENTES;
extern const char *FILE_PROFESIONALES;
extern const char *FILE_COBERTURAS;

/// VALIDACIONES GRALES

bool InterfazGeneral :: CompararForeignKey(Registro *_registro){

    switch(ObtenerTipoDeObjeto(*_registro)){
            case 0: {//Paciente
                        Paciente *aux=(Paciente *)_registro;
                        Archivo arch(FILE_PACIENTES,sizeof(*aux));
                        int pos = arch.buscarRegistro(*aux);
                        if ( arch.buscarRegistro(*aux) >= 0 ){
                            free(aux);
                            return true;
                        }
                        free(aux);
                        return false;
                    }
                   break;
            case 1: {//Profesional
                        Profesional *aux=(Profesional *)_registro;
                        Archivo arch(FILE_PROFESIONALES,sizeof(*aux));
                        int pos = arch.buscarRegistro(*aux);
                        if ( arch.buscarRegistro(*aux) >= 0 ){
                            free(aux);
                            return true;
                        }
                        free(aux);
                        return false;
                    }
                   break;
            case 2:{//Usuario
                        Usuario *aux=(Usuario *)_registro;
                        Archivo arch(FILE_USUARIOS,sizeof(*aux));
                        int pos = arch.buscarRegistro(*aux);
                        if ( arch.buscarRegistro(*aux) >= 0 ){
                            free(aux);
                            return true;
                        }
                        free(aux);
                        return false;
                    }
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
