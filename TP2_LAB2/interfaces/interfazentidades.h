#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED
#include "../modelos/profesional.h"
#include "../modelos/registro.h"
#include "../modelos/usuario.h"
#include "../modelos/paciente.h"
#include "../interfaces/interfazgeneral.h"
#include <vector>

class InterfazPersona : public InterfazGeneral{
    public:
        void MostrarCabeceraPersona();
};

class InterfazUsuario : public InterfazPersona {
    public:
        bool CargarUsuario(Usuario &);
        void MostrarUsuario(Usuario);
        void ModificarUsuario(Usuario &);
        void AgregarUsuarioAArchivo(Usuario);
        void ModificarUsuarioEnArchivo(Usuario);
        void ListarUsuarios();
        bool AsociarUsuario(Usuario &);
        int  ObtenerUsuario(Usuario & );
};

class InterfazProfesional : public InterfazPersona  {
    public:
        bool CargarProfesional(Profesional &);
        void MostrarProfesional(Profesional);
        void ModificarProfesional(Profesional &);
        void AgregarAArchivo(Profesional);
        void ModificarEnArchivo(Profesional &);
        void ListarProfesionales();

        void ListarProfesionalesConFiltro(vector<int> & , Filtros );
        void ActualizarProfesional(Profesional , int );

        int  GetCantidadProfesionales();
        int  ObtenerProfesional(Profesional &);
};

class InterfazPaciente : public InterfazPersona  {
    public:
        bool CargarPaciente(Paciente &);
        void MostrarPaciente(Paciente);
        void ModificarPaciente(Paciente &);
        void AgregarPacienteAArchivo(Paciente);
        void ModificarPacienteEnArchivo(Paciente);
        void ListarPacientes();

        void ListarPacientesConFiltro(vector<int> & _vec, Filtros);
        void ActualizarPaciente(Paciente , int );

        int  GetCantidadPacientes();
        int  ObtenerPaciente(Paciente & );

};

#endif // INTERFAZ_H_INCLUDED
