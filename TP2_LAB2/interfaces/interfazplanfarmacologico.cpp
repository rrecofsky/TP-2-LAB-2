#include "../modelos/planfarmacologico.h"
#include "../modelos/detalleplanfarmacologico.h"
#include "../validaciones/validaciones.h"
#include "../modelos/fecha.h"
#include "../interfaces/interfazplanfarmacologico.h"
#include "../interfaces/interfazentidades.h"
#include "../util/rlutil.h"
#include "../interfaces/interfazfecha.h"
#include "../interfaces/interfazmedicamento.h"
#include "../modelos/medicamento.h"
#include "../interfaces/interfazfarmacosdelmedicamento.h"

using namespace std;
using namespace rlutil;

extern const char *FILE_USUARIOS;
extern const char *FILE_PACIENTES;
extern const char *FILE_PROFESIONALES;
extern const char *FILE_COBERTURAS;
extern const char *FILE_PLANFARMACO;
extern const char *FILE_DETALLESPLANFARMACO;
extern Usuario usr_lgd;

///************************************************************************************///
///********************************* PLAN FARMACOLOGICO *******************************///
///************************************************************************************///

 int InterfazPlanFarmacologico ::  GetCantidadPlanes(){
    Archivo planfarmas(FILE_PLANFARMACO,sizeof(PlanFarmacologico),true);
    return planfarmas.getCantidadRegistros();
 }


int InterfazPlanFarmacologico :: ObtenerPlanFarmacologico(PlanFarmacologico & _planFamrma, bool ultimo = false){
    Archivo planfarmas(FILE_PLANFARMACO,sizeof(PlanFarmacologico),true);
    if (!ultimo)
        return planfarmas.leerRegistro(_planFamrma);
    else
        _planFamrma.SetId(planfarmas.getCantidadRegistros()-1);

    return planfarmas.leerRegistro(_planFamrma);
 }


bool InterfazPlanFarmacologico :: CargarPlanFarmacologico(PlanFarmacologico & _planFarmacologico){

    InterfazPaciente itfzPac;
    InterfazMedicamento itfzMed;

    if (itfzPac.GetCantidadPacientes() == 0 ){
        cout<<"NO EXISTEN PACIENTES CARGADOS EN EL SISTEMA"<<endl;
        system("PAUSE"); system("cls");
        return false;
    }

    if (itfzMed.GetCantidadMedicamentos() == 0 ){
        cout<<"NO EXISTEN MEDICAMENTOS CARGADOS EN EL SISTEMA"<<endl;
        system("PAUSE"); system("cls");
        return false;
    }

    cout<<"DEBE RELACIONAR UN PACIENTE AL PLAN, PACIENTES DISPONIBLERS:"<<endl<<endl;
    vector<int> vecPac;
    itfzPac.ListarPacientesConFiltro(vecPac,Sin_Filtro);


    InterfazFecha IF;
    ValidacionesTipoDato validaTDato;
    ValidacionesGenerales validaGeneral;
    InterfazUsuario itfzUser;
    char  notas[500];
    Fecha fechaEmision;

    Usuario user_aux;
    user_aux.ChangeUserName(usr_lgd.GetUserNamee());
    itfzUser.ObtenerUsuario(user_aux);

    Paciente paciente;

    cout<<"DESEA ASIGNARLE UNO DE LOS PACIENTES DISPONIBLES? S/N"<<endl;
    if (!validaGeneral.leer_SoN()) return false;
    do{
            do{
                cout<<"INGRESE EL ID DEL PACIENTE QUE DESEA RELACIONAR: ";
                paciente.SetId(validaTDato.cargar_Entero());
                if (!VerficicarOpcionListada(vecPac,paciente.GetId())){
                    cout<<"EL ID INGRESADO NO SE ENCUENTRA EN LA LISTA, DESEA SALIR? S/N"<<endl;
                    if (validaGeneral.leer_SoN()) return false;
                    system("cls");
                }
                break;
            } while(true);
        cout<<endl;
        int posPac = itfzPac.ObtenerPaciente(paciente);
        if (posPac >= 0 ){
            _planFarmacologico.SetIdPaciente(paciente.GetId());
            validaTDato.generar_Mensaje(2,"PACIENTE ASIGNADO EXITOSAMENTE!");
            system("PAUSE");
            system("cls");
            break;
            }else{
                    validaTDato.generar_Mensaje(0,"EL ID INGRESADO DEL PACIENTE ES INCORRECTO");
                    system("PAUSE");
                    system("cls");
                 }
    }while(true);

    system("cls");
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
    cout<<"FECHA DE FINALIZACION DEL PLAN: ";
    _planFarmacologico.SetFechaFinDelPlan(IF.CargarFecha(false));

    system("PAUSE");
    system("cls");

    if ( !AgregarPlanFarmacologicoAArchivo(_planFarmacologico) ) return false;


   // ObtenerPlanFarmacologico(_planFarmacologico,true);
   // system("cls");

    InterfazDetallePlanFarmacologico itfzDetallePlan;
    DetallePlanFarmacologico detallePlan;
    detallePlan.SetIdPlanFarmacologico( GetCantidadPlanes()-1 );

    if (itfzDetallePlan.CargarDetallePlanFarmacologico(detallePlan)){
        itfzDetallePlan.AgregarDetallePlanFarmacologicoAArchivo(detallePlan);

        Archivo planFarmaco(FILE_PLANFARMACO,sizeof(PlanFarmacologico));
        int posPlan = planFarmaco.buscarRegistro(_planFarmacologico);
        _planFarmacologico.SetIdDetallePlan(detallePlan.GetId());
        planFarmaco.grabarRegistro(_planFarmacologico,posPlan);
    }
    else
        return false;

    return true;
}


