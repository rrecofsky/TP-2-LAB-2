#include "../validaciones/validaciones.h"
#include "../modelos/fecha.h"
#include "../modelos/farmacos_del_medicamento.h"
#include "../util/rlutil.h"
#include "../interfaces/interfazmedicamento.h"
#include "../interfaces/interfazfecha.h"
#include "../interfaces/interfazfarmaco.h"
#include "../interfaces/interfazfarmacosdelmedicamento.h"


using namespace std;
using namespace rlutil;

extern const char *FILE_MEDICAMENTOS;
extern const char *FILE_FARMACOSDELMEDICAMENTO;
extern Usuario usr_lgd;

int InterfazMedicamento :: GetCantidadMedicamentos(){
    Archivo medicamentos(FILE_MEDICAMENTOS,sizeof(Medicamento),true);
    return medicamentos.getCantidadRegistros() ;
}

int InterfazMedicamento :: ObtenerMedicamento(Medicamento & _medicamento){
    Archivo medicamentos(FILE_MEDICAMENTOS,sizeof(Medicamento),true);
    return medicamentos.leerRegistro(_medicamento);
}


bool InterfazMedicamento :: CargarMedicamento(Medicamento & _medicamento, vector<int> & vecFarmARelacionar){

    InterfazFarmaco itfzFarm;

    if (itfzFarm.GetCantidadFarmacos() == 0 ){
        cout<<"NO EXISTEN FARMACOS CARGADOS EN EL SISTEMA"<<endl;
        system("PAUSE"); system("cls");
        return false;
    }
    InterfazFecha IF;
    ValidacionesTipoDato validaTDato;
    ValidacionesGenerales validaGeneral;
    char cadena[50] = {};
    system("cls");
    cout<<"DEBE RELACIONAR UN O MAS FARMACOS AL MEDICAMENTO, FARMCOS DISPONIBLES: "<<endl<<endl;
    Farmaco farmaco;
    vector<int> vecFar;
    itfzFarm.ListarFarmacosConFiltro(vecFar);

    cout<<"DESEA ASIGNARLE UNO DE LOS FARMACOS DISPONIBLES? S/N"<<endl;
    if (!validaGeneral.leer_SoN()) return false;
    do{
        cout<<"INGRESE EL ID DEL FARMACO QUE DESEA RELACIONAR: ";
        farmaco.SetId(validaTDato.cargar_Entero());
        if (!VerficicarOpcionListada(vecFar,farmaco.GetId())){
            validaTDato.generar_Mensaje(0,"EL ID INGRESADO NO SE ENCUENTRA EN LA LISTA, DESEA SALIR? S/N");
            if (validaGeneral.leer_SoN()) return false;
        }else {
                vecFarmARelacionar.push_back(farmaco.GetId());
                EliminarDuplicadosDelVector(vecFarmARelacionar);
                cout<<"DESEA RELACIONAR OTRO FARMACO: S/N "<<endl;
                if ( !validaGeneral.leer_SoN()) break;
              }
    }while(true);
    cout<<endl;
    cout<<"INGRESE LA ACCION TERAPEUTICA: "<<endl;
    cout << endl << "> ";
    cin.clear();
    cin.ignore();
    cin.getline(cadena,50);
    _medicamento.SetaccionTerapeutica(cadena);
    cout<<"INGRESE EL TIPO DE PRESENTACION: 0->CAPSULAS, 1->COMPRIMIDOS "<<endl;
    _medicamento.SetIdPresentacion( validaGeneral.ValidarOpciones(0,1,"INGRESE UN VALOR ENTRE 0 Y 1") );
    cout<<"INGRESE LA DOSIS: "<<endl;
    _medicamento.SetDosis( validaTDato.cargar_Entero() );
    cout<<"INGRESE LA FECHA DE VENCIMIENTO: "<<endl;
    Fecha fechaAux;
    cout<<"INGRESE EL DIA";
    fechaAux.SetDia(validaGeneral.ValidarDia());
    cout<<"INGRESE EL MES";
    fechaAux.SetMes(validaGeneral.ValidarMes());
    cout<<"INGRESE EL ANIO";
    fechaAux.SetAnio(validaTDato.cargar_Entero() );
    _medicamento.SetFechaVencimiento(fechaAux);
    return true;
}

void InterfazMedicamento :: MostrarMedicamento(Medicamento _medicamento){
    char presentacion[50] = {}, fabrica[10] = {};
    InterfazFecha IF;
    InterfazFarmacosDelMedicamento itfzFarmDelMed;
    cout << left;
    if (_medicamento.GetId() != -1)
        cout << setw(4)  << _medicamento.GetId();
    else
        cout << setw(4)  << " - ";

    cout << setw(15)  << strcat(presentacion, (char*)_medicamento.GetIdPresentacion() == 0 ? "Capsulas" : "Comprimidos" );
    cout << setw(10)  << _medicamento.GetDosis();
    cout << setw(20)  << IF.GetfechaFormateada( _medicamento.GetFechaVecimiento());
    cout << setw(20)  << _medicamento.GetaccionTerapeutica();
    cout << setw(30)  << itfzFarmDelMed.ObtenerStrFarmacosSeparadosPorComa(_medicamento.GetId());

};


