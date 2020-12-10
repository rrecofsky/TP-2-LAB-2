#include "../modelos/informe.h"

//gets
Fecha Informe :: GetFechaEmision(){return fechaEmision;};
int   Informe :: GetIdPaciente(){return idPaciente;}
int   Informe :: GetIdProfesional(){return idProfesional;}
const char* Informe :: GetDetalle(){return detalle;}
//sets
void  Informe :: SetFechaEmision(Fecha _fechaEmision){fechaEmision = _fechaEmision;}
void  Informe :: SetIdPaciente(int _idPaciente){idPaciente = _idPaciente;}
void  Informe :: SetIdProfesional(int _idProfesional){idProfesional = _idProfesional;}
void  Informe :: SetDetalle(const char* _detalle){strcpy(detalle,_detalle);}

//heredadas
int   Informe :: getSize(){return sizeof *this;}
bool  Informe :: comparaID(Registro *temp){
            Informe *aux=(Informe *)temp;
            if(aux->ID == ID) return true;
            return false;
}

