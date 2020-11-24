#include "modelos/menu.h"


const char *FILE_PACIENTES     = "archivos/pacientes.dat";
const char *FILE_PROFESIONALES = "archivos/profesionales.dat";
const char *FILE_USUARIOS      = "archivos/usuarios.dat";
const char *FILE_COBERTURAS    = "archivos/coberturas.dat";
const char *FILE_PLANFARMACO   = "archivos/planesfarmaco.dat";


using namespace std;

int main()
{
    MenuLogin login;
    login.Login();
    return 0;
}
