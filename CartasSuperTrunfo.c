#include <stdio.h>

struct Carta {
    char estado;
    char codigo[4];     // ex: A01
    char cidade[50];    // nome da cidade
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;    // novo
    float pibPerCapita; // novo
};

int main() {
    struct Carta cartas[2];
    int i;

    // Cadastro das 2 cartas
    for (i = 0; i < 2; i++) {
        printf("\n=== Cadastro da Carta %d ===\n", i + 1);

        printf("Estado (A-H): ");
        scanf(" %c", &cartas[i].estado);

        printf("Codigo da carta (ex: A01): ");
        scanf("%s", cartas[i].codigo);

        printf("Nome da cidade: ");
        scanf(" %[^\n]", cartas[i].cidade);

        printf("Populacao: ");
        scanf("%d", &cartas[i].populacao);

        printf("Area (em km2): ");
        scanf("%f", &cartas[i].area);

        printf("PIB (em bilhoes): ");
        scanf("%f", &cartas[i].pib);

        printf("Numero de pontos turisticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);

        // Cálculos
        cartas[i].densidade = cartas[i].populacao / cartas[i].area;
        cartas[i].pibPerCapita = (cartas[i].pib * 1000000000.0f) / cartas[i].populacao;
        // ↑ multipliquei o PIB por 1 bilhão para converter do valor "em bilhões" para "reais"
    }

    // Exibir as cartas cadastradas
    printf("\n\n=== Informacoes das Cartas ===\n");
    for (i = 0; i < 2; i++) {
        printf("\nCarta %d:\n", i + 1);
        printf("Estado: %c\n", cartas[i].estado);
        printf("Codigo: %s\n", cartas[i].codigo);
        printf("Nome da Cidade: %s\n", cartas[i].cidade);
        printf("Populacao: %d\n", cartas[i].populacao);
        printf("Area: %.2f km2\n", cartas[i].area);
        printf("PIB: %.2f bilhoes de reais\n", cartas[i].pib);
        printf("Numero de Pontos Turisticos: %d\n", cartas[i].pontosTuristicos);
        printf("Densidade Populacional: %.2f hab/km2\n", cartas[i].densidade);
        printf("PIB per Capita: %.2f reais\n", cartas[i].pibPerCapita);
    }

    return 0;
}
