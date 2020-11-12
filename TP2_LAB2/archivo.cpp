#include "ui.h"
#include "rlutil.h"
#include "archivo.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace rlutil;

//LEE EL REGISTRO UBICADO EN LA POSICI�N pos, Y LO ESCRIBE EN LA REFERENCIA var
//DEVUELVE 1 SI LEYO; 0 SI NO LEYO; -1 SI EL ARCHIVO NO EXISTE
int  Archivo::leerRegistro(Registro &var, int pos){
       int x;
       if(!abrirArchivo(SoloLectura)){
         return -1;
       }
        fseek(pF,pos*var.getSize(),0);
        x=fread(pRegistro,var.getSize(),1,pF);
        fclose(pF);
        var=(Registro *)pRegistro;
        cerrarArchivo();
        return x;
       }


//grabarRegistro( Registro &dato, int pos).
//ESCRIBE EN EL DISCO LOS DATOS EXISTENTES EN LA REFERENCIA dato
//SI EL VALOR DE POS ES -1 AGREGA UN REGISTRO NUEVO
// SI EL VALOR ES 0 O POSITIVO SOBREESCRIBE EL REGISTRO UBICADO EN ESA POSICION
//DEVUELVE 1 SI GRABO; -1 SI NO EXISTE; 0 SI NO PUDO GRABAR
int Archivo::grabarRegistro( Registro &dato, int pos){
      int grabo;
      if(pos==-1){
        dato.SetId(cantidadRegistros());
        if(!abrirArchivo(Agregar)){
        cout<<"no pudo abrir en AB"<<endl;
        anykey();
        system("cls");
        return -1;
        }
      }
      else{
        if(!abrirArchivo(LecturaEscritura)){
          return -1;
          }
        fseek(pF,pos*tamanioRegistro,0);
      }
      grabo=fwrite(&dato,tamanioRegistro,1,pF);
      cerrarArchivo();
      if(grabo &&pos==-1)  cantRegistros++;
      return grabo;
}

//alta(Registro &obj)
//AGREGA UN REGISTRO AL ARCHIVO
//VALIDA EL CAMPO CLAVE
//DEVUELVE -1 SI NO PUDO ABRIR EL ARCHIVO, 1 SI GRABO, 0 SI NO GRABO Y -2 SI SE REPITE EL CODIGO
int Archivo::alta(Registro &obj){
  int grabo;
  if(!abrirArchivo(Agregar)){
    return -1;
  }
  system("cls");
  cout<<"ALTA DE REGISTRO"<<endl;
  obj.Cargar();
  int pos=buscarRegistro(obj);
  if(pos==-1){
    grabo=grabarRegistro(obj,-1);
    cerrarArchivo();
    return grabo;
    }
  else{
    cout<<"YA EXISTE EL CODIGO"<<endl;
    cout<<"NO SE GRABO EL REGISTRO"<<endl;
    anykey();
    system("cls");
    }
  return -2;
}
//listarArchivo(Registro &aux)
//LISTA EL ARCHIVO COMPLETO
bool Archivo::listarArchivo(Registro &aux){
       if(cantRegistros==0)return false;
       if(!abrirArchivo(SoloLectura)){
         return false;
       }
       while(fread(pRegistro,tamanioRegistro,1,pF)){
         aux=(Registro *)pRegistro;
         aux.Mostrar();
         };
       cerrarArchivo();
       return true;
}


//COMPARA EL CAMPO CLAVE DEL REGISTRO RECIBIDO COMO PARAMETRO CON LOS REGISTROS DEL ARCHIVO.
//SI YA EXISTE EL VALOR DEL CAMPO CLAVE DEVUELVE LA POSICI�N QUE OCUPA EN EL ARCHIVO
//SI NO LO ENCUENTRA DEVUELVE -1, Y SI NO PUDO ABRIR EL ARCHIVO DEVUELVE -2
int Archivo::buscarRegistro(Registro &obj){
       if(!abrirArchivo(SoloLectura)){
         return -2;
       }
       while(fread(pRegistro,tamanioRegistro,1,pF)){
            if(obj.comparaID((Registro*)pRegistro)){
              int pos=(ftell(pF)-tamanioRegistro)/tamanioRegistro;
              cerrarArchivo();
              return pos;
            }
         };
       cerrarArchivo();
       return -1;
}


//abrirArchivo(Modo modo)
//ABRE EL ARCHIVO EN EL MODO ESTABLECIDO POR EL PARAMETRO modo.
//DEVUELVE TRUE SI PUDO ABRIR Y FALSE SI NO PUDO ABRIR
bool Archivo::abrirArchivo(Modo modo){
  switch(estado){
    case AbiertoR:
    case AbiertoW:
    case AbiertoA:
    case AbiertoRW:cerrarArchivo();
        break;
    }
  switch(modo){
      case SoloLectura:
                      pF=fopen(nombreArchivo,"rb");
                      if(!pF)return false;
                      estado=AbiertoR;
                      break;
      case Escritura:
                      pF=fopen(nombreArchivo,"wb");
                      if(!pF)return false;
                      estado=AbiertoW;
                      break;
      case Agregar:
                      pF=fopen(nombreArchivo,"ab");
                      if(!pF) return false;
                      estado=AbiertoA;
                      break;
      case LecturaEscritura:
                      pF=fopen(nombreArchivo,"rb+");
                      if(!pF)return false;
                      estado=AbiertoRW;
                      break;

    }
    return true;
}
