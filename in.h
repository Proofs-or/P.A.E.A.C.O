    #include<stdio.h>
    //#include"structs.h"

    char tipos[4][11] = {"Impedancia", "Trafo", "Gerador", "Carga"};


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

    void in_store(Impedancia *Zstruct, Trafo *Tstruct, Gerador *Gstruct, Carga *Cstruct, int* n){
        printf("Inserir os dados para cada componente:\nObs: Leia o arquivo de instrucoes!!\n");

        void in_fillZ(int n, Impedancia *v);
        void in_fillT(int n, Trafo *v);
        void in_fillG(int n, Gerador *v);
        void in_fillC(int n, Carga *v);

        in_fillG(n[3], Gstruct);
        in_fillT(n[2], Tstruct);
        in_fillC(n[4], Cstruct);
        in_fillZ(n[1], Zstruct);

    }

        void in_fillZ(int n, Impedancia *v){

        for(int count = 0; count < n; count++){
            printf("\tImpedancia %d\n", count + 1);
            printf("Fator de Potencia:\t");
            scanf("%lf", &(v->fp) + count*sizeof(v));
            printf("\n");

            printf("Impedancia Complexa (Ohm):\t");
            scanf("%lf", &(v->Z) + count*sizeof(v));
            printf("\n");

            printf("No de entrada:\t");
            scanf("%d", &(v->pos[0]) + count*sizeof(v));
            printf("\n");

            printf("No de saida:\t");
            scanf("%d", &(v->pos[1]) + count*sizeof(v));
            printf("\n");

            printf("Zona de Tensão:\t");
            scanf("%d", &(v->zT) + count*sizeof(v));
            printf("\n");
        }
        
        //printf("%lf", (v + count*sizeof(v))->V);
    }

        void in_fillT(int n, Trafo *v){

        for(int count = 0; count < n; count++){
            printf("\tImpedancia %d\n", count + 1);
            printf("Relacao de Transformacao (Vin/Vout)):\t");
            scanf("%lf", &(v->alpha) + count*sizeof(v));
            printf("\n");
            
            printf("Potencia Complexa (MVA):\t");
            scanf("%lf", &(v->S) + count*sizeof(v));
            printf("\n");

            printf("Impedancia Complexa (Ohm):\t");
            scanf("%lf", &(v->Z) + count*sizeof(v));
            printf("\n");

            printf("Fator de Potencia:\t");
            scanf("%lf", &(v->fp) + count*sizeof(v));
            printf("\n");

            printf("No de entrada:\t");
            scanf("%d", &(v->pos[0]) + count*sizeof(v));
            printf("\n");

            printf("No de saida:\t");
            scanf("%d", &(v->pos[1]) + count*sizeof(v));
            printf("\n");

            printf("Zona de Tensão:\t");
            scanf("%d", &(v->zT) + count*sizeof(v));
            printf("\n");
        }
        
        //printf("%lf", (v + count*sizeof(v))->V);
    }

    void in_fillG(int n, Gerador *v){

        for(int count = 0; count < n; count++){
            printf("\tImpedancia %d\n", count + 1);
            printf("Tensao (kV):\t");
            scanf("%lf", &(v->V) + count*sizeof(v));
            printf("\n");
            
            printf("Potencia Complexa (MVA):\t");
            scanf("%lf", &(v->S) + count*sizeof(v));
            printf("\n");

            printf("Fator de Potencia:\t");
            scanf("%lf", &(v->fp) + count*sizeof(v));
            printf("\n");

            printf("Impedancia Complexa (Ohm):\t");
            scanf("%lf", &(v->Z) + count*sizeof(v));
            printf("\n");

            printf("No de entrada:\t");
            scanf("%d", &(v->pos) + count*sizeof(v));
            printf("\n");

            printf("Zona de Tensão:\t");
            scanf("%d", &(v->zT) + count*sizeof(v));
            printf("\n");
        }
        
        //printf("%lf", (v + count*sizeof(v))->V);
    }

    void in_fillC(int n, Carga *v){
        
        for(int count = 0; count < n; count++){
            printf("\tImpedancia %d\n", count + 1);
            printf("Potencia Complexa (MVA):\t");
            scanf("%lf", &(v->S) + count*sizeof(v));
            printf("\n");

            printf("Impedancia Complexa (Ohm):\t");
            scanf("%lf", &(v->Z) + count*sizeof(v));
            printf("\n");

            printf("Fator de Potencia:\t");
            scanf("%lf", &(v->fp) + count*sizeof(v));
            printf("\n");

            printf("No de saida:\t");
            scanf("%d", &(v->pos) + count*sizeof(v));
            printf("\n");

            printf("Zona de Tensão:\t");
            scanf("%d", &(v->zT) + count*sizeof(v));
            printf("\n");
        }
        //printf("%lf", (v + count*sizeof(v))->V);
    }