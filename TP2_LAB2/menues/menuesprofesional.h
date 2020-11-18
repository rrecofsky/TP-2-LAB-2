#ifndef MENUESPROFESIONAL_H_INCLUDED
#define MENUESPROFESIONAL_H_INCLUDED

#include "../interfaces/interfazplanfarmacologico.h"

void MenuProfesionalConsulta();
void MenuProfesionalListado();
void MenuProfesional();
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
///PACIENTES
void AltaPacienteDelProfesional();
void MostrarPacientesDelProfesional();
void ModificarPacienteDelProfesional();
///MENUES
void MenuGeneral(const char * );



#endif // MENUESPROFESIONAL_H_INCLUDED
