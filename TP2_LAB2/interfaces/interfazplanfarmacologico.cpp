#include "../modelos/planfarmacologico.h"
#include "../modelos/detalleplanfarmacologico.h"
#include "../validaciones/validaciones.h"
#include "../modelos/fecha.h"
#include "../interfaces/interfazplanfarmacologico.h"
#include "../interfaces/interfazentidades.h"
#include "../util/rlutil.h"
#include "../interfaces/interfazfecha.h"

using namespace std;
using namespace rlutil;

extern const char *FILE_USUARIOS;
extern const char *FILE_PACIENTES;
extern const char *FILE_PROFESIONALES;
extern const char *FILE_COBERTURAS;
extern const char *FILE_PLANFARMACO;
extern Usuario usr_lgd;



int InterfazPlanFarmacologico :: ObtenerPlanFarmacologico(PlanFarmacologico & _planFamrma){
    Archivo planfarmas(FILE_PLANFARMACO,sizeof(PlanFarmacologico));
    return planfarmas.leerRegistro(_planFamrma);
 }


bool InterfazPlanFarmacologico :: CargarPlanFarmacologico(PlanFarmacologico & _planFarmacologico){
    InterfazFecha IF;
    ValidacionesTipoDato validaTDato;
    ValidacionesGenerales validaGeneral;
    InterfazPersona IPsna;
    char  notas[500];
    Fecha fechaEmision;

    Usuario user_aux;
    //Archivo usuarios(FILE_USUARIOS,sizeof(Usuario));
    //le seteo el user para buscarlo en el archivo
    user_aux.ChangeUserName(usr_lgd.GetUserNamee());
    IPsna.ObtenerUsuario(user_aux);
    //Seteo el ID del usr logueado -> UN profesional
    _planFarmacologico.SetIdProfesional(user_aux.GetIdPersona());

    cout<<"FECHA DE EMISION (Automatica): ";
    cout<<IF.GetfechaFormateada(fechaEmision.GetFechaActual());
    _planFarmacologico.SetEmision(fechaEmision.GetFechaActual());
    cout<<endl<<endl;
    cout<<"NOTAS";
    cout << endl << "> ";
    cin.clear();
    cin.ignore();
    cin.getline(notas,500);
    _planFarmacologico.SetNotas(notas);
    cls();
    cout<<"DEBE RELACIONAR UN PACIENTE AL PLAN"<<endl<<endl;
    do{
        InterfazPaciente IP;
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
    ///*************** ESTO NO DEBERIA SER NECESARIO, EN OCASIONES DA ERROR SI SE SACA, CONSULTAR ********/
        Archivo pacientes(FILE_PACIENTES,sizeof(Paciente));
        //si existe en el archivo, entonces el ID esta OK
        int posPac = IPsna.ObtenerPaciente(paciente);
        if (posPac >= 0 ){
            _planFarmacologico.SetIdPaciente(paciente.GetId());
            validaTDato.generar_Mensaje(2,"PACIENTE ASIGNADO EXITOSAMENTE!");
            system("PAUSE");
            return true;
            //si el prof no existe
            }else{
                    validaTDato.generar_Mensaje(0,"EL ID INGRESADO DEL PACIENTE ES INCORRECTO");
                    system("PAUSE");
                 }
    }while(true);
    return false;
}


void InterfazPlanFarmacologico :: MostrarPlanFarmacologico(PlanFarmacologico _planFarmacologico){
    InterfazPersona interfazPersona;
    Profesional profesional;
    Paciente paciente;
    cout << left;
    if (_planFarmacologico.GetId() != -1)
        cout << setw(4)  << _planFarmacologico.GetId();
    else
        cout << setw(4)  << " - ";

    paciente.SetId(_planFarmacologico.GetIdPaciente());
    interfazPersona.ObtenerPaciente(paciente);
    cout << setw(10)  << paciente.GetNombres();
    cout << setw(10)  << paciente.GetApellidos();

    profesional.SetId(_planFarmacologico.GetIdProfesional() );
    interfazPersona.ObtenerProfesional(profesional);
    cout << setw(10)  << profesional.GetNombres();
    cout << setw(10)  << profesional.GetApellidos();

    cout << setw(50)  << _planFarmacologico.GetNotas();

    cout<<endl;
};

void InterfazPlanFarmacologico :: ListarPlanesFarmacologicos(){

    PlanFarmacologico planFarma;
    ValidacionesTipoDato validaTDato;
    Archivo planesfarmaco(FILE_PLANFARMACO,sizeof(planFarma),true);
    if( planesfarmaco.getCantidadRegistros() != 0){

        cout << left;
        cout << setw(4)  << "ID";
        cout << setw(20) << "PACIENTE";
        cout << setw(20) << "PROFESIONAL";
        cout << setw(50) << "NOTAS";
        cout << endl;

        while(fread(&planFarma,sizeof(planFarma),1,planesfarmaco.GetPF())){
        if (planFarma.GetIdProfesional() == usr_lgd.GetIdPersona() && usr_lgd.GetPerfilUser() == Perfil_Profesional ||
            planFarma.GetIdPaciente() == usr_lgd.GetIdPersona() && usr_lgd.GetPerfilUser() == Perfil_Paciente)
             MostrarPlanFarmacologico(planFarma);


        };
    }else validaTDato.generar_Mensaje(2,"NO EXISTEN PLANES FARMACOLOGICOS CARGADOS EN EL SISTEMA");
    cout<<endl<<endl;
    system("PAUSE");
    return;
};

void InterfazPlanFarmacologico :: AgregarPlanFarmacologicoAArchivo(PlanFarmacologico _planFarmacologico){
    cls();
    ValidacionesGenerales valGral;
    cout << left;
    cout << setw(4)  << "ID";
    cout << setw(20) << "PACIENTE";
    cout << setw(20) << "PROFESIONAL";
    cout << setw(50) << "NOTAS";
    cout << endl;

    MostrarPlanFarmacologico(_planFarmacologico);
    cout<<endl<<endl;
    cout<<"ESTA SEGURO QUE DESEA AGREGAR EL SIGUIENTE PLAN FARMACOLOGICO? S/N";
    if(valGral.leer_SoN())
    {
        Archivo planesfarmacologicos(FILE_PLANFARMACO,sizeof(PlanFarmacologico));
        if(planesfarmacologicos.grabarRegistro(_planFarmacologico,-1) == 1)
            cout<<"SE GRABO SATISFACTORIAMENTE EL PROFESIONAL CARGADO"<<endl;
        else
            cout<<"NO SE PUDO GRABAR SATISFACTORIAMENTE EL PROFESIONAL CARGADO"<<endl;
    }
    cout<<endl;
    system("PAUSE");

};

