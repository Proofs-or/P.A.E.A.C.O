    #include<stdio.h>
    //#include"structs.h"

    char tipos[4][11] = {"Impedancia", "Trafo", "Gerador", "Carga"};
    //char tipos2[4] = {"I", "T", "G", "C"};


    void in_info(int* n, int* aux){
        printf("\n\n");
        printf("Insercao de componentes\n");
        *aux = 0;
        printf("Insira o numero de componentes no sistema\n");
        for(int i = 0; i < 4; i++){
            printf("%s:\t", tipos[i]);
            scanf("%d", (n + i));
            printf("\n");
            
            *aux = *aux + *(n + i);
        }
    }

    void in_store(Componente *Xstruct, int* n, FILE *arq){
        printf("Inserir os dados para cada componente:\nObs: Leia as instrucoes!!\n");

        void in_fill(int* n, Componente *v, FILE *arq);

        in_fill(n, &Xstruct[0], arq);

    }

    void in_fill(int* n, Componente *v, FILE *arq){
        arq = fopen("in.paiaco", "a");
        fprintf(arq, "%d\n\n", *n);
        for(int k = 0; k < 4; k++){
            fprintf(arq, "%s\t%d\n", tipos[k], n[k]);

            for(int count = 0; count < n[k+1]; count++){
                
                (v + count*sizeof(v))->type = k + 1;
                fprintf(arq, "%d\t%d\t", k, count);
                printf("\t%s %d\n", tipos[k], count + 1);
                if(k == 1){
                    printf("Relacao de Transformacao (Vin/Vout)):\t");
                    scanf("%lf", &(v->alpha) + count*sizeof(v));
                    printf("\n");
                }else{
                    (v + count*sizeof(v))->alpha = -99;
                }
                fprintf(arq, "%lf\t", (v + count*sizeof(v))->alpha);

                printf("Potencia Complexa (MVA):\t");
                scanf("%lf", &(v->S) + count*sizeof(v));
                printf("\n");
                fprintf(arq, "%lf\t", (v + count*sizeof(v))->S);

                printf("Impedancia Complexa (Ohm):\t");
                scanf("%lf", &(v->Z) + count*sizeof(v));
                printf("\n");
                fprintf(arq, "%lf\t", (v + count*sizeof(v))->Z);

                printf("Fator de Potencia:\t");
                scanf("%lf", &(v->fp) + count*sizeof(v));
                printf("\n");
                fprintf(arq, "%lf\t", (v + count*sizeof(v))->fp);

                printf("No de entrada:\t");
                scanf("%d", &(v->pos[0]) + count*sizeof(v));
                printf("\n");
                fprintf(arq, "%d\t", (v + count*sizeof(v))->pos[0]);

                if(k != 2 && k != 3){
                    printf("No de saida:\t");
                    scanf("%d", &(v->pos[1]) + count*sizeof(v));
                    printf("\n");
                }else{
                    (v + count*sizeof(v))->pos[1] = -99;
                }
                fprintf(arq, "%d\t", (v + count*sizeof(v))->pos[1]);

                if(k == 2){
                    printf("Tensão (kV):\t");
                    scanf("%lf", &(v->V) + count*sizeof(v));
                    printf("\n");
                }else{
                    (v + count*sizeof(v))->V = -99;
                }
                fprintf(arq, "%lf\t", (v + count*sizeof(v))->V);
                
                //printf("Zona de Tensão:\t");
                //scanf("%d", &(v->zT) + count*sizeof(v));
                //printf("\n");
                fprintf(arq, "\n");
                odss_include(arq, &v[0], count);

            }
        }
        //printf("%lf", (v + count*sizeof(v))->V);
    }