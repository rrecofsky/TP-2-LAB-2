#ifndef INTERFAZCOBERTURA_H_INCLUDED
#define INTERFAZCOBERTURA_H_INCLUDED
#include "../modelos/cobertura.h"
#include "../modelos/registro.h"

class InterfazCobertura  {
    public:
        void CargarCobertura(Cobertura &);
        void MostrarCobertura(Cobertura);
        void ModificarCobertura(Cobertura &);
        void AgregarCoberturaAArchivo(Cobertura);
        void ModificarCoberturaEnArchivo(Cobertura);
        void ListarCoberturas();
        bool AsociarCobertura(Cobertura &);
};

#endif // INTERFAZCOBERTURA_H_INCLUDED
