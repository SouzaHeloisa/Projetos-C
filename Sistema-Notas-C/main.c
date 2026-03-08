#include <stdio.h>
#include <locale.h>

void cadastrarNota(float notas[], int *quantidade);
void mostrarNotas(float notas[], int quantidade);
void calcularMedia(float notas[], int quantidade, float *media);
void maiorNota(float notas[], int quantidade, float *maior);

int main() {
    setlocale(LC_ALL, "");
    float notas[50];
    int quantidade = 0;
    int opcao;

    do {

        printf("\n===== SISTEMA DE NOTAS =====\n");
        printf("1 - Cadastrar nota\n");
        printf("2 - Mostrar notas\n");
        printf("3 - Calcular media\n");
        printf("4 - Mostrar maior nota\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                cadastrarNota(notas, &quantidade);
                break;

            case 2:
                mostrarNotas(notas, quantidade);
                break;

            case 3: {
                float media;
                calcularMedia(notas, quantidade, &media);
                printf("Media da turma: %.2f\n", media);
                break;
            }

            case 4: {
                float maior;
                maiorNota(notas, quantidade, &maior);
                printf("Maior nota: %.2f\n", maior);
                break;
            }

            case 5:
                printf("Encerrando programa...\n");
                break;

            default:
                printf("Opcao invalida!\n");

        }

    } while(opcao != 5);

    return 0;
}

void cadastrarNota(float notas[], int *quantidade) {

    printf("Digite a nota: ");
    scanf("%f", &notas[*quantidade]);

    (*quantidade)++;

}

void mostrarNotas(float notas[], int quantidade) {

    if(quantidade == 0) {
        printf("Nenhuma nota cadastrada.\n");
        return;
    }

    printf("\nNotas cadastradas:\n");

    for(int i = 0; i < quantidade; i++) {
        printf("Nota %d: %.2f\n", i + 1, notas[i]);
    }

}

void calcularMedia(float notas[], int quantidade, float *media) {

    if(quantidade == 0) {
        *media = 0;
        return;
    }

    float soma = 0;

    for(int i = 0; i < quantidade; i++) {
        soma += notas[i];
    }

    *media = soma / quantidade;

}

void maiorNota(float notas[], int quantidade, float *maior) {

    if(quantidade == 0) {
        *maior = 0;
        return;
    }

    *maior = notas[0];

    for(int i = 1; i < quantidade; i++) {
        if(notas[i] > *maior) {
            *maior = notas[i];
        }
    }

}