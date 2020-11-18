#include <iostream>
#include <cstring>
#include "../util/ui.h"
#include "../util/rlutil.h"

#include "../modelos/especialidad.h"
#include "../modelos/archivo.h"
#include "../modelos/fecha.h"
#include "../menues/informes.h"
#include "../modelos/paciente.h"
#include "../modelos/profesional.h"
#include "../modelos/medicacion.h"
#include "../menues/menuesadministrador.h"
#include "../validaciones/validaciones.h"
#include "../interfaces/interfazentidades.h"
#include "../info/info.h"

using namespace std;
using namespace rlutil;

extern const char *FILE_PACIENTES;
extern const char *FILE_PROFESIONALES;

void MenuAdministrador()
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


void MenuGeneralAdministrador(const char * entidad)
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

void MenuAlcance()
{
    ValidacionesTipoDato valTDato;
    while(true){
        cls();
        title("ALCANCE DEL PROYECTO", APP_TITLEFORECOLOR, APP_TITLEBACKCOLOR);
        gotoxy(1, 3);
        cout<<"1) Alcance Del Prototipo                     "<<endl;
        cout<<"2) Reglas Del Software Por Perfil De Usuario "<<endl;
        cout<<"4) Reglas Del Software Por Clases            "<<endl;
        cout<<"5) Validaciones Generales                    "<<endl;
        cout<<"6) Verificaciones Gneerales                  "<<endl;
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

void AltaProfesional(){
    cls();
    InterfazProfesional IP;
    Profesional prof;
    if (IP.CargarProfesional(prof))
        IP.AgregarAArchivo(prof);
    return;
}

void MostrarProfesionales()
{
    cls();
    InterfazProfesional IP;
    IP.ListarProfesionales();
}

void ModificarProfesional(){

    cls();
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

void AltaUsuario(){
    cls();
    InterfazUsuario IU;
    Usuario usr;
    if (IU.CargarUsuario(usr))
        IU.AgregarUsuarioAArchivo(usr);
    return;
}

void MostrarUsuarios(){
    cls();
    InterfazUsuario IU;
    IU.ListarUsuarios();
}

void ModificarUsuario(){
    cls();
    InterfazUsuario IU;
    IU.ModificarUsuario(usr_lgd);
}


/***************************** PRESENTACIONES *********************/


void AltaPresentacion(){
    cls();
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO"<<endl<<endl;
    system("PAUSE");
return;
};
void ModificarPresentacion(){
     cls();
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO"<<endl<<endl;
    system("PAUSE");
    return;
};
void MostrarPresentacion(){
     cls();
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO"<<endl<<endl;
    system("PAUSE");
    return;
};
/***************************** FARMACOS  *********************/
void AltaFarmaco(){
     cls();
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO"<<endl<<endl;
    system("PAUSE");
    return;
};
void ModificarFarmaco(){
     cls();
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO"<<endl<<endl;
    system("PAUSE");
    return;
};
void MostrarFarmaco(){
     cls();
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO"<<endl<<endl;
    system("PAUSE");
    return;
};
/***************************** COBERTURAS *********************/
void AltaCobertura(){
     cls();
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO"<<endl<<endl;
    system("PAUSE");
    return;
};
void ModificarCobertura(){
     cls();
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO"<<endl<<endl;
    system("PAUSE");
    return;
};
void MostrarCobertura(){
     cls();
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO"<<endl<<endl;
    system("PAUSE");
    return;
};
/***************************** ESPECIALDIADES *********************/

void AltaEspecialidad(){
     cls();
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO"<<endl<<endl;
    system("PAUSE");
    return;
};
void ModificarEspecialidad(){
     cls();
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO"<<endl<<endl;
    system("PAUSE");
    return;
};
void MostrarEspecialidad(){
     cls();
    cout<<"ESTE MODULO AUN NO HA SIDO IMPLEMENTADO"<<endl<<endl;
    system("PAUSE");
    return;
};


