#ifndef INTERFAZINFORME_H_INCLUDED
#define INTERFAZINFORME_H_INCLUDED

#include "../modelos/informe.h"

class InterfazInforme : public InterfazGeneral {
    public:
        int  ObtenerInforme(Informe & _informe);
        bool CargarInforme(Informe &);
        void MostrarInforme(Informe );
        void ListarInformes();
        void AgregarInformeAArchivo(Informe );


};



#endif // INTERFAZINFORME_H_INCLUDED
