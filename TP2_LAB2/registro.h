#ifndef REGISTRO_H_INCLUDED
#define REGISTRO_H_INCLUDED

#include "fecha.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

//Clase Abastracta registro
class Registro{
  protected:
      int   ID;
      bool  estado;
      Fecha fechaAlta;
      Fecha fechaBaja;
  public:
      Registro();
      //SETs
      void  SetId();  //Los Ids se generan igual para todas las clases: se debe buscar el ultimo en su archivo correspondiente
      void  SetEstado(bool); //Los estados se generan por defecto en true con el constructor, pero se puede setear al darla de baja
      //GETs
      int   GetId();
      bool  GetEstado();
      Fecha GetFechaAlta();
      Fecha GetFechaBaja();
      //GET VIRTUALES
      virtual void Cargar() = 0;
      virtual void Mostrar()= 0;
      virtual int getSize() = 0;//DEVUELVE EL SIZEOF DEL OBJETO
      virtual Registro& operator = (Registro *) =0;//SOBRECARGA PARA ASIGNAR UN PUNTERO REGISTRO A UNA REFERENCIA A UN OBJETO DE UNA CLASE DERIVADA DE REGISTRO
      virtual bool comparaID(Registro*)=0;// SE SUPONE QUE CADA CLASE TIENE UNA PROPIEDAD QUE
};                                       // IDENTIFICA A CADA OBJETO (UN PROPIEDAD CLAVE)
     //COMO ESA IDENTIFICACION UNICA (ID) PUEDE SER DE DISTINTO TIPO SE DEBE HACER UN METODO
      //PARA COMPARAR EL VALOR DE LA PROPIEDAD CLAVE ENTRE DISTINTOS OBJETOS

#endif // REGISTRO_H_INCLUDED
