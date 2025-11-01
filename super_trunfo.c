#include <stdio.h>
#include <string.h>

float CalcularDensidade(int populacao, float area) {
    return (float) populacao / area;
}

float pibPerCapita(float pib, int populacao) {
    return pib / (float) populacao;
}

float obterAtributo(int opcao, int populacao, float area, float pib, int pontos, float pibCapita, float densidade) {
    switch (opcao) {
        case 1:
        return populacao;
        case 2: 
        return area;
        case 3: 
        return pib;
        case 4: 
        return pontos;
        case 5: 
        return pibCapita;
        case 6: 
        return densidade;
        default: return 0;
    }
}

void nomeAtributo(int opcao, char *nome) {
    switch (opcao) {
        case 1: 
        strcpy(nome, "População"); 
        break;
        case 2: 
        strcpy(nome, "Área"); 
        break;
        case 3: 
        strcpy(nome, "PIB"); 
        break;
        case 4: 
        strcpy(nome, "Pontos Turísticos"); 
        break;
        case 5: 
        strcpy(nome, "PIB per Capita"); 
        break;
        case 6: 
        strcpy(nome, "Densidade Demográfica"); 
        break;
        default: strcpy(nome, "Desconhecido");
    }
}

int main() {
    char nome1[50], nome2[50];
    int populacao1, populacao2, pontos_tr1, pontos_tr2;
    float area1, area2, pib1, pib2;
    float densidadePop1, densidadePop2, pibCapita1, pibCapita2;
    int op1, op2;
    float valor1a, valor1b, valor2a, valor2b;
    char nomeA1[50], nomeA2[50];
    float soma1, soma2;
    int pontos1 = 0, pontos2 = 0;

    // Dados do País 1
    printf("Digite o nome do País 1:\n");
    fgets(nome1, sizeof(nome1), stdin);
    nome1[strcspn(nome1, "\n")] = 0;

    printf("Digite a População do País 1:\n");
    scanf("%d", &populacao1);
    printf("Digite a área em km² do País 1:\n");
    scanf("%f", &area1);
    printf("Digite o PIB do País 1:\n");
    scanf("%f", &pib1);
    printf("Digite a quantidade de pontos turísticos do País 1:\n");
    scanf("%d", &pontos_tr1);

    getchar(); // limpa buffer

    // Dados do País 2
    printf("\nDigite o nome do País 2:\n");
    fgets(nome2, sizeof(nome2), stdin);
    nome2[strcspn(nome2, "\n")] = 0;

    printf("Digite a População do País 2:\n");
    scanf("%d", &populacao2);
    printf("Digite a área em km² do País 2:\n");
    scanf("%f", &area2);
    printf("Digite o PIB do País 2:\n");
    scanf("%f", &pib2);
    printf("Digite a quantidade de pontos turísticos do País 2:\n");
    scanf("%d", &pontos_tr2);

    // Cálculos
    densidadePop1 = CalcularDensidade(populacao1, area1);
    densidadePop2 = CalcularDensidade(populacao2, area2);
    pibCapita1 = pibPerCapita(pib1, populacao1);
    pibCapita2 = pibPerCapita(pib2, populacao2);

    // Menu interativo
    printf("\nEscolha dois atributos para comparar entre %s e %s:\n", nome1, nome2);
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - PIB per Capita\n6 - Densidade Demográfica\n");

    printf("\nEscolha o primeiro atributo: ");
    scanf("%d", &op1);

    do {
        printf("\nEscolha o segundo atributo diferente do primeiro:\n");
        scanf("%d", &op2);
        (op2 == op1) ? printf("Você já escolheu esse atributo. Escolha outro.\n") : 0;
    } while (op2 == op1);

    // Obtenção dos valores
    valor1a = obterAtributo(op1, populacao1, area1, pib1, pontos_tr1, pibCapita1, densidadePop1);
    valor1b = obterAtributo(op2, populacao1, area1, pib1, pontos_tr1, pibCapita1, densidadePop1);

    valor2a = obterAtributo(op1, populacao2, area2, pib2, pontos_tr2, pibCapita2, densidadePop2);
    valor2b = obterAtributo(op2, populacao2, area2, pib2, pontos_tr2, pibCapita2, densidadePop2);

    nomeAtributo(op1, nomeA1);
    nomeAtributo(op2, nomeA2);

    // Comparação individual com operador ternário
    (op1 == 6) ? 
        (valor1a < valor2a ? pontos1++ : (valor2a < valor1a ? pontos2++ : 0)) :
        (valor1a > valor2a ? pontos1++ : (valor2a > valor1a ? pontos2++ : 0));

    (op2 == 6) ? 
        (valor1b < valor2b ? pontos1++ : (valor2b < valor1b ? pontos2++ : 0)) :
        (valor1b > valor2b ? pontos1++ : (valor2b > valor1b ? pontos2++ : 0));

    // Soma dos atributos
    soma1 = valor1a + valor1b;
    soma2 = valor2a + valor2b;

    // Exibição
    printf("\nRESULTADO DA COMPARAÇÃO\n");
    printf("País 1: %s\n", nome1);
    printf("País 2: %s\n\n", nome2);

    printf("Atributo 1: %s\n", nomeA1);
    printf("%s: %.2f\n%s: %.2f\n\n", nome1, valor1a, nome2, valor2a);

    printf("Atributo 2: %s\n", nomeA2);
    printf("%s: %.2f\n%s: %.2f\n\n", nome1, valor1b, nome2, valor2b);

    printf("Soma dos atributos:\n%s: %.2f\n%s: %.2f\n\n", nome1, soma1, nome2, soma2);

    // Determinação do vencedor com operador ternário
    (soma1 > soma2) ? printf("Vencedor: %s\n", nome1)
    : (soma2 > soma1) ? printf("Vencedor: %s\n", nome2)
    : printf("Empate!\n");

    return 0;
}

