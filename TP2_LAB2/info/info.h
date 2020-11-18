#ifndef INFO_H_INCLUDED
#define INFO_H_INCLUDED

#include "../util/rlutil.h"
#include "iostream"

using namespace std;
using namespace rlutil;

void AlcanceDelPrototipo(){
    cout << left;
    cout<<"Admin puede crear usuarios con perfil PROFESIONAL y asociarlos a algun profesional"<<endl;
	cout<<"Admin puede ver la lista de Usuarios con password y todo"<<endl;
	cout<<"Admin debe crear Profesionales"<<endl;
	cout<<"Admin puede listar los profesionales"<<endl;
	cout<<"Admin no puede listar los pacientes"<<endl;
	cout<<"Admin no puede listar los planes farmacologicos ni sus detalles"<<endl;
	cout<<"Profesional puede crear pacientes"<<endl;
	cout<<"Profesional puede crear usuarios con perfil paciente"<<endl;
	cout<<"Profesional puede crear planes farmacos y asociarle el plan algun paciente"<<endl;
	cout<<"Paciente puede ver todos los profesionales"<<endl;
	cout<<"Paciente puede ver sus planes farmacologicos"<<endl;
	cout<<endl<<endl;
	system("PAUSE");
}

void ReglasDelSoftwarePorPerfilDeUsuario(){
    cout << left;
    cout<<"ADMIN:"<<endl;
    cout<<"     VER"<<endl;
    cout<<"          usuarios: Los lista (con pass y todo)"<<endl;
    cout<<"          profesionales"<<endl;
    cout<<"          pacientes"<<endl;
    cout<<"          presentacciones"<<endl;
    cout<<"          armacos"<<endl;
    cout<<"          coberturase"<<endl;
    cout<<"          especialidades"<<endl;
    cout<<"     VALIDACIONES "<<endl;
    cout<<"          Si no existe el archivo de profesionales no pude agregar usuarios poruqe no hay con quien relacionarlos"<<endl;
    cout<<"     ALTA"<<endl;
    cout<<"          Da de alta SOLO usuarios profesionales"<<endl;
    cout<<"          Puede dar de alta presentaciones (NO DISPONIBLE AUN)"<<endl;
    cout<<"          Puede dar de alta farmacos (NO DISPONIBLE AUN)"<<endl;
    cout<<"          Debe dar de alta  coberturas (NO DISPONIBLE AUN)"<<endl;
    cout<<"          Debe dar de alta  especialidades (NO DISPONIBLE AUN)"<<endl;
    cout<<"PROFESIONAL:"<<endl;
	cout<<"     VER"<<endl;
	cout<<"          Solo puede ver SUS PACIENTES (BETA: EN DESARROLLO)"<<endl;
	cout<<"	         Solo puede ver USUARIOS DE SUS PACIENTES (BETA: EN DESARROLLO)"<<endl;
	cout<<"          Solo puede ver SUS PLANES FARMACOS"<<endl;
	cout<<"          Solo puede ver sus Detalles de PLan farmaco (NO DISPONIBLE AUN)"<<endl;
	cout<<"	         Solo puede ver SUS Informes (NO DISPONIBLE AUN)" <<endl;
	cout<<"	         presentacciones (NO DISPONIBLE AUN)"<<endl;
	cout<<"          farmacos (NO DISPONIBLE AUN)"<<endl;
	cout<<"	         coberturas (NO DISPONIBLE AUN)"<<endl;
	cout<<"	         Puede ver medicaciones"<<endl;
	cout<<"	         Puede ver presentaciones"<<endl;
	cout<<"	         Puede ver farmaco"<<endl;
	cout<<"	         Puede ver planes farmacos"<<endl;
    cout<<"          Puede ver detalles de plan f."<<endl;
	cout<<"      ALTA"<<endl;
    cout<<"          Puede dar de alta usuarios CON PERFIL paciente"<<endl;
	cout<<"	         Puede dar de alta pacientes"<<endl;
    cout<<"	         Puede dar de alta planes farmacologicos"<<endl;
    cout<<"	         Puede dar de alta detalles de planes farmacologicos"<<endl;
    cout<<"	         Puede dar de alta dinformes"<<endl;
    cout<<"     VALIDACIONES"<<endl;
	cout<<"	         Debe relacionar un usuario a un paciente, siempre "<<endl;
    cout<<"          Debe relacionar un plan a un paciente, el src (prof) se setea solo"<<endl;
	cout<<"          Debe relacionar un farmaco a un detalle de plan/plan"<<endl;
	cout<<"          Debe relacionar un detalle a un plan"<<endl;
	cout<<"     MODIFICACIONES"<<endl;
    cout<<"	         Puede modificar su user/pass"<<endl;
    cout<<"PACIENTE:"<<endl;
	cout<<"     VER "<<endl;
	cout<<"          Puede ver sus planes farmac asociados"<<endl;
	cout<<"	         Puede ver los detalles de sus planes asociados"<<endl;
	cout<<"	         Puede ver los datos de su profesional"<<endl;
	cout<<"     MODIFICAR:"<<endl;
	cout<<"	         Puede cambiar su user/pass"<<endl;
    cout<<"          Puede cambiar la cantidad de pastillas"<<endl;
	cout<<"     VALIDACIONES:"<<endl;
	cout<<endl<<endl;
	system("PAUSE");
}
/*
void ReglasDelSoftwarePorClases(){
return;
}

void ValidacionesGenerales(){
return;
}

void VerificacionesGneerales(){
return;
}
*/
#endif // INFO_H_INCLUDED
