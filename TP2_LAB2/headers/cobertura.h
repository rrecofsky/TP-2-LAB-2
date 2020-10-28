#ifndef COBERTURA_H_INCLUDED
#define COBERTURA_H_INCLUDED

class Cobertura{
    private:
       int ID;
       char nombre[50];
    public:
        Cobertura(const char *n)
        {
            ID = 0; //buscar en base al nro en los archivos
            strcpy(nombre,n);
        }
        ~Cobertura(){};
        //GETs
        int GetId();
        char *GetNombre();
        void SetId(int);
        void SetNombre(const char*);
};

#endif // COBERTURA_H_INCLUDED
