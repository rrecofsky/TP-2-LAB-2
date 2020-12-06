#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#include "../modelos/registro.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "../interfaces/interfazentidades.h"



using namespace std;

/////////////
//DEFINICIONES CLASE ARCHIVO
//Los registros del archivo deben ser objetos de clases
//derivadas de la clase registro
//
//Los métodos reciben una referencia a un objeto Registro.
//A partir de esta referencia, que representará a un objeto
//de alguna clase derivada de Registro, se consigue la especificidad
//de cada archivo.
//
//Todos los métodos abren y cierran el archivo de acuerdo
//a lo que sea necesario. No se pueda abrir el archivo desde fuera de la clase
///////////////////////////////////

enum Estado{//ESTADOS EN LOS QUE PUEDE ESTAR EL ARCHIVO
  NoExiste,
  Cerrado,
  AbiertoR,
  AbiertoW,
  AbiertoA,
  AbiertoRW
  };

 enum Modo{//MODOS DE APERTURA DE UN ARCHIVO
   SoloLectura,
   Escritura,
   Agregar,
   LecturaEscritura
   };

class Archivo{
  private:
    FILE *pF;
    int tamanioRegistro;
    void *pRegistro;
    char *nombreArchivo;
    int cantRegistros; //+1 es el ID
    int estado;
    int cantidadRegistros(){
          if(!abrirArchivo(SoloLectura)){
             estado=Cerrado;
             return 0;
            }
          fseek(pF,0,2);
          long cant=ftell(pF)/tamanioRegistro;
          cerrarArchivo();
          return (int) cant;
      }
    bool abrirArchivo(Modo modo);
    void cerrarArchivo(){
      fclose(pF);
      estado=Cerrado;
      }
  public:
      Archivo(const char *nombre, int tam, bool open = false){
          nombreArchivo=new char[strlen(nombre)+1];
          if(nombreArchivo==NULL)exit(1);
          strcpy(nombreArchivo,nombre);
          tamanioRegistro=tam;
          pRegistro=(void *)malloc(tamanioRegistro);
          cantRegistros=cantidadRegistros();
          //para los mostrar de las interfaces necesito abrir el archivo
          if (open == true){
                abrirArchivo(SoloLectura);
          }
          estado=Cerrado;
      }
    ~Archivo(){
          delete nombreArchivo;
          if(pF)fclose(pF);
          free(pRegistro);
      }

      int leerRegistro(Registro &,int );
      int  leerRegistro(Registro &);
      int buscarRegistro(Registro &);
      int grabarRegistro( Registro & , int);
      int   alta(Registro &);
      const char *getNombreArchivo(){return nombreArchivo;}
      int   getCantidadRegistros(){return cantRegistros;}
      FILE * GetPF(){return pF;} //obtener el puntero

  };






#endif // ARCHIVO_H_INCLUDED
