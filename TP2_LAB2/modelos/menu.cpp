#include <iostream>
#include <cstring>
#include "../util/ui.h"
#include "../util/rlutil.h"
#include "../modelos/especialidad.h"
#include "../modelos/archivo.h"
#include "../modelos/fecha.h"
#include "../modelos/paciente.h"
#include "../modelos/profesional.h"
#include "../modelos/medicacion.h"
#include "../modelos/usuario.h"
#include "../modelos/menu.h"
#include "../modelos/planfarmacologico.h"
#include "../validaciones/validaciones.h"
#include "../interfaces/interfazentidades.h"
#include "../interfaces/interfazplanfarmacologico.h"

using namespace std;
using namespace rlutil;

extern const char *FILE_PACIENTES;
extern const char *FILE_PROFESIONALES;
extern const char *FILE_USUARIOS;

const char *user_adm = "admin";
const char *pass_adm = "admin";
Usuario     usr_lgd(user_adm,pass_adm,Perfil_Administrador);

/// ************************************************************************************* ///
/// ********************************** METODOS LOGO  ************************************ ///
/// ************************************************************************************* ///

void Logo :: logo(){
cout << left;

cout << left<<"      db           `7MM                      db              "<<endl;
cout << left<<"     ;MM:            MM                                       "<<endl;
cout << left<<"    ,V^MM.      ,M**bMM  `7MMpMMMb.pMMMb.  `7MM  `7MMpMMMb.    "<<endl;
cout << left<<"   ,M  `MM    ,AP    MM    MM    MM    MM    MM    MM    MM    "<<endl;
cout << left<<"   AbmmmqMA   8MI    MM    MM    MM    MM    MM    MM    MM    "<<endl;
cout << left<<"  A'     VML  `Mb    MM    MM    MM    MM    MM    MM    MM    "<<endl;
cout << left<<".AMA.   .AMMA. `Wbmd*MML..JMML  JMML  JMML..JMML..JMML  JMML.."<<endl;
cout << left;
cout<<endl<<endl;
cout << left<<endl;
cout << left<<" .M***bgd          `7MM                   `7MM                            "<<endl;
cout << left<<",MI    *Y            MM                     MM         .M      ,pP..Yq.   "<<endl;
cout << left<<"`MMb.      ,6*Yb.    MM  `7MM  `7MM    ,M*bMM        `7MM     1w      Yq   "<<endl;
cout << left<<"  `YMMNq. 8)   MM    MM    MM    MM  ,AP    MM         MM     6W'    `Wb  "<<endl;
cout << left<<".     `MM  ,pm9MM    MM    MM    MM  8MI    MM         MM     8M      M8  "<<endl;
cout << left<<"Mb     dM 8M   MM    MM    MM    MM  `Mb    MM         MM  ,, YA.    ,A9  "<<endl;
cout << left<<" *Ybmmd*  `Moo9^Yo..JMML.  `Mbod*YML. `Wbmd*MML.     .JMML.db  `Ybmmd9'   "<<endl;
cout << left;
cout<<endl<<endl<<endl<<endl;
}

/// ************************************************************************************* ///
/// ********************************** METODOS LOGIN ************************************ ///
/// ************************************************************************************* ///

