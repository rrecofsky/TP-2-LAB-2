#include "interfazentidades.h"
#include <limits>
#include <iostream>

#include "../modelos/archivo.h"
#include "../validaciones/validaciones.h"
#include "../util/rlutil.h"
#include "../interfaces/interfazcobertura.h"
#include "../interfaces/interfazfecha.h"

extern const char *FILE_USUARIOS;
extern const char *FILE_PACIENTES;
extern const char *FILE_PROFESIONALES;
extern const char *FILE_COBERTURAS;
extern Usuario usr_lgd;
using namespace rlutil;

using namespace std;

///INTERFAZ PERSONA

 int InterfazPersona :: AsociarProfesional(Profesional & _profesional){

    Archivo profesionales(FILE_PROFESIONALES,sizeof(Profesional));
    int posEntidad = profesionales.buscarRegistro(_profesional);
    if ( posEntidad >= 0 && profesionales.leerRegistro(_profesional, posEntidad) != -1){
        cout<<_profesional.GetNombres()<<" - "<<_profesional.GetApellidos()<<endl;
        system("PAUSE");
        return posEntidad;
    }

    return -1;

 }

  int InterfazPersona :: AsociarPaciente(Paciente & _paciente){
            Archivo pacientes(FILE_PACIENTES,sizeof(Paciente));
            int posEntidad = pacientes.buscarRegistro(_paciente);
            if ( posEntidad >= 0 && pacientes.leerRegistro(_paciente, posEntidad) != -1)
                return posEntidad;
            return -1;

 }

void InterfazPersona :: MostrarCabeceraPersona(){
    cout << left;
    cout << setw(4)   << "ID";
    cout << setw(12)  << "NOMBRES";
    cout << setw(12)  << "APELLIDOS";
    cout << setw(12)  << "GENERO";
    cout << setw(12)  << "DNI";
    cout << setw(12)  << "EDAD";
    cout << setw(16)  << "FECHA NAC";
    return;
 }

 void ObtenerPersona(Persona &){
     /*
    Profesional prof;
    Archivo profesionales(FILE_PROFESIONALES,sizeof(Profesional));

    int posEntidad = profesionales.buscarRegistro(prof);
    if ( posEntidad >= 0 && profesionales.leerRegistro(_persona, posEntidad) != -1)
        return posEntidad;
    else{
            Archivo pacientes(FILE_PACIENTES,sizeof(Paciente));
            Paciente pac;
            posEntidad = pacientes.buscarRegistro(pac);
            if ( posEntidad >= 0 && pacientes.leerRegistro(_persona, posEntidad) != -1)
                return posEntidad;
        }
    return posEntidad;
    */
 }

/// INTERFAZ USUARIO

bool InterfazUsuario :: AsociarUsuario(Usuario & _user){

    Usuario usr;
    Archivo usuarios(FILE_USUARIOS,sizeof(Usuario));
    int posUsuario = usuarios.buscarRegistro(usr);
    if ( posUsuario >= 0 && usuarios.leerRegistro(_user, posUsuario) != -1)
        return true;

    return false;
}

