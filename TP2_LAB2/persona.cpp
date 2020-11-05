#include "persona.h"

/*
//Constructor persona
Persona::Persona(const char *_nombre, const char *_apellido, Fecha _fecha, int _dni){
            strcpy(nombres,_nombre);
            strcpy(apellidos,_apellido);
            fecha_nacimiento = _fecha;
            DNI              = _dni;
            estado           = true;
}
*/
//Gets

const char * Persona :: GetNombres(){return nombres;}
const char * Persona :: GetApellidos(){return apellidos; }
Fecha Persona :: GetFechaNacimiento(){ return fecha_nacimiento; }
int   Persona :: GetDNI(){return DNI;}
char  Persona :: GetGenero(){ return genero; }

const char* Persona ::GetUser(){return user;}
const char* Persona ::GetPass(){return pass;}

//Sets

void  Persona :: SetNombres(const char * _nombres){strcpy(nombres,_nombres);}
void  Persona :: SetApellidos(const char *_apellidos){ strcpy(apellidos,_apellidos);}
void  Persona :: SetFechaNacimiento(Fecha _fechaNacimiento){fecha_nacimiento = _fechaNacimiento;}
void  Persona :: SetDNI(int _dni){ DNI = _dni;}
void  Persona :: SetGenero(char _genero){ genero = _genero;}

void  Persona :: ChangeUserName(const char*_userName){strcpy(user,_userName);}
void  Persona :: ChangeUserPass(const char*_password){strcpy(pass,_password);}



