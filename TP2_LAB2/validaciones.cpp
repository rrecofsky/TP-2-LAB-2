#include <iostream>
#include "ui.h"
#include "rlutil.h"
#include "validaciones.h"
#include <string>
#include <typeinfo>




using namespace std;
using namespace rlutil;



/// VALIDACIONES GRALES

Perfil ValidacionesGenerales :: ValidarPerfilDeUsuario(){
    ValidacionesTipoDato val;
    bool fail;
    int  dato;
    do
    {
        dato = val.cargar_Entero();
        fail = dato < Perfil_Administrador || dato > Perfil_Paciente ? true : false;
        if (fail) val.generar_Mensaje(Error,"PERFIL NO DISPONIBLE.");

    }while(fail);
    return (Perfil)dato;
}

bool ValidacionesGenerales :: EsBiciesto(Fecha _fecha)
//retorna true si es fecha valida
{
    bool validoFecha=true;

    //Biciesto para el mes de febrero
    if (_fecha.GetMes()==2 && _fecha.GetDia()==29 && ( _fecha.GetAnio() % 400 != 0 || _fecha.GetAnio() % 4 == 0 && _fecha.GetAnio() % 100 != 0 ))
    {
        validoFecha=false;
    }
    return validoFecha;
}

int ValidacionesGenerales :: ValidarDia(){
    return ValidarOpciones(1,31,"INGRESE UN DIA VALIDO");
}

int ValidacionesGenerales :: ValidarMes(){
    return ValidarOpciones(1,12,"INGRESE UN MES VALIDO");
}

int ValidacionesGenerales :: ValidarAnio(){
    Fecha fechaAux;
    return ValidarOpciones(fechaAux.GetFechaActual().GetAnio() - 100,fechaAux.GetFechaActual().GetAnio(),"INGRESE UN MES ANIO");
}

int ValidacionesGenerales :: ValidarOpciones(int _opMin, int _opMax, const char * _msj){
    ValidacionesTipoDato val;
    bool fail;
    int  dato;
    do
    {
        dato = val.cargar_Entero();
        fail = dato < _opMin || dato > _opMax ? true : false;
        if (fail) val.generar_Mensaje(Error,strcat("ERROR: ",_msj));

    }while(fail);
    return dato;
}

bool ValidacionesGenerales :: leer_SoN()
{
    ValidacionesTipoDato vtd;
    bool rta_Correcta;
    char opcion;
    do
    {
        cout << endl << "> ";
        cin>>opcion;
        opcion = toupper(opcion);
        if (opcion != 'S' && opcion != 'N')
        {
            vtd.generar_Mensaje(0,"ERROR: RESPUESTA INVALIDA. DEBE TIPEAR S o N ...");
            rta_Correcta = false;
        }else{
                rta_Correcta = true;
             }
    }while(!rta_Correcta);
    if (opcion == 'S')
    {
        return true;
    } else
         {
            return false;
         }

}



char ValidacionesGenerales :: ValidarGenero(){
    ValidacionesTipoDato val;
    bool fail;
    char  dato;
    do
    {
        dato = val.cargar_Char();
        dato = toupper(dato);
        fail = dato == 'M' || dato == 'F'  ? false : true;
        if (fail) val.generar_Mensaje(Error,"GENERO NO DISPONIBLE, INGRESE M o F.");

    }while(fail);
    return dato;
}

///VALIDACIONES TIPO DE DATO

int ValidacionesTipoDato :: cargar_Entero()
{
    bool fail;
    int dato;
    cin.clear(); //resetear flags
    fflush(stdin); //limpiar buffer
    do
    {
        cout << endl << "> ";
        fail = (cin>>dato).fail();
        if (fail)//validar tipo de dato
        {
            cin.clear(); //resetear flags
            fflush(stdin); //limpiar buffer
            generar_Mensaje(0,"ERROR: TIPO DE DATO INCORRECTO. INGRESE NUEVAMENTE.");
        }
    }while(fail);
    return dato;

}

float ValidacionesTipoDato :: cargar_Float()
{
    bool fail;
    float dato;
    cin.clear(); //resetear flags
    fflush(stdin); //limpiar buffer
    do
    {
         fail = (cin>>dato).fail();
        if (fail)//validar tipo de dato
        {
            cin.clear(); //resetear flags
            fflush(stdin); //limpiar buffer
            generar_Mensaje(0,"ERROR: TIPO DE DATO INCORRECTO. INGRESE NUEVAMENTE ...");
        }
    }while(fail);
    return dato;
}

bool ValidacionesTipoDato :: cargar_Bool()
{
    bool fail;
    bool dato;
    cin.clear(); //resetear flags
    fflush(stdin); //limpiar buffer
    do
    {
        fail = (cin>>dato).fail();
        if (fail)//validar tipo de dato
        {
            cin.clear(); //resetear flags
            fflush(stdin); //limpiar buffer
            generar_Mensaje(0,"ERROR: TIPO DE DATO INCORRECTO. VALORES ADMITIDOS: 0 o 1. INGRESE NUEVAMENTE ...");
        }
    }while(fail);
    return dato;
}

char ValidacionesTipoDato :: cargar_Char()
{
    bool fail;
    char dato;
    cin.clear(); //resetear flags
    fflush(stdin); //limpiar buffer
    do
    {
        cout << endl << "> ";
        fail = (cin>>dato).fail();
        if (fail)//validar tipo de dato
        {
            cin.clear(); //resetear flags
            fflush(stdin); //limpiar buffer
            generar_Mensaje(0,"ERROR: TIPO DE DATO INCORRECTO. INGRESE NUEVAMENTE ...");
        }
    }while(fail);
    return dato;
}

void  ValidacionesTipoDato :: generar_Mensaje(int _error,const char *_mensaje)
{
    _error == Error ? setColor(LIGHTRED) : setColor(LIGHTBLUE);

    switch(_error){
        case Error:
                         cout << endl << "ERROR: "       << _mensaje << endl;
                         break;
        case Advertencia:
                         cout << endl << "ADVERTENCIA: " << _mensaje << endl;
                         break;
        case Informativo:
                         cout << endl << "INFORMATIVO: " << _mensaje << endl;
                         break;
        default:
                         return;
    }
    setColor(WHITE);
    return;
}

void ValidacionesTipoDato :: ADesarrollar()
{/*
  char x;
  int j;
  Profesional p;
  if (typeid(x) == typeid(char)) cout << "X ES CHAR! " <<  "!\n";
  if (typeid(j) == typeid(char)) cout << "J ES CHAR! " <<  "!\n"; else cout<<"J NO ES CHAR!";
  if (typeid(p) == typeid(Profesional)) cout << "P ES PROFESIONAL! " <<  "!\n"; else cout<<"J NO ES CHAR!"; */
  return;
}