void InterfazPlanFarmacologico :: MostrarPlanFarmacologico(PlanFarmacologico _planFarmacologico){

    Profesional profesional;
    Paciente paciente;
    InterfazPaciente itfzPac;
    InterfazProfesional itfzaProf;
    InterfazFecha IF;
    Fecha fecha;
    cout << left;
    if (_planFarmacologico.GetId() != -1)
        cout << setw(4)  << _planFarmacologico.GetId();
    else
        cout << setw(4)  << " - ";

    paciente.SetId(_planFarmacologico.GetIdPaciente());
    itfzPac.ObtenerPaciente(paciente);
    string nombrePac(paciente.GetNombres()), apellidoPac(paciente.GetApellidos());
    cout << setw(20)  << nombrePac+" "+apellidoPac;

    profesional.SetId(_planFarmacologico.GetIdProfesional() );
    itfzaProf.ObtenerProfesional(profesional);
    string nombreProf(profesional.GetNombres()), apellidoProf(profesional.GetApellidos());
    cout << setw(20)  <<nombreProf+" "+apellidoProf;
    cout << setw(15)  <<(string)((IF.EsFechaPosterior( _planFarmacologico.GetFechaFinDelPlan(),fecha.GetFechaActual()) == true) ? "Activo" : "Inactivo");
    cout << setw(50)  << _planFarmacologico.GetNotas();
};


void InterfazPlanFarmacologico :: MostrarPlanConDetallePlanFarmacologicoCombinado(PlanFarmacologico _planFarmacologico, DetallePlanFarmacologico _detallePlan, Medicamento _medicamento){
    Fecha fecha;
    //detalle
    InterfazFarmacosDelMedicamento itfzFarmDelMed;
    //Plan farmaco
    Profesional profesional;
    Paciente paciente;
    InterfazPaciente itfzPac;
    InterfazProfesional itfzaProf;
    //Medicamento
    char presentacion[50] = {}, fabrica[10] = {};
    InterfazFecha IF;

    cout << left;
    ///Plan Farma

    if (usr_lgd.GetPerfilUser() == Perfil_Profesional ){
        paciente.SetId(_planFarmacologico.GetIdPaciente());
        itfzPac.ObtenerPaciente(paciente);
        string nombrePac(paciente.GetNombres()), apellidoPac(paciente.GetApellidos());
        cout << setw(20)  << nombrePac+" "+apellidoPac;
    }else{
            profesional.SetId(_planFarmacologico.GetIdProfesional() );
            itfzaProf.ObtenerProfesional(profesional);
            string nombreProf(profesional.GetNombres()), apellidoProf(profesional.GetApellidos());
            cout << setw(20)  <<nombreProf+" "+apellidoProf;
         }

    cout << setw(10)  <<(string)((IF.EsFechaPosterior( _planFarmacologico.GetFechaFinDelPlan(),fecha.GetFechaActual()) == true) ? "Activo" : "Inactivo");
    cout << setw(15)  << IF.GetfechaFormateada(_planFarmacologico.GetFechaFinDelPlan());
//  cout << setw(40)  << _planFarmacologico.GetNotas();

    ///Medicamento
    cout << setw(15)  << strcat(presentacion, (char*)_medicamento.GetIdPresentacion() == 0 ? "Capsulas" : "Comprimidos" );
    cout << setw(10)  << _medicamento.GetDosis();
    cout << setw(15)  << _medicamento.GetaccionTerapeutica();
    cout << setw(23)  << itfzFarmDelMed.ObtenerStrFarmacosSeparadosPorComa(_medicamento.GetId());

    ///Detalle del Plan

    cout << setw(5)   << _detallePlan.GetId();
    cout << setw(10)  << _detallePlan.GetDosisdiaria();
    cout << setw(15)  << _detallePlan.GetMgPorDosis();
    cout << setw(10)  << _detallePlan.GetCantComprimidos();
    cout << setw(10)  << _detallePlan.GetCantidadMgDisponibles();
    cout << setw(15)  << _detallePlan.GetCantidadDiasCubiertos();

    cout<<endl;
};


