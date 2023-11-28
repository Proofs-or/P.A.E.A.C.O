    #include <stdio.h>
    #include<stdlib.h>
    #include"structs.h"
    #include "in.h"
    #include "sep.h"
    #include "pu.h"


    int main(void){

        int menu(int n);

        printf("P.A.I.A.C.O. 1.0\nAll rights reserved\n");

        int aux = menu(0);
        if(aux == 99){
            return -99;
        }
        return 0;
    }

    int menu(int n){

        int seriously(int n);
        int choice = -99;
        int aux = 0;

        if(n == 0){
            printf("Boas vindas ao P.A.I.A.C.O!\n");
        }
        printf("************MENU************\n");
        printf("1.\tIncluir S.E.P.\n");
        printf("2.\tCalcular S.E.P.\n");
        printf("3.\tSobre\n");
        for(int i = 0; choice != 1 && choice != 2 && choice != 3; i++){
            scanf("%d", &choice);
            if(choice == 1){
                int componentes[5];
                in_info( &componentes[1], &componentes[0] );

                Impedancia Zstruct[ componentes[1] ];
                Trafo Tstruct[ componentes[2] ];
                Gerador Gstruct[ componentes[3] ];
                Carga Cstruct[ componentes[4] ];

                in_store(&Zstruct[0], &Tstruct[0], &Gstruct[0], &Cstruct[0], &componentes[0]);
                int* sep = calloc( 4 * componentes[0] * componentes[0] , sizeof(int));
                //sep_matrix(&sep[0], &componentes[0], Tstruct, Gstruct, Zstruct, Cstruct);
                free(sep);
                aux = 1;
            
            }/*else if(choice == 2){
                printf("1.\tPassar S.E.P. para PU\n");
                printf("2.\tCalcular Fluxo de Potencia\n");
                scanf("%d", &choice);
                if(choice == 1){
                    double Sbase;
                    printf("Inserir base de potencia do sistema (MVA)");
                    scanf("%lf", &Sbase);
                    #define zonas (componentes[2] + 1);
                    double Vbase[zonas];
                    printf("Inserir tensão base (kVA)\n");
                    scanf("%lf", &Vbase);
                    printf("Em qual zona foi registrada essa informacao?\n");
                    scanf("%d", &choice);
                    
                    //comporzona(choice, );
                    //pu_calcbases(Sbase, Vbase, &base[0], componentes[2]);
                    }
                }
                aux = 1;
            }*/
            if(aux != 1){
                if(seriously(i) == 99){
                    return 99;
                }
            }
        }
        return 0;
    }

    int seriously(int n){
        if(n == 0 || n == 1 || n == 2){
            printf("Entrada Invalida\n");
        }else if(n > 2 && n < 5){
            printf("TT\nTente novamente\n");
        }else if(n >= 5 && n < 10){
            printf(">|\tTente novamente\t|<\n");
        }else{
            printf("Erasing /system32, please wait...\n");
            for(int i = 0; i < 10; i++){
                printf(".\n");
            }
            return 99;
        }
        return 0;
    }
