#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
    private:
        int dia;
        int mes;
        int anio;
    public:
         Fecha(int _dia = 0, int _mes = 0, int _anio = 0){
            dia  = _dia;
            mes  = _mes;
            anio = _anio;
        }
        ~Fecha(){
            dia  = 0;
            mes  = 0;
            anio = 0;
        }
        ///GETS
        int   GetDia();
        int   GetMes();
        int   GetAnio();
        Fecha GetFechaActual();
        const char * GetFechaConFormato();
        ///SETS
        void  SetDia(int);
        void  SetMes(int);
        void  SetAnio(int);
        void  SetNuevaFecha(int,int,int);
        ///CARGAS y CONSULTAS
        void  CargarFecha();
        void  GetFecha();

};



#endif // FECHA_H_INCLUDED
