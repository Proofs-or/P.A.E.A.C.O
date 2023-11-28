    #include<stdio.h>

    typedef struct
    {
        double V;
        double S;
        double Z;
        double I;

    } Basee;

    typedef struct
    {
        double V;
        double S;
        double fp;
        double Z;
        int zT;
        int pos;

    } Gerador;

    typedef struct
    {
        double S;
        double fp;
        double Z;
        int zT;
        int pos;

    } Carga;

    typedef struct
    {
        double S;
        double fp;
        double Z;
        double alpha;
        int zT;
        int pos[2];

    } Trafo;

    typedef struct
    {
        double S;
        double fp;
        double Z;
        int zT;
        int pos[2];

    } Impedancia;