#include <iostream>
#include "ui.h"
#include "rlutil.h"
#include "validaciones.h"
#include <string>
#include <typeinfo>
#include "usuario.h"
#include "profesional.h"



using namespace std;
using namespace rlutil;




///VALIDACIONES LOGIN

int ValidacionesGenerales :: ValidarPerfilDeUsuario(){
    ValidacionesTipoDato val;
    bool fail;
    int  dato;
    do
    {
        dato = val.cargar_Entero();
        fail = dato < Admin || dato > Paciente ? true : false;
        if (fail) val.generar_Mensaje(Error,"PERFIL NO DISPONIBLE.");

    }while(fail);
    return dato;
}

int ValidacionesGenerales :: ValidarOpciones(int _opMin, int _opMax){
    ValidacionesTipoDato val;
    char str[80];
    bool fail;
    int  dato;
    do
    {
        dato = val.cargar_Entero();
        fail = dato < _opMin || dato > _opMax ? true : false;
        if (fail) val.generar_Mensaje(Error,strcat("OPCIONES DISPONIBLES: ",strcat (strcpy (str,(char*)_opMin),(char*)_opMax)));

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
{
  char x;
  int j;
 /* Profesional p;
  if (typeid(x) == typeid(char)) cout << "X ES CHAR! " <<  "!\n";
  if (typeid(j) == typeid(char)) cout << "J ES CHAR! " <<  "!\n"; else cout<<"J NO ES CHAR!";
  if (typeid(p) == typeid(Profesional)) cout << "P ES PROFESIONAL! " <<  "!\n"; else cout<<"J NO ES CHAR!"; */
  return;
}