void InterfazMedicamento :: ListarMedicamentos(){

    Medicamento medicamento;
    ValidacionesTipoDato validaTDato;
    Archivo medicamentos(FILE_MEDICAMENTOS,sizeof(medicamento),true);
    if( medicamentos.getCantidadRegistros() != 0){

        cout << left;
        cout << setw(4)  << "ID";
        cout << setw(15) << "PRESENTACION";
        cout << setw(10) << "DOSIS";
        cout << setw(20) << "FECHA VENCIMIENTO";
        cout << setw(20) << "ACCION TERAPEUTICA";
        cout << setw(30) << "FARMACOS ASOCIADOS";
        cout << endl;

        while(fread(&medicamento,sizeof(medicamento),1,medicamentos.GetPF())){
                MostrarMedicamento(medicamento);
                cout<<endl;

        }


    }else validaTDato.generar_Mensaje(2,"NO EXISTEN MEDICAMENTOS CARGADOS EN EL SISTEMA");
    cout<<endl<<endl;
    system("PAUSE");
    return;
};


void InterfazMedicamento :: AgregarMedicamentoAArchivo(Medicamento _medicamento,  vector<int>  vecFarmARelacionar){
    cls();
    ValidacionesGenerales valGral;
    ValidacionesTipoDato validaTDato;
    cout << left;
        cout << setw(4)  << "ID";
        cout << setw(15) << "PRESENTACION";
        cout << setw(10) << "DOSIS";
        cout << setw(20) << "FECHA VENCIMIENTO";
        cout << setw(20) << "ACCION TERAPEUTICA";
        if (_medicamento.GetId() != -1)
            cout << setw(30) << "FARMACOS ASOCIADOS";
        cout << endl;

    MostrarMedicamento(_medicamento);
    cout<<endl<<endl;
    cout<<"ESTA SEGURO QUE DESEA AGREGAR EL SIGUIENTE MEDICAMENTO? S/N";
    if(valGral.leer_SoN())
    {
        farmacos_del_medicamento farmacosDelMedicamento;
        Archivo medicamentos(FILE_MEDICAMENTOS,sizeof(Medicamento),true);
        Archivo farmacosDelMed(FILE_FARMACOSDELMEDICAMENTO, sizeof(farmacos_del_medicamento),true);
        cout<<"Guardando farmacos del medicamento ... "<<endl<<endl;
        for ( size_t i=0; i < vecFarmARelacionar.size(); i++){
            farmacosDelMedicamento.setIdFarmaco( vecFarmARelacionar[i] );
            farmacosDelMedicamento.setIdMedicamento(  medicamentos.getCantidadRegistros() );
            farmacosDelMed.grabarRegistro(farmacosDelMedicamento,-1);
        }
        if(medicamentos.grabarRegistro(_medicamento,-1) == 1)
            validaTDato.generar_Mensaje(2,"SE GRABO SATISFACTORIAMENTE EL MEDICAMENTO CARGADO");
        else
             validaTDato.generar_Mensaje(0,"SE PUDO GRABAR SATISFACTORIAMENTE EL MEDICAMENTO CARGADO");
    }
    cout<<endl;
    system("PAUSE");

};

void InterfazMedicamento :: ListarMedicamentosConFiltro(vector<int> & _vec){
    Archivo medicamentos(FILE_MEDICAMENTOS,sizeof(Medicamento),true);
    ValidacionesTipoDato validaTDato;
    Medicamento medicamento;
    if( medicamentos.getCantidadRegistros() != 0){
        cout << setw(4)  << "ID";
        cout << setw(15) << "PRESENTACION";
        cout << setw(10) << "DOSIS";
        cout << setw(20) << "FECHA VENCIMIENTO";
        cout << setw(20) << "ACCION TERAPEUTICA";
        cout << setw(30) << "FARMACOS ASOCIADOS";
        cout << endl;
        while(fread(&medicamento,sizeof(Medicamento),1,medicamentos.GetPF())){
                _vec.push_back(medicamento.GetId());
                MostrarMedicamento(medicamento);
                cout<< endl;
        }

    }else  validaTDato.generar_Mensaje(1,"NO EXISTEN MEDICAMENTOS CARGADOS EN EL SISTEMA");
    cout<<endl<<endl;
    system("PAUSE");
    return;
}
