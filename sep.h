    #include <stdio.h>
    #include<stdlib.h>
    #include<math.h>

    void sep_matrix(int* v, int* n, Componente *Xstruct){
        void buscar(int* fim, int* v, int* addpos, Componente *Xstruct, int* componentes, int n, int mode);

        int fimpos = 1;
        int aux;
        //#define def[4] (char*){'Z', 'T', 'G', 'C'};                             //A
        int addpos[4] = {1, *n, -*n, -1};
        int vector[ *n ]; 

        for(int i = 0; i < *n; i++){
            if((Xstruct + i*sizeof(Xstruct))->type == 2 || (Xstruct + i*sizeof(Xstruct))->type == 3){
                aux = i;
            }
            vector[i] = i;
        }
        v[2*(n[0])*(n[0]) + 0] = -100 * (Xstruct + aux*sizeof(Xstruct))->type + n[ (Xstruct + aux*sizeof(Xstruct))->type ];
        v[2*(n[0])*(n[0]) + 1] = (Xstruct + aux*sizeof(Xstruct))->pos[0];

        int* fim = calloc(fimpos, sizeof(int));
        fim[0] = 2 * (n[0])*(n[0]) + 1;           //Posição (2*n[0])(1), vetor de tamanho 2*n;
        int i = n[0] - 1;
        while(i > 0){               
            for(int m = 0; m < fimpos; m++){                                            //Repetição do "fim"
                for(int k = 0; k < *n; k++){                                          //Repetição componentes
                    for(int x = 0; x<2 ; x++){                                    //Repetição pos[0] e pos[1]
                        if(vector[k] != -99 && (Xstruct + k*sizeof(Xstruct))->pos[x] == v[ fim[m] ] && (Xstruct + k*sizeof(Xstruct))->pos[x] != -99){
                            for(int h = 0; h < 4; h++){                             //Repetição direita, baixo, cima, esquerda
                                if(v[ fim[m] + addpos[h] ] == 0){
                                    v[ fim[m] + addpos[h] ] = (-100 * (Xstruct + k*sizeof(Xstruct))->type + n[ (Xstruct + aux*sizeof(Xstruct))->type ]); //Insere o componente na matriz
                                    vector[k] = -99;                                                                //Retira o componente do "a fazer"
                                    i--;                                                                            //Informa que há um componente a menos no "pool" de repetições
                                    if((Xstruct + k*sizeof(Xstruct))->type != 2 && (Xstruct + k*sizeof(Xstruct))->type != 3){//Colocar o outro nó, se for o caso
                                        fim[m] = fim[m] + 2*addpos[h];
                                        v[ fim[m] ] = (Xstruct + k*sizeof(Xstruct))->pos[abs(x - 1)];
                                    }else if(i != 0){       //Caso gerador ou carga, encontrar outro nó em que faltam componentes, se for o caso
                                        fimpos++;
                                        fim = (int *)realloc(fim, fimpos * sizeof(int));
                                        fim[fimpos - 1] = -99;
                                        buscar(&fim[fimpos - 2], v, &addpos[0], &Xstruct[0], &k, *n, 0);
                                        m++;
                                    }
                                    h = 5;
                                }
                            }
                        }   
                    }
                }
            }
        }
        free(fim);
    }


    void posicao(int a, int b, int n, int* v, int* nv, int enable){
        if(enable){
            *nv = *nv + 1;
            v = (int *)realloc(v, (*nv) * sizeof(int));
        }
        *(v + *nv) = (n*a) + b;
    }

    void buscar(int* fim, int* v, int* addpos, Componente *Xstruct, int* componentes, int n, int mode){
        void condicao(int mode, int* cond, int*v, int* fim);
        
        int aux = *fim;
        int cond;
        int c;
        condicao(mode, &cond, v, fim);
        
        while(cond){
            for(int h = 3; h >= 0; h--){
                if( mode == 0 && v[ aux - c * *(addpos + h) ] > 0 ){
                    aux = aux - c * *(addpos + h);
                    for(int i = 0; i < n; i++){
                        for(int k = 0; k < 2; k++){
                            if( (Xstruct + i*sizeof(Xstruct))->pos[k] == v[ aux ]){
                                *componentes = i - 1;
                                *(fim + 1) = aux;
                            }    
                        }
                    }
                }else if(mode == 1 || mode == 2){
                    
                    if(v[ aux - c * *(addpos + h) ] < 0){
                        aux = aux - c * *(addpos + h);
                        *fim = aux;
                    }else if(v[ aux - c * *(addpos + h) ] > 0){
                        aux = aux - *(addpos + h);
                        *fim = aux;
                    }
                }
            }
            condicao(mode, &cond, v, fim);
        }
    }

    void condicao(int mode, int* cond, int*v, int* fim){
        if(mode == 0){
            if(*(fim + 1) == -99){
                *cond = 1;
            }else{
                *cond = 0;
            }
        }else if(mode == 1){
            if(v[ *fim ] < -299 || v[ *fim ] > -200){//Trafo?
                *cond = 1;
            }else if(v[ *fim ] < -399 || v[ *fim ] > -300){
                *cond = 1;
            }else if(v[ *fim ] < -499 || v[ *fim ] > -400){
                *cond = 1;
            }else{
                *cond = 0;
            }
        }
    }