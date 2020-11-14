#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include "../modelos/fecha.h"
#include "../modelos/usuario.h"
#include "../modelos/profesional.h"
#include "../modelos/persona.h"
#include <ctype.h>

enum TipoMensaje{
    Error,
    Advertencia,
    Informativo
};

class ValidacionesGenerales{
    public:
        Perfil ValidarPerfilDeUsuario(); //solo permite cargar un tipo de usuario correcto
        int ValidarOpciones(int , int , const char *);
        char ValidarGenero();
        bool leer_SoN();
        int ValidarDia();
        int ValidarMes();
        int ValidarAnio();
        bool EsBiciesto(Fecha );
        const char * GetFechaConFormato(Fecha);

};

class ValidacionesTipoDato{
    public:
        int cargar_Entero();
        float cargar_Float();
        bool cargar_Bool();
        char cargar_Char();
        void generar_Mensaje(int ,const char *);
        void ADesarrollar();
};

bool  compararCadenas(char *,char*);
bool  compararCaracter(char& ,char& );




#endif // VALIDACIONES_H_INCLUDED
