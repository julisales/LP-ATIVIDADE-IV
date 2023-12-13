#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct ficha_alunos
{
    char nome[200];
    char nascimento[200];
    float notas[2];
    float media;
};

void calcular_media(struct ficha_alunos *alunos)
{
    int i, j;

    for (i = 0; i < 5; i++)
    {
        float soma = 0;
        for (j = 0; j < 5; j++)
        {
            soma += alunos[i].notas[j];
        }

        alunos[i].media = soma / 5; 
    }
}

void verificar_aprovacao(struct ficha_alunos aluno)
{
    if (aluno.media >= 7.0)
    {
        printf("Aprovado!\n");
    }
    else
    {
        printf("Reprovado!\n");
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    struct ficha_alunos alunos[5];
    int i, j;

    for (i = 0; i < 5; i++)
    {
        printf("Informações do %d° aluno:\n\n", i + 1);

        printf("Nome: ");
        gets(alunos[i].nome);

        printf("Data de nascimento: ");
        gets(alunos[i].nascimento);

        for (j = 0; j < 2; j++)
        {
            printf("%dª nota: ", j + 1);
            scanf("%f", &alunos[i].notas[j]);
        }

        calcular_media(alunos);
        fflush(stdin);
        system("cls || clear");
    }

    for (i = 0; i < 2; i++)
    {
        printf("\nInformações do %d° aluno:\n", i + 1);
        printf("Nome: %s \n", alunos[i].nome);
        printf("Data de nascimento: %s\n", alunos[i].nascimento);
        for(j = 0; j < 2; j++){
            printf("%d° nota: %.2f \n", j + 1, alunos[i].notas[j]);
        }
        printf("Média: %.2f\n", alunos[i].media);

        verificar_aprovacao(alunos[i]);
    }

    return 0;
}
