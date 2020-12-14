
#include "../validaciones/validaciones.h"
#include "../modelos/archivo.h"
#include "../util/rlutil.h"
#include "../interfaces/interfazinforme.h"
#include "../interfaces/interfazfecha.h"
#include "../interfaces/interfazentidades.h"

using namespace std;
using namespace rlutil;
extern const char *FILE_INFORMES;

extern Usuario usr_lgd;

int InterfazInforme :: ObtenerInforme(Informe & _informe){
    Archivo informes(FILE_INFORMES,sizeof(Informe),true);
    return informes.leerRegistro(_informe);
}


bool InterfazInforme :: CargarInforme(Informe & _informe){

    InterfazPaciente itfzPac;

    if (itfzPac.GetCantidadPacientes() == 0 ){
        cout<<"NO EXISTEN PACIENTES CARGADOS EN EL SISTEMA"<<endl;
        system("PAUSE"); system("cls");
        return false;
    }

    InterfazProfesional itfzProf;
    ValidacionesTipoDato validaTDato;
    ValidacionesGenerales validaGeneral;
    char detalle[100] = {};
    system("cls");
    Fecha fecha;

    _informe.SetFechaEmision( fecha.GetFechaActual() );

    do{
        cout<<"NRO DE INFORME: "<<endl;
        _informe.SetNroInforme( validaTDato.cargar_Entero() );
        if (!CompararForeignKey( &_informe ))
            break;
        else{
                validaTDato.generar_Mensaje(0,"YA EXISTE UN INFORME CON ESE NRO, REINGRESE NUEVAMENTE");
                cout<<endl;
                system("PAUSE");
                system("cls");
            }

    }while(true);

    cout<<"INGRESE EL DETALLE DEL INFORME: "<<endl;
    cin.clear();
    cin.ignore();
    cout << endl << "> ";
    cin.getline(detalle,100);
    _informe.SetDetalle(detalle);

     Paciente paciente;

     vector<int> vecList;
     do{
            cout<<"PACIENTES DISPONIBLES"<<endl<<endl;
            itfzPac.ListarPacientesConFiltro(vecList,Sin_Filtro);
            cout<<"INGRESE EL ID DEL PACIENTE: ";
            paciente.SetId(validaTDato.cargar_Entero());
            if (!VerficicarOpcionListada(vecList,paciente.GetId())){
                cout<<"EL ID INGRESADO NO SE ENCUENTRA EN LA LISTA, DESEA SALIR? S/N"<<endl;
                if (validaGeneral.leer_SoN()) return false;
                system("PAUSE"); system("cls");
            }
            _informe.SetIdPaciente(paciente.GetId());
            break;
        }while(true);

    _informe.SetIdProfesional( usr_lgd.GetIdPersona()  );
     /// analizar si corresponde
     /*
     Profesional profesional;
     vecList.clear();
     do{
            cout<<"PROFESIONALES DISPONIBLES"<<endl<<endl;
            itfzProf.ListarProfesionalesConFiltro(vecList,Sin_Filtro);
            cout<<"INGRESE EL ID DEL PROFESIONAL: ";
            profesional.SetId(validaTDato.cargar_Entero());
            if (!VerficicarOpcionListada(vecList,profesional.GetId())){
                cout<<"EL ID INGRESADO NO SE ENCUENTRA EN LA LISTA, DESEA SALIR? S/N"<<endl;
                if (validaGeneral.leer_SoN()) return false;
                system("PAUSE"); system("cls");
            }
            _informe.SetIdProfesional(profesional.GetId());
            break;
        }while(true);
        cout<<endl;
    */
    system("PAUSE");
    system("cls");
    return true;
}


