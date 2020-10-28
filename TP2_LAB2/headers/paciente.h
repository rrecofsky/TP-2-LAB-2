#ifndef PACIENTE_H_INCLUDED
#define PACIENTE_H_INCLUDED

class Paciente{
    private:
        int nro_Afiliado; //nro de afiliado
        int ID_Conertura; //0 es sin cobertura
        int ID_PlanFarmacologico; //R FUERTE A N, no pueden existir sin un paciente
        int ID_Informe; //R FUERTE A 1, no puede existir si un paciente
    public:
        Paciente(int n =0, int c=0, int p =0, int i =0){
            nro_Afiliado         = n;
            ID_Conertura         = c;
            ID_PlanFarmacologico = 0;
            ID_Informe           = 0;
        }
        ~Paciente(){};
        //GETs
        int GetNroAfiliado();
        int GetIdCobertura();
        int GetInforme();
        //SETs
        void SetNroAfiliado(int);
        void SetIdCObertura(int);
        void SetIdInforme(int);


};


#endif // PACIENTE_H_INCLUDED
