#ifndef INFO_H_INCLUDED
#define INFO_H_INCLUDED

#include "../util/rlutil.h"
#include "iostream"

using namespace std;
using namespace rlutil;

void AlcanceDelPrototipo(){
    cout << left;
    cout<<"Admin puede crear usuarios con perfil PROFESIONAL"<<endl;
	cout<<"Admin puede ver la lista de Usuarios con password y todo"<<endl;
	cout<<"Admin debe creat Profesionales"<<endl;
	cout<<"Admin puede listar los profesionales"<<endl;
	cout<<"Porfesional crea pacientes"<<endl;
	cout<<"Profesional crea usuarios"<<endl;
	cout<<"Profesional crea plan farmaco y asocia el plan al paciente"<<endl;
	cout<<"Paciente consulta datos de los profesionales"<<endl;
	cout<<"Paciente consulta datos de los profesionales"<<endl;
	cout<<endl<<endl;
	system("PAUSE");
}

void ReglasDelSoftwarePorPerfilDeUsuario(){
    cout << left;
    cout<<"ADMIN:"<<endl;
    cout<<"     VER"<<endl;
    cout<<"                 usuarios: Los lista (con pass y todo)"<<endl;
    cout<<"                 profesionales"<<endl;
    cout<<"                 pacientes"<<endl;
    cout<<"                 presentacciones"<<endl;
    cout<<"                 farmacos"<<endl;
    cout<<"                 coberturase"<<endl;
    cout<<"                 especialidades"<<endl;
    cout<<"     VALIDACIONES "<<endl;
    cout<<"               Si no existe el archivo de profesionales no pude agregar usuarios poruqe no hay con quien relacionarlos"<<endl;
    cout<<"     ALTA"<<endl;
    cout<<"                 Da de alta SOLO usuarios profesionales --> OK"<<endl;
    cout<<"                 Puede dar de alta presentaciones"<<endl;
    cout<<"                 Puede dar de alta farmaco"<<endl;
    cout<<"                 Debe dar de lata las coberturas"<<endl;
    cout<<"                 Debe dar de alta las especialidades"<<endl;

    cout<<"PROFESIONAL:"<<endl;
	cout<<"     VER"<<endl;
	cout<<"             	Solo puede ver SUS PACIENTES"<<endl;
	cout<<"	                Solo puede ver USUARIOS DE SUS PACIENTES"<<endl;
	cout<<"             	Solo puede ver SUS PLANES FARMACOS"<<endl;
	cout<<"             	Solo puede ver sus Detalles de PLan farmaco"<<endl;
	cout<<"	                Solo puede ver SUS Informes"<<endl;
	cout<<"	                presentacciones"<<endl;
	cout<<"             	farmacos"<<endl;
	cout<<"	                coberturas"<<endl;
	cout<<"               	especialidades"<<endl;
	cout<<"     ALTA"<<endl;
    cout<<"                 Puede dar de alta usuarios pacientes"<<endl;
	cout<<"	                Puede dar de alta pacientes"<<endl;
	cout<<"	                Puede dar de alta medicaciones"<<endl;
	cout<<"	                Puede dar de alta presentaciones"<<endl;
	cout<<"	                Puede dar de alta farmaco"<<endl;
	cout<<"	                Puede dar de alta planes farmacos"<<endl;
    cout<<"                 Puede dar de alta detalles de plan f."<<endl;
    cout<<"	    VALIDACIONES"<<endl;
	cout<<"	                Debe relacionar un usuario a un paciente, siempre --> TESTEAR"<<endl;
    cout<<"                 Debe relacionar un plan a un paciente, el src (prof) se setea solo"<<endl;
	cout<<"                 Debe relacionar un farmaco a un detalle de plan/plan"<<endl;
	cout<<"                 Debe relacionar un detalle a un plan"<<endl;
	cout<<"     MODIFICACIONES"<<endl;
    cout<<"	                Puede modificar su user/pass"<<endl;

    cout<<"PACIENTE:"<<endl;
	cout<<"     VER "<<endl;
	cout<<"             	Puede ver sus planes farmac asociados"<<endl;
	cout<<"	                Puede ver los detalles de sus planes asociados"<<endl;
	cout<<"	                Puede ver los datos de su profesional"<<endl;
	cout<<"     MODIFICAR:"<<endl;
	cout<<"	                Puede cambiar su user/pass"<<endl;
    cout<<"                 Puede cambiar la cantidad de pastillas"<<endl;
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
