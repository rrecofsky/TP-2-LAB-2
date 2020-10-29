#include <iostream>
#include "login.h"
#include "usuario.h"
#include "rlutil.h"


using namespace std;

int main()
{ /*
    Usuario user("admin","1234");

    cout<<"User: "<<user.GetUser();
    cout<<endl;
    cout<<"Pass: "<<user.GetPass();

    rlutil::anykey();
    */
    MenuLogin("admin","admin");
    return 0;
}
