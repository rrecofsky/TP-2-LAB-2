
#include "../validaciones/validaciones.h"
#include "../modelos/archivo.h"
#include "../util/rlutil.h"
#include "../interfaces/interfazinforme.h"
#include "../interfaces/interfazfecha.h"

using namespace std;
using namespace rlutil;
extern const char *FILE_INFORMES;


int InterfazInforme :: ObtenerInforme(Informe & _informe){
    Archivo informes(FILE_INFORMES,sizeof(Informe),true);
    return informes.leerRegistro(_informe);
}


bool InterfazInforme :: CargarInforme(Informe & _informe){
    ///TERMINAR!
    ValidacionesTipoDato validaTDato;
    char detalle[100] = {};
    system("cls");

    cout<<"INGRESE EL DETALLE DEL INFORME: "<<endl;
    cin.clear();
    cin.ignore();
    cout << endl << "> ";
    cin.getline(detalle,100);
    _informe.SetDetalle(detalle);



    cout<<endl;
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
//    itfzProf.ObtenerProfesional(prof);
    pac.SetId(_informe.GetIdPaciente());
//    itfzPac.ObtenerPaciente(pac);
    cout << left;
    if (_informe.GetId() != -1)
        cout << setw(4)  << _informe.GetId();
    else
        cout << setw(4)  << " - ";

    cout << setw(20)  << IF.GetfechaFormateada( _informe.GetFechaEmision());
    cout << setw(20)  << (string)prof.GetNombres() + (string)prof.GetApellidos();
    cout << setw(20)  << prof.GetApellidos();
    cout << setw(50)  << _informe.GetDetalle();
};


void InterfazInforme :: ListarInformes(){

    Informe informe;
    ValidacionesTipoDato validaTDato;
    Archivo informes(FILE_INFORMES,sizeof(Informe),true);
    if( informes.getCantidadRegistros() != 0){

        cout << left;
        cout << setw(4)  << "ID";
        cout << setw(20) << "F. EMISION";
        cout << setw(20) << "PROFESIONAL";
        cout << setw(20) << "PACIENTE";
        cout << setw(50) << "DETALLE";
        cout << endl;

        while(fread(&informe,sizeof(Informe),1,informes.GetPF()))
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


