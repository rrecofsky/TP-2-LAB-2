#ifndef INTERFAZESPECIALIDAD_H_INCLUDED
#define INTERFAZESPECIALIDAD_H_INCLUDED

#include "../modelos/especialidad.h"
#include "../modelos/registro.h"
#include "../interfaces/interfazgeneral.h"

class InterfazEspecialidad : public InterfazGeneral {
    public:
        int  ObtenerEspecialidad(Especialidad & );
        bool CargarEspecialidad(Especialidad &);
        void MostrarEspecialidad(Especialidad );
        void ListarEspecialidades();
        void AgregarEspecialidadAArchivo(Especialidad );

        void ModificarEspecialidad(Especialidad & );
        void ActualizarEspecialidad(Especialidad , int );
        void ModificarEspecialidadEnArchivo(Especialidad );

};


#endif // INTERFAZESPECIALIDAD_H_INCLUDED
