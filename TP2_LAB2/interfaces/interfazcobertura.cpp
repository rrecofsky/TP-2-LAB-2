#include "../validaciones/validaciones.h"
#include "../modelos/cobertura.h"
#include "../modelos/archivo.h"
#include "../util/rlutil.h"
#include "../interfaces/interfazcobertura.h"

using namespace std;
using namespace rlutil;
extern const char *FILE_COBERTURAS;


int InterfazCobertura :: ObtenerCobertura(Cobertura & _cobertura){
    Archivo coberturas(FILE_COBERTURAS,sizeof(Cobertura));
    return coberturas.leerRegistro(_cobertura);
}


bool InterfazCobertura :: CargarCobertura(Cobertura & _cobertura){
    ValidacionesTipoDato validaTDato;
    char cobertura[50] = {};
    system("cls");
    do{
        cout<<"INGRESE EL NOMBRE DE LA COBERTURA: "<<endl;
        cin.clear();
        cin.ignore();
        cout << endl << "> ";
        cin.getline(cobertura,50);
        _cobertura.SetNombre(cobertura);
        if (!CompararForeignKey( &_cobertura) )
            break;
        else{
                validaTDato.generar_Mensaje(0,"YA EXISTE UNA COBERTURA CON ESE NOMBRE, REINGRESE NUEVAMENTE");
                cout<<endl;
                system("PAUSE");
                system("cls");
            }

    }while(true);
    return true;
}


void InterfazCobertura :: MostrarCobertura(Cobertura _cobertura){
    char presentacion[50], fabrica[10];
    cout << left;
    if (_cobertura.GetId() != -1)
        cout << setw(4)  << _cobertura.GetId();
    else
        cout << setw(4)  << " - ";

    cout << setw(20)  << _cobertura.GetNombre();
};


void InterfazCobertura :: ListarCoberturas(){

    Cobertura cobertura;
    ValidacionesTipoDato validaTDato;
    Archivo coberturas(FILE_COBERTURAS,sizeof(Cobertura),true);
    if( coberturas.getCantidadRegistros() != 0){

        cout << left;
        cout << setw(4)  << "ID";
        cout << setw(20) << "COBERTURA";
        cout << endl;

        while(fread(&cobertura,sizeof(Cobertura),1,coberturas.GetPF()))
             MostrarCobertura(cobertura);

    }else validaTDato.generar_Mensaje(2,"NO EXISTEN COBERTURAS CARGADAS EN EL SISTEMA");
    cout<<endl<<endl;
    system("PAUSE");
    return;
}


void InterfazCobertura :: AgregarCoberturaAArchivo(Cobertura _cobertura){
    cls();
    ValidacionesGenerales valGral;
    ValidacionesTipoDato validaTDato;
    cout << left;
        cout << setw(4)  << "ID";
        cout << setw(20) << "COBERTURA";
        cout << endl;

    MostrarCobertura(_cobertura);
    cout<<endl<<endl;
    cout<<endl<<"ESTA SEGURO QUE DESEA AGREGAR LA SIGUIENTE COBERTURA? S/N";
    if(valGral.leer_SoN())
    {
        Archivo coberturas(FILE_COBERTURAS,sizeof(Cobertura));
        if(coberturas.grabarRegistro(_cobertura,-1) == 1)
            validaTDato.generar_Mensaje(2,"SE GRABO SATISFACTORIAMENTE LA COBERTURA CARGADA");
        else
            validaTDato.generar_Mensaje(0,"NO SE PUDO GRABAR SATISFACTORIAMENTE LA COBERTURA");
    }
    cout<<endl;
    system("PAUSE");

};




