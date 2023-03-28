#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// -=-=-=-=-=--=-=-=-=-=-Ex1-=-=-=-=-=--=-=-=-=-=-
void hm(int mnts, int* h, int* m) // EX1
{
    *h = mnts/60;
    *m = mnts-(*h*60);
}

void Ex1_l1()
{
    int h, m;
    hm(180, &h, &m);

    printf("Horas: %i\nMinutos:%i", h, m);
};

// -=-=-=-=-=--=-=-=-=-=-Ex2-=-=-=-=-=--=-=-=-=-=-
void calcula_hexa(float l, float* area, float *perimetro)
{
    *area = (3*pow(l, 2)*sqrt(3))/2;
    *perimetro = 6*l;
}

void Ex2_l1()
{
    float area, perimetro;
    calcula_hexa(2, &area, &perimetro);
    printf("Area: %.2f\nPerimetro: %.2f", area, perimetro);
}
// -=-=-=-=-=--=-=-=-=-=-Ex3-=-=-=-=-=--=-=-=-=-=-
void mm(int v[], int tam, int* min, int* max)
{
    for(int i=0; i<tam; i++)
    {
        if(v[i]<(*min)) *min=v[i];
        if(v[i]>(*max)) *max=v[i];
    }
}

void Ex3_l1()
{
    int vetor[8] = {0, 1, 2, 3, 4, 5, 7, 8};
    int max, min;
    mm(vetor, 8, &min, &max);
    printf("Minimium: %i\nMaximum: %i", min, max);
}
// -=-=-=-=-=--=-=-=-=-=-Ex4-=-=-=-=-=--=-=-=-=-=-
float* duplica_vetor(float v[], int tam)
{
    float* cv = calloc(tam, sizeof(float));
    for(int i=0; i<tam; i++) *(cv+i) = v[i];
    return cv;
}

void Ex4_l1()
{
    float vector[8] = {1.2, 2.2, 1.4, 1.0, 1.8, 2.1, 3.2, 8.2};
    float* cvector = duplica_vetor(vector, 8);

    printf("Vector1 pos 5: %.1f\nVector2 pos 5: %.1f", vector[4], *(cvector+5));
}
// -=-=-=-=-=--=-=-=-=-=-Ex5-=-=-=-=-=--=-=-=-=-=-
int* uniao(int* x1, int* x2, int n1, int n2, int* qtd)
{
    int* u = calloc(n1+n2, sizeof(int));
    int i, j, k;

    *qtd=n1;

    for(i=0; i<n1; i++) u[i] = x1[i];

    for(i=0; i<n1; i++)
    {
        int inList = 0;
        for(j=0; j<n2; j++)
        {
            if(x1[i] == x2[j]) {
                inList = 1;
                break;
            }
            else {
                inList=0;
                k=j;
            }
        }
        if(!inList){
            u[*qtd] = x2[k];
            (*qtd)++;
        }
    }

    u = realloc(u, sizeof(int)*(*qtd));

    return u;
}

