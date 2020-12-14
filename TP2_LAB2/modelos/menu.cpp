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
#include "../modelos/informe.h"
#include "../validaciones/validaciones.h"
#include "../interfaces/interfazentidades.h"
#include "../interfaces/interfazplanfarmacologico.h"
#include "../interfaces/interfazmedicamento.h"
#include "../interfaces/interfazfarmaco.h"
#include "../interfaces/interfazcobertura.h"
#include "../interfaces/interfazespecialidad.h"
#include "../interfaces/interfazinforme.h"



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

    Logo logo;
    logo.logo();
    Perfil  tipoDeUsuario=Perfil_Paciente;
    ValidacionesGenerales validacionLogin;

    cout << "                   INGRESE EL PERFIL DEL USUARIO:"<<endl<<endl;
    cout << "                        0 - Administrador"<<endl;
    cout << "                        1 - Profesional"<<endl;
    cout << "                        2 - Paciente"<<endl;

    tipoDeUsuario = validacionLogin.ValidarPerfilDeUsuario();

    Archivo archUsuarios(FILE_USUARIOS,sizeof(Usuario));
    char user[50]={}, pass[50]={};
    bool  salir=false;
    Usuario usrAxuLogin;

    system("cls");
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
        cout<<"USUARIO O CONTRASENIA INCORRECTOS. DESEA SALIR? S/N"<<endl;
        salir = validacionLogin.leer_SoN();
        system("cls");
        if (!salir){
            cout << "INGRESE UN USUARIO: ";
            cin.clear();
            cin.ignore();
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
        system("cls");
        title("MENU PRINCIPAL", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);
        cout<<"1) PROFESIONALES        "<<endl;
        cout<<"2) USUARIOS             "<<endl;
        cout<<"3) MEDICAMENTOS         "<<endl;
        cout<<"4) FARMACOS             "<<endl;
        cout<<"5) COBERTURAS           "<<endl;
        cout<<"6) ESPECIALIDADES       "<<endl;
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
                    MenuGeneralAdministrador("MEDICAMENTO");
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
        system("cls");
        title(entidad, APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);
        cout<<"1) ALTA               "<<endl;
        cout<<"2) LISTAR             "<<endl;
        if (strcmp(entidad,"COBERTURA") == 0 || strcmp(entidad,"PROFESIONAL") == 0 || strcmp(entidad,"ESPECIALIDAD") == 0 )
            cout<<"3) MODIFICAR          "<<endl;
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
                            if(strcmp("MEDICAMENTO",entidad) == 0)
                                AltaMedicamento();
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
            case 3:
                    if (strcmp("PROFESIONAL",entidad) == 0)
                        ModificarProfesional();
                        else
                            if(strcmp("COBERTURA",entidad) == 0)
                                ModificarCobertura();
                            else
                                if(strcmp("ESPECIALIDAD",entidad) == 0)
                                    ModificarEspecialidad();
                    break;
            case 2:
                    if (strcmp("PROFESIONAL",entidad) == 0)
                        MostrarProfesionales();
                    else
                        if(strcmp("USUARIO",entidad) == 0)
                            MostrarUsuarios();
                        else
                            if(strcmp("MEDICAMENTO",entidad) == 0)
                                MostrarMedicamento();
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

/******************* FUNCIONES BASICAS PROFESIONAL *************************/

void MenuAdministrador :: AltaProfesional(){
    system("cls");
    InterfazProfesional IP;
    Profesional prof;
    if (IP.CargarProfesional(prof))
        IP.AgregarAArchivo(prof);
    return;
}

void MenuAdministrador :: MostrarProfesionales()
{
    system("cls");
    InterfazProfesional IP;
    IP.ListarProfesionales();
}

void MenuAdministrador :: ModificarProfesional(){
    system("cls");
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
    system("cls");
    InterfazUsuario IU;
    Usuario usr;
    if (IU.CargarUsuario(usr))
        IU.AgregarUsuarioAArchivo(usr);
    return;
}

void MenuAdministrador :: MostrarUsuarios(){
    system("cls");
    InterfazUsuario IU;
    IU.ListarUsuarios();
}

/***************************** MEDICAMENTOS *********************/


void MenuAdministrador :: AltaMedicamento(){
    system("cls");
    InterfazMedicamento IM;
    Medicamento medicamento;
    vector<int> vecFarmARelacionar;
    if (IM.CargarMedicamento(medicamento,vecFarmARelacionar))
        IM.AgregarMedicamentoAArchivo(medicamento,vecFarmARelacionar);
    return;
};

void MenuAdministrador :: MostrarMedicamento(){
    system("cls");
    InterfazMedicamento IM;
    IM.ListarMedicamentos();

};
/***************************** FARMACOS  *********************/
void MenuAdministrador :: AltaFarmaco(){
    system("cls");
    InterfazFarmaco IF;
    Farmaco farmaco;
    if (IF.CargarFarmaco(farmaco))
        IF.AgregarFarmacoAArchivo(farmaco);
    return;
};

void MenuAdministrador :: MostrarFarmaco(){
    system("cls");
    InterfazFarmaco IF;
    IF.ListarFarmacos();
};

/***************************** COBERTURAS *********************/
void MenuAdministrador :: AltaCobertura(){
    system("cls");
    InterfazCobertura IC;
    Cobertura cob;
    if (IC.CargarCobertura(cob))
        IC.AgregarCoberturaAArchivo(cob);
};
void MenuAdministrador :: ModificarCobertura(){
    system("cls");
    ValidacionesTipoDato valTipoDato;
    ValidacionesGenerales valGeneral;
    InterfazCobertura IC;
    Cobertura cob;
    cout<<"DESEA VER LA LISTA DE COBERTURAS? S/N"<<endl;
    if (valGeneral.leer_SoN()) IC.ListarCoberturas();
    cout<<"INGRESE EL ID DE LA COBERTURA QUE DESEA MODIFICAR: ";
    cob.SetId(valTipoDato.cargar_Entero());
    IC.ModificarCobertura(cob);
};

void MenuAdministrador :: MostrarCobertura(){
    system("cls");
    InterfazCobertura IC;
    IC.ListarCoberturas();
};
/***************************** ESPECIALDIADES *********************/

void MenuAdministrador :: AltaEspecialidad(){
    system("cls");
    InterfazEspecialidad IE;
    Especialidad esp;
    if (IE.CargarEspecialidad(esp))
        IE.AgregarEspecialidadAArchivo(esp);
};

void MenuAdministrador :: ModificarEspecialidad(){
    system("cls");
    ValidacionesTipoDato valTipoDato;
    ValidacionesGenerales valGeneral;
    InterfazEspecialidad IE;
    Especialidad esp;
    cout<<"DESEA VER LA LISTA DE ESPECIALIDADES? S/N"<<endl;
    if (valGeneral.leer_SoN()) IE.ListarEspecialidades();
    cout<<"INGRESE EL ID DE LA ESPECIALIDAD QUE DESEA MODIFICAR: ";
    esp.SetId(valTipoDato.cargar_Entero());
    IE.ModificarEspecialidad(esp);
};

void MenuAdministrador :: MostrarEspecialidad(){
    system("cls");
    InterfazEspecialidad IE;
    IE.ListarEspecialidades();
};

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
    //    cout<<"5) MODIFICAR DATOS DE USUARIO"<<endl;
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
            /*
            case 5:
                   ModificarDatosDeUsuarioLogueado();
                   break;
            */
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
        system("cls");
        title(_objeto, APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);
        cout<<"1) ALTA"<<endl;
        cout<<"2) LISTAR"<<endl;
        //cout<<"3) MODIFICAR"<<endl;
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
    system("cls");
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
    cout<<"MODULO INCOMPLETO"<<endl;
    system("PAUSE");
    ///TESTEAR!
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
    IPF.CargarPlanFarmacologico(planFarmaco);
    return;
}

