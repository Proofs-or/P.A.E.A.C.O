        #include<stdio.h>
        void odss_init(FILE *arq, double V){
        arq = fopen("sys.dss", "a");

        fprintf(arq, "clear !limpa a memória do ODSS\nSet DefaultBaseFrequency=60 !Frequencia base de 60Hz\nnew circuit.4busDYBal   basekV=%.4lf phases=3 !Cria um novo sistema\n~ mvasc3=200000 200000 !Barra fonte dada como infinita\n!DADOS DOS CONDUTORES -> EXEMPLO, INCOMPATÍVEL COM P.A.I.A.C.O, mas substitui as impedâncias das linhas pelos dados de seus condutores\n\nnew wiredata.conductor Runits=mi Rac=0.306 GMRunits=ft GMRac=0.0244  Radunits=in Diam=0.721\nnew wiredata.neutral   Runits=mi Rac=0.592 GMRunits=ft GMRac=0.00814 Radunits=in Diam=0.563\n\nnew linegeometry.4wire nconds=4 nphases=3 reduce=yes !Realiza redução de KRON na linha\n\n!Localização geométrica dos condutores -> EXEMPLO, INCOMPATÍVEL COM P.A.I.A.C.O~ cond=1 wire=conductor units=ft x=-4   h=28\n~ cond=2 wire=conductor units=ft x=-1.5 h=28\n ~ cond=3 wire=conductor units=ft x=3    h=28\n ~ cond=4 wire=neutral   units=ft x=0    h=24\n\nnew line.imoedancia1 geometry=4wire length=2000 units=ft bus1=sourcebus bus2=n2 !O tamanho da linha interfere na impedância da mesma\n\n\n\n!DADOS DO P.A.I.A.C.O\n", V);
        fclose(arq);
    }

    void odss_include(FILE *arq, Componente *Xstruct, int u){
        arq = fopen("sys.dss", "a");
        if((Xstruct + u*sizeof(Componente))->type == 3){
            fprintf(arq, "new load.carga%d phases=3 bus1=n%d conn=wye kV=%.4lf kW=%.4lf pf=%.2lf  model=1 ! Inclusão da Carga %d", u + 1, (Xstruct + u*sizeof(Componente))->pos[0], (Xstruct + u*sizeof(Componente))->V, (Xstruct + u*sizeof(Componente))->S * (Xstruct + u*sizeof(Componente))->fp, (Xstruct + u*sizeof(Componente))->fp, u + 1);
        }

        if((Xstruct + u*sizeof(Componente))->type == 1){
            fprintf(arq, "new transformer.trafo%d xhl=6\n");
            for(int x = 0; x < 2; x++){
                fprintf(arq, "~ wdg=%d bus=%d conn=wye kV=%.4lf kVA=%.4lf %r=%.2lf\n", u + 1, x + 1,  (Xstruct + u*sizeof(Componente))->pos[x], (Xstruct + u*sizeof(Componente))->V, (Xstruct + u*sizeof(Componente))->S, (Xstruct + u*sizeof(Componente))->Z);
            }
        }
        fclose(arq);
    }

    void odss_bases(Base *b, int nb, FILE *arq){
        arq = fopen("sys.dss", "a");
        for(int x = 1; x < nb; x++){
            fprintf(arq, ", %lf", (b + x*sizeof(Base))->V);
        }
        fclose(arq);
    }

    void odss_close(FILE *arq){
        arq = fopen("sys.dss", "a");
        fprintf(arq, "]\n calcvoltagebases     ! **** calcula as bases de tensão\nsolve ! instrução para resolver o fluxo de carga\n\n! Formas diferentes para mostrar diferentes relatórios. Irá gerar arquivos de relatórios\n//show Voltage  LL Nodes !mostra tensoes de linha\n//show voltages LN Nodes  !mostra tensoes de fase\n//show currents resid=yes elements  ! mostra as correntes\n//Show Powers kva Elements !mostra a potencia\n");
        fclose(arq);
    }