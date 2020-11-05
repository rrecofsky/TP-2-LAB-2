#include <iostream>
#include "login.h"
#include "rlutil.h"
#include "profesional.h"

const char *FILE_PACIENTES = "pacientes.dat";
const char *FILE_PROFESIONALES = "profesionales.dat";
const char *user = "admin";
const char *pass = "admin";

using namespace std;

int main()
{
    MenuLogin(user,pass);
    return 0;
}