void MenuProfesional :: MostrarPlanesFarmacologicosDelProfesional(){
    system("cls");
    InterfazDetallePlanFarmacologico idp;
    idp.ListarDetallesDePlanesFarmacologicos();

    InterfazPlanFarmacologico IPF;
    IPF.ListarPlanesFarmacosCombinados();
}


/******************** INFORMES ***********************/
void MenuProfesional :: AltaDeInformes(){
    system("cls");
    InterfazInforme IF;
    Informe informe;
    if (IF.CargarInforme(informe))
        IF.AgregarInformeAArchivo(informe);
}

void MenuProfesional :: MostrarInformesDelProfesional(){
    system("cls");
    InterfazInforme IF;
    IF.ListarInformes();
};

/********************* DATOS DEL USUARIO *****************/
void MenuProfesional :: ModificarDatosDeUsuarioLogueado(){
    ///TESTEAR!
    system("cls");
    cls();
    InterfazUsuario IU;
    IU.ModificarUsuario(usr_lgd);
}

/********************* USUARIOS *********************/

void MenuProfesional :: AltaDeUsuariosPaciente(){
    system("cls");
    InterfazUsuario IU;
    Usuario usr;
    if (IU.CargarUsuario(usr))
        IU.AgregarUsuarioAArchivo(usr);
    return;
}

void MenuProfesional :: MostrarUsuariosPaciente(){
    system("cls");
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
        cout<<"1) MIS PLANES FARMACOLOGICOS"<<endl;
        cout<<"2) PROFESIONALES"<<endl;
        cout<<"3) ADMINISTRAR PLAN FARMACO"<<endl;
        cout<<"----------------------"<<endl;
        cout<<"0) REGRESAR"<<endl;

        int opcion;
        opcion = valTDato.cargar_Entero();

        switch(opcion){
            case 1: MostrarPlanesFarmacologicosDelPaciente();
            break;
            case 2: MostrarProfesionalesDelPaciente();
            break;
            case 3: AdminPlanFarmaco();
            break;
            case 0:
                    return;
            break;
        }
        cin.ignore();
    }
    return ;
}

///VERIFICAR!!
void MenuPaciente :: AdminPlanFarmaco(){

    ValidacionesTipoDato valTipoDato;
    ValidacionesGenerales valGeneral;

    InterfazDetallePlanFarmacologico IDP;
    DetallePlanFarmacologico det;

    InterfazPaciente IP;
    Paciente pac;
    InterfazPlanFarmacologico itfzPlanFc;
    cout<<"DESEA VER SU LISTA DE PLANES? S/N"<<endl;
    if (valGeneral.leer_SoN()) itfzPlanFc.ListarPlanesFarmacosCombinados();
    system("cls");
    cout<<"INGRESE EL ID DEL PLAN QUE DESEA MODIFICAR: ";
    det.SetId(valTipoDato.cargar_Entero());
    system("cls");
    IDP.ModificarDetallePlan(det);
    IDP.ModificarDetalleEnArchivo(det);
    return;
}

void MenuPaciente :: MostrarPlanesFarmacologicosDelPaciente(){
    system("cls");
    InterfazPlanFarmacologico IPF;
    IPF.ListarPlanesFarmacosCombinados();
    return;
}

void MenuPaciente :: MostrarProfesionalesDelPaciente(){
    system("cls");
    InterfazProfesional IP;
    IP.ListarProfesionales();
}

void MenuPaciente :: ModificarUsuarioPaciente(){
    system("cls");
    InterfazUsuario IU;
    IU.ModificarUsuario(usr_lgd);
}
