#include "modelos/menu.h"

const char *FILE_PACIENTES             = "archivos/pacientes.dat";
const char *FILE_PROFESIONALES         = "archivos/profesionales.dat";
const char *FILE_USUARIOS              = "archivos/usuarios.dat";
const char *FILE_COBERTURAS            = "archivos/coberturas.dat";
const char *FILE_PLANFARMACO           = "archivos/planesfarmaco.dat";
const char *FILE_DETALLESPLANFARMACO   = "archivos/detallesplanesfarmaco.dat";
const char *FILE_MEDICAMENTOS          = "archivos/medicamentos.dat";
const char *FILE_FARMACOS              = "archivos/farmacos.dat";
const char *FILE_FARMACOSDELMEDICAMENTO= "archivos/farmacosdelmedicamento.dat";
const char *FILE_ESPECIALIDADES        = "archivos/especialidades.dat";
const char *FILE_INFORMES              = "archivos/informes.dat";

using namespace std;

int main()
{
    MenuLogin login;
    login.Login();
    return 0;
}
