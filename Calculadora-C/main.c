#include <stdio.h>
#include <locale.h>

void soma(float a, float b, float *resultado);
void subtracao(float a, float b, float *resultado);
void multiplicacao(float a, float b, float *resultado);
void divisao(float a, float b, float *resultado);

int main() {
    setlocale(LC_ALL, "");
    
    int opcao;
    float num1, num2, resultado;

    do{
        printf("\n======== Calculadora Simples ========\n");
        printf("    Escolha a operacao:\n");
        printf("    1. Soma\n");
        printf("    2. Subtracao\n");
        printf("    3. Multiplicacao\n");
        printf("    4. Divisao\n");
        printf("    5. Sair\n");
        printf("====================================\n");
        printf("Escolha um Opcao: ");
        scanf("%d", &opcao);

        if (opcao >= 1 && opcao <= 4) {
            printf("Digite o primeiro numero: ");
            scanf("%f", &num1);

            printf("Digite o segundo numero: \n");
            scanf("%f", &num2);

        switch (opcao) {
            case 1:
                soma(num1, num2, &resultado);
                printf("Resultado: %.2f\n", resultado);
                break;
            case 2:
                subtracao(num1, num2, &resultado);
                printf("Resultado: %.2f\n", resultado);
                break;
            case 3:
                multiplicacao(num1, num2, &resultado);
                printf("Resultado: %.2f\n", resultado);
                break;
            case 4:
                if (num2 != 0) {
                    divisao(num1, num2, &resultado);
                    printf("Resultado: %.2f\n", resultado);
                } else {
                    printf("===== Erro: Divisao por zero nao e permitida. =====\n");
                }
                break;
            }
        }if (opcao == 5) {
            printf("===== Saindo da calculadora. Ate logo! =====\n");
        } else if (opcao < 1 || opcao > 5) {
            printf("===== Opcao invalida. Por favor, escolha uma opcao entre 1 e 5. git=====\n");
        }
    }while (opcao != 5);    

    return 0;
}

void soma(float a, float b, float *resultado) {
    *resultado = a + b;
}

void subtracao(float a, float b, float *resultado) {
    *resultado = a - b;
}

void multiplicacao(float a, float b, float *resultado) {
    *resultado = a * b;
}

void divisao(float a, float b, float *resultado) {
    *resultado = a / b;
}