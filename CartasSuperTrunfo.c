#include <stdio.h>

struct Carta {
    char estado;
    char codigoDaCarta[4];    
    char nomeDaCidade[50];   
    int populacao;
    float area;
    float pib;
    int numeroDePontosTuristicos;
};

int main() {
    struct Carta cartas[8]; 
    int i;

    for (i = 0; i < 8; i++) {
        printf("\n=== Cadastro da Carta %d ===\n", i + 1);

        printf("Digite a letra do estado (A-H): ");
        scanf(" %c", &cartas[i].estado);

        printf("Digite o codigo da carta (ex: A01): ");
        scanf("%s", cartas[i].codigoDaCarta);

        printf("Digite o nome da cidade: ");
        scanf(" %[^\n]", cartas[i].nomeDaCidade);

        printf("Digite a populacao: ");
        scanf("%d", &cartas[i].populacao);

        printf("Digite a area (em km2): ");
        scanf("%f", &cartas[i].area);

        printf("Digite o PIB (em bilhoes): ");
        scanf("%f", &cartas[i].pib);

        printf("Digite o numero de pontos turisticos: ");
        scanf("%d", &cartas[i].numeroDePontosTuristicos);
    }


    printf("\n\n=== Informacoes das Cartas ===\n");
    for (i = 0; i < 8; i++) {
        printf("\nCarta %d:\n", i + 1);
        printf("Estado: %c\n", cartas[i].estado);
        printf("Codigo: %s\n", cartas[i].codigoDaCarta);
        printf("Nome da Cidade: %s\n", cartas[i].nomeDaCidade);
        printf("Populacao: %d\n", cartas[i].populacao);
        printf("Area: %.2f km2\n", cartas[i].area);
        printf("PIB: %.2f bilhoes de reais\n", cartas[i].pib);
        printf("Numero de Pontos Turisticos: %d\n", cartas[i].numeroDePontosTuristicos);
    }

    return 0;
}
