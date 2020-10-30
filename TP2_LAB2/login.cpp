#include <iostream>
#include <string.h>
#include "menuesadministrador.h"
#include "menuespaciente.h"
#include "menuesprofesional.h"

using namespace std;

void MenuLogin(char* usr, char* pas)
{
    char user[50], pass[50];
    cout<<"Ingrese un usuario: ";
    cin>>user;
    cout<<"Ingrese su contrasenia: ";
    cin>>pass;

    if (strcmp(usr,user) == 0 && strcmp(pass,pas)  ==  0){
       MenuAdministrador();
    }else if (strcmp("paciente",user) == 0 && strcmp(pass,"paciente")  ==  0){
            MenuPaciente();
          }
         else if (strcmp("profesional",user) == 0 && strcmp(pass,"profesional")  ==  0){
                MenuProfesional();
               }
    return;
}
