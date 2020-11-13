#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include <iostream>
#include <cstring>
#include "../modelos/fecha.h"
#include "../modelos/profesional.h"
#include "../modelos/paciente.h"


class Informe:public Registro{
    private:
        char  descripcion[500];
        int   numero;
        Fecha fecha;
        int   ID_profesional;
        int   ID_paciente;
        bool  estado;
    public:
        Informe( Fecha _fecha, int _idProfesional = 0, int _idPaciente =0, const char *_descripcion = "", int _nunero = 0){
            numero         = _nunero;
            fecha          = _fecha;
            ID_profesional = _idProfesional;
            ID_paciente    = _idPaciente;
            estado         = true;
            strcpy(descripcion,_descripcion);
        }
        ~Informe(){};
        //GETs
        const char* GetDescripcion();
        int         GetNumero();
        Fecha       GetFecha();
        int         GetProfesional();
        int         GetPaciente();
        bool        GetEstado();
        //SETs
        void SetDescripcion(const char*);
        void SetNumero(int);
        void SetFecha(Fecha);
        void SetProfesional(int);
        void SetPaciente(int);

};

#endif // INFORMES_H_INCLUDED
