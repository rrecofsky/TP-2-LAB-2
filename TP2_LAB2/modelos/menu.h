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
        void MenuGeneralAdministrador(const char *);

        void AltaProfesional();
        void ModificarProfesional();
        void MostrarProfesionales();

        void AltaUsuario();
        void ModificarUsuario();
        void MostrarUsuarios();

        void MenuAlcance();

        void AltaPresentacion();
        void ModificarPresentacion();
        void MostrarPresentacion();

        void AltaFarmaco();
        void ModificarFarmaco();
        void MostrarFarmaco();

        void AltaCobertura();
        void ModificarCobertura();
        void MostrarCobertura();

        void AltaEspecialidad();
        void ModificarEspecialidad();
        void MostrarEspecialidad();

        //INFO
        void AlcanceDelPrototipo();
        void ReglasDelSoftwarePorPerfilDeUsuario();
};

class MenuProfesional{
    public:
        void MenuProfesionalConsulta();
        void MenuProfesionalListado();
        void MenuProf();
        void menuListarPlanesFarmacologicos(const char *);
        void menuListarPlanesFarmacologicosPorPaciente(const char *);
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
};

#endif // MENU_H_INCLUDED
