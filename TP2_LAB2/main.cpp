#include "menues/login.h"

#include <string.h>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;


const char *FILE_PACIENTES     = "archivos/pacientes.dat";
const char *FILE_PROFESIONALES = "archivos/profesionales.dat";
const char *FILE_USUARIOS      = "archivos/usuarios.dat";
const char *FILE_COBERTURAS    = "archivos/coberturas.dat";
const char *FILE_PLANFARMACO   = "archivos/planesfarmaco.dat";


using namespace std;

int main()
{

     char str[10]={};//dd/mm/aaaa
    char dd[2]={}, mm[2]={}, aaaa[4]={};
    itoa(10,dd,10);
    strcat(str,dd);
    strcat(str,"/");
    itoa(12,mm,10);
    strcat(str,mm);
    strcat(str,"/");
    itoa(1987,aaaa,10);
    strcat(str,aaaa);
    cout<< str;

    MenuLogin();
    return 0;
}