void InterfazPlanFarmacologico :: ListarPlanesFarmacosCombinados(){
    PlanFarmacologico planFarma;
    ValidacionesTipoDato validaTDato;

    InterfazDetallePlanFarmacologico itfzDetalleplanfarma;
    InterfazMedicamento itfzmed;

    Archivo planesfarmaco(FILE_PLANFARMACO,sizeof(planFarma),true);
    if( planesfarmaco.getCantidadRegistros() != 0){

        cout << left;
        if (usr_lgd.GetPerfilUser() == Perfil_Profesional )
            cout << setw(20) << "PACIENTE";
        else
            cout << setw(20) << "PROFESIONAL";
        cout << setw(10) << "ESTADO";
        cout << setw(15) << "F. FIN PLAN";
      //  cout << setw(40) << "NOTAS";

        cout << setw(15) << "PRESENTACION";
        cout << setw(10) << "MG x UN";
        cout << setw(15) << "ACCION T.";
        cout << setw(23) << "FARMACOS";

        cout << setw(5)  << "ID";
        cout << setw(10) << "DOSIS";
        cout << setw(15) << "MG./ DOSIS";
        cout << setw(10) << "COMP.";
        cout << setw(10) << "MG";
        cout << setw(15) << "DIAS CUB";

        cout << endl;

        while(fread(&planFarma,sizeof(planFarma),1,planesfarmaco.GetPF())){

        if (planFarma.GetIdProfesional() == usr_lgd.GetIdPersona() && usr_lgd.GetPerfilUser() == Perfil_Profesional ||
            planFarma.GetIdPaciente() == usr_lgd.GetIdPersona() && usr_lgd.GetPerfilUser() == Perfil_Paciente){

             Medicamento medicamento;
             DetallePlanFarmacologico detallePlan;

             detallePlan.SetIdPlanFarmacologico(planFarma.GetId());
             itfzDetalleplanfarma.ObtenerDetalleDelPlanFarmacologico(detallePlan,false);
             medicamento.SetId( detallePlan.GetIdPlanMedicamento());
             itfzmed.ObtenerMedicamento(medicamento);
/*
             system ("cls");
             cout<<"DATOS DEL DETALLE ENCONTRADO!"<<endl;
             cout<<" DETALPLAN ID: "<<detallePlan.GetId()<<endl;
             cout<<" planFarma.GetIdDetallePlan(): "<<planFarma.GetIdDetallePlan()<<endl;
             cout<<" detallePlan.GetIdPlanFarmacologico(): "<<detallePlan.GetIdPlanFarmacologico()<<endl;
             cout << "MG X DOSIS " <<detallePlan.GetMgPorDosis()<<endl;
             cout << "CANT COMP "<< detallePlan.GetCantComprimidos()<<endl;
             cout << " MG DISP "<< detallePlan.GetCantidadMgDisponibles()<<endl;
             cout << " DIAS CUB" << detallePlan.GetCantidadDiasCubiertos()<<endl;
             system("PAUSE"); system ("cls");*/

             MostrarPlanConDetallePlanFarmacologicoCombinado(planFarma,detallePlan,medicamento);

            }


        };
    }else validaTDato.generar_Mensaje(2,"NO EXISTEN PLANES FARMACOLOGICOS CARGADOS EN EL SISTEMA");
    cout<<endl<<endl;
    system("PAUSE");
    return;
}

