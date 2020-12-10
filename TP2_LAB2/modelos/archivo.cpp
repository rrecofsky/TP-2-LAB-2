#include "../util/ui.h"
#include "../util/rlutil.h"
#include "archivo.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace rlutil;

//LEE EL REGISTRO UBICADO EN LA POSICIÓN pos, Y LO ESCRIBE EN LA REFERENCIA var
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

 //BUSCA EL REGISTRO Y SI LO ENCUENTRA, LO ESCRIBE EN AL REFERENCIA
 //DEVUELVE 1 SI LEYO; 0 SI NO LEYO; -1 SI EL ARCHIVO NO EXISTE
 int  Archivo::leerRegistro(Registro &var){
       int x;
       if(!abrirArchivo(SoloLectura)){
         return -1;
       }
        int pos = buscarRegistro(var);
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


//USAR POLIMORFISMO CON CLASE InterfazGenerica
bool Archivo::listarArchivoProfesionales(Profesional &aux){
      InterfazProfesional interfazProfesional;
       if(cantRegistros==0)return false;
       if(!abrirArchivo(SoloLectura)){
            cout<<"NO ABRI EL ARCHIVO"<<endl;
         return false;
       }
       while(fread(&aux,tamanioRegistro,1,pF)){
         interfazProfesional.MostrarProfesional(aux);
         };
       cerrarArchivo();
       return true;
}


//COMPARA EL CAMPO CLAVE DEL REGISTRO RECIBIDO COMO PARAMETRO CON LOS REGISTROS DEL ARCHIVO.
//SI YA EXISTE EL VALOR DEL CAMPO CLAVE DEVUELVE LA POSICIÓN QUE OCUPA EN EL ARCHIVO
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
