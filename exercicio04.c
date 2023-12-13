#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct ContaBancaria {
    int numero_conta;
    char nome_titular[50];
    float saldo;
    char tipo_conta[20];
};

void limpar_tela() {
    system("cls || clear");
}

void depositar(struct ContaBancaria *conta) {
    float valor_deposito;
    printf("Digite o valor a ser depositado: R$ ");
    scanf("%f", &valor_deposito);

    if (valor_deposito > 0) {
        conta->saldo += valor_deposito;
        printf("Depósito realizado com sucesso!\n");
    } else {
        printf("Valor de depósito inválido!\n");
    }
}

void sacar(struct ContaBancaria *conta) {
    float valor_saque;
    printf("Digite o valor a ser sacado: R$ ");
    scanf("%f", &valor_saque);

    if (valor_saque > 0 && valor_saque <= conta->saldo) {
        conta->saldo -= valor_saque;
        printf("Saque realizado com sucesso!\n");
    } else {
        printf("Valor de saque inválido ou saldo insuficiente!\n");
    }
}

void imprimir_saldo(struct ContaBancaria conta) {
    printf("Número da Conta: %d\n", conta.numero_conta);
    printf("Nome do Titular: %s\n", conta.nome_titular);
    printf("Tipo de Conta: %s\n", conta.tipo_conta);
    printf("Saldo Atual: R$ %.2f\n", conta.saldo);
}

int main() {
    setlocale(LC_ALL, "portuguese");

    struct ContaBancaria minha_conta;
    minha_conta.numero_conta = 12345678;
    strcpy(minha_conta.nome_titular, "Maria");
    minha_conta.saldo = 13000;
    strcpy(minha_conta.tipo_conta, "Corrente");

    int opcao;

    do {
        printf("\n              MENU             \n");
        printf(" OPÇÃO   |        FUNÇÃO       \n");
        printf("   1     | Depositar           \n");
        printf("   2     | Sacar               \n");
        printf("   3     | Consultar saldo    \n");
        printf("   4     | Sair do programa    \n");

        printf("\nEscolha a opção desejada: ");
        scanf("%d", &opcao);

        limpar_tela();

        switch (opcao) {
            case 1:
                depositar(&minha_conta);
                break;

            case 2:
                sacar(&minha_conta);
                break;

            case 3:
                imprimir_saldo(minha_conta);
                break;

            case 4:
                printf("Saindo do programa...\n");
                break;

            default:
                printf("Opção inválida. Tente novamente!\n");
        }
    } while (opcao != 4);

    return 0;
}

