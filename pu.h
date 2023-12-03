    #include <stdio.h>

    void pu_empu(double Sbase, Componente *b, int n, Base *c, FILE *arq){
        arq = fopen("pu.paeaco", "a");

        for(int  i = n - 1; i > 0; i--){
            if((b + sizeof(Componente)*i)->V != 0){
                (b + sizeof(Componente)*i)->V = (b + sizeof(Componente)*i)->V / (c + sizeof(Base) * ( (b + sizeof(Componente)*i)->zT - 1))->V;
                (c + sizeof(Base) * ( (b + sizeof(Componente)*i)->zT - 1))->Vr = (b + sizeof(Componente)*i)->V;
            }else{
                (b + sizeof(Componente)*i)->V = (c + sizeof(Base) * ( (b + sizeof(Componente)*i)->zT - 1))->Vr;
            }
            (b + sizeof(Componente)*i)->S = (b + sizeof(Componente)*i)->S / Sbase;
            (b + sizeof(Componente)*i)->Z = (b + sizeof(Componente)*i)->Z * Sbase / pow( (c + sizeof(Base) * ( (b + sizeof(Componente)*i)->zT - 1) )->V , 2);
            (b + sizeof(Componente)*i)->I = (b + sizeof(Componente)*i)->S / (b + sizeof(Componente)*i)->V;
            fprintf(arq, "%lf\t%lf\t%lf\t%d\n", (b + sizeof(Componente)*i)->V, (b + sizeof(Componente)*i)->S, (b + sizeof(Componente)*i)->Z, i);
        }
        fclose(arq);
    }

    void pu_Vzona(int nb, Base *b, long int* v, int n, Componente *Xstruct, double Vfixo, int nVfixo){
        int zon = 0;
        for(int i = 0; i < n; i++){
            if(v[i] == nVfixo){
                sep_findzona(v, Xstruct, n, &zon, nVfixo);
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