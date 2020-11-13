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

void InterfazPlanFarmacologico :: CargarPlanFarmacologico(PlanFarmacologico & _planFarmacologico){
    InterfazFecha IF;
    ValidacionesTipoDato validaTDato;
    ValidacionesGenerales validaGeneral;
    char  notas[500];
    Fecha fechaEmision;
    Usuario user_aux;
    Archivo usuarios(FILE_USUARIOS,sizeof(Usuario));
    user_aux.ChangeUserName(usr_lgd.GetUserNamee());//le seteo el user para buscarlo en el archivo
    int posUsuario = usuarios.buscarRegistro(user_aux);
    _planFarmacologico.SetIdProfesional(user_aux.GetIdPersona());//si encuentra el ID, lo relaciono
    char nombres[50], apellidos[50];
    cout<<"FECHA DE EMISION (Automatica)"<<endl;
    cout<<IF.GetfechaFormateada(fechaEmision);
    _planFarmacologico.SetEmision(fechaEmision.GetFechaActual());
    cout<<endl;
    cout<<"NOTAS";
    cout << endl << "> ";
    cin.clear();
    cin.ignore();
    cin.getline(apellidos,500);
    _planFarmacologico.SetNotas(notas);

    cout<<"DESEA RELACIONAR UN PACIENTE AL USUARIO? S/N";
          if (validaGeneral.leer_SoN()){
              //busco los pacientes del archivo
              Archivo pacientes(FILE_PACIENTES,sizeof(Paciente));
              Paciente paciente;
              cout<<"PACIENTES DISPONIBLES"<<endl<<endl;
              //listo los pacientes
              InterfazPaciente IP;
              IP.ListarPacientes();
              cout<<"INGRESE EL ID DEL PACIENTE QUE DESEA RELACIONAR: ";
              //ingreso el ID del paciente que quiero buscar
              paciente.SetId(validaTDato.cargar_Entero());
              //si existe en el archivo, entonces el ID esta OK
              int posPaciente = pacientes.buscarRegistro(paciente);
              //le relaciono el ID del paciente al usuario
              if (posPaciente >= 0 ) _planFarmacologico.SetIdPaciente(paciente.GetId());
    }
    return;
}


void InterfazPlanFarmacologico :: MostrarPlanFarmacologico(PlanFarmacologico _planFarmacologico){
    InterfazPersona interfazPersona;
    Persona paciente, profesional;
    cls();
    cout << left;
    cout << setw(12)  << "PACIENTE";
    cout << setw(12)  << "PROFESIONAL";
    cout << setw(12)  << "NOTAS";
    cout << endl;
    cout << left;
//    interfazPersona.AsociarPersona(_planFarmacologico.GetIdPaciente());
    cout << setw(6)  << paciente.GetNombres();
    cout << setw(6)   << paciente.GetApellidos();
    interfazPersona.AsociarPersona(profesional);
    cout << setw(6)  << profesional.GetNombres();
    cout << setw(6)   << profesional.GetApellidos();
    cout << setw(12) <<_planFarmacologico.GetNotas();
    cout<<endl;
};

void InterfazPlanFarmacologico :: AgregarPlanFarmacologicoAArchivo(PlanFarmacologico _planFarmacologico){
    cls();
    ValidacionesGenerales valGral;
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

