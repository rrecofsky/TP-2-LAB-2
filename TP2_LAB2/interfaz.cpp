#include "interfaz.h"
#include <limits>
#include <iostream>

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

void InterfazUsuario :: CargarUsuario(Usuario & _user){
    InterfazPaciente IP;
    ValidacionesTipoDato validaTDato;
    ValidacionesGenerales validaGeneral;
    Fecha fecha;
    char user[50], pass[50];
    cout<<"USUARIO";
    cin.clear();
    cin.ignore();
    cout << endl << "> ";
    cin.getline(user,50);
    _user.ChangeUserName(user);
    cout<<endl;
    cout<<"CONTRASENIA";
    cout << endl << "> ";
    cin.getline(pass,50);
    _user.ChangeUserPass(pass);
    if (usr_lgd.GetPerfilUser() == Perfil_Administrador){
    //Si es ADMIN puede relacionar un profesional a un usuario
        _user.ChangePerfilUser((Perfil)validaGeneral.ValidarPerfilDeUsuario());
        cout<<"DESEA RELACIONAR UN PROFESIONAL AL USUARIO? S/N";
        if (validaGeneral.leer_SoN()){
            InterfazProfesional IntfzProf;
            //busco los pacientes del archivo
            Archivo profesionales(FILE_PACIENTES,sizeof(Paciente));
            Profesional profesional;
            cout<<"PACIENTES DISPONIBLES"<<endl<<endl;
            //listo los pacientes
            IntfzProf.ListarProfesionales();
            cout<<"INGRESE EL ID DEL PROFESIONAL QUE DESEA RELACIONAR: ";
            //ingreso el ID del paciente que quiero buscar
            profesional.SetId(validaTDato.cargar_Entero());
            //si existe en el archivo, entonces el ID esta OK
            int posProfesional = profesionales.buscarRegistro(profesional);
            //le relaciono el ID del paciente al usuario
            if (posProfesional >= 0 ) _user.ChangeIdPersona(profesional.GetId());
        }
    }else _user.ChangePerfilUser(Perfil_Paciente); //si no es un admin solo se pueden dar de alta pacientes
    cout<<"DESEA RELACIONAR UN PACIENTE AL USUARIO? S/N";
    if (validaGeneral.leer_SoN()){
        //busco los pacientes del archivo
        Archivo pacientes(FILE_PACIENTES,sizeof(Paciente));
        Paciente paciente;
        cout<<"PACIENTES DISPONIBLES"<<endl<<endl;
        //listo los pacientes
        IP.ListarPacientes();
        cout<<"INGRESE EL ID DEL PROFESIONAL QUE DESEA RELACIONAR: ";
        //ingreso el ID del paciente que quiero buscar
        paciente.SetId(validaTDato.cargar_Entero());
        //si existe en el archivo, entonces el ID esta OK
        int posPaciente = pacientes.buscarRegistro(paciente);
        //le relaciono el ID del paciente al usuario
        if (posPaciente >= 0 ) _user.ChangeIdPersona(paciente.GetId());
    }
    return;
};

void InterfazUsuario :: MostrarUsuario(Usuario _user){};
void InterfazUsuario :: ModificarUsuario(Usuario & _user){};
void InterfazUsuario :: AgregarUsuarioAArchivo(Usuario _user){};
void InterfazUsuario :: ModificarUsuarioEnArchivo(Usuario _user){};
void InterfazUsuario :: ListarUsuarios(){};

///INERFAZ PROFESIONAL

void InterfazProfesional :: CargarProfesional(Profesional &prof){
    ValidacionesTipoDato validaTDato;
    ValidacionesGenerales validaGeneral;
    Fecha fecha;
    char nombres[50], apellidos[50];
    cout<<"NOMBRES";
    cin.clear();
    cin.ignore();
    cout << endl << "> ";
    cin.getline(nombres,50);
    prof.SetNombres(nombres);
    cout<<endl;
    cout<<"APELLIDOS";
    cout << endl << "> ";
    cin.getline(apellidos,50);
    prof.SetApellidos(apellidos);
    cout<<endl;
    cout<<"GENERO";
    prof.SetGenero(validaGeneral.ValidarGenero());
    cout<<endl;
    cout<<"FECHA DE NACIMIENTO"<<endl;
    fecha.CargarFecha();
    prof.SetFechaNacimiento(fecha);
    cout<<endl;
    cout<<"DNI";
    prof.SetDNI(validaTDato.cargar_Entero());
    cout<<endl;
    cout<<"NRO DE MATRICULA";
    prof.SetMatricula(validaTDato.cargar_Entero());
    cout<<endl;
    cout<<"ID DE LA ESPECIALIDAD";
    prof.SetEspecialidad(validaTDato.cargar_Entero());
    return;
};

void InterfazProfesional :: MostrarProfesional(Profesional _prof){

    cls();
    cout << left;
    if (usr_lgd.GetPerfilUser() == Perfil_Administrador)//Solo el admin ve el ID
    cout << setw(12)  << "ID";
    cout << setw(12)  << "NOMBRES";
    cout << setw(12)  << "APELLIDOS";
    cout << setw(12)  << "GENERO";
    cout << setw(12)  << "DNI";
    cout << setw(12)  << "EDAD";
    cout << setw(12)  << "MATRICULA";
    cout << setw(12)  << "ESPECIALIDAD";
    cout << endl;
    cout << left;
    if (usr_lgd.GetPerfilUser() == Perfil_Administrador){
        cout << setw(12)  << _prof.GetId();
        cout << setw(12)  ;  _prof.GetFechaAlta();
        if ( !_prof.GetEstado() )//si esta dado de baja
            cout << setw(12)  ; _prof.GetFechaBaja();
    }
    cout << setw(12)  << _prof.GetNombres();
    cout << setw(12)  << _prof.GetApellidos();
    cout << setw(12)  << _prof.GetGenero();
    cout << setw(12)  << _prof.GetDNI();
    cout << setw(12)  << _prof.GetEdad();
    cout << setw(12)  << _prof.GetMatricula();
    cout<<  setw(12)  << "SIN IMPLEMENTAR";
    /*
    _prof.GetFechaNacimiento().GetFecha();

    */
};


