#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define TAM 3

void limpartela (){
    system("cls || clear");
}

struct info_contatos {
	char nome[200];
	char telefone[200];
	char email[200];
};

char* buscar_nome(struct info_contatos contatos[], char* nome) {
	int i;
    for (i = 0; i < TAM; i++) {
        if (strcmp(contatos[i].nome, nome) == 0) {
            return contatos[i].telefone;
        }
    }
	return "Contato não cadastrado!";
}

int main (){
	setlocale(LC_ALL, "portuguese");
	
	struct info_contatos contatos[TAM];
	
	int i;
	char busca[200];
	char* resultado_busca;
	
	for (i = 0; i < TAM; i++) {
        printf("Cadastro do %dº contato: \n\n", i + 1);
        
		printf("Nome: ");
        gets(contatos[i].nome);
        
		printf("Telefone: ");
        gets(contatos[i].telefone);
        
		printf("Email: ");
        gets(contatos[i].email);
        
        fflush(stdin);
        limpartela();
    }
    
    printf("Digite o nome para fazer a busca do contato: ");
    gets(busca);
    
	resultado_busca = buscar_nome(contatos, busca);
	
	limpartela();
	
	printf("%-20s %-20s \n", "Nome", "Telefone");
	printf("%-20s %-20s \n", busca, resultado_busca);
	
	return 0;
}