bool InterfazUsuario :: CargarUsuario(Usuario & _user){
    ValidacionesTipoDato validaTDato;
    Archivo pacientes(FILE_PACIENTES,sizeof(Paciente));
    Archivo profesionales(FILE_PROFESIONALES,sizeof(Profesional));
    if ( usr_lgd.GetPerfilUser() == Perfil_Profesional && pacientes.getCantidadRegistros() == 0 ){
         validaTDato.generar_Mensaje(0,"NO ES POSIBLE CARGAR UN USUARIO SI NO EXISTE AL MENOS UN PACIENTE PARA ASOCIARLE");
         system("PAUSE");
         return false;
    }
    if ( usr_lgd.GetPerfilUser() == Perfil_Administrador && profesionales.getCantidadRegistros() == 0){
         validaTDato.generar_Mensaje(0,"NO ES POSIBLE CARGAR UN USUARIO SI NO EXISTE AL MENOS UN PROFESIONAL PARA ASOCIARLE");
         system("PAUSE");
         return false;
    }
    InterfazPaciente IP;
    char user[50], pass[50];
    ValidacionesGenerales validaGeneral;
    Fecha fecha;

    do{
        cin.clear();
         cin.ignore();
        cout<<"USUARIO";
        cout << endl << "> ";
        cin.getline(user,50);
        _user.ChangeUserName(user);
        if (!validaGeneral.EsCadenaAlfanumerica(_user.GetUserNamee())){
                validaTDato.generar_Mensaje(0,"SOLO SE PERMITEN VALORES ALFANUMERICOS");
        }
        else
            if (CompararForeignKey(&_user)){
                validaTDato.generar_Mensaje(0,"YA EXISTE UN USUARIO CON ESE NOMBRE, DESEA CARGAR OTRO? S/N");
                if (! validaGeneral.leer_SoN()) return false;
            }else
                break;
    }while(true);

    cout<<endl;
    cout<<"CONTRASENIA";
    cout << endl << "> ";
    cin.getline(pass,50);
     _user.ChangeUserPass(pass);
    //Solo si es ADMIN puede relacionar un profesional a un usuario

    if (usr_lgd.GetPerfilUser() == Perfil_Administrador){
        cout<<"DESEA ASIGNARLE UN USUARIO PROFESIONAL? S/N"<<endl;//solo admin
        if (validaGeneral.leer_SoN()){
            cls();
            do{
                    _user.ChangePerfilUser(Perfil_Profesional);
                    InterfazProfesional IntfzProf;
                    //busco los pacientes del archivo
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
                    if (posProfesional >= 0 ){
                            _user.ChangeIdPersona(profesional.GetId());
                            validaTDato.generar_Mensaje(2,"PROFESIONAL ASIGNADO EXITOSAMENTE!");
                            system("PAUSE");
                            return true;
                    }else{
                            validaTDato.generar_Mensaje(0,"EL ID INGRESADO DEL PROFESIONAL ES INCORRECTO");
                            system("PAUSE");
                         }
            }while(true);
        }else return false;
    }
    do{
            cout<<"ASIGNE UN PACIENTE AL USUARIO"<<endl;
            _user.ChangePerfilUser(Perfil_Paciente);
            //busco los pacientes del archivo
            Paciente paciente;
            cout<<"PACIENTES DISPONIBLES"<<endl<<endl;
            //listo los pacientes
            IP.ListarPacientes();
            cout<<"DESEA ASIGNARLE UNO DE LOS PACIENTES DISPONIBLES? S/N"<<endl;
            if (! validaGeneral.leer_SoN()) return false;
            cout<<endl;
            cout<<"INGRESE EL ID DEL PACIENTE QUE DESEA RELACIONAR: ";
            //ingreso el ID del paciente que quiero buscar
            paciente.SetId(validaTDato.cargar_Entero());
            //si existe en el archivo, entonces el ID esta OK
            int posPaciente = pacientes.buscarRegistro(paciente);
            //le relaciono el ID del paciente al usuario
            if (posPaciente >= 0 ){
                    _user.ChangeIdPersona(paciente.GetId());
                    validaTDato.generar_Mensaje(2,"PACIENTE ASIGNADO EXITOSAMENTE!");
                    system("PAUSE");
                    return true;
            }else{
                    validaTDato.generar_Mensaje(0,"EL ID INGRESADO DEL PACIENTE ES INCORRECTO");
                    system("PAUSE");
                 }
    }while(true);
    return false;
};

void InterfazUsuario :: MostrarUsuario(Usuario _user){
    InterfazPersona interfazPersona;
    cout << left;
    cout << setw(4)  << _user.GetId();
    if (usr_lgd.GetPerfilUser() == Perfil_Administrador){
        cout << setw(12)  << _user.GetUserPass();
    }
    cout << setw(12)  << _user.GetUserNamee();
    if (_user.GetPerfilUser()  == Perfil_Profesional )
        cout << setw(12)  << "PROFESIONAL";
    else
        cout << setw(12)  << "PACIENTE";
    if (_user.GetPerfilUser() == Perfil_Profesional){
        Profesional profesional;
        profesional.SetId(_user.GetIdPersona());
        interfazPersona.AsociarProfesional(profesional);
        cout << setw(6)  << profesional.GetNombres();
        cout << setw(6)  << _user.GetIdPersona(); //profesional.GetApellidos();
    }
    else{
        Paciente paciente;
        paciente.SetId(_user.GetIdPersona());
        interfazPersona.AsociarPaciente(paciente);
        cout << setw(6)  << paciente.GetNombres();
        cout << setw(6)  << paciente.GetApellidos();
        }

    cout<<endl;
   //   cout<<"ID PERSONA DEL USER: "<<_user.GetIdPersona();
   // /system("PAUSE");
};

