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
        int  ID_profesional;
        int ID_paciente;
        bool estado;
    public:
        Informe( Fecha f, int pf = 0, int pc =0, const char *h = "", int n = 0){
            ID_Informe = 0; //se debe buscar en ela rchivo el ultimo ID
            strcpy(descripcion,h);
            numero = n;
            fecha = f;
            ID_profesional = pf;
            ID_paciente = pc;
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
