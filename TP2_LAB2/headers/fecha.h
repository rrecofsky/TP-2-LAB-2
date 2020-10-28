#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
    private:
        int dia;
        int mes;
        int anio;
    public:
        Fecha(int d = 0, int m = 0, int a = 0){
            dia=d;
            mes=m;
            anio=a;
        }
        ~Fecha(){
            dia=0;
            mes=0;
            anio=0;
        }
        int GetDia();
        int GetMes();
        int GetAnio();
        Fecha GetFecha();
        void SetDia(int);
        void SetMes(int);
        void SetAnio(int);
        void SetFecha(Fecha);

};



#endif // FECHA_H_INCLUDED
