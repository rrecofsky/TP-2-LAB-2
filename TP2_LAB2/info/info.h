#ifndef INFO_H_INCLUDED
#define INFO_H_INCLUDED

#include "../util/rlutil.h"
#include "iostream"

using namespace std;
using namespace rlutil;

void AlcanceDelPrototipo(){
    cout << left;
    cout<<"FLUJO BASICO DEL PROCESO HASTA EL MOMENTO"<<endl;
    cout<<"1.El administrador carga/lista/edita profesionales"<<endl;
	cout<<"2.El administrador carga/lista usuarios (perfil profesional) y los relaciona a alguno de los profesionales creados"<<endl;
	cout<<"3.El usuario con perfil Profesional puede crear/ listar (sus) pacientes"<<endl;
	cout<<"4.El usuario con perfil Profesional puede crear usuarios y debe asociarlos a los pacientes disponibles"<<endl;
	cout<<"5.El administrador crea un plan farmacologico y se lo asocia a un paciente"<<endl;
	cout<<"6.El paciente puede ver sus planes farmacoligicos (IMPLEMENTADO PARCIALMENTE, sin DETALLE)"<<endl;
	cout<<"7.El paciente puede ver ver el listado de profesionales completo"<<endl;
	cout<<endl<<endl;
	cout<<"VALIDACIONES:"<<endl;
	cout<<"Logica de loguin -> menu por tipo de usuario"<<endl;
	cout<<"Los nombres de los usuarios puede ser alfanumericos"<<endl;
	cout<<"Los nombres de las personas solo pueden ser alfabeticos"<<endl;
	cout<<"No se pueden crear usuarios si no existe el archivod e pacientes o profesionales"<<endl;
	cout<<"El profesional solo da de altas usuario de tipo paciente (con relacion de paciente obligatoria)"<<endl;
	cout<<"El adminsitrador solo puede dar de alta usuarios de tipo profesionales (con relacion de profesional obligatoria)"<<endl;
	cout<<"El nombre de usuario no se puede repetir y es FK"<<endl;
	cout<<"Todos los registros tiene una fecha de alta, que es la misma del momento en el que se crean"<<endl;
	cout<<"Si no se asocia un paciente al plan farmacologico, se descarta"<<endl;
	cout<<"El plan farmacologico se relaciona de forma automatica al ID del profesional que lo crea"<<endl;
	cout<<"La fecha de emision del plan es la actual y es automatica"<<endl;
	cout<<"Se corrobora MES, DIA, ANIO y Año bisiesto"<<endl;
	cout<<"Se corrobora por intervalo numerico el nro de DNI"<<endl;
	cout<<"Se corrobora por intervalo numerico el nro de matricula"<<endl;
	cout<<"Se corrobora por intervalo numerico el nro de afiliado"<<endl;
	cout<<"Validaciones de tipos de datos en la mayoria de los casos (resta implementar algunos)"<<endl;
    cout<<"Un usuario NO EXISTE sin un paciente o prefesional relacionado"<<endl;
    cout<<"No se pueden cargar cadenas vacias (metodo creado pero no aplicado aun)"<<endl;
    cout<<"UserOwnerId creado en Registro para poder listar los objetos de sus propietarios (sin terminar de implementar)"<<endl;
    cout<<"Logo de inciios del sistema 'ADMIN SALUD 1.0'"<<endl;
    cout<<"No se permite asociar un usuario a un paciente/profesional ya asociado a otro usuario"<<endl;
    cout<<"Los profesionales SOLO ven sus pacientes y SUS PLANES FARMACOLOGICOS"<<endl;
    cout<<"Se valida los datos al ingresar el PERFIL de usuario"<<endl;
    cout<<"Las Altas Bajas y Modificacion de datos, son responsabilidad de la 'clases Interfaz' de cada clase"<<endl;
    cout<<"Se validacion opciones INT por intervalo y se emite un mensaje si hay error (todo aprametrizable)"<<endl;
    cout<<"Se valida el ingresoi del Genero"<<endl;
    cout<<"Se valida el ingreso de 'S' o 'N'"<<endl;
    cout<<"Se valida el dia, mes y anio"<<endl;
    cout<<"Se valida año bisciesto"<<endl;
    cout<<"Se valida si la cadena es alfanumerica"<<endl;
    cout<<"Se valida si la cadena es alfabetica"<<endl;
    cout<<"Se corrobora el ingreso de datos de tipo INT, FLOAT, BOOL, CHAR"<<endl;
    cout<<"Se muestra la fecha con formato DD/MM/AAAA"<<endl;
    cout<<endl<<endl;
	cout<<"ACLARACION IMPORTANTE!"<<endl;
	cout<<"Todas las clases tienen los metodos Mostrar, cargar, etc, estos seran eliminados cuando se terminen de implementar las interfaces. Los mismos NO SE ESTAN UTILIZANDO"<<endl;
	cout<<"Cuando se termine de implementar todo, solo se podran dar de baja las coberturas, lo deas es toda informacion que se utiliza como traza y no se puede modificar ni dar de baja logicamente, para el caso de los medicamentos por ejemplo, tendran un atributo para filtrarlos en las listas"<<endl;
	cout<<"Alguans funcionalidades estan repetidas. Esto se hizo a proposito porque esta en proceso una mejora de impelemtacion"<<endl;
	cout<<endl<<endl;
	system("PAUSE");
}