void InterfazInforme :: MostrarInforme(Informe _informe){
    InterfazFecha IF;
    InterfazProfesional itfzProf;
    InterfazPaciente    itfzPac;
    Profesional prof;
    Paciente pac;
    prof.SetId(_informe.GetIdProfesional());
    itfzProf.ObtenerProfesional(prof);
    pac.SetId(_informe.GetIdPaciente());
    itfzPac.ObtenerPaciente(pac);
    cout << left;
    if (_informe.GetId() != -1)
        cout << setw(4)  << _informe.GetId();
    else
        cout << setw(4)  << " - ";

    cout << setw(10)  << _informe.GetNroInforme();
    cout << setw(20)  << IF.GetfechaFormateada( _informe.GetFechaEmision());
    cout << setw(20)  << (string)prof.GetNombres() + (string)prof.GetApellidos();
    cout << setw(20)  << (string)prof.GetApellidos() + (string)pac.GetApellidos() ;
    cout << setw(50)  << _informe.GetDetalle();
};


void InterfazInforme :: ListarInformes(){

    Informe informe;
    ValidacionesTipoDato validaTDato;
    Archivo informes(FILE_INFORMES,sizeof(Informe),true);
    if( informes.getCantidadRegistros() != 0){

        cout << left;
        cout << setw(4)  << "ID";
        cout << setw(10) << "NRO. INFORME";
        cout << setw(20) << "F. EMISION";
        cout << setw(20) << "PROFESIONAL";
        cout << setw(20) << "PACIENTE";
        cout << setw(50) << "DETALLE";
        cout << endl;

        while(fread(&informe,sizeof(Informe),1,informes.GetPF()))

        if (informe.GetIdProfesional() == usr_lgd.GetIdPersona() && usr_lgd.GetPerfilUser() == Perfil_Profesional)
        // || planFarma.GetIdPaciente() == usr_lgd.GetIdPersona() && usr_lgd.GetPerfilUser() == Perfil_Paciente)

             MostrarInforme(informe);

    }else validaTDato.generar_Mensaje(2,"NO EXISTEN INFORMES CARGADOS EN EL SISTEMA");
    cout<<endl<<endl;
    system("PAUSE");
    return;
}


void InterfazInforme :: AgregarInformeAArchivo(Informe _informe){
    cls();
    ValidacionesGenerales valGral;
    ValidacionesTipoDato validaTDato;

    cout << left;
    cout << setw(4)  << "ID";
    cout << setw(10) << "NRO. INFORME";
    cout << setw(20) << "F. EMISION";
    cout << setw(20) << "PROFESIONAL";
    cout << setw(20) << "PACIENTE";
    cout << setw(50) << "DETALLE";
    cout << endl;

    MostrarInforme(_informe);
    cout<<endl<<endl;
    cout<<endl<<"ESTA SEGURO QUE DESEA AGREGAR EL SIGUIENTE INFORME? S/N";
    if(valGral.leer_SoN())
    {
        Archivo informes(FILE_INFORMES,sizeof(Informe));
        if(informes.grabarRegistro(_informe,-1) == 1)
            validaTDato.generar_Mensaje(2,"SE GRABO SATISFACTORIAMENTE EL INFORME");
        else
            validaTDato.generar_Mensaje(0,"NO SE PUDO GRABAR SATISFACTORIAMENTE EL INFORME");
    }
    cout<<endl;
    system("PAUSE");

};


void InterfazInforme :: ListarInformesConFiltro(vector<int> & _vec){
    Archivo informes(FILE_INFORMES,sizeof(Informe),true);
    ValidacionesTipoDato validaTDato;
    Informe informe;
    if( informes.getCantidadRegistros() != 0){
        cout << left;
        cout << setw(4)  << "ID";
        cout << setw(10) << "NRO. INFORME";
        cout << setw(20) << "F. EMISION";
        cout << setw(20) << "PROFESIONAL";
        cout << setw(20) << "PACIENTE";
        cout << setw(50) << "DETALLE";
        cout << endl;
        while(fread(&informe,sizeof(Informe),1,informes.GetPF())){
                _vec.push_back(informe.GetId());
                MostrarInforme(informe);
        }

    }else  validaTDato.generar_Mensaje(1,"NO EXISTEN INFORMES CARGADOS EN EL SISTEMA");
    cout<<endl<<endl;
    system("PAUSE");
    return;
}
