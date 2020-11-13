#include "informes.h"

///GETS

const char* Informe:: GetDescripcion(){return descripcion;}
int         Informe:: GetNumero(){return numero;}
Fecha       Informe:: GetFecha(){return fecha;}
int         Informe:: GetProfesional(){return ID_profesional;}
int         Informe:: GetPaciente(){return ID_paciente;}

///SETS

void Informe:: SetDescripcion(const char* _descripcion){strcpy(descripcion,_descripcion);}
void Informe:: Informe:: SetNumero(int _numero){numero = _numero;}
void Informe:: SetFecha(Fecha _fecha){fecha = _fecha;}
void Informe:: SetProfesional(int _idProfesional){ID_profesional = _idProfesional;}
void Informe:: SetPaciente(int _idPaciente){ID_paciente = _idPaciente;}
