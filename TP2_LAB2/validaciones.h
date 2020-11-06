#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

enum TipoMensaje{
    Error,
    Advertencia,
    Informativo
};

class ValidacionesGenerales{
    public:
        int ValidarPerfilDeUsuario(); //solo permite cargar un tipo de usuario correcto
        int ValidarOpciones(int _opMin, int _opMax);
        bool leer_SoN();
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



#endif // VALIDACIONES_H_INCLUDED
