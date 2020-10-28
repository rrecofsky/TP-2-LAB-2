#ifndef FARMACO_H_INCLUDED
#define FARMACO_H_INCLUDED

class Farmaco{
    private:
       int ID;
       char nombre[50];
    public:
        Farmaco(const char *n)
        {
            ID = 0; //buscar en base al nro en los archivos
            strcpy(nombre,n);
        }
        ~Farmaco(){};
        //GETs
        int GetId();
        char *GetNombre();
        void SetId(int);
        void SetNombre(const char*);
};

#endif // FARMACO_H_INCLUDED
