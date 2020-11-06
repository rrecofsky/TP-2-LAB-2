#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

void MenuLogin();
/*
void NoAnda(const char* user){

    Archivo archProfesional(FILE_PROFESIONALES,sizeof(Profesional));
    Profesional profesionalSistema;
    //cambio de forma temporal el user del reg profesional, para buscarlo por comparacion con el usuario
    profesionalSistema.ChangeUserName(user);
    int posProfesional = archProfesional.buscarRegistro(profesionalSistema);
    int regLeido = archProfesional.leerRegistro(profesionalSistema, posProfesional);
    cout<<"PASS p: "<<profesionalSistema.GetPass()<<endl;
    cout<<"USER p: "<<profesionalSistema.GetUser()<<endl;
    cout<<"NOMBRES: "<<profesionalSistema.GetDNI()<<endl;
    cout<<"NOMBRES: "<<profesionalSistema.GetGenero()<<endl;
    cout<<"Posicion de postProf: "<<posProfesional<<endl;
    cout<<"regLeido: 1-->SI "<<regLeido<<endl;
    system("PAUSE");

}
*/

#endif // LOGIN_H_INCLUDED
