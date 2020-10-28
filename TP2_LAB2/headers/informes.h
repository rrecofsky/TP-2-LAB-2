#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

#include "../headers/fecha.h"
#include "../headers/profesional.h"
#include "../headers/paciente.h"
#include "iostream"
#include "cstring"

class Informe{
    private:
        int ID_Informe;
        char descripcion[500];
        int numero;
        Fecha fecha;
        Profesional profesional;
        Paciente paciente;
        bool estado;
    public:
        Informe( Fecha f, Profesional pf, Paciente pc, const char *h = "", int n = 0){
            ID_Informe = 0; //se debe buscar en ela rchivo el ultimo ID
            strcpy(descripcion,h);
            numero = n;
            fecha = f;
            profesional = pf;
            paciente = pc;
            estado = true;
        }
        ~Informe(){};
        //GETs
        int GetIdInforme();
        char *GetDescripcion();
        int GetNumero();
        Fecha GetFecha();
        Profesional GetProfesional();
        Paciente GetPaciente();
        bool GetEstado();
        //SETs
        void SetID(int);
        void SetDescripcion(const char*);
        void SetNumero(int);
        void SetFecha(Fecha);
        void SetProfesional(Profesional);
        void SetPaciente(Paciente);

};

#endif // INFORMES_H_INCLUDED
