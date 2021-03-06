#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED



class Logo{
    public:
        void logo();
};

class MenuLogin{
    public:
        void Login();
};

class MenuAdministrador{
    public:
        void MenuAdmin();
        void MenuGeneralAdministrador(const char * entidad);

        void AltaProfesional();
        void ModificarProfesional();
        void MostrarProfesionales();

        void AltaUsuario();
        void MostrarUsuarios();

        void AltaMedicamento();
        void MostrarMedicamento();

        void AltaFarmaco();
        void MostrarFarmaco();

        void AltaCobertura();
        void ModificarCobertura();
        void MostrarCobertura();

        void AltaEspecialidad();
        void ModificarEspecialidad();
        void MostrarEspecialidad();
};

class MenuProfesional{
    public:
        void MenuProfesionalConsulta();
        void MenuProfesionalListado();
        void MenuProf();
        void menuListarPorProfesionalPaciente(const char *);///PABLO
        void PlanesFarmacologicos();
        void Pacientes();
        void Consultas();
        void ModificarDatosDeUsuarioLogueado();
        ///USUARIOS
        void AltaDeUsuariosPaciente();
        void MostrarUsuariosPaciente();
        ///INFORMES
        void AltaDeInformes();
        void MostrarInformesDelProfesional();
        void MostrarInformesDelPaciente(); ///PABLO
        ///PLANESFARMA
        void AltaPlanFarmacologico();
        void MostrarPlanesFarmacologicosDelProfesional();
        void MostrarPlanesFarmacologicosDelPaciente();
        ///PACIENTES
        void AltaPacienteDelProfesional();
        void MostrarPacientesDelProfesional();
        void ModificarPacienteDelProfesional();
        ///ESTUDIOS
        void MostrarEstudiosDelProfesional();
        ///MENUES
        void MenuGeneral(const char * );

};

class MenuPaciente{
    public:
        void MostrarPlanesFarmacologicosDelPaciente();
        void MostrarProfesionalesDelPaciente();
        void ModificarUsuarioPaciente();
        /*aun*/
        void MenuPacienteConsulta();
        void MenuPlanFarmacologico();
        void MenuPac();
        void MenuPacienteListados();
        void AdminPlanFarmaco();
};

#endif // MENU_H_INCLUDED