void InterfazUsuario :: AgregarUsuarioAArchivo(Usuario _user){
    cls();
    ValidacionesGenerales valGral;
    ValidacionesTipoDato validaTDato;
    cout << left;
    if (usr_lgd.GetPerfilUser() == Perfil_Administrador)
        cout << setw(12)  << "CONTRASENIA";
    cout << setw(12)  << "USUARIO";
    cout << setw(12)  << "PERFIL";
    cout << setw(12)  << "ENTIDAD";
    cout << endl;
    MostrarUsuario(_user);
    cout<<endl<<endl;
    cout<<"ESTA SEGURO QUE DESEA AGREGAR EL SIGUIENTE USUARIO? S/N";
    if(valGral.leer_SoN())
    {
        Archivo usuarios(FILE_USUARIOS,sizeof(Usuario));
        if(usuarios.grabarRegistro(_user,-1) == 1)
            validaTDato.generar_Mensaje(2,"SE GRABO SATISFACTORIAMENTE EL PROFESIONAL CARGADO");
        else
            validaTDato.generar_Mensaje(0,"NO SE PUDO GRABAR SATISFACTORIAMENTE EL PROFESIONAL CARGADO");
    }
    cout<<endl;
    system("PAUSE");

};

void InterfazUsuario :: ListarUsuarios(){

    Usuario user;
    ValidacionesTipoDato validaTDato;
    Archivo usuarios(FILE_USUARIOS,sizeof(Usuario),true);
    if( usuarios.getCantidadRegistros() != 0){
        cout << left;
        cout << setw(4)  << "ID";
        if (usr_lgd.GetPerfilUser() == Perfil_Administrador)
            cout << setw(12)  << "CONTRASENIA";
        cout << setw(12)  << "USUARIO";
        cout << setw(12)  << "PERFIL";
        cout << setw(12)  << "ENTIDAD";
        cout << endl;

        while(fread(&user,sizeof(Usuario),1,usuarios.GetPF())){
             MostrarUsuario(user);
        };
    }else validaTDato.generar_Mensaje(2,"NO EXISTEN USUARIOS CARGADOS EN EL SISTEMA");
    system("PAUSE");
    return;
};

void InterfazUsuario :: ModificarUsuario(Usuario & _user){
    //REVISAR.
    ValidacionesGenerales validaGeneral;
    ValidacionesTipoDato validaTDato;
    char str[50];
    cout<<"DESEA MODIFICAR SU NOMBRE DE USUARIO?: "<<_user.GetUserNamee()<<" S/N"<<endl;
    if (validaGeneral.leer_SoN()){
        do{
            cin.clear();
             cin.ignore();
            cout<<"USUARIO";
            cout << endl << "> ";
            cin.getline(str,50);
            _user.ChangeUserName(str);
            if (!validaGeneral.EsCadenaAlfanumerica(_user.GetUserNamee())){
                    validaTDato.generar_Mensaje(0,"SOLO SE PERMITEN VALORES ALFANUMERICOS");
            }
            else
                if (CompararForeignKey(&_user)){
                    validaTDato.generar_Mensaje(0,"YA EXISTE UN USUARIO CON ESE NOMBRE, DESEA CARGAR OTRO? S/N");
                    if (! validaGeneral.leer_SoN()) return;
                }else
                    break;
        }while(true);
    }
    cout<<"DESEA MODIFICAR LA CONTRASENIA? S/N"<<endl;
    if ( validaGeneral.leer_SoN()){
            cin.clear();
             cin.ignore();
            cout<<"CONTRASENIA";
            cout << endl << "> ";
            cin.getline(str,50);
            _user.ChangeUserPass(str);
    }else return;
}

