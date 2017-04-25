#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_VET 1000

typedef struct{
char sigla[20];
int membros;
float S, A, N;
int totalvotos, faltantes;
}Partido;

typedef struct{
char partido[20];
char voto;
}Votos;

int main(){
int i, j=0, cont=0, totalmembros=0, totalvotos=0;
char c;
Partido Part[TAM_VET];
Votos Vot;
    printf("-------------- CADASTRANDO PARTIDOS -----------------\n\n");
    for(i=0; i<TAM_VET; i++){
        strcpy(Part[i].sigla, "");
        //fgets(Part[i].sigla, 20, stdin); //NAO TA LENDO NA MESMA LINHA
        scanf("%s", Part[i].sigla);
        if (strstr(Part[i].sigla, "FIM")) break;
        scanf("%d", &Part[i].membros);
        //printf("%d", Part[i].membros);
        Part[i].S=0;
        Part[i].N=0;
        Part[i].A=0;
        Part[i].totalvotos=0;
        cont++;
        totalmembros=totalmembros+Part[i].membros;
    }//printf("%d %d", cont, totalmembros);
    printf("\n\n---------------- VOTACAO ------------[S = SIM | N = NAO | A = ABSTENCIA]\n\n");
    for(i=0; i<totalmembros; i++){
 //       printf("Entrei");
        //fgets(Vot.partido, 99, stdin);
        scanf(" %s", Vot.partido);
//        printf ("%s", Vot.partido);
        if (strstr(Vot.partido, "FIM")) break;
        scanf(" %c", &c);
//        printf("%c\n", c);
        while(strcmp(Part[j].sigla, Vot.partido)) j++;
        if (c=='S'){
            Part[j].S++;
//            printf ("%f\n", Part[j].S);
        }else if (c=='N'){
             Part[j].N++;
 //            printf ("%d\n", Part[j].N);
        }else if (c=='A'){
            Part[j].A++;
 //           printf ("%d\n", Part[j].A);
        }
            Part[j].totalvotos++;
            Part[j].faltantes=Part[j].membros-Part[j].totalvotos;
            j=0;
    }
    printf("\n\n---------------- APURACAO ----------------------------------------\n\n");
    for (i=0; i<cont; i++){
        printf("%s: %.0f (Sim) %.0f%%,", Part[i].sigla, Part[i].S, (Part[i].S/(Part[i].membros))*100);
        printf(" %.0f (Nao) %.0f%%,", Part[i].N, (Part[i].N/(Part[i].membros))*100);
        printf(" %.0f (Abst) %.0f%%,", Part[i].A, (Part[i].A/(Part[i].membros))*100);
        printf(" %.d (Faltas) %d%%\n", Part[i].faltantes, (Part[i].faltantes*100)/Part[i].membros);
    }
return 0;


}