void MenuLogin :: Login(){

    // ------------> TEMPORAL
 //   MenuAdministrador();
 //   return;
    //  ------------> TEMPORAL
    Logo logo;
    logo.logo();
   // Logo();

    Archivo archUsuarios(FILE_USUARIOS,sizeof(Usuario));
    Perfil  tipoDeUsuario=Perfil_Paciente;
    ValidacionesGenerales validacionLogin;
    char user[50], pass[50];
    bool  salir=false;
    Usuario usrAxuLogin; //Se usa para copiar en el objeto, el registro del archivo.

    cout << "                   INGRESE EL PERFIL DEL USUARIO:"<<endl<<endl;
    cout << "                        0 - Administrador"<<endl;
    cout << "                        1 - Profesional"<<endl;
    cout << "                        2 - Paciente"<<endl;


        tipoDeUsuario = validacionLogin.ValidarPerfilDeUsuario();

    cls();
    cin.clear();
    cin.ignore();
    cout << "INGRESE UN USUARIO: ";
    cout << endl << "> ";
    cin.getline(user,50);
    cout << "INGRESE UNA CONTRASENIA: ";
    cout << endl << "> ";
    cin.getline(pass,50);

    do{
        if (tipoDeUsuario == usr_lgd.GetPerfilUser() &&
             strcmp(user,usr_lgd.GetUserNamee()) == 0 &&
             strcmp(pass,usr_lgd.GetUserPass()) == 0  )
            { //si es ADMIN
                MenuAdministrador menuadmin;
                menuadmin.MenuAdmin();
               return;
            }
            else{
                    //cambio de forma temporal el user del reg de usuario
                    usrAxuLogin.ChangeUserName(user);
                    //Cambio el paciente encontrado en el registro
                    int posUserLdg = archUsuarios.buscarRegistro(usrAxuLogin);
                    archUsuarios.leerRegistro(usrAxuLogin, posUserLdg);
                    if (  strcmp(usrAxuLogin.GetUserNamee(),user) == 0 && strcmp(usrAxuLogin.GetUserPass(),pass) == 0 ){
                       if ( usrAxuLogin.GetPerfilUser() == Perfil_Profesional && tipoDeUsuario == Perfil_Profesional){
                                usr_lgd = usrAxuLogin;
                                MenuProfesional   menuprof;
                                menuprof.MenuProf();
                                return;
                        }
                        else
                            if ( usrAxuLogin.GetPerfilUser() == Perfil_Paciente && tipoDeUsuario == Perfil_Paciente) {
                                usr_lgd = usrAxuLogin;
                                MenuPaciente menupac;
                                menupac.MenuPac();
                                return;
                            }
                    }
                }
        cout<<"USUARIO O CONTRASENIA INCORRECTOS. DESEA SALIR? S - N"<<endl;
        salir = validacionLogin.leer_SoN();
        cls();
        if (!salir){
            cout << "INGRESE UN USUARIO: ";
            cin.clear(); // unset failbit
            cin.ignore(); // skip bad input
            cout << endl << "> ";
            cin.getline(user,50);
            cout << "INGRESE UNA CONTRASENIA: ";
            cout << endl << "> ";
            cin.getline(pass,50);
        }else return;
    }
    while(true);

    return;
}

/// ************************************************************************************* ///
/// ********************************** METODOS ADMIN ************************************ ///
/// ************************************************************************************* ///