void InterfazUsuario :: ModificarUsuarioEnArchivo(Usuario _user){
    ValidacionesGenerales valGral;
    ValidacionesTipoDato validaTDato;
    Archivo usuarios(FILE_USUARIOS,sizeof(Usuario));
    int posUser = usuarios.buscarRegistro(_user);
    if ( posUser != -1 && usuarios.leerRegistro(_user, posUser) != -1){
        MostrarUsuario(_user);
        cout<<endl<<endl;
        cout<<"ESTA SEGURO QUE DESEA MODIFICAR EL SIGUIENTE USUARIO? S/N"<<endl;
        if(!valGral.leer_SoN())
        {
            ModificarUsuario(_user);
            if(usuarios.grabarRegistro(_user,posUser) == 1)
                validaTDato.generar_Mensaje(2,"SE ACTUALIZO SATISFACTORIAMENTE EL PROFESIONAL CARGADO");
            else
                validaTDato.generar_Mensaje(0,"NO SE PUDO ACTUALIZAR SATISFACTORIAMENTE EL PROFESIONAL CARGADO");
            cout<<endl;
            system("PAUSE");
            return;
        }
    }else{
            validaTDato.generar_Mensaje(0,"NO EXISTE UN PROFESIONAL CON EL ID: ");
            cout<<_user.GetId();
            cout<<endl<<endl;
            system("PAUSE");
         }
}


///INERFAZ PROFESIONAL

bool InterfazProfesional :: CargarProfesional(Profesional &prof){
    InterfazFecha IF;
    ValidacionesTipoDato validaTDato;
    ValidacionesGenerales validaGeneral;
    char nombres[50], apellidos[50];
    do{
        cout<<"NOMBRES";
        cin.clear();
        cin.ignore();
        cout << endl << "> ";
        cin.getline(nombres,50);
        if (!validaGeneral.EsCadenaAlfabetica(nombres)){
            validaTDato.generar_Mensaje(0,"SOLO SE PERMITEN VALORES DEL ALFABETO");
            cout<<endl;
          //  system("PAUSE");
        }else break;
    }while(true);
    prof.SetNombres(nombres);
    cout<<endl;
    do{
        cout<<"APELLIDOS";
        cout << endl << "> ";
        cin.getline(apellidos,50);
        if (!validaGeneral.EsCadenaAlfabetica(apellidos)){
            validaTDato.generar_Mensaje(0,"SOLO SE PERMITEN VALORES DEL ALFABETO");
            cout<<endl;
        //    system("PAUSE");
        }else break;
    }while(true);
    prof.SetApellidos(apellidos);
    cout<<endl;
    cout<<"GENERO";
    prof.SetGenero(validaGeneral.ValidarGenero());
    cout<<endl;
    cout<<"FECHA DE NACIMIENTO"<<endl;
    prof.SetFechaNacimiento(IF.CargarFecha());
    cout<<endl;
    cout<<"DNI";
    prof.SetDNI(validaGeneral.ValidarDNI());
    cout<<endl;
    cout<<"NRO DE MATRICULA";
    prof.SetMatricula(validaGeneral.ValidarMatricula());
    cout<<endl;
    cout<<"INGRESE EL ID DE UNA ESPECIALIDAD DISPONIBLES";
     prof.SetMatricula(validaTDato.cargar_Entero());
     /**************************** DESARROLLAR ESPECIALIDAD *******************************/
     /*
    do{
            Especialidad esp;
            cout<<"INGRESE EL ID DE UNA DE LAS ESPECIALIDADES DISPONIBLES";
            prof.SetMatricula(validaTDato.cargar_Entero());
            //seteo la especialidad
            esp.SetId(validaTDato.cargar_Entero());
            cout<<"ESPECIALIDADES DISPONIBLES"<<endl<<endl;
            //listo los pacientes
            IP.ListarPacientes();
            cout<<"DESEA ASIGNARLE UNO DE LOS PACIENTES DISPONIBLES? S/N"<<endl;
            if (! validaGeneral.leer_SoN()) return false;
            cout<<endl;
            cout<<"INGRESE EL ID DEL PACIENTE QUE DESEA RELACIONAR: ";
            //ingreso el ID del paciente que quiero buscar
            paciente.SetId(validaTDato.cargar_Entero());
            //si existe en el archivo, entonces el ID esta OK
            int posPaciente = pacientes.buscarRegistro(paciente);
            //le relaciono el ID del paciente al usuario
            if (posPaciente >= 0 ){
                    prof.SetEspecialidad(validaTDato.cargar_Entero());
                    validaTDato.generar_Mensaje(2,"PACIENTE ASIGNADO EXITOSAMENTE!");
                    system("PAUSE");
                    return true;
            }else{
                    validaTDato.generar_Mensaje(0,"EL ID INGRESADO DEL PACIENTE ES INCORRECTO");
                    system("PAUSE");
                 }
    }while(true);
    */
    return true;
};