void InterfazPlanFarmacologico :: ListarPlanesFarmacologicos(){

    PlanFarmacologico planFarma;
    ValidacionesTipoDato validaTDato;
    Archivo planesfarmaco(FILE_PLANFARMACO,sizeof(planFarma),true);
    if( planesfarmaco.getCantidadRegistros() != 0){

        cout << left;
        cout << setw(4)  << "ID";
        cout << setw(20) << "PACIENTE";
        cout << setw(20) << "PROFESIONAL";
        cout << setw(15) << "ESTADO";
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

bool InterfazPlanFarmacologico :: AgregarPlanFarmacologicoAArchivo(PlanFarmacologico _planFarmacologico){
    cls();
    ValidacionesGenerales valGral;
    ValidacionesTipoDato validaTDato;
    cout << left;
    cout << setw(4)  << "ID";
    cout << setw(20) << "PACIENTE";
    cout << setw(20) << "PROFESIONAL";
    cout << setw(20) << "ESTADO";
    cout << setw(50) << "NOTAS";
    cout << endl;

    MostrarPlanFarmacologico(_planFarmacologico);
    cout<<endl<<endl;
    cout<<"ESTA SEGURO QUE DESEA AGREGAR EL SIGUIENTE PLAN FARMACOLOGICO? S/N";
    if(valGral.leer_SoN())
    {
        Archivo planesfarmacologicos(FILE_PLANFARMACO,sizeof(PlanFarmacologico));
        if(planesfarmacologicos.grabarRegistro(_planFarmacologico,-1) == 1){
            validaTDato.generar_Mensaje(2,"SE GRABO SATISFACTORIAMENTE EL PLAN FARMACOLOGICO CARGADO");
            cout<<endl;
            system("PAUSE");
            return true;
            }
        else{
            validaTDato.generar_Mensaje(0,"NO FUE POSIBLE GUARDAR EL PLAN");
            cout<<endl;
            system("PAUSE");
            return false;
            }
    }
    cout<<endl;
    system("PAUSE");
    return false;

};

///************************************************************************************///
///*************************** DETALLE DEL FARMACOLOGICO *****************************///
///************************************************************************************///

 int InterfazDetallePlanFarmacologico ::  GetCantidadDetallesPlanes(){
    Archivo detallesPlanes(FILE_DETALLESPLANFARMACO,sizeof(DetallePlanFarmacologico),true);
    return detallesPlanes.getCantidadRegistros();
 }

int InterfazDetallePlanFarmacologico :: ObtenerDetalleDelPlanFarmacologico(DetallePlanFarmacologico & _detalle, bool ultimo = false){
    Archivo detallesPlanes(FILE_DETALLESPLANFARMACO,sizeof(DetallePlanFarmacologico),true);
    if (!ultimo)
        return detallesPlanes.leerRegistro(_detalle);
    else
        _detalle.SetId(detallesPlanes.getCantidadRegistros()-1);

    return detallesPlanes.leerRegistro(_detalle);
 }





bool InterfazDetallePlanFarmacologico :: CargarDetallePlanFarmacologico(DetallePlanFarmacologico & _detallePlanFarma){

    InterfazMedicamento itfzMed;
    InterfazFecha itfzFecha;

     if (itfzMed.GetCantidadMedicamentos() == 0 ){
        cout<<"NO EXISTEN MEDICAMENTOS CARGADOS EN EL SISTEMA"<<endl;
        system("PAUSE"); system("cls");
        return false;
    }

    InterfazFecha IF;
    ValidacionesTipoDato validaTDato;
    ValidacionesGenerales validaGeneral;
    Medicamento medicamento;
    vector<int> vecMed;

    system("cls");
    cout<<"DEBE ASOCIAR UN MEDICAMENTO"<<endl<<endl;
    itfzMed.ListarMedicamentosConFiltro(vecMed);
    do{
        cout<<"INGRESE EL ID DEL MEDICAMENTO QUE DESEA RELACIONAR: "<<endl<<endl;
        medicamento.SetId(validaTDato.cargar_Entero());
        if (!VerficicarOpcionListada(vecMed,medicamento.GetId())){
            cout<<"EL ID INGRESADO NO SE ENCUENTRA EN LA LISTA, REINGRESE"<<endl;
        }else{
            system("cls");
            break;
        }
    } while(true);
    cout<<endl;

    _detallePlanFarma.SetIdPlanMedicamento(medicamento.GetId());
    validaTDato.generar_Mensaje(2,"MEDICACION ASIGNADA EXITOSAMENTE!");
    system("PAUSE");
    system("cls");

    cout<<"INGRESE LA DOSIS DIARIA (CANT DE PASTILLAS): "<<endl;
    _detallePlanFarma.SetDosisdiaria( validaTDato.cargar_Entero() );
    cout<<"INGRESE LA DOSIS EN MG A CONSUMIR: "<<endl;
    _detallePlanFarma.SetMgPorDosis(validaTDato.cargar_Entero());

    cout<<"ENTREGA MUESTRA GRATIS? S/N"<<endl;
    if (validaGeneral.leer_SoN())
    {
        cout<<"INGRESE LA CANTIDAD DE COMPRIMIDOS: "<<endl;
        _detallePlanFarma.SetCantComprimidos( validaTDato.cargar_Entero() );
        cout<<"INGRESE LA CANTIDAD DE MILIGRAMOS POR COMPIRMIDO: "<<endl;
        _detallePlanFarma.SetCantMiligramos( validaTDato.cargar_Entero() );
    }

    AgregarDetallePlanFarmacologicoAArchivo(_detallePlanFarma);
    return ObtenerDetalleDelPlanFarmacologico( _detallePlanFarma );
}

void InterfazDetallePlanFarmacologico :: MostrarDetallePlanFarmacologico(DetallePlanFarmacologico _detallePlanFarmacologico){

    cout << left;
    if (_detallePlanFarmacologico.GetId() != -1)
        cout << setw(4)  << _detallePlanFarmacologico.GetId();
    else
        cout << setw(4)  << " - ";

    cout << setw(20)  << _detallePlanFarmacologico.GetDosisdiaria();
    cout << setw(20)  << _detallePlanFarmacologico.GetMgPorDosis();
    cout << setw(20)  << _detallePlanFarmacologico.GetCantComprimidos();
    cout << setw(20)  << _detallePlanFarmacologico.GetCantidadMgDisponibles();
    cout << setw(20)  << _detallePlanFarmacologico.GetCantidadDiasCubiertos();

    cout<<endl;
}

void InterfazDetallePlanFarmacologico :: ListarDetallesDePlanesFarmacologicos(){

    DetallePlanFarmacologico detPlanFarma;
    ValidacionesTipoDato validaTDato;
    Archivo detallesPlanFarma(FILE_DETALLESPLANFARMACO,sizeof(DetallePlanFarmacologico),true);
    if( detallesPlanFarma.getCantidadRegistros() != 0){

        cout << left;
        cout << setw(4)  << "ID";
        cout << setw(20) << "PASTILLAS POR DIA";
        cout << setw(20) << "DOSIS POR PASTILLA";
        cout << setw(20) << "PASTILLAS DISPONIBLES";
        cout << setw(20) << "MG DIPONIBLES";
        cout << setw(20) << "DIAS CUBIERTOS";
        cout << endl;


        while(fread(&detPlanFarma,sizeof(detPlanFarma),1,detallesPlanFarma.GetPF())){
             MostrarDetallePlanFarmacologico(detPlanFarma);
        };

    }else validaTDato.generar_Mensaje(2,"NO EXISTEN DETALLES DE PLANES FARMACOLOGICOS CARGADOS EN EL SISTEMA");
    cout<<endl<<endl;
    system("PAUSE");
    return;
};

void InterfazDetallePlanFarmacologico :: AgregarDetallePlanFarmacologicoAArchivo(DetallePlanFarmacologico _detallePlanFarmacologico){
    system("PAUSE");
    ValidacionesGenerales valGral;
    ValidacionesTipoDato validaTDato;
    cout << left;
        cout << left;
        cout << setw(4)  << "ID";
        cout << setw(20) << "PASTILLAS POR DIA";
        cout << setw(20) << "MG POR PASTILLA";
        cout << setw(20) << "CANT. DISPONIBLE";
        cout << setw(20) << "MG. DIPONIBLE";
        cout << setw(20) << "DIAS CUBIERTOS";
        cout << endl;

    MostrarDetallePlanFarmacologico(_detallePlanFarmacologico);
    cout<<endl<<endl;

    Archivo detallesplanesfarmacologicos(FILE_DETALLESPLANFARMACO,sizeof(DetallePlanFarmacologico));
    if(detallesplanesfarmacologicos.grabarRegistro(_detallePlanFarmacologico,-1) == 1)
        validaTDato.generar_Mensaje(2,"SE GRABO SATISFACTORIAMENTE EL DETALLE DEL PLAN FARMACOLOGICO CARGADO");
    else
        validaTDato.generar_Mensaje(0,"NO SE PUDO GRABAR SATISFACTORIAMENTE EL DETALLE CARGADO");

    cout<<endl;
    system("PAUSE");
};

/*
void InterfazDetallePlanFarmacologico :: SupervisarMedicamentosDisponibles(){
    Medicamento medicamento;
    vector<Medicamento> vecMedicamentos;
    while(fread(&medicamento,sizeof(Medicamento),1,medicamentos.GetPF())){
            if (medicamento. )
                vecMedicamentos.push_back(medicamento);
                MostrarMedicamento(medicamento);
    }
}
*/

/// ADMIN PERSONAL DE LAS DROGAS PARA EL PAC.

void InterfazDetallePlanFarmacologico :: ModificarDetallePlan(DetallePlanFarmacologico & _detallePlanFarma){

        ValidacionesTipoDato validaTDato;
        cout<<"INGRESE LA CANTIDAD DE COMPRIMIDOS: "<<endl;
        _detallePlanFarma.SetCantComprimidos( validaTDato.cargar_Entero() );
        cout<<"INGRESE LA CANTIDAD DE MILIGRAMOS POR COMPIRMIDO: "<<endl;
        _detallePlanFarma.SetCantMiligramos( validaTDato.cargar_Entero() );
        return ;
}

bool InterfazDetallePlanFarmacologico :: ActualizarDetallePlan(DetallePlanFarmacologico _det, int _pos){
    Archivo detallrPlan(FILE_DETALLESPLANFARMACO,sizeof(DetallePlanFarmacologico),true);
    detallrPlan.grabarRegistro(_det,_pos);
}


void InterfazDetallePlanFarmacologico :: ModificarDetalleEnArchivo(DetallePlanFarmacologico _detalle){
    ValidacionesGenerales valGral;
    ValidacionesTipoDato validaTDato;
    DetallePlanFarmacologico auxDetalle;

    auxDetalle.SetId(_detalle.GetId());

    Archivo detallePlan(FILE_DETALLESPLANFARMACO,sizeof(DetallePlanFarmacologico),true);
    int posDet = detallePlan.buscarRegistro(auxDetalle);
    if ( posDet != -1 && detallePlan.leerRegistro(auxDetalle, posDet) != -1){

            auxDetalle.SetCantComprimidos(_detalle.GetCantComprimidos());
            auxDetalle.SetCantMiligramos(_detalle.GetCantMiligramos());

           if(ActualizarDetallePlan(auxDetalle,posDet))
            validaTDato.generar_Mensaje(2,"SE ACTUALIZO SATISFACTORIAMENTE EL DETALLE");
                else
            validaTDato.generar_Mensaje(0,"NO SE PUDO ACTUALIZAR SATISFACTORIAMENTE EL DETALLE");
            cout<<endl<<endl;

            system("PAUSE");
            return;
    }else{
            validaTDato.generar_Mensaje(0,"NO EXISTE UN DETALLE CON EL ID: ");
            cout<<_detalle.GetId();
            cout<<endl<<endl;
            system("PAUSE");
         }
}

/*
void InterfazDetallePlanFarmacologico :: ModificarDetalleEnArchivo(DetallePlanFarmacologico _detalle){
    ValidacionesGenerales valGral;
    ValidacionesTipoDato validaTDato;
    DetallePlanFarmacologico auxDetalle;
    auxDetalle.SetId(_detalle.GetId());

    Archivo detallesPlan(FILE_DETALLESPLANFARMACO,sizeof(DetallePlanFarmacologico));
    int posDet = detallesPlan.buscarRegistro(auxDetalle);
    if ( posDet != -1 && detallesPlan.leerRegistro(auxDetalle, posDet) != -1){
        system("cls");
        if(detallesPlan.grabarRegistro(auxDetalle,posDet) == 1)
            validaTDato.generar_Mensaje(2,"SE ACTUALIZO SATISFACTORIAMENTE EL DETALLE");
        else
            validaTDato.generar_Mensaje(0,"NO SE PUDO ACTUALIZAR SATISFACTORIAMENTE EL DETALLE");
        cout<<endl<<endl;
        system("PAUSE");
        return;
    }
}
*/
