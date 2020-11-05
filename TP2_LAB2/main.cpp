#include <iostream>
#include "login.h"
#include "usuario.h"
#include "rlutil.h"


#include "detalleplanfarmacologico.h"

using namespace std;

int main()
{ /*
    Usuario user("admin","1234");

    cout<<"User: "<<user.GetUser();
    cout<<endl;
    cout<<"Pass: "<<user.GetPass();

    rlutil::anykey();
    */

    DetallePlanFarmacologico dpf;
    dpf.Cargar();
    dpf.Mostrar();
    cout<<"Fecha de alta de registro: "<<dpf.GetFechaAlta().GetDia()<<"/"<<dpf.GetFechaAlta().GetMes()<<"/"<<dpf.GetFechaAlta().GetAnio()<<endl;
    cout<<"Fecha de baja de registro: "<<dpf.GetFechaBaja().GetDia()<<"/"<<dpf.GetFechaBaja().GetMes()<<"/"<<dpf.GetFechaBaja().GetAnio()<<endl;
    dpf.SetEstado(false);
    cout<<"Fecha de baja de registro: "<<dpf.GetFechaBaja().GetDia()<<"/"<<dpf.GetFechaBaja().GetMes()<<"/"<<dpf.GetFechaBaja().GetAnio()<<endl;

    MenuLogin("admin","admin");
    return 0;
}
