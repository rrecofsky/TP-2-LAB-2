#include <iostream>
#include <string>
#include <typeinfo>
#include "../util/ui.h"
#include "../util/rlutil.h"
#include "../validaciones/validaciones.h"
#include "../modelos/fecha.h"
//#include "../modelos/paciente.h"
//#include "../modelos/profesional.h"

using namespace std;
using namespace rlutil;

///Funciones GLOBALES

#define GetSize(array_char) (sizeof(array_char)/sizeof(*(array_char)))

//int longitud=GetSize(array_caracteres_enteros);


bool  compararCaracter(char& _c1,char& _c2){

    if (_c1 == _c2) return true;
    else
        if (toupper(_c1) == toupper(_c2))
            return true;

    return false;
}

bool  compararCadenas(char *_cad1,char*_cad2){
string str1(_cad1), str2(_cad2);
return ( (strlen(_cad1) == strlen(_cad2) ) &&
       equal( str1.begin(),str1.end(), str2.begin(), &compararCaracter ));
}

///VALIDACIONES GENERALES

bool ValidacionesGenerales :: EsCadenaAlfanumerica(const char * _cadena){
    ValidacionesTipoDato val;
 /*   if (EsCadenaVacia(_cadena)){
        val.generar_Mensaje(Error,"NO SE ADMITEN TEXTOS SIN LETRAS");
        cout<<endl<<endl;
        system("PAUSE");
        false;
    }*/
    for (int i=0; i<strlen(_cadena);i++)
        if (!isalnum(_cadena[i]))
            return false;
    return true;
}

bool ValidacionesGenerales :: EsCadenaAlfabetica(const char * _cadena){
    ValidacionesTipoDato val;
  /*  if (EsCadenaVacia(_cadena)){
        val.generar_Mensaje(Error,"NO SE ADMITEN TEXTOS SIN LETRAS");
        cout<<endl<<endl;
        system("PAUSE");
        false;
    }*/
    for (int i=0; i<strlen(_cadena);i++)
        if (!isalpha(_cadena[i]))
            return false;
    return true;
}

bool ValidacionesGenerales :: EsCadenaVacia(const char * _cadena){
    if (strlen(_cadena) == 0)
        true;
    false;
}


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

    if ( _fecha.GetDia() <1 || _fecha.GetDia() >31) {
        validoFecha=false;
    }
    if (_fecha.GetMes()<1 || _fecha.GetMes()>12) {
        validoFecha=false;
    }
    if (_fecha.GetAnio()<1000) {
        validoFecha=false;
    }
    //Biciesto para el mes de febrero
    if ( _fecha.GetMes()==2 && _fecha.GetDia()==29 && ( _fecha.GetAnio() % 400 != 0 || (_fecha.GetAnio() % 4 == 0 && _fecha.GetAnio() % 100 != 0) ))
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
        if (fail) val.generar_Mensaje(Error,_msj);

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

int  ValidacionesGenerales :: ValidarDNI(){
    return ValidarOpciones( 5000000,  50000000, "EL DNI NO PUEDE SER MENOR QUE 5.000.000 NI MAYOR QUE 70.000.000");
}

int  ValidacionesGenerales :: ValidarNroAlifiado( ){
     return ValidarOpciones( 0,  4000000, "EL NRO DE AFILIADO NO PUEDE SER MENOR QUE 1000 NI MAYOR QUE 4000");
}

int  ValidacionesGenerales ::  ValidarMatricula( ){
    return ValidarOpciones( 0,  400000, "EL NRO DE MATRICULA NO PUEDE SER MENOR QUE 10000 NI MAYOR QUE 40000");
}

///VALIDACIONES TIPO DE DATO
/*
const char *  ValidacionesTipoDato :: cargar_Cadena(int tam ){
    //*No funciona bien, consultar.
    char cadena[tam];
    cout << endl << "> ";
    cin.clear();
    cin.ignore();
    cin.getline(cadena,tam);
    return cadena;
}*/


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

const char* ValidacionesTipoDato :: intToStr(int _data) {
    string strData = to_string(_data);
    char* temp = new char[strData.length() + 1];
    strcpy(temp, strData.c_str());
    return temp;
}


