#include "../validaciones/validaciones.h"
#include "../modelos/fecha.h"
#include "../modelos/archivo.h"
#include "../util/rlutil.h"
#include "../interfaces/interfazfarmaco.h"
#include "../interfaces/interfazfecha.h"


using namespace std;
using namespace rlutil;

extern const char *FILE_FARMACOS;
extern Usuario usr_lgd;


int InterfazFarmaco :: ObtenerFarmaco(Farmaco & _farmaco){
    Archivo farmacos(FILE_FARMACOS,sizeof(Farmaco));
    return farmacos.leerRegistro(_farmaco);
}

int InterfazFarmaco :: GetCantidadFarmacos(){
    Archivo farmacos(FILE_FARMACOS,sizeof(Farmaco),true);
    return farmacos.getCantidadRegistros() ;
}


bool InterfazFarmaco :: CargarFarmaco(Farmaco & _farmaco){
    ValidacionesTipoDato validaTDato;
    char farmaco[50] = {};
    system("cls");
    do{
        cout<<"INGRESE EL NOMBRE DEL FARMACO: "<<endl;
        cin.clear();
        cin.ignore();
        cout << endl << "> ";
        cin.getline(farmaco,50);
        _farmaco.SetNombre(farmaco);
        if (!CompararForeignKey( &_farmaco) )
            break;
        else{
                validaTDato.generar_Mensaje(0,"YA EXISTE UN FARMACO CON ESE NOMBRE, REINGRESE NUEVAMENTE");
                cout<<endl;
                system("PAUSE");
                system("cls");
            }
    }while(true);
    return true;
}


void InterfazFarmaco :: MostrarFarmaco(Farmaco _farmaco, bool mostrarEnDetalle = false){
    char presentacion[50], fabrica[10];
    InterfazFecha IF;
    cout << left;
    if (_farmaco.GetId() != -1)
        cout << setw(4)  << _farmaco.GetId();
    else
        cout << setw(4)  << " - ";

    cout << setw(20)  << _farmaco.GetNombre();
    if (!mostrarEnDetalle)
        cout<<endl;
};


void InterfazFarmaco :: ListarFarmacos(){

    Farmaco farmaco;
    ValidacionesTipoDato validaTDato;
    Archivo farmacos(FILE_FARMACOS,sizeof(Farmaco),true);
    if( farmacos.getCantidadRegistros() != 0){

        cout << left;
        cout << setw(4)  << "ID";
        cout << setw(20) << "FARMACO";
        cout << endl;

        while(fread(&farmaco,sizeof(farmaco),1,farmacos.GetPF()))
             MostrarFarmaco(farmaco);

    }else validaTDato.generar_Mensaje(2,"NO EXISTEN FARMACOS CARGADOS EN EL SISTEMA");
    cout<<endl<<endl;
    system("PAUSE");
    return;
}


void InterfazFarmaco :: AgregarFarmacoAArchivo(Farmaco _farmaco){
    cls();
    ValidacionesGenerales valGral;
    ValidacionesTipoDato validaTDato;
    cout << left;
        cout << setw(4)  << "ID";
        cout << setw(20) << "FARMACO";
        cout << endl;

    MostrarFarmaco(_farmaco);
    cout<<endl<<endl;
    cout<<"UNA VEZ PERSISTIDO ESTE REGISTRO, EL MISMO NO PODRA SER MODIFICADO";
    cout<<endl<<"ESTA SEGURO QUE DESEA AGREGAR EL SIGUIENTE FARMACO? S/N";
    if(valGral.leer_SoN())
    {
        Archivo farmacos(FILE_FARMACOS,sizeof(Farmaco));
        if(farmacos.grabarRegistro(_farmaco,-1) == 1)
            validaTDato.generar_Mensaje(2,"SE GRABO SATISFACTORIAMENTE EL FARMACO CARGADO");
        else
            validaTDato.generar_Mensaje(0,"NO SE PUDO GRABAR SATISFACTORIAMENTE EL FARMACO CARGADO");
    }
    cout<<endl;
    system("PAUSE");

};


void InterfazFarmaco :: ListarFarmacosConFiltro(vector<int> & _vec){
    Archivo farmacos(FILE_FARMACOS,sizeof(Farmaco),true);
    ValidacionesTipoDato validaTDato;
    Farmaco farmaco;
    if( farmacos.getCantidadRegistros() != 0){
        cout << setw(4)  << "ID";
        cout << setw(20) << "FARMACO";
        cout << endl;
        while(fread(&farmaco,sizeof(Farmaco),1,farmacos.GetPF())){
                _vec.push_back(farmaco.GetId());
                MostrarFarmaco(farmaco);
        }

    }else  validaTDato.generar_Mensaje(1,"NO EXISTEN FARMACOS CARGADOS EN EL SISTEMA");
    cout<<endl<<endl;
    system("PAUSE");
    return;
}



