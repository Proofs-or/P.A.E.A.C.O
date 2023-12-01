    #include <stdio.h>

    /*void pu_calcbases(double Sbase, double Vbase, Componente *b, int zonas, int zVbase){
        
        for(int  i = 0; i < zonas; i++){
            (b + sizeof(Componente)*i)->V = (b + sizeof(Componente)*i)->V / (c + sizeof(Base) * ( (b + sizeof(Componente)*i)->zT - 1);
            (b + sizeof(Componente)*i)->S = (b + sizeof(Componente)*i)->S / Sbase;
            (b + sizeof(Componente)*i)->Z = (b + sizeof(Componente)*i)->Z * Sbase / pow( (c + sizeof(Base) * ( (b + sizeof(Componente)*i)->zT - 1) )->V , 2);
            (b + sizeof(Componente)*i)->I = 2; //Sei n, ajuda nois
        }
    }*/

    void pu_Vzona(int nb, Base *b, long int* v, int n){
        int zon = 0;
        printf("Insira a tensao fixada do sistema (kV)\n");
        scanf("%d", &Vfixo);
        printf("Em qual no foi aferida essa tensao?\n");
        scanf("%d", &nVfixo);
        for(int i = 0; i < n; i++){
            if(v[i] == nVfixo){
                sep_findzona(&zon , nVfixo);
                for(int k = 0; k < nb; k++){
                    if( (b + k*sizeof(Base))->zona == zon ){
                        Vfixo = Vfixo / (b + k*sizeof(Base))->V;
                        for(int y = 0; y < nb; y++){
                            (b + y*sizeof(Base))->V = Vfixo * (b + y*sizeof(Base))->V;
                        }
                        k = nb;
                    }
                }
            }
        }
    }