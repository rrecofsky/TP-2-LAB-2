#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED
//#include "usuario.h"
#include "profesional.h"
#include "registro.h"
#include "usuario.h"
#include "paciente.h"

class InterfazPersona{
    public:
        void AsociarPersona(Persona &);
};

class InterfazUsuario  {
    public:
        void CargarUsuario(Usuario &);
        void MostrarUsuario(Usuario);
        void ModificarUsuario(Usuario &);
        void AgregarUsuarioAArchivo(Usuario);
        void ModificarUsuarioEnArchivo(Usuario);
        void ListarUsuarios();
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

class InterfazPaciente  {
    public:
        void CargarPaciente(Paciente &);
        void MostrarPaciente(Paciente);
        void ModificarPaciente(Paciente &);
        void AgregarPacienteAArchivo(Paciente);
        void ModificarPacienteEnArchivo(Paciente);
        void ListarPacientes();

};

#endif // INTERFAZ_H_INCLUDED
