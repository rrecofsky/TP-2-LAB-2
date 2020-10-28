#ifndef PRESENTACION_H_INCLUDED
#define PRESENTACION_H_INCLUDED

class Presentacion{
    private:
       int ID;
       char nombre[50]; //nombre de la presentacion
       int cantidad; //cantidad de pastillas de la presentacion
       float mg; //miligramos de cada pastilla
    public:
        Presentacion(const char *n)
        {
            ID = 0; //buscar en base al nro en los archivos
            strcpy(nombre,n);
        }
        ~Presentacion(){};
        //GETs
        int GetId();
        char *GetNombre();
        int GetCantidad();
        float GetMg();
        //SET's
        void SetId(int);
        void SetNombre(const char*);
        void SetCantidad(int);
        void SetMg(float);
};

#endif // PRESENTACION_H_INCLUDED
