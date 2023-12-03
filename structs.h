    #include<stdio.h>

    typedef struct
    {
        double V;
        double Vr;
        int zona;

    } Base;

    typedef struct
    {
        long int type;
        double V;
        double S;
        double I;
        double fp;
        double Z;
        double alpha;
        int zT;
        int pos[2];

    } Componente;