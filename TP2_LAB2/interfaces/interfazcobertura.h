#ifndef INTERFAZCOBERTURA_H_INCLUDED
#define INTERFAZCOBERTURA_H_INCLUDED
#include "../modelos/cobertura.h"
#include "../modelos/registro.h"
#include "../interfaces/interfazgeneral.h"

class InterfazCobertura : public InterfazGeneral {
    public:
        int  ObtenerCobertura(Cobertura & );
        bool CargarCobertura(Cobertura &);
        void MostrarCobertura(Cobertura );
        void ListarCoberturas();
        void AgregarCoberturaAArchivo(Cobertura );

        void ModificarCobertura(Cobertura & );
        void ActualizarCobertura(Cobertura , int );
        void ModificarCoberturaEnArchivo(Cobertura );

        void ListarCoberturasConFiltro(vector<int> & );
        int  GetCantidadCoberturas();

};

#endif // INTERFAZCOBERTURA_H_INCLUDED