void ReglasDelSoftwarePorPerfilDeUsuario(){
    cout << left;
    cout<<"ADMIN:"<<endl;
    cout<<"     LISTA"<<endl;
    cout<<"          usuarios: Los lista (con pass y todo)"<<endl;
    cout<<"          profesionales"<<endl;
    cout<<"          presentacciones"<<endl;
    cout<<"          armacos"<<endl;
    cout<<"          coberturase"<<endl;
    cout<<"          especialidades"<<endl;
    cout<<"     VALIDACIONES "<<endl;
    cout<<"          La mayoria ya desarrolladas ..."<<endl;
    cout<<"     ALTA"<<endl;
    cout<<"          Da de alta SOLO usuarios profesionales"<<endl;
    cout<<"          Da de alta  profesionales"<<endl;
    cout<<"          Puede dar de alta presentaciones (NO DISPONIBLE AUN)"<<endl;
    cout<<"          Puede dar de alta farmacos (NO DISPONIBLE AUN)"<<endl;
    cout<<"          Debe dar de alta  coberturas (NO DISPONIBLE AUN)"<<endl;
    cout<<"          Debe dar de alta  especialidades (NO DISPONIBLE AUN)"<<endl;
    cout<<"PROFESIONAL:"<<endl;
	cout<<"     LISTA"<<endl;
	cout<<"          Solo puede ver SUS PACIENTES "<<endl;
	cout<<"	         Solo puede ver USUARIOS DE SUS PACIENTES (BETA: EN DESARROLLO)"<<endl;
	cout<<"          Solo puede ver SUS PLANES FARMACOS"<<endl;
	cout<<"          Solo puede ver sus Detalles de PLan farmaco"<<endl;
	cout<<"	         Solo puede ver SUS Informes " <<endl;
	cout<<"	         presentacciones "<<endl;
	cout<<"          farmacos "<<endl;
	cout<<"	         coberturas "<<endl;
	cout<<"	         Puede ver medicaciones"<<endl;
	cout<<"	         Puede ver presentaciones"<<endl;
	cout<<"	         Puede ver farmaco"<<endl;
	cout<<"      ALTA"<<endl;
    cout<<"          Puede dar de alta usuarios CON PERFIL paciente"<<endl;
	cout<<"	         Puede dar de alta pacientes"<<endl;
    cout<<"	         Puede dar de alta planes farmacologicos"<<endl;
    cout<<"	         Puede dar de alta detalles de planes farmacologicos"<<endl;
    cout<<"	         Puede dar de alta informes"<<endl;
    cout<<"     VALIDACIONES"<<endl;
	cout<<"	         Debe relacionar un usuario a un paciente, siempre "<<endl;
    cout<<"          Debe relacionar un plan a un paciente, el src (prof) se setea solo"<<endl;
	cout<<"          Debe relacionar un farmaco a un detalle de plan/plan"<<endl;
	cout<<"          Debe relacionar un detalle a un plan"<<endl;
	cout<<"          faltan agregar mas .... muchas ya desarrolaldas"<<endl;
	cout<<"     MODIFICACIONES"<<endl;
    cout<<"	         Puede modificar su user/pass"<<endl;
    cout<<"PACIENTE:"<<endl;
	cout<<"     LISTA "<<endl;
	cout<<"          Puede ver sus planes farmac asociados"<<endl;
	cout<<"	         Puede ver los detalles de sus planes asociados"<<endl;
	cout<<"	         Puede ver los el listado completop de profesionales"<<endl;
    cout<<"	         Puede ver los el su profesional"<<endl;
	cout<<"     MODIFICAR:"<<endl;
	cout<<"	         Puede cambiar su user/pass"<<endl;
    cout<<"          Puede cambiar la cantidad de pastillas del detalle del plan"<<endl;
	cout<<"     VALIDACIONES:"<<endl;
	cout<<"          Sin definir:"<<endl;
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