void InterfazProfesional :: MostrarProfesional(Profesional _prof){

    InterfazFecha IF;
    cout << left;
    cout << setw(4)   << _prof.GetId();
    cout << setw(12)  << _prof.GetNombres();
    cout << setw(12)  << _prof.GetApellidos();
    cout << setw(12)  << _prof.GetGenero();
    cout << setw(12)  << _prof.GetDNI();
    cout << setw(12)  << _prof.GetEdad();
    cout << setw(16)  << IF.GetfechaFormateada(_prof.GetFechaNacimiento());
    cout << setw(12)  << _prof.GetMatricula();
    cout<<  setw(12)  << "SIN IMPLEMENTAR";
    cout<< endl;
};


void InterfazProfesional :: AgregarAArchivo(Profesional _prof){
    cls();
    ValidacionesGenerales valGral;
    ValidacionesTipoDato validaTDato;
    MostrarProfesional(_prof);
    cout<<endl<<endl;
    cout<<"ESTA SEGURO QUE DESEA AGREGAR EL SIGUIENTE PROFESIONAL? S/N";
    if(valGral.leer_SoN())
    {
        Archivo profesionales(FILE_PROFESIONALES,sizeof(Profesional));
        if(profesionales.grabarRegistro(_prof,-1) == 1)
            validaTDato.generar_Mensaje(2,"SE GRABO SATISFACTORIAMENTE EL PROFESIONAL CARGADO");
        else
            validaTDato.generar_Mensaje(0,"NO SE PUDO GRABAR SATISFACTORIAMENTE EL PROFESIONAL CARGADO");
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
            cout<<"6) ESPECIALIDAD"<<endl;
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
                            _prof.SetDNI(valGral.ValidarDNI()); //se debe crear CARGAR DNI
                            break;
                    case 5:
                            cout<<"NRO DE MATRICULA: ";
                            _prof.SetMatricula(valGral.ValidarMatricula());
                            break;
                    case 6:
                            cout<<"ESPECIALIDAD: ";
                            _prof.SetEspecialidad(valTipoDato.cargar_Entero());
                            break;
                    case 0:
                            return;
                            break;
                }

        }
        return ;
}

void InterfazProfesional :: ModificarEnArchivo(Profesional &_prof){
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
}

void InterfazProfesional :: ListarProfesionales(){
    Archivo profesionales(FILE_PROFESIONALES,sizeof(Profesional),true);
    Profesional prof;
    if( profesionales.getCantidadRegistros() != 0){
        InterfazPersona IP;
        IP.MostrarCabeceraPersona();
        cout << left;
        cout << setw(12)  << "MATRICULA";
        cout << setw(12)  << "ESPECIALIDAD";
        cout << endl;
        while(fread(&prof,sizeof(Profesional),1,profesionales.GetPF())){
             MostrarProfesional(prof);
        };

    }else cout<<"NO EXISTEN USUARIOS CARGADOS EN EL SISTEMA";
    cout<<endl<<endl;
    system("PAUSE");
    return;
}

/// INTERFAZ PACIENTE

