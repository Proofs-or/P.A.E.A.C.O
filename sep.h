#include<stdio.h>
#include<stdlib.h>

void sep_matrix(int* v, int* n, Trafo *T, Gerador *G, Impedancia *Z, Carga *C){

    v[2*(*n)*(*n) + *n] = -200;
    v[2*(*n)*(*n) + *n - 1] = (T + 0)->pos[0];
    v[2*(*n)*(*n) + *n + 1] = (T + 0)->pos[1];

    int ini[2] = {(T + 0)->pos[0], 2*(*n)*(*n) + *n - 1};
    int fim[2] = {(T + 0)->pos[1], 2*(*n)*(*n) + *n + 1};

    int i = n[0];
    while(i > 0){
        int j[4] = {0, 0, 0, 0};

        while(j[2] < n[3]){
            if((G + j[2])->pos == ini[0]){

                ini[0] = (G + j[2])->pos;
                ini[1] = ini[1] -1;
                v[ini[1] - 1] = -300 - j[2];
                i--;
            
            }else if((G + j[2])->pos == fim[0]){

                fim[0] = (G + j[2])->pos;
                fim[1] = fim[2] + 1;  
                v[fim[1] + 1] = -300 - j[2];
                i--;
            }
            j[2]++;
        }

        while(j[3] < n[4]){
            if((C + j[3])->pos == ini[0]){

                ini[0] = (C + j[3])->pos;
                ini[1] = ini[1] -1;
                v[ini[1] - 1] = -400 - j[3];
                i--;
            
            }else if((C + j[3])->pos == fim[0]){

                fim[0] = (C + j[3])->pos;
                fim[1] = fim[2] + 1;  
                v[fim[1] + 1] = -400 - j[3];
                i--;
            }
            j[3]++;
        }

        while(j[1] < n[2]){
            if((T + j[1])->pos[0] == ini[0]){

                ini[0] = (T + j[1])->pos[0];
                ini[1] = ini[1] -1;
                v[ini[1] - 1] = -200 - j[1];
                i--;
            
            }else if((T + j[1])->pos[0] == fim[0]){

                fim[0] = (T + j[1])->pos[0];
                fim[1] = fim[2] + 1;  
                v[fim[1] + 1] = -200 - j[1];
                i--;
            }else if((T + j[1])->pos[1] == fim[0]){

                fim[0] = (T + j[1])->pos[1];
                fim[1] = fim[2] + 1;  
                v[fim[1] + 1] = -200 - j[1];
                i--;
            } else if((T + j[1])->pos[1] == ini[0]){

                ini[0] = (T + j[1])->pos[1];
                ini[1] = ini[1] -1;
                v[ini[1] - 1] = -200 - j[1];
                i--;
            }
            j[1]++;
        }


            while(j[0] < n[1]){
            if((Z + j[0])->pos[0] == ini[0]){

                ini[0] = (T + j[0])->pos[0];
                ini[1] = ini[1] -1;
                v[ini[1] - 1] = -100 - j[0];
                i--;
            
            }else if((T + j[0])->pos[0] == fim[0]){

                fim[0] = (T + j[0])->pos[0];
                fim[1] = fim[2] + 1;  
                v[fim[1] + 1] = -100 - j[0];
                i--;
            }else if((T + j[0])->pos[1] == fim[0]){

                fim[0] = (T + j[0])->pos[1];
                fim[1] = fim[2] + 1;  
                v[fim[1] + 1] = -100 - j[0];
                i--;
            } else if((T + j[0])->pos[1] == ini[0]){

                ini[0] = (T + j[0])->pos[1];
                ini[1] = ini[1] -1;
                v[ini[1] - 1] = -100 - j[0];
                i--;
            
            }
            j[0]++;
        }
    }

}