void MenuAdministrador :: MenuAdmin()
{
    initUI();
    title("", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    ValidacionesTipoDato valTDato;
    while(true)
    {
        cls();
        title("MENU PRINCIPAL", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);
        cout<<"1) PROFESIONALES       "<<endl;
        cout<<"2) USUARIOS            "<<endl;
        cout<<"3) PRESENTACIONES      "<<endl;
        cout<<"4) FARMACOS            "<<endl;
        cout<<"5) COBERTURAS          "<<endl;
        cout<<"6) ESPECIALIDADES      "<<endl;
        cout<<"7) ALCANCE DEL PROYECTO "<<endl;
        cout<<"----------------------  "<<endl;
        cout<<"0) SALIR DEL PROGRAMA   "<<endl;

        int opcion;
        opcion = valTDato.cargar_Entero();

        switch(opcion){
            case 1:
                    MenuGeneralAdministrador("PROFESIONAL");
                    break;
            case 2:
                    MenuGeneralAdministrador("USUARIO");
                    break;
            case 3:
                    MenuGeneralAdministrador("PRESENTACION");
                    break;
            case 4:
                    MenuGeneralAdministrador("FARMACO");
                    break;
            case 5:
                    MenuGeneralAdministrador("COBERTURA");
                    break;
            case 6:
                    MenuGeneralAdministrador("ESPECIALIDAD");
                    break;
            case 7: MenuAlcance();
                    break;
            case 0:
                return;
            break;
        }
        cin.ignore();
    }
    return ;
}


void MenuAdministrador :: MenuGeneralAdministrador(const char * entidad)
{
    ValidacionesTipoDato valTDato;
    while(true)
    {
        cls();
        title(entidad, APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);
        cout<<"1) ALTA               "<<endl;
        cout<<"2) MODIFICAR          "<<endl;
        cout<<"3) LISTAR             "<<endl;
        cout<<"----------------------"<<endl;
        cout<<"0) REGRESAR           "<<endl;

        int opcion;
        opcion = valTDato.cargar_Entero();

        switch(opcion)
        {
            case 1: if (strcmp("PROFESIONAL",entidad) == 0)
                        AltaProfesional();
                    else
                        if(strcmp("USUARIO",entidad) == 0)
                            AltaUsuario();
                        else
                            if(strcmp("PRESENTACION",entidad) == 0)
                                AltaPresentacion();
                            else
                                if(strcmp("FARMACO",entidad) == 0)
                                    AltaFarmaco();
                                else
                                    if(strcmp("COBERTURA",entidad) == 0)
                                        AltaCobertura();
                                    else
                                        if(strcmp("ESPECIALIDAD",entidad) == 0)
                                            AltaEspecialidad();


                    break;
            case 2:
                    if (strcmp("PROFESIONAL",entidad) == 0)
                        ModificarProfesional();
                    else
                        if(strcmp("USUARIO",entidad) == 0)
                            ModificarUsuario();
                        else
                            if(strcmp("PRESENTACION",entidad) == 0)
                                ModificarPresentacion();
                            else
                                if(strcmp("FARMACO",entidad) == 0)
                                    ModificarFarmaco();
                                else
                                    if(strcmp("COBERTURA",entidad) == 0)
                                        ModificarCobertura();
                                    else
                                        if(strcmp("ESPECIALIDAD",entidad) == 0)
                                            ModificarEspecialidad();
                    break;
            case 3:
                    if (strcmp("PROFESIONAL",entidad) == 0)
                        MostrarProfesionales();
                    else
                        if(strcmp("USUARIO",entidad) == 0)
                            MostrarUsuarios();
                        else
                            if(strcmp("PRESENTACION",entidad) == 0)
                                MostrarPresentacion();
                            else
                                if(strcmp("FARMACO",entidad) == 0)
                                    MostrarFarmaco();
                                else
                                    if(strcmp("COBERTURA",entidad) == 0)
                                        MostrarCobertura();
                                    else
                                        if(strcmp("ESPECIALIDAD",entidad) == 0)
                                            MostrarEspecialidad();
                    break;
            case 0:
                    return;
            break;
        }
        cin.ignore();
    }
    return ;
}

void MenuAdministrador :: MenuAlcance()
{
    ValidacionesTipoDato valTDato;
    while(true){
        cls();
        title("ALCANCE DEL PROYECTO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);
        cout<<"1) Alcance Del Prototipo                     "<<endl;
        cout<<"2) Reglas Del Software Por Perfil De Usuario "<<endl;
        cout<<"3) Reglas Del Software Por Clases            "<<endl;
        cout<<"4) Validaciones Generales                    "<<endl;
        cout<<"5) Verificaciones Gneerales                  "<<endl;
        cout<<"----------------------                       "<<endl;
        cout<<"0) REGRESAR                                  "<<endl;

        int opcion;
        opcion = valTDato.cargar_Entero();

        switch(opcion)
        {
            case 1: AlcanceDelPrototipo();
                    break;
            case 2:
                   ReglasDelSoftwarePorPerfilDeUsuario();
                    break;
            case 3:
               //     ReglasDelSoftwarePorClases();
                    break;
            case 4:// ValidacionesGenerales();
                    break;
            case 5:// VerificacionesGneerales();
                    break;
            case 0: return;
            break;
        }
        cin.ignore();
    }
    return ;
}

/******************* FUNCIONES BASICAS PROFESIONAL *************************/

void MenuAdministrador :: AltaProfesional(){
    cls();
    InterfazProfesional IP;
    Profesional prof;
    if (IP.CargarProfesional(prof))
        IP.AgregarAArchivo(prof);
    return;
}

void MenuAdministrador :: MostrarProfesionales()
{
    cls();
    InterfazProfesional IP;
    IP.ListarProfesionales();
}

void MenuAdministrador :: ModificarProfesional(){

    system("cls");
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO..."<<endl;
    system("PAUSE");
    return;

    ValidacionesTipoDato valTipoDato;
    ValidacionesGenerales valGeneral;
    InterfazProfesional IP;
    Profesional prof;
    cout<<"DESEA VER LA LISTA DE PROFESIONALES? S/N"<<endl;
    if (valGeneral.leer_SoN()) IP.ListarProfesionales();
    cout<<"INGRESE EL ID DEL PROFESIONAL QUE DESEA MODIFICAR: ";
    prof.SetId(valTipoDato.cargar_Entero());
    IP.ModificarEnArchivo(prof);
}

/******************* FUNCIONES BASICAS USUARIO  *************************/

void MenuAdministrador :: AltaUsuario(){
    cls();
    InterfazUsuario IU;
    Usuario usr;
    if (IU.CargarUsuario(usr))
        IU.AgregarUsuarioAArchivo(usr);
    return;
}

void MenuAdministrador :: MostrarUsuarios(){
    cls();
    InterfazUsuario IU;
    IU.ListarUsuarios();
}

void MenuAdministrador :: ModificarUsuario(){
    cls();
    InterfazUsuario IU;
    IU.ModificarUsuario(usr_lgd);
}


/***************************** PRESENTACIONES *********************/


void MenuAdministrador :: AltaPresentacion(){
    system("cls");
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO..."<<endl;
    system("PAUSE");
    return;
};
void MenuAdministrador :: ModificarPresentacion(){
    system("cls");
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO..."<<endl;
    system("PAUSE");
    return;
};
void MenuAdministrador :: MostrarPresentacion(){
    system("cls");
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO..."<<endl;
    system("PAUSE");
    return;
};
/***************************** FARMACOS  *********************/
void MenuAdministrador :: AltaFarmaco(){
    system("cls");
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO..."<<endl;
    system("PAUSE");
    return;
};
void MenuAdministrador :: ModificarFarmaco(){
   system("cls");
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO..."<<endl;
    system("PAUSE");
    return;
};
void MenuAdministrador :: MostrarFarmaco(){
    system("cls");
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO..."<<endl;
    system("PAUSE");
    return;
};
/***************************** COBERTURAS *********************/
void MenuAdministrador :: AltaCobertura(){
    system("cls");
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO..."<<endl;
    system("PAUSE");
    return;
};
void MenuAdministrador :: ModificarCobertura(){
    system("cls");
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO..."<<endl;
    system("PAUSE");
    return;
};
void MenuAdministrador :: MostrarCobertura(){
     system("cls");
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO..."<<endl;
    system("PAUSE");
    return;
};
/***************************** ESPECIALDIADES *********************/

void MenuAdministrador :: AltaEspecialidad(){
     cls();
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO"<<endl<<endl;
    system("PAUSE");
    return;
};
void MenuAdministrador :: ModificarEspecialidad(){
     cls();
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO"<<endl<<endl;
    system("PAUSE");
    return;
};
void MenuAdministrador :: MostrarEspecialidad(){
     cls();
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO"<<endl<<endl;
    system("PAUSE");
    return;
};

void MenuAdministrador :: AlcanceDelPrototipo(){
    cout << left;
    cout<<"FLUJO BASICO DEL PROCESO HASTA EL MOMENTO"<<endl;
    cout<<"1.El administrador carga/lista/edita profesionales"<<endl;
	cout<<"2.El administrador carga/lista usuarios (perfil profesional) y los relaciona a alguno de los profesionales creados"<<endl;
	cout<<"3.El usuario con perfil Profesional puede crear/ listar (sus) pacientes"<<endl;
	cout<<"4.El usuario con perfil Profesional puede crear usuarios y debe asociarlos a los pacientes disponibles"<<endl;
	cout<<"5.El usuario con perfil Profesional crea un plan farmacologico y se lo asocia a un paciente"<<endl;
	cout<<"6.El usuario con perfilpaciente puede ver sus planes farmacoligicos (IMPLEMENTADO PARCIALMENTE, sin DETALLE)"<<endl;
	cout<<"7.El usuario con perfil paciente puede ver ver el listado de profesionales completo"<<endl;
	cout<<endl<<endl;
	cout<<"VALIDACIONES:"<<endl;
	cout<<"Logica de loguin -> menu por tipo de usuario"<<endl;
	cout<<"Los nombres de los usuarios puede ser alfanumericos"<<endl;
	cout<<"Los nombres de las personas solo pueden ser alfabeticos"<<endl;
	cout<<"No se pueden crear usuarios si no existe el archivod e pacientes o profesionales"<<endl;
	cout<<"El profesional solo da de altas usuario de tipo paciente (con relacion de paciente obligatoria)"<<endl;
	cout<<"El adminsitrador solo puede dar de alta usuarios de tipo profesionales (con relacion de profesional obligatoria)"<<endl;
	cout<<"El nombre de usuario no se puede repetir y es FK"<<endl;
	cout<<"Todos los registros tiene una fecha de alta, que es la misma del momento en el que se crean"<<endl;
	cout<<"Si no se asocia un paciente al plan farmacologico, se descarta"<<endl;
	cout<<"El plan farmacologico se relaciona de forma automatica al ID del profesional que lo crea"<<endl;
	cout<<"La fecha de emision del plan es la actual y es automatica"<<endl;
	cout<<"Se corrobora MES, DIA, ANIO y Año bisiesto"<<endl;
	cout<<"Se corrobora por intervalo numerico el nro de DNI"<<endl;
	cout<<"Se corrobora por intervalo numerico el nro de matricula"<<endl;
	cout<<"Se corrobora por intervalo numerico el nro de afiliado"<<endl;
	cout<<"Validaciones de tipos de datos en la mayoria de los casos (resta implementar algunos)"<<endl;
    cout<<"Un usuario NO EXISTE sin un paciente o prefesional relacionado"<<endl;
    cout<<"No se pueden cargar cadenas vacias (metodo creado pero no aplicado aun)"<<endl;
    cout<<"UserOwnerId creado en Registro para poder listar los objetos de sus propietarios (sin terminar de implementar)"<<endl;
    cout<<"Logo de inciios del sistema 'ADMIN SALUD 1.0'"<<endl;
    cout<<"No se permite asociar un usuario a un paciente/profesional ya asociado a otro usuario"<<endl;
    cout<<"Los profesionales SOLO ven sus pacientes y SUS PLANES FARMACOLOGICOS"<<endl;
    cout<<"Se valida los datos al ingresar el PERFIL de usuario"<<endl;
    cout<<"Las Altas Bajas y Modificacion de datos, son responsabilidad de la 'clases Interfaz' de cada clase"<<endl;
    cout<<"Se validacion opciones INT por intervalo y se emite un mensaje si hay error (todo aprametrizable)"<<endl;
    cout<<"Se valida el ingresoi del Genero"<<endl;
    cout<<"Se valida el ingreso de 'S' o 'N'"<<endl;
    cout<<"Se valida el dia, mes y anio"<<endl;
    cout<<"Se valida año bisciesto"<<endl;
    cout<<"Se valida si la cadena es alfanumerica"<<endl;
    cout<<"Se valida si la cadena es alfabetica"<<endl;
    cout<<"Se corrobora el ingreso de datos de tipo INT, FLOAT, BOOL, CHAR"<<endl;
    cout<<"Se muestra la fecha con formato DD/MM/AAAA"<<endl;
    cout<<endl<<endl;
	cout<<"ACLARACION IMPORTANTE!"<<endl;
	cout<<"Todas las clases tienen los metodos Mostrar, cargar, etc, estos seran eliminados cuando se terminen de implementar las interfaces. Los mismos NO SE ESTAN UTILIZANDO"<<endl;
	cout<<"Cuando se termine de implementar todo, solo se podran dar de baja las coberturas, lo deas es toda informacion que se utiliza como traza y no se puede modificar ni dar de baja logicamente, para el caso de los medicamentos por ejemplo, tendran un atributo para filtrarlos en las listas"<<endl;
	cout<<"Alguans funcionalidades estan repetidas. Esto se hizo a proposito porque esta en proceso una mejora de impelemtacion"<<endl;
	cout<<"No se esta validando DNI, MATRICULAS o NRO de cobertura repetidos. Se verificara en el proyecto completo."<<endl;
	cout<<endl<<endl;
	system("PAUSE");
}

void MenuAdministrador :: ReglasDelSoftwarePorPerfilDeUsuario(){
    cout << left;
    cout<<"ADMIN:"<<endl;
    cout<<"     LISTA"<<endl;
    cout<<"          usuarios: Los lista (con pass y todo)"<<endl;
    cout<<"          profesionales"<<endl;
    cout<<"          presentacciones"<<endl;
    cout<<"          armacos"<<endl;
    cout<<"          coberturase"<<endl;
    cout<<"          especialidades"<<endl;
    cout<<"     VALIDACIONES "<<endl;
    cout<<"          La mayoria ya desarrolladas ..."<<endl;
    cout<<"     ALTA"<<endl;
    cout<<"          Da de alta SOLO usuarios profesionales"<<endl;
    cout<<"          Da de alta  profesionales"<<endl;
    cout<<"          Puede dar de alta presentaciones (NO DISPONIBLE AUN)"<<endl;
    cout<<"          Puede dar de alta farmacos (NO DISPONIBLE AUN)"<<endl;
    cout<<"          Debe dar de alta  coberturas (NO DISPONIBLE AUN)"<<endl;
    cout<<"          Debe dar de alta  especialidades (NO DISPONIBLE AUN)"<<endl;
    cout<<"PROFESIONAL:"<<endl;
	cout<<"     LISTA"<<endl;
	cout<<"          Solo puede ver SUS PACIENTES "<<endl;
	cout<<"	         Solo puede ver USUARIOS DE SUS PACIENTES (BETA: EN DESARROLLO)"<<endl;
	cout<<"          Solo puede ver SUS PLANES FARMACOS"<<endl;
	cout<<"          Solo puede ver sus Detalles de PLan farmaco"<<endl;
	cout<<"	         Solo puede ver SUS Informes " <<endl;
	cout<<"	         presentacciones "<<endl;
	cout<<"          farmacos "<<endl;
	cout<<"	         coberturas "<<endl;
	cout<<"	         Puede ver medicaciones"<<endl;
	cout<<"	         Puede ver presentaciones"<<endl;
	cout<<"	         Puede ver farmaco"<<endl;
	cout<<"      ALTA"<<endl;
    cout<<"          Puede dar de alta usuarios CON PERFIL paciente"<<endl;
	cout<<"	         Puede dar de alta pacientes"<<endl;
    cout<<"	         Puede dar de alta planes farmacologicos"<<endl;
    cout<<"	         Puede dar de alta detalles de planes farmacologicos"<<endl;
    cout<<"	         Puede dar de alta informes"<<endl;
    cout<<"     VALIDACIONES"<<endl;
	cout<<"	         Debe relacionar un usuario a un paciente, siempre "<<endl;
    cout<<"          Debe relacionar un plan a un paciente, el src (prof) se setea solo"<<endl;
	cout<<"          Debe relacionar un farmaco a un detalle de plan/plan"<<endl;
	cout<<"          Debe relacionar un detalle a un plan"<<endl;
	cout<<"          faltan agregar mas .... muchas ya desarrolaldas"<<endl;
	cout<<"     MODIFICACIONES"<<endl;
    cout<<"	         Puede modificar su user/pass"<<endl;
    cout<<"PACIENTE:"<<endl;
	cout<<"     LISTA "<<endl;
	cout<<"          Puede ver sus planes farmac asociados"<<endl;
	cout<<"	         Puede ver los detalles de sus planes asociados"<<endl;
	cout<<"	         Puede ver los el listado completop de profesionales"<<endl;
    cout<<"	         Puede ver los el su profesional"<<endl;
	cout<<"     MODIFICAR:"<<endl;
	cout<<"	         Puede cambiar su user/pass"<<endl;
    cout<<"          Puede cambiar la cantidad de pastillas del detalle del plan"<<endl;
	cout<<"     VALIDACIONES:"<<endl;
	cout<<"          Sin definir:"<<endl;
	cout<<endl<<endl;
	system("PAUSE");
}


/// ************************************************************************************* ///
/// ********************************** METODOS PROFE ************************************ ///
/// ************************************************************************************* ///

void MenuProfesional :: MenuProf(){
    initUI();
    title("", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    ValidacionesTipoDato valTDato;
    while(true){
        cls();
        title("PROFESIONAL", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);
        cout<<"1) USUARIOS"<<endl;
        cout<<"2) PACIENTES"<<endl;
        cout<<"3) PLANES FARMACOLOGICOS"<<endl;
        cout<<"4) INFORMES "<<endl;
        cout<<"5) MODIFICAR DATOS DE USUARIO"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"0) REGRESAR"<<endl;

        int opcion;
        opcion = valTDato.cargar_Entero();

        switch(opcion){
            case 1:
                   MenuGeneral("USUARIOS");
                   break;
            case 2:
                   MenuGeneral("PACIENTES");
                   break;
            case 3:
                   MenuGeneral("PLANES FARMACOLOGICOS");
                   break;
            case 4:
                   MenuGeneral("INFORMES");
                   break;
            case 5:
                   ModificarDatosDeUsuarioLogueado();
                   break;
            case 0:
                   return;
            break;
        }
        cin.ignore();
    }
    return;
}

/******************* MENU GENERAL **************************************/

void MenuProfesional :: MenuGeneral(const char * _objeto)
{
    ValidacionesTipoDato valTDato;
    while(true)
    {
        cls();
        title(_objeto, APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);
        cout<<"1) ALTA"<<endl;
        cout<<"2) MODIFICAR"<<endl;
        cout<<"3) LISTAR"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"0) REGRESAR"<<endl;

        int opcion;
        opcion = valTDato.cargar_Entero();

        switch(opcion)
        {
            case 1: if(strcmp("PACIENTES",_objeto) == 0)
                            AltaPacienteDelProfesional();
                        else
                            if(strcmp("USUARIOS",_objeto) == 0)
                                AltaDeUsuariosPaciente();
                            else
                                if(strcmp("PLANES FARMACOLOGICOS",_objeto) == 0)
                                    AltaPlanFarmacologico();
                                else
                                    if(strcmp("INFORMES",_objeto) == 0)
                                        AltaDeInformes();
                    break;
            case 2:
                    if(strcmp("PACIENTES",_objeto) == 0)
                            ModificarPacienteDelProfesional();
                        else
                            if(strcmp("USUARIOS",_objeto) == 0){
                                cout<<"NO ES POSIBLE MODIFICAR LOS USUARIOS DADOS DE ALTA"<<endl<<endl;
                                system("PAUSE");
                            }
                            else
                                if(strcmp("PLANES FARMACOLOGICOS",_objeto) == 0)
                                    AltaPlanFarmacologico();
                                else
                                    if(strcmp("INFORMES",_objeto) == 0)
                                        AltaDeInformes();
                    break;
            case 3:
                    if(strcmp("PACIENTES",_objeto) == 0)
                            MostrarPacientesDelProfesional(); ///SE DEBEN VER SUS PACIENTES!
                        else
                            if(strcmp("USUARIOS",_objeto) == 0){
                                MostrarUsuariosPaciente();
                            }
                            else
                                if(strcmp("PLANES FARMACOLOGICOS",_objeto) == 0)
                                    MostrarPlanesFarmacologicosDelProfesional();
                                else
                                    if(strcmp("INFORMES",_objeto) == 0)
                                        MostrarInformesDelProfesional();
            case 0:
                    return;
            break;
        }
        cin.ignore();
    }
    return ;
}

/******************* FUNCIONES BASICAS PACIENTE *************************/

void MenuProfesional :: AltaPacienteDelProfesional(){
    cls();
    InterfazPaciente IP;
    Paciente paciente;
    if (IP.CargarPaciente(paciente))
        IP.AgregarPacienteAArchivo(paciente);
    return;
}

void MenuProfesional :: MostrarPacientesDelProfesional(){
    system("cls");
    InterfazPaciente IP;
    IP.ListarPacientes();
}

void MenuProfesional :: ModificarPacienteDelProfesional(){
    system("cls");
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO..."<<endl;
    system("PAUSE");
    return;

    ValidacionesTipoDato valTipoDato;
    ValidacionesGenerales valGeneral;
    InterfazPaciente IP;
    Paciente pac;
    cout<<"DESEA VER LA LISTA DE PACIENTES? S/N"<<endl;
    if (valGeneral.leer_SoN()) IP.ListarPacientes();
    cls();
    cout<<"INGRESE EL ID DEL PACIENTE QUE DESEA MODIFICAR: ";
    pac.SetId(valTipoDato.cargar_Entero());
    cls();
    IP.ModificarPacienteEnArchivo(pac);
}

/******************* MENUES PLAN FARMA *****************************/

void MenuProfesional :: AltaPlanFarmacologico(){
    system("cls");
    InterfazPlanFarmacologico IPF;
    PlanFarmacologico planFarmaco;
    if (IPF.CargarPlanFarmacologico(planFarmaco))
        IPF.AgregarPlanFarmacologicoAArchivo(planFarmaco);
    return;
}

void MenuProfesional :: MostrarPlanesFarmacologicosDelProfesional(){
    system("cls");
    InterfazPlanFarmacologico IPF;
    IPF.ListarPlanesFarmacologicos();
    return;
}

/********************** ESTUDIOS ********************/
void MenuProfesional :: MostrarEstudiosDelProfesional(){
    system("cls");
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO..."<<endl;
    system("PAUSE");
    return;
}

/******************** INFORMES ***********************/
void MenuProfesional :: MostrarInformesDelProfesional(){
    system("cls");
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO..."<<endl;
    system("PAUSE");
    return;
}

void MenuProfesional :: AltaDeInformes(){
    system("cls");
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO..."<<endl;
    system("PAUSE");
    return;
};

/********************* DATOS DEL USUARIO *****************/
void MenuProfesional :: ModificarDatosDeUsuarioLogueado(){
    system("cls");
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO..."<<endl;
    system("PAUSE");
    return;
    cls();
    InterfazUsuario IU;
    IU.ModificarUsuario(usr_lgd);
}

/********************* USUARIOS *********************/

void MenuProfesional :: AltaDeUsuariosPaciente(){
    cls();
    InterfazUsuario IU;
    Usuario usr;
    if (IU.CargarUsuario(usr))
        IU.AgregarUsuarioAArchivo(usr);
    return;
}

void MenuProfesional :: MostrarUsuariosPaciente(){
    cls();
    InterfazUsuario IU;
    IU.ListarUsuarios();
}


/// ************************************************************************************* ///
/// ********************************** METODOS PACIE ************************************ ///
/// ************************************************************************************* ///

void MenuPaciente :: MenuPac(){
    initUI();
    ValidacionesTipoDato valTDato;
    title("PACIENTE", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
    while(true){
        cls();
        title("MENU PRINCIPAL", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);
        cout<<"1) PLAN FARMACOLOGICO"<<endl;
        cout<<"2) PROFESIONALES"<<endl;
        cout<<"3) MODIFICAR DATOS DE USUARIO"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"0) REGRESAR"<<endl;

        int opcion;
        opcion = valTDato.cargar_Entero();

        switch(opcion){
            case 1: MostrarPlanesFarmacologicosDelPaciente();
            break;
            case 2: MostrarProfesionalesDelPaciente();
            break;
            case 3: ModificarUsuarioPaciente();
            case 0:
                    return;
            break;
        }
        cin.ignore();
    }
    return ;
}

void MenuPaciente :: MostrarPlanesFarmacologicosDelPaciente(){
    cls();
    InterfazPlanFarmacologico IPF;
    IPF.ListarPlanesFarmacologicos();
    return;
}

void MenuPaciente :: MostrarProfesionalesDelPaciente(){

    cls();
    InterfazProfesional IP;
    IP.ListarProfesionales();
}

void MenuPaciente :: ModificarUsuarioPaciente(){
    cls();
    InterfazUsuario IU;
    IU.ModificarUsuario(usr_lgd);
}


void MenuPaciente :: MenuPacienteConsulta(){
    while(true){
        rlutil::cls();
        title("PACIENTE - CONSULTA", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);
        cout<<"1) MEDICACION"<<endl;
        cout<<"2) PROFESIONAL"<<endl;
        cout<<"3) ESTUDIOS REALIZADOS"<<endl;
        cout<<"4) PLAN FARMACOLOGICO"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"0) REGRESAR"<<endl;

        int opcion;
        cout << endl << "> ";
        cin >> opcion;

        switch(opcion){
            case 1:
            rlutil::anykey();
            break;
            case 2:
            rlutil::anykey();
            break;
            case 3:
            rlutil::anykey();
            break;
            case 4: MenuPlanFarmacologico();
            rlutil::anykey();
            case 0:
                return;
            break;
        }
        cin.ignore();
    }
    return ;
}

void MenuPaciente :: MenuPlanFarmacologico(){
    while(true){
        rlutil::cls();
        title("PACIENTE - CONSULTA", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);
        cout<<"1) MEDICACION"<<endl;
        cout<<"2) PROFESIONAL"<<endl;
        cout<<"3) DETALLE DEL PLAN"<<endl;
        cout<<"4) STOCK"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"0) REGRESAR"<<endl;

        int opcion;
        cout << endl << "> ";
        cin >> opcion;

        switch(opcion){
            case 1:
            rlutil::anykey();
            break;
            case 2:
            rlutil::anykey();
            break;
            case 3:
            rlutil::anykey();
            break;
            case 4:
            rlutil::anykey();
            case 0:
                return;
            break;
        }
        cin.ignore();
    }
    return ;
}

void MenuPaciente :: MenuPacienteListados(){
    while(true){
        rlutil::cls();
        title("PACIENTE - LISTADO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);
        cout<<"1) LISTADO DE MEDICACION ACTUAL"<<endl;
        cout<<"2) LISTADO DE PROFESIONALES"<<endl;
        cout<<"3) LISTADO DE ESTUDIOS REALIZADOS"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"0) REGRESAR"<<endl;

        int opcion;
        cout << endl << "> ";
        cin >> opcion;

        switch(opcion){
            case 1:
                rlutil::anykey();
            break;
            case 2:
            rlutil::anykey();
            break;
            case 3:
            rlutil::anykey();
            break;
            case 0:
                return;
            break;
        }
        cin.ignore();
    }
    return ;
}
