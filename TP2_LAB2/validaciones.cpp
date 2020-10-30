#include <iostream>
#include "ui.h"
#include "rlutil.h"
#include "validaciones.h"
#include <string.h>

using namespace std;
using namespace rlutil;

int cargar_Entero()
{
    bool fail;
    int dato;
    cin.clear(); //resetear flags
    fflush(stdin); //limpiar buffer
    do
    {
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

float cargar_Float()
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

bool cargar_Bool()
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

char cargar_Char()
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

bool leer_SoN()
{
    bool rta_Correcta;
    char opcion;
    do
    {
        cin>>opcion;
        opcion = toupper(opcion);
        if (opcion != 'S' && opcion != 'N')
        {
            generar_Mensaje(0,"ERROR: RESPUESTA INVALIDA. DEBE TIPEAR S o N ...");
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

void generar_Mensaje(int error,char *mensaje)
{  //0: error - 1: advertencia - 2 : OK
    error == 0 ? setColor(LIGHTRED) : setColor(LIGHTBLUE);;
    cout<<endl<<mensaje<<endl;
    anykey();
    cls();
    setColor(WHITE);
    return;
}
