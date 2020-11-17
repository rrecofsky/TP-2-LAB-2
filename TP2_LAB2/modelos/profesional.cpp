#include "../modelos/profesional.h"
#include <iostream>
#include <limits>
#include "../validaciones/validaciones.h"
#include "../util/rlutil.h"
#include "../modelos/usuario.h"

using namespace std;
using namespace rlutil;

extern Usuario usr_lgd;

int  Profesional :: GetMatricula(){return matricula;}
int  Profesional :: GetEspecialidad(){return ID_especialidad;}
//SETs
void Profesional :: SetMatricula(int _matricula){matricula = _matricula;}
void Profesional :: SetEspecialidad(int _idEspecialidad){ID_especialidad = _idEspecialidad;}

///pol

bool  Profesional :: comparaID(Registro *temp){
        Profesional *aux=(Profesional *)temp;
        if( (DNI != 0 && aux->DNI != 0 )&& DNI == aux->DNI ) return true;
        if(ID == aux->ID ) return true;
        return false;
}


///MOSTRAR Y CARGAR

int matricula;
int ID_especialidad;

void Profesional :: Cargar(){

    Persona::Cargar();
    cout<<"NRO DE MATRICULA: ";
    cin>>matricula;
    cout<<endl;
    cout<<"ID DE LA ESPECIALIDAD: ";
    cin>>ID_especialidad;
    return;
}

void Profesional :: Mostrar(){

    cout << left;
    if (usr_lgd.GetPerfilUser() == Perfil_Administrador)//Solo el admin ve el ID
    cout << setw(12) << ID;
    cout << setw(12) << nombres;
    cout << setw(12) << apellidos;
    cout << setw(12) << genero;
    cout << setw(12) << DNI;
    cout << setw(12) << GetEdad();
    cout << setw(12) << matricula;
    cout << setw(12) <<"SIN IMPLEMENTAR";
    cout<<endl;
}

void Profesional :: Modificar(){
    ValidacionesGenerales validacion;
    int opcion=0;
    Persona :: Mostrar();
    cout<<"NRO DE MATRICULA: "<<matricula<<endl;
    cout<<"ID DE LA ESPECIALIDAD: "<<ID_especialidad<<endl;
    cout<<"ESPECIALIDAD: "<<"A DESARROLLAR ..."<<endl;
    cout<<"QUE DESEA MODIFICAR?"<<endl;
    cout<<"1) NOMBRES"<<endl;
    cout<<"2) APELLIDOS"<<endl;
    cout<<"3) GENERO"<<endl;
    cout<<"4) DNI"<<endl;
    cout<<"5) NRO DE MATRICULA"<<endl;
    cout<<"7) ESTADO"<<endl;
    cout<<"8) ESPECIALIDAD"<<endl;
    cout<<"----------------------"<<endl;
    cout<<"0) REGRESAR"<<endl;
    cout << endl << "> ";
    cin >> opcion;
    switch(opcion)
        {
            case 1: cin.getline(nombres,50);
                    break;
            case 2:
                    cin.getline(apellidos,50);
                    break;
            case 3:
                    genero = validacion.ValidarGenero();
                    break;
            case 4:
                    cin>>DNI;
                    break;
            case 5:
                    cin>>matricula;
                    break;
            case 6:
                    cin>>ID_especialidad;
                    break;
            case 7:
                    cin>>estado;
                    break;
            case 0:
                    return;
            break;
        }
    cout<<endl;
    return ;
}
