#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sep_matrix(int* v, int* n, Trafo *T, Gerador *G, Impedancia *Z, Carga *C){

    int fimpos = 1;
    #define def[4] (char*){'Z', 'T', 'G', 'C'};                             //A
    int addpos[4] = {1, *n, -*n, -1};

    v[2*(n[0])*(n[0]) + 0] = -300;
    v[2*(n[0])*(n[0]) + 1] = (G + 0)->pos;

    int* fim = calloc(fimpos, sizeof(int));
    fim[0] = 2*(n[0])*(n[0]) + 1;           //Posição (2*n[0])(1), vetor de tamanho 2*n;

    int i = n[0];
    while(i > 0){
        int j[4] = {0, 0, 0, 0};
        for(int m = 0; m < fimpos; m++){                                            //Repetição do "fim"                                                     //Repetição direita, baixo, cima, esquerda
            for(int k = 0; k < 4; k++){                                             //Repetição Z, T, G, C
                for(int x = 0; x<2 ; x++){                                         //Repetição pos[0] e pos[1]
                    while(j[k] < n[k+1]){                                           //Repetição posição entre o mesmo tipo
                        if((def[k] + j[k])->pos[x] == v[ fim[m] ] && (def[k] + j[k])->pos[x] != 0){
                            for(int h = 0; h < 4; h++){
                                if(v[ fim[m] ]){
                                    fim[m] = fim[m] + 2*addpos[h];
                                    v[ fim[m] ] = -100 + j[k];
                                    v[ fim[m] ] = (def[k] + j[k])->pos[ not( x )];                            //Muda a posição do "fim atual"
                                    i--;
                                    h = 5;
                                }
                            }
                        }   
                        j[2]++;
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