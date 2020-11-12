#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED
//#include "usuario.h"
#include "profesional.h"
#include "registro.h"


class InterfazUsuario  {
    public:
        void Cargar();
        void Mostrar();
        void CambiarPasswrd();
        void BajaDeUsuario();
};

class InterfazProfesional  {
    public:
        void CargarProfesional(Profesional &);
        void MostrarProfesional(Profesional);
        void ModificarProfesional(Profesional &);
        void AgregarAArchivo(Profesional);
        void ModificarEnArchivo(Profesional);
        void ListarProfesionales();

};

#endif // INTERFAZ_H_INCLUDED