void Ex5_l1(){
    int qtd;
    int arr1[8] = {1, 2, 3, 4, 5, 6, 7, 9};
    int arr2[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int* arr3 = uniao(arr1, arr2, 8, 8, &qtd);

    for(int i=0; i<qtd; i++) printf("Pos: %i\nval: %i\n=-=-=-=-=-=-=-=\n", i, arr3[i]);
}
// -=-=-=-=-=--=-=-=-=-=-Ex6-=-=-=-=-=--=-=-=-=-=-
void Ex6_l1()
{
    int X=2,Y=2; // define trocado para variavel porem define a macro para substituir 2 no lugar de X e Y na compilacao
    int **A; // define uma variavel que aponta para outros ponteiros
    int i,j; // define as variaveis de interacao

    A = (int**)malloc(Y * sizeof(int*)); // Aloca um espaco de 2 pointeros de inteiro para A
    for(i = 0; i < Y; i++)
        A[i] = (int*)malloc(X * sizeof(int));  // Aloca 2 valores inteiros para o ponteiro dentro de A

    // Passa sobre os vetor 2D e insere a soma de i+j
    for(i = 0; i < Y; i++)
        for(j = 0; j < X; j++)
            A[i][j]=i+j;

    // Passa sobre o vetor 2D e printa na tela do usuário os valores
    for(i = 0; i < Y; i++)
        for(j = 0; j < X; j++)
            printf("%d \t",A[i][j]);

    // Libera os ponteiros dentro de A
    for(i = 0; i < Y; i++)
        free(A[i]);

    // Libera A
    free(A);
}
// -=-=-=-=-=--=-=-=-=-=-Ex7-=-=-=-=-=--=-=-=-=-=-
typedef struct dma {

int dia;
int mes;//30 dias
int ano;//365 dias

}Data;

void Ex7_l1()
{
    Data d1, d2;
    d1.ano=2022;
    d1.mes=9;
    d1.dia=10;

    d2.ano=2023;
    d2.mes=2;
    d2.dia=10;

    int diffAno = abs(d1.ano-d2.ano);
    int diffMes = abs(d1.mes-d2.mes);
    int diffDia = abs(d1.dia-d2.dia);

    int daysDiff = diffDia + (diffMes*30) + (diffAno*365);

    printf("Difference between dates in days: %i", daysDiff);
    
}
// -=-=-=-=-=--=-=-=-=-=-Ex8-=-=-=-=-=--=-=-=-=-=-
typedef struct tda
{
    char RA[20];
    char Nome[30];
    int n1;
    int n2;
}Aluno;

void Ex8_l1()
{
    int n, i;
    Aluno* alunos;
    printf("Insira o numero de alunos: ");
    scanf("%i", &n);

    alunos = (Aluno*) calloc(n, sizeof(Aluno));

    for(i=0; i<n; i++)
    {   
        printf("Aluno numero: %i \n", i);
        printf("Insira o RA: ");
        fflush(stdin);
        fgets(alunos[i].RA, 19, stdin);
        printf("Insira o Nome: ");
        fflush(stdin);
        fgets(alunos[i].Nome, 29, stdin);
        printf("Insira o n1: ");
        scanf("%i", &(alunos[i].n1));
        printf("Insira o n2: ");
        scanf("%i", &(alunos[i].n2));
        printf("-=-=-=-=-=-=\n");
    }
    for(i=0; i<n; i++)
    {
        float avrg = (alunos[i].n1 + alunos[i].n2)/2.0;
        printf("RA: %s\n", alunos[i].RA);
        printf("Nome: %s\n", alunos[i].Nome);
        printf("Media: %.1f\n", avrg);
        printf("-=-=-=-=-=-=\n");
    }

    free(alunos);
}
// -=-=-=-=-=--=-=-=-=-=-Ex9-=-=-=-=-=--=-=-=-=-=-
typedef struct prod
{
    char nome[30];
    int codigo;
    float preco;

}produtos;

void Ex9_l1()
{
    int tam = 2, i;
    produtos* armazem = malloc(tam*sizeof(produtos));

    for(i=0; i<tam; i++)
    {
        produtos* produto = (armazem+i);

        printf("Insira o nome: ");
        fflush(stdin);
        fgets(produto->nome, 29, stdin);
        printf("Insira o codigo: ");
        scanf("%i", &(produto->codigo));
        printf("Insira o preco: ");
        scanf("%f", &(produto->preco));
        printf("=-=-=-=-=-=\n");
    }
    printf("=-=-=-=-=-=\n");
    for(i=0; i<tam; i++)
    {
        produtos* produto = (armazem+i);
        printf("Nome: %s", produto->nome);
        printf("Codigo: %i\n", produto->codigo);
        printf("Preco: %.2f\n", produto->preco);
        printf("=-=-=-=-=-=\n");
    }

    free(armazem);
}
// -=-=-=-=-=--=-=-=-=-=-Ex10=-=-=-=-=--=-=-=-=-=-
typedef struct Q
{
    int tipo;
    float largura;
    float comprimento;
}Quarto;

float calcular_area(float largura, float comprimento)
{
    return largura*comprimento;
}

int lampada(int tipo, float area)
{
    int potencias[] = {12, 15, 18, 20, 22};
    return ceil((potencias[tipo]*area)/60);
} 

void Ex10_l1()
{
    Quarto* quartos = malloc(sizeof(Quarto));
    int i=0, j;
    int tipo;

    while (1)
    {
        Quarto* curQuarto = (quartos+i);
        printf("Insira o tipo de comodo: ");
        scanf("%i", &tipo);

        if (tipo < 1) break;
        if(tipo>5)
        {
            printf("Tipo de comodo nao existente\n");
        }

        quartos = realloc(quartos, (sizeof(Quarto)*i+1));

        curQuarto->tipo = tipo;

        printf("Insira a largura: ");
        scanf("%f", &(curQuarto->largura));

        printf("Insira o comprimento: ");
        scanf("%f", &(curQuarto->comprimento));
        printf("-=-=-=-=-=\n");

        i++;
    }

    for(j=0; j<i; j++)
    {
        Quarto* curQuarto = (quartos+j);
        printf("Tipo do comodo: %i\n", curQuarto->tipo);
        printf("Largura: %.2f\n", curQuarto->largura);
        printf("Comprimento: %.2f\n", curQuarto->comprimento);
        printf("Area: %.2f\n", calcular_area(curQuarto->largura, curQuarto->comprimento));
        printf("Lampadas: %i\n", lampada(curQuarto->tipo, calcular_area(curQuarto->largura, curQuarto->comprimento)));
        printf("-=-=-=-=-=");
    }

    free(quartos);
    
}

int main_List1(int sub) {
    //Ex1_l1();
    //Ex2_l1();
    //Ex3_l1();
    //Ex4_l1();
    //Ex5_l1();
    //Ex6_l1();
    //Ex7_l1();
    //Ex8_l1();
    //Ex9_l1();
    Ex10_l1();
    return 0;
}