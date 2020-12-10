#include "../validaciones/validaciones.h"
#include "../modelos/especialidad.h"
#include "../modelos/archivo.h"
#include "../util/rlutil.h"
#include "../interfaces/interfazespecialidad.h"

using namespace std;
using namespace rlutil;
extern const char *FILE_ESPECIALIDADES;


int InterfazEspecialidad :: ObtenerEspecialidad(Especialidad & _especialidad){
    Archivo especialidades(FILE_ESPECIALIDADES,sizeof(Especialidad),true);
    return especialidades.leerRegistro(_especialidad);
}


bool InterfazEspecialidad :: CargarEspecialidad(Especialidad & _especialidad){
    ValidacionesTipoDato validaTDato;
    char especialidad[50] = {};
    system("cls");
    do{
        cout<<"INGRESE EL NOMBRE DE LA ESPECIALIDAD: "<<endl;
        cin.clear();
        cin.ignore();
        cout << endl << "> ";
        cin.getline(especialidad,50);
        _especialidad.SetNombre(especialidad);
        if (!CompararForeignKey( &_especialidad) )
            break;
        else{
                validaTDato.generar_Mensaje(0,"YA EXISTE UNA ESPECIALIDAD CON ESE NOMBRE, REINGRESE NUEVAMENTE");
                cout<<endl;
                system("PAUSE");
                system("cls");
            }

    }while(true);
    return true;
}


void InterfazEspecialidad :: MostrarEspecialidad(Especialidad _especialidad){
    cout << left;
    if (_especialidad.GetId() != -1)
        cout << setw(4)  << _especialidad.GetId();
    else
        cout << setw(4)  << " - ";

    cout << setw(20)  << _especialidad.GetNombre();
};


void InterfazEspecialidad :: ListarEspecialidades(){

    Especialidad especialidad;
    ValidacionesTipoDato validaTDato;
    Archivo especialidades(FILE_ESPECIALIDADES,sizeof(Especialidad),true);
    if( especialidades.getCantidadRegistros() != 0){

        cout << left;
        cout << setw(4)  << "ID";
        cout << setw(20) << "ESPECIALIDAD";
        cout << endl;

        while(fread(&especialidad,sizeof(Especialidad),1,especialidades.GetPF()))
             MostrarEspecialidad(especialidad);

    }else validaTDato.generar_Mensaje(2,"NO EXISTEN ESPECIALIDADES CARGADAS EN EL SISTEMA");
    cout<<endl<<endl;
    system("PAUSE");
    return;
}


void InterfazEspecialidad :: AgregarEspecialidadAArchivo(Especialidad _especialidad){
    cls();
    ValidacionesGenerales valGral;
    ValidacionesTipoDato validaTDato;
    cout << left;
        cout << setw(4)  << "ID";
        cout << setw(20) << "ESPECIALIDAD";
        cout << endl;

    MostrarEspecialidad(_especialidad);
    cout<<endl<<endl;
    cout<<endl<<"ESTA SEGURO QUE DESEA AGREGAR LA SIGUIENTE ESPECIALIDAD? S/N";
    if(valGral.leer_SoN())
    {
        Archivo especialidades(FILE_ESPECIALIDADES,sizeof(Especialidad));
        if(especialidades.grabarRegistro(_especialidad,-1) == 1)
            validaTDato.generar_Mensaje(2,"SE GRABO SATISFACTORIAMENTE LA ESPECIALIDAD CARGADA");
        else
            validaTDato.generar_Mensaje(0,"NO SE PUDO GRABAR SATISFACTORIAMENTE LA ESPECIALIDAD");
    }
    cout<<endl;
    system("PAUSE");

};


/// new

void InterfazEspecialidad :: ModificarEspecialidad(Especialidad & _especialidad){
        CargarEspecialidad(_especialidad);
        return ;

}

void InterfazEspecialidad :: ActualizarEspecialidad(Especialidad _esp, int _pos){
    Archivo especialidades(FILE_ESPECIALIDADES,sizeof(Especialidad));
    especialidades.grabarRegistro(_esp,_pos);
}


void InterfazEspecialidad :: ModificarEspecialidadEnArchivo(Especialidad _especialidad){
    ValidacionesGenerales valGral;
    ValidacionesTipoDato validaTDato;
    Archivo especialidades(FILE_ESPECIALIDADES,sizeof(Especialidad));
    int posEsp = especialidades.buscarRegistro(_especialidad);
    if ( posEsp != -1 && especialidades.leerRegistro(_especialidad, posEsp) != -1){
        MostrarEspecialidad(_especialidad);
        cout<<endl<<endl;
        cout<<"ESTA SEGURO QUE DESEA MODIFICAR LA SIGUIENTE COBERTURA? S/N"<<endl;
        if(valGral.leer_SoN())
        {
            cls();
            ModificarEspecialidad(_especialidad);
            if(especialidades.grabarRegistro(_especialidad,posEsp) == 1)
                validaTDato.generar_Mensaje(2,"SE ACTUALIZO SATISFACTORIAMENTE LA ESPECIALIDAD");
            else
            validaTDato.generar_Mensaje(0,"NO SE PUDO ACTUALIZAR SATISFACTORIAMENTE LA ESPECIALIDAD");
            cout<<endl<<endl;
            system("PAUSE");
            return;
        }
    }else{
            validaTDato.generar_Mensaje(0,"NO EXISTE UNA ESPECIALIDAD CON EL ID: ");
            cout<<_especialidad.GetId();
            cout<<endl<<endl;
            system("PAUSE");
         }
}