void InterfazProfesional :: AgregarAArchivo(Profesional _prof){
    cls();
    ValidacionesGenerales valGral;
    MostrarProfesional(_prof);
    cout<<endl<<endl;
    cout<<"ESTA SEGURO QUE DESEA AGREGAR EL SIGUIENTE PROFESIONAL? S/N";
    if(valGral.leer_SoN())
    {
        Archivo profesionales(FILE_PROFESIONALES,sizeof(Profesional));
        if(profesionales.grabarRegistro(_prof,-1) == 1)
            cout<<"SE GRABO SATISFACTORIAMENTE EL PROFESIONAL CARGADO"<<endl;
        else
            cout<<"NO SE PUDO GRABAR SATISFACTORIAMENTE EL PROFESIONAL CARGADO"<<endl;
    }
    cout<<endl;
    system("PAUSE");
};

void InterfazProfesional :: ModificarProfesional(Profesional &_prof){
        ValidacionesGenerales valGral;
        ValidacionesTipoDato valTipoDato;
        int opcion=0;
        char nombres[50], apellidos[50];
        while(true){
            cls();
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
                    case 1: {
                             cout<<"NOMBRES: ";
                            cin.clear();
                            cin.ignore();
                            cin.getline(nombres,50);
                            _prof.SetNombres(nombres);
                            }
                            break;
                    case 2:{
                            cout<<"APELLIDOS: ";
                            cin.clear();
                            cin.ignore();
                            cin.getline(nombres,50);
                            _prof.SetApellidos(apellidos);
                            }

                            break;
                    case 3:{
                             cout<<"GENERO: ";
                             cin.clear();
                             cin.ignore();
                            _prof.SetGenero(valGral.ValidarGenero());
                            }
                            break;
                    case 4:
                            cout<<"DNI: ";
                            _prof.SetDNI(valTipoDato.cargar_Entero()); //se debe crear CARGAR DNI
                            break;
                    case 5:
                            _prof.SetMatricula(valTipoDato.cargar_Entero());
                            break;
                    case 6:
                            cout<<"ESPECIALIDAD: ";
                            _prof.SetEspecialidad(valTipoDato.cargar_Entero());
                            break;
                    case 7:
                            _prof.SetEstado(valTipoDato.cargar_Bool());
                            break;
                    case 0:
                            return;
                            break;
                }

        }
        return ;
}

void InterfazProfesional :: ModificarEnArchivo(Profesional _prof){
    ValidacionesGenerales valGral;
    Archivo profesionales(FILE_PROFESIONALES,sizeof(Profesional));
    int posProf = profesionales.buscarRegistro(_prof);
    if ( posProf != -1 && profesionales.leerRegistro(_prof, posProf) != -1){
        MostrarProfesional(_prof);
        cout<<endl<<endl;
        cout<<"ESTA SEGURO QUE DESEA MODIFICAR EL SIGUIENTE PROFESIONAL? S/N"<<endl;
        if(valGral.leer_SoN())
        {
            ModificarProfesional(_prof);
            if(profesionales.grabarRegistro(_prof,posProf) == 1)
                cout<<"SE ACTUALIZO SATISFACTORIAMENTE EL PROFESIONAL CARGADO"<<endl;
            else
                cout<<"NO SE PUDO ACTUALIZAR SATISFACTORIAMENTE EL PROFESIONAL CARGADO"<<endl;

            cout<<endl;
            system("PAUSE");
            return;
        }
    }else{
            cout<<"NO EXISTE UN PROFESIONAL CON EL ID: "<<_prof.GetId()<<endl;
            cout<<endl<<endl;
            system("PAUSE");

         }
};

void InterfazProfesional :: ListarProfesionales(){
    Archivo profesionales(FILE_PROFESIONALES,sizeof(Profesional));
    Profesional prof;
    cls();

    cout << left;
    if (usr_lgd.GetPerfilUser() == Perfil_Administrador)//Solo el admin ve el ID
    cout << setw(12)  << "ID";
    cout << setw(12)  << "NOMBRES";
    cout << setw(12)  << "APELLIDOS";
    cout << setw(12)  << "GENERO";
    cout << setw(12)  << "DNI";
    cout << setw(12)  << "EDAD";
    cout << setw(12)  << "MATRICULA";
    cout << setw(12)  << "ESPECIALIDAD";
    cout << endl;

    if(!profesionales.listarArchivo(prof)){
        cout<<"NO HAY REGISTROS PARA LISTAR"<<endl;
        cout<<endl<<endl;
        system("PAUSE");
        system("cls");
    }
    cout<<endl<<endl;
    system("PAUSE");
    return;
}

/// INTERFAZ PACIENTE

void InterfazPaciente :: CargarPaciente(Paciente & _paciente){}
void InterfazPaciente :: MostrarPaciente(Paciente _paciente){}
void InterfazPaciente :: ModificarPaciente(Paciente & _paciente){}
void InterfazPaciente :: AgregarPacienteAArchivo(Paciente _paciente){}
void InterfazPaciente :: ModificarPacienteEnArchivo(Paciente _paciente){}
void InterfazPaciente :: ListarPacientes(){}


