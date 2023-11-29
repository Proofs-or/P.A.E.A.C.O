    #include<stdio.h>

    typedef struct
    {
        double V;
        double S;
        double Z;
        double I;

    } Base;

    typedef struct
    {
        char type;
        double V;
        double S;
        double fp;
        double Z;
        double alpha;
        int zT;
        int pos[2];

    } Componente;