bool InterfazPaciente :: CargarPaciente(Paciente & _paciente){
    InterfazFecha IF;
    ValidacionesTipoDato validaTDato;
    ValidacionesGenerales validaGeneral;
    char nombres[50], apellidos[50];
    cout<<"NOMBRES";
    cin.clear();
    cin.ignore();
    cout << endl << "> ";
    cin.getline(nombres,50);
    _paciente.SetNombres(nombres);
    cout<<endl;
    cout<<"APELLIDOS";
    cout << endl << "> ";
    cin.getline(apellidos,50);
    _paciente.SetApellidos(apellidos);
    cout<<endl;
    cout<<"GENERO";
    _paciente.SetGenero(validaGeneral.ValidarGenero());
    cout<<endl;
    cout<<"FECHA DE NACIMIENTO"<<endl;
    _paciente.SetFechaNacimiento(IF.CargarFecha());
    cout<<endl;
    cout<<"DNI";
    _paciente.SetDNI(validaTDato.cargar_Entero());
    cout<<endl;
    cout<<"AFILIADO";
    _paciente.SetNroAfiliado(validaTDato.cargar_Entero());
    cout<<endl;
    cout<<"DESEA RELACIONARLE UNA COBERTURA AL PACIENTE? S/N";
    if (validaGeneral.leer_SoN()){
         //busco los pacientes del archivo
         Archivo coberturas(FILE_COBERTURAS,sizeof(Cobertura));
         Cobertura cobertura;
         cout<<"COBERTURAS DISPONIBLES"<<endl<<endl;
         //listo los pacientes
         InterfazCobertura IC;
         IC.ListarCoberturas();
         cout<<"INGRESE EL ID DE LA COBERTURA QUE DESEA ASOCIARLE: ";
         //ingreso el ID del paciente que quiero buscar
         cobertura.SetId(validaTDato.cargar_Entero());
         //si existe en el archivo, entonces el ID esta OK
         int posCobertura = coberturas.buscarRegistro(cobertura);
         //le relaciono el ID del paciente al usuario
         if (posCobertura >= 0 ) _paciente.SetIdCObertura(cobertura.GetId());
    }
    return true;

}
void InterfazPaciente :: MostrarPaciente(Paciente _paciente){

    InterfazFecha IF;
    cout << left;
    cout << setw(4)  << _paciente.GetId();
    cout << setw(12)  << _paciente.GetNombres();
    cout << setw(12)  << _paciente.GetApellidos();
    cout << setw(12)  << _paciente.GetGenero();
    cout << setw(12)  << _paciente.GetDNI();
    cout << setw(12)  << _paciente.GetEdad();
    cout << setw(16)  << IF.GetfechaFormateada(_paciente.GetFechaNacimiento());
    cout << setw(16)  << _paciente.GetNroAfiliado();
    cout<<  setw(12)  << "SIN IMPLEMENTAR";
    cout<<  endl;
}

void InterfazPaciente :: AgregarPacienteAArchivo(Paciente _paciente){
cls();
    ValidacionesGenerales valGral;
    InterfazPersona IP;
    IP.MostrarCabeceraPersona();
    cout << left;
    cout << setw(16)  << "NRO AFILIADO";
    cout << setw(12)  << "COBERTURA";
    cout << endl;
    MostrarPaciente(_paciente);
    cout<<endl<<endl;
    cout<<"ESTA SEGURO QUE DESEA AGREGAR EL SIGUIENTE PACIENTE? S/N";
    if(valGral.leer_SoN())
    {
        Archivo pacientes(FILE_PACIENTES,sizeof(Paciente));
        if(pacientes.grabarRegistro(_paciente,-1) == 1)
            cout<<"SE GRABO SATISFACTORIAMENTE EL PACIENTE"<<endl;
        else
            cout<<"NO SE PUDO GRABAR SATISFACTORIAMENTE EL PACIENTE"<<endl;
    }
    cout<<endl;
    system("PAUSE");
}

