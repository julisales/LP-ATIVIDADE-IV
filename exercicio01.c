#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


struct ficha_contatos
{
    char nome[200];
    char telefone[200];
    char email[200];
};

#define TAM 3

char* buscar_telefone(struct ficha_contatos contatos[], int num_contatos, char* nome)
{
    int i;
    for (i = 0; i < num_contatos; i++)
    {
        if (strcmp(contatos[i].nome, nome) == 0)
        {
            return contatos[i].telefone;
        }
    }

    return "Contato não cadastrado!";
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    struct ficha_contatos contatos[3];

    int i;
    char busca_nome[200];

    for (i = 0; i < TAM; i++)
    {
        printf("Informações do %dº usuário: \n \n", i + 1);

        printf("Nome: ");
        gets(contatos[i].nome);

        printf("Email: ");
        gets(contatos[i].email);

        printf("Telefone: ");
        gets(contatos[i].telefone);

        fflush(stdin);
        system("cls || clear");
    }

    printf("Busque o contato desejado pelo nome: ");
    gets(busca_nome);

    char* telefone_encontrado = buscar_telefone(contatos, TAM, busca_nome);

    if(telefone_encontrado != 0)
    {
        printf("Telefone: %s \n", telefone_encontrado);
    }
    else 
    {
        printf("Contato não encontrado! \n");
    }

    return 0;
}