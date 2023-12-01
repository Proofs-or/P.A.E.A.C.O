    #include<stdio.h>
    #include<stdlib.h>
    #include<math.h>

    void sep_matrix(long int* v, int* n, Componente *Xstruct){
        void buscar(int* fim, long int* v, int* addpos, Componente *Xstruct, int* componentes, int n, int mode, int* direcao, Relacao *rel);
        int sizerel = 0;
        int fimpos = 1;
        int zona[1] = {1, 1};
        int aux;
        //#define def[4] (char*){'Z', 'T', 'G', 'C'};                             //A
        int addpos[4] = {1, *n, -*n, -1};
        int vector[ *n ]; 

        for(int i = 0; i < *n; i++){
            if((Xstruct + i*sizeof(Componente))->type == 2 || (Xstruct + i*sizeof(Componente))->type == 3){
                aux = i;
            }
            vector[i] = i;
        }
        v[2*(n[0])*(n[0]) + 0] = -10 * (Xstruct + aux*sizeof(Componente))->type - n[0];
        (Xstruct + aux*sizeof(Componente))->type = -100 * (Xstruct + aux*sizeof(Componente))->type - n[0];
        (Xstruct + aux*sizeof(Componente))->zT = zona[0];
        v[2*(n[0])*(n[0]) + 1] = (Xstruct + aux*sizeof(Componente))->pos[0];

        int* fim = calloc(fimpos, sizeof(int));
        fim[0] = 2 * (n[0])*(n[0]) + 1;           //Posição (2*n[0])(1), vetor de tamanho 2*n;
        int i = n[0] - 1;
        while(i > 0){               
            for(int m = 0; m < fimpos; m++){                                            //Repetição do "fim"
                for(int k = 0; k < *n; k++){                                          //Repetição componentes
                    for(int x = 0; x<2 ; x++){                                    //Repetição pos[0] e pos[1]
                        if(vector[k] != -99 && (Xstruct + k*sizeof(Componente))->pos[x] == v[ fim[m] ] && (Xstruct + k*sizeof(Componente))->pos[x] != -99){
                            for(int h = 0; h < 4; h++){                             //Repetição direita, baixo, cima, esquerda
                                if(v[ fim[m] + addpos[h] ] == 0){
                                    v[ fim[m] + addpos[h] ] = (-100 * (Xstruct + k*sizeof(Componente))->type - n[i]); //Insere o componente na matriz
                                    if((Xstruct + aux*sizeof(Componente))->type == 2){
                                        zona[1]++;
                                        //sizerel++;
                                        //rel = realloc(rel, (sizerel) * sizeof(Relacao));
                                        //(rel + (sizerel - 1)*sizeof(Relacao))->zona[abs(0 - 1*x)] = zona[0];
                                        //(rel + (sizerel - 1)*sizeof(Relacao))->zona[abs(1 - 1*x)] = zona[1];
                                        //(rel + (sizerel - 1)*sizeof(Relacao))->alpha = (Xstruct + aux*sizeof(Componente))->alpha;
                                        b = realloc(b, zona[1] * sizeof(Base));
                                        (b + zona[1 - 1]*sizeof(Base))->V = pow( (Xstruct + aux*sizeof(Componente))->alpha , 1 - (2 * x) ) * (b + zona[0 - 1]*sizeof(Base))->V;

                                        zona[0] = zona[1];
                                    }
                                    (Xstruct + aux*sizeof(Componente))->zT = zona;
                                    (Xstruct + k*sizeof(Componente))->type = -100 * (Xstruct + k*sizeof(Componente))->type - n[i];
                                    vector[k] = -99;                                                                //Retira o componente do "a fazer"
                                    i--;                                                                            //Informa que há um componente a menos no "pool" de repetições
                                    if((Xstruct + k*sizeof(Componente))->type != 2 && (Xstruct + k*sizeof(Componente))->type != 3){//Colocar o outro nó, se for o caso
                                        fim[m] = fim[m] + 2*addpos[h];
                                        v[ fim[m] ] = (Xstruct + k*sizeof(Componente))->pos[abs(x - 1)];
                                    }else if(i != 0){       //Caso gerador ou carga, encontrar outro nó em que faltam componentes, se for o caso
                                        fimpos++;
                                        fim = (int *)realloc(fim, fimpos * sizeof(int));
                                        fim[fimpos - 1] = -99;
                                        buscar(&fim[fimpos - 2], v, &addpos[0], &Xstruct[0], &k, *n, 0, &zona);
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


    void posicao(int a, int b, int n, long int* v, int* nv, int enable){
        if(enable){
            *nv = *nv + 1;
            v = (int *)realloc(v, (*nv) * sizeof(int));
        }
        *(v + *nv) = (n*a) + b;
    }

    void buscar(int* fim, long int* v, int* addpos, Componente *Xstruct, int* componentes, int n, int mode, int* direcao){
        void condicao(int mode, int* cond, long int*v, int* fim);
        
        int aux = *fim;
        int cond;
        int c = 2;
        condicao(mode, &cond, v, fim);
        
        while(cond){
            for(int h = 3; h >= 0; h--){
                if( mode == 0 && v[ aux + c * *(addpos + h) ] > 0 ){
                    aux = aux + c * *(addpos + h);
                    for(int i = 0; i < n; i++){
                        for(int k = 0; k < 2; k++){
                            if( (Xstruct + i*sizeof(Componente))->pos[k] == v[ aux ]){
                                *componentes = i - 1;
                                *(fim + 1) = aux;
                                sep_findzona();
                                h = 5;
                                k = 3;
                                i = n;
                            }    
                        }
                    }
                }/*else if(mode == 1){
                    if(v[ aux - *(addpos + h) ] < 0){
                        aux = aux - *(addpos + h);
                        *fim = aux;
                        *direcao = h;
                        h = 5;
                    }else if(v[ aux - *(addpos + h) ] > 0){
                        aux = aux - *(addpos + h);
                        *fim = aux;
                        *direcao = h;
                        h = 5;
                    }
                }else if(mode == 2){
                    //if(v[ aux - c * *(addpos + h) ])
                    printf("Olá!!");
                }*/
            }
            condicao(mode, &cond, v, fim);
        }
    }

    void sep_findzona(){
        for(int p = 3; p >= 0; p++){
            if(v[ aux + *(addpos + p) ] < 0){
                for(int u = 0; u < n; u++){
                    if( v[ aux + *(addpos + p) ] == (Xstruct + u*sizeof(Componente))->type){
                        *zona = (Xstruct + i*sizeof(Componente))->zT;
                    }
                }
            }
        }
    }

    void condicao(int mode, int* cond, long int*v, int* fim){
        if(mode == 0){
            if(*(fim + 1) == -99){
                *cond = 1;
            }else{
                *cond = 0;
            }
        }/*else if(mode == 1){
            if(v[ *fim ] > -299 && v[ *fim ] < -200){// É um Trafo?
                *cond = 0;
            }else if(v[ *fim ] > -399 && v[ *fim ] < -300){
                *cond = 0;
            }else if(v[ *fim ] > -499 && v[ *fim ] < -400){
                *cond = 0;
            }else{
                *cond = 1;
            }
        }else if(mode == 2){
            if(v[ *fim ] != *(fim + 1)){
                *cond = 1;
            }else{
                *cond = 0;
            }

        }*/
    }