void InterfazPaciente :: ListarPacientes(){
    Archivo pacientes(FILE_PACIENTES,sizeof(Paciente),true);
    Paciente pac;
    if( pacientes.getCantidadRegistros() != 0){
        InterfazPersona IP;
        IP.MostrarCabeceraPersona();
        cout << left;
        cout << setw(16)  << "NRO AFILIADO";
        cout << setw(12)  << "COBERTURA";
        cout << endl;
        while(fread(&pac,sizeof(Paciente),1,pacientes.GetPF())){
             MostrarPaciente(pac);
        };

    }else cout<<"NO EXISTEN PACIENTES CARGADOS EN EL SISTEMA";
    cout<<endl<<endl;
    system("PAUSE");
    return;
}

void InterfazPaciente :: ModificarPaciente(Paciente & _paciente){
        ValidacionesGenerales valGral;
        ValidacionesTipoDato valTipoDato;
        InterfazFecha IF;
        int opcion=0;
        char nombres[50], apellidos[50];
        while(true){
            cls();
            cout<<"QUE DESEA MODIFICAR?"<<endl;
            cout<<"1) NOMBRES"<<endl;
            cout<<"2) APELLIDOS"<<endl;
            cout<<"3) GENERO"<<endl;
            cout<<"4) DNI"<<endl;
            cout<<"5) FECHA DE NACIMIENTO"<<endl;
            cout<<"6) NRO AFILIADO"<<endl;
            cout<<"7) COBERTURA"<<endl;
            cout<<"8) ESTADO (Solo Admin) "<<endl;
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
                            _paciente.SetNombres(nombres);
                            }
                            break;
                    case 2:{
                            cout<<"APELLIDOS: ";
                            cin.clear();
                            cin.ignore();
                            cin.getline(nombres,50);
                            _paciente.SetApellidos(apellidos);
                            }

                            break;
                    case 3:{
                             cout<<"GENERO: ";
                             cin.clear();
                             cin.ignore();
                            _paciente.SetGenero(valGral.ValidarGenero());
                            }
                            break;
                    case 4:
                            cout<<"DNI: ";
                            _paciente.SetDNI(valTipoDato.cargar_Entero()); //se debe crear CARGAR DNI
                            break;
                    case 5:
                             cout<<"FECHA DE NACIMIENTO: ";
                             _paciente.SetFechaNacimiento(IF.CargarFecha());
                            break;
                    case 6:
                            cout<<"NRO DE AFILIADO: ";
                            _paciente.SetNroAfiliado(valTipoDato.cargar_Entero()); //Se debe crear para validar NO SE PUEDEN REPETIR!
                            break;
                    case 7:
                            cout<<"COBERTURA: ";
                            _paciente.SetEstado(valTipoDato.cargar_Entero());
                            break;
                    case 8: //Desarrollar estado para que se les cambie el estado a las relaciones que correspondan
                            //como el plan farmacologico
                            cout<<"ESTADO: ";
                            _paciente.SetEstado(valTipoDato.cargar_Bool());
                            break;
                    case 0:
                            return;
                            break;
                }

        }
        return ;

}
void InterfazPaciente :: ModificarPacienteEnArchivo(Paciente _paciente){
    ValidacionesGenerales valGral;
    Archivo pacientes(FILE_PROFESIONALES,sizeof(Profesional));
    int posPac = pacientes.buscarRegistro(_paciente);
    if ( posPac != -1 && pacientes.leerRegistro(_paciente, posPac) != -1){
        MostrarPaciente(_paciente);
        cout<<endl<<endl;
        cout<<"ESTA SEGURO QUE DESEA MODIFICAR EL SIGUIENTE PROFESIONAL? S/N"<<endl;
        if(valGral.leer_SoN())
        {
            cls();
            ModificarPaciente(_paciente);
            if(pacientes.grabarRegistro(_paciente,posPac) == 1)
                cout<<"SE ACTUALIZO SATISFACTORIAMENTE EL PACIENTE"<<endl;
            else
                cout<<"NO SE PUDO ACTUALIZAR SATISFACTORIAMENTE EL PACIENTE"<<endl;

            cout<<endl;
            system("PAUSE");
            return;
        }
    }else{
            cout<<"NO EXISTE UN PROFESIONAL CON EL ID: "<<_paciente.GetId()<<endl;
            cout<<endl<<endl;
            system("PAUSE");
         }
}



