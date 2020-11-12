#include "interfaz.h"
#include <limits>
#include <iostream>
#include "usuario.h"
#include "archivo.h"
#include "validaciones.h"
#include "rlutil.h"

extern const char *FILE_USUARIOS;
extern const char *FILE_PACIENTES;
extern const char *FILE_PROFESIONALES;
extern Usuario usr_lgd;
using namespace rlutil;


using namespace std;

/// INTERFAZ USUARIO
/*
void  InterfazUsuario :: Mostrar(){

        cout<<"USER: "<<usr_lgd.GetUserName()<<endl;
        cout<<"PASS: "<<usr_lgd.GetUserPass()<<endl;
        cout<<strcat("PERFIL: ",usr_lgd.GetPerfilUser() == 1 ? "PROFESIONAL" : "PACIENTE")<<endl;
        cout<<"USUARIO RELACIONADO: "<<"##DESARRROLLAR##"<<endl;
        if (usr_lgd.GetPerfilUser()==Perfil_Administrador){
            cout<<"FECHA DE ALTA: "<<usr_lgd.GetFechaAlta().GetFechaConFormato()<<endl;
            cout<<"FECHA DE BAJA: "<<usr_lgd.GetFechaBaja().GetFechaConFormato()<<endl;
            cout<<strcat("ESTADO: ",usr_lgd.GetEstado() == true ? "ACTIVO" : "INAVTIVO")<<endl;
            cout<<"ID: "<<usr_lgd.GetId()<<endl;
        }
        getchar();
        return;
}

void  InterfazUsuario :: Cargar()
{
        char usr[50], pas[50];
        cout<<"USER: ";
        cin.clear(); // unset failbit
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); // skip bad input
        cin.getline(usr,50);
        usr_lgd.ChangeUserName(usr);
        cout<<endl;
        cout<<"PASS: ";
        cin.getline(pas,50);
        usr_lgd.ChangeUserPass(pas);
        cout<<"FALTA RELACIONAR A UN USUARIO"<<endl;
}

void InterfazUsuario :: CambiarPasswrd(){
        char usr[50], pas[50];
        cout<<"NUEVO USUARIO ";
        cin.clear(); // unset failbit
        cin.ignore(numeric_limits<streamsize>::max(),'\n'); // skip bad input
        cin.getline(usr,50);
        usr_lgd.ChangeUserName(usr);
        cout<<endl;
        cout<<"NUEVA CONTRASENIA: ";
        cin.getline(pas,50);
        usr_lgd.ChangeUserPass(pas);
}

void  InterfazUsuario :: BajaDeUsuario(){
//Se da de baja el usuario, y a la Persona relacionada
/*
       Archivo archUsuarios(FILE_USUARIOS,sizeof(Usuario));
       ValidacionesGenerales validaciones;
       Usuario usrAux;
       char salir;
       char usrName[50];//var aux
       int tipoDeUsuario=-1; //tipo de usuario que se desea dar de baja
       do{
            cout << "INGRESE EL PERFIL DEL USUARIO QUE DESEA DESHABILITAR:"<<endl<<endl;
            cout << "1 - Profesional"<<endl;
            cout << "2 - Paciente"<<endl;

            tipoDeUsuario = validaciones.ValidarPerfilDeUsuario();

            cout << "INGRESE UN USUARIO: ";
            cout << endl << "> ";
            cin.getline(usrName,50);
            usrAux.ChangeUserName(usrName);
            int posUser = archUsuarios.buscarRegistro(usrAux);

            if ( archUsuarios.leerRegistro(usrAux, posUser) != -1)
                if(tipoDeUsuario == Perfil_Profesional){
                    Archivo archProfesionales(FILE_PROFESIONALES,sizeof(Usuario));
                    int posProfesional = archProfesionales.buscarRegistro(usrAux.GetId());


                }else
                    if(tipoDeUsuario == Perfil_Paciente){
                    Archivo archPacientes(FILE_PACIENTES,sizeof(Usuario));

                    }
            else{
                cout<<"NO SE ENCONTRO EL USUARIO: "<<usrName<<", DESEA VOLVER A CARGAR? S/N"<<endl;
                salir = validaciones.leer_SoN();
                if (salir) return;
                }
       }while(true);
    return;

}
*/
///INERFAZ PROFESIONAL

