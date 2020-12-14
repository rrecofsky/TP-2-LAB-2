#include "../modelos/usuario.h"
#include "../modelos/profesional.h"
#include "../modelos/paciente.h"
#include "../interfaces/interfazgeneral.h"
#include "../modelos/archivo.h"
#include "../interfaces/interfazentidades.h"
#include "../modelos/planfarmacologico.h"
#include "../modelos/cobertura.h"
#include "../modelos/especialidad.h"
#include "../modelos/farmaco.h"
#include "../modelos/informe.h"

extern const char *FILE_USUARIOS;
extern const char *FILE_PACIENTES;
extern const char *FILE_PROFESIONALES;
extern const char *FILE_COBERTURAS;
extern const char *FILE_PLANFARMACO;
extern const char *FILE_ESPECIALIDADES;
extern const char *FILE_FARMACOS;
extern const char *FILE_INFORMES;

/// VALIDACIONES GRALES

bool InterfazGeneral :: VerficicarOpcionListada(vector<int> & _vec, int _opcion){
    vector<int>::iterator it;
    it = find (_vec.begin(), _vec.end(), _opcion);
    if (it != _vec.end())
        return true;

    return false;
}

void InterfazGeneral :: EliminarDuplicadosDelVector(vector<int> & _vec){
    sort(_vec.begin(), _vec.end());
     _vec.erase( unique(_vec.begin(),_vec.end()),_vec.end() );

}

bool InterfazGeneral :: CompararForeignKey(Registro *_registro){
    switch(ObtenerTipoDeObjeto(*_registro)){
            case 0: {//Paciente
                        Paciente *aux=(Paciente *)_registro;
                        Archivo arch(FILE_PACIENTES,sizeof(*aux));
                        if ( arch.buscarRegistro(*aux) >= 0 ){
                            return true;
                        }
                        return false;
                    }
                   break;
            case 1: {//Profesional
                        Profesional *aux=(Profesional *)_registro;
                        Archivo arch(FILE_PROFESIONALES,sizeof(*aux));
                        if ( arch.buscarRegistro(*aux) >= 0 ){
                            return true;
                        }
                        return false;
                    }
                   break;
            case 2:{//Usuario
                        Usuario *aux=(Usuario *)_registro;
                        Archivo arch(FILE_USUARIOS,sizeof(*aux));
                        if ( arch.buscarRegistro(*aux) >= 0 ){
                             return true;
                        }
                        return false;
                    }
                   break;
            case 3:{//Cobertura
                        Cobertura *aux=(Cobertura *)_registro;
                        Archivo arch(FILE_COBERTURAS,sizeof(*aux));
                        if ( arch.buscarRegistro(*aux) >= 0 ){
                             return true;
                        }
                        return false;
                    }

                   break;
            case 4:{//Especialidad
                        Especialidad *aux=(Especialidad *)_registro;
                        Archivo arch(FILE_ESPECIALIDADES,sizeof(*aux));
                        if ( arch.buscarRegistro(*aux) >= 0 ){
                             return true;
                        }
                        return false;
                    }
                   return false;
            case 5:{//Farmaco
                        Farmaco *aux=(Farmaco *)_registro;
                        Archivo arch(FILE_FARMACOS,sizeof(*aux));
                        if ( arch.buscarRegistro(*aux) >= 0 ){
                             return true;
                        }
                        return false;
                    }
                   return false;
            case 6:{//Informes
                        Informe *aux=(Informe *)_registro;
                        Archivo arch(FILE_INFORMES,sizeof(*aux));
                        if ( arch.buscarRegistro(*aux) >= 0 ){
                             return true;
                        }
                        return false;
                    }
                   return false;
            break;
        }

}


TipoObjeto InterfazGeneral :: ObtenerTipoDeObjeto(Registro &_registro)
{
  if (typeid(_registro) == typeid(Usuario)) return Tipo_Usuario;
  if (typeid(_registro) == typeid(Paciente)) return Tipo_Paciente;
  if (typeid(_registro) == typeid(Profesional)) return Tipo_Profesional;
  if (typeid(_registro) == typeid(Cobertura)) return Tipo_Cobertura;
  if (typeid(_registro) == typeid(Especialidad)) return Tipo_Especialidad;
  if (typeid(_registro) == typeid(Farmaco)) return Tipo_farmaco;
}




