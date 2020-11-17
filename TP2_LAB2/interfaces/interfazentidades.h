#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED
#include "../modelos/profesional.h"
#include "../modelos/registro.h"
#include "../modelos/usuario.h"
#include "../modelos/paciente.h"
#include "../interfaces/interfazgeneral.h"

class InterfazPersona{
    public:
        int  AsociarProfesional(Profesional &);
        void MostrarCabeceraPersona();
        void ObtenerPersona(Persona &);
        int  AsociarPaciente(Paciente & );
        int AsociarUsuario(Usuario & );
};

class InterfazUsuario : public InterfazGeneral {
    public:
        bool CargarUsuario(Usuario &);
        void MostrarUsuario(Usuario);
        void ModificarUsuario(Usuario &);
        void AgregarUsuarioAArchivo(Usuario);
        void ModificarUsuarioEnArchivo(Usuario);
        void ListarUsuarios();
        bool AsociarUsuario(Usuario &);
};

class InterfazProfesional {
    public:
        bool CargarProfesional(Profesional &);
        void MostrarProfesional(Profesional);
        void ModificarProfesional(Profesional &);
        void AgregarAArchivo(Profesional);
        void ModificarEnArchivo(Profesional &);
        void ListarProfesionales();

};

class InterfazPaciente  {
    public:
        bool CargarPaciente(Paciente &);
        void MostrarPaciente(Paciente);
        void ModificarPaciente(Paciente &);
        void AgregarPacienteAArchivo(Paciente);
        void ModificarPacienteEnArchivo(Paciente);
        void ListarPacientes();

};

#endif // INTERFAZ_H_INCLUDED