void InterfazProfesional :: CargarProfesional(Profesional &prof){
    ValidacionesTipoDato validaTDato;
    ValidacionesGenerales validaGeneral;
    Fecha fecha;
    char nombres[50], apellidos[50];
    cout<<"NOMBRES: ";
    cin.clear(); // unset failbit
    cin.ignore(numeric_limits<streamsize>::max(),'\n'); // skip bad input
    cin.getline(nombres,50);
    prof.SetNombres(nombres);
    cout<<endl;
    cout<<"APELLIDOS: ";
    cin.getline(apellidos,50);
    prof.SetApellidos(apellidos);
    cout<<endl;
    cout<<"GENERO: ";
    prof.SetGenero(validaGeneral.ValidarGenero());
    cout<<"FECHA DE NACIMIENTO: ";
    fecha.CargarFecha();
    prof.SetFechaNacimiento(fecha);
    cout<<endl;
    cout<<"DNI: ";
    prof.SetDNI(validaTDato.cargar_Entero());
    cout<<endl;
    cout<<"NRO DE MATRICULA: ";
    prof.SetMatricula(validaTDato.cargar_Entero());
    cout<<endl;
    cout<<"ID DE LA ESPECIALIDAD: ";
    prof.SetEspecialidad(validaTDato.cargar_Entero());
    return;
};

void InterfazProfesional :: MostrarProfesional(Profesional _prof){

    cout<<"NOMBRES: "<<_prof.GetNombres()<<endl;
    cout<<"APELLIDOS: "<<_prof.GetApellidos()<<endl;
    cout<<"GENERO: "<<_prof.GetGenero()<<endl;
    cout<<"DNI: "<<_prof.GetDNI()<<endl;
    cout<<"EDAD: "<<_prof.GetEdad()<<endl;
    cout<<"FECHA DE NACIMIENTO: ";
    _prof.GetFechaNacimiento().GetFecha();
    cout<<endl;
    cout<<"NRO DE MATRICULA: "<<_prof.GetMatricula()<<endl;
    cout<<"ID DE LA ESPECIALIDAD: "<<_prof.GetEspecialidad()<<endl;
    cout<<"ESPECIALIDAD: "<<"A DESARROLLAR ..."<<endl;
    cout<<endl;
    anykey();

};
void InterfazProfesional :: ModificarProfesional(){};

void InterfazProfesional :: AgregarAArchivo(Profesional _prof){
    cls();
    ValidacionesGenerales valGral;
    cout<<"ESTA SEGURO QUE DESEA AGREGAR EL SIGUIENTE PROFESIONAL? S/N";
    cout<<endl<<endl;
    MostrarProfesional(_prof);
    cout << endl << "> ";
    if(valGral.leer_SoN())
    {
        Archivo profesionales(FILE_PROFESIONALES,sizeof(Profesional));
        if(profesionales.grabarRegistro(_prof,-1) == 1)
            cout<<"SE GRABO SATISFACTORIAMENTE EL PROFESIONAL CARGADO"<<endl;
        else
            cout<<"NO SE PUDO GRABAR SATISFACTORIAMENTE EL PROFESIONAL CARGADO"<<endl;
    }
    anykey();
};

void InterfazProfesional :: ModificarEnArchivo(Profesional _prof, int _posiscion){
    ValidacionesGenerales validaciones;
    Archivo profesionales(FILE_PROFESIONALES,sizeof(Profesional));
    Profesional prof;
    char rta;
    int idProfesional;
    cout<<"DESEA VER LA LISTA DE PROFESIONALES? S/N"<<endl;
    rta = validaciones.leer_SoN();
         if (rta) MostrarProfesionales();
    cout<<"INGRESE EL ID DEL PROFESIONAL: ";
    cout << endl << "> ";
    cin>>idProfesional;
    prof.SetId(idProfesional);
    int posProf = profesionales.buscarRegistro(prof);
    if ( profesionales.leerRegistro(prof, posProf) != -1){ //si encontro el profesional
        prof.Modificar();
        if(profesionales.grabarRegistro(prof,posProf) == 1)
            cout<<"SE ACTUALIZO SATISFACTORIAMENTE EL PROFESIONAL CARGADO"<<endl;
        else
            cout<<"NO SE PUDO ACTUALIZAR SATISFACTORIAMENTE EL PROFESIONAL CARGADO"<<endl;
        anykey();
        return;
    }
};

void InterfazProfesional :: ListarProfesionales(){
    Archivo profesionales(FILE_PROFESIONALES,sizeof(Profesional));
    Profesional prof;
    if(!profesionales.listarArchivo(prof)){
        cout<<"NO HAY REGISTROS PARA LISTAR"<<endl;
        anykey();
        system("cls");
    }
}

