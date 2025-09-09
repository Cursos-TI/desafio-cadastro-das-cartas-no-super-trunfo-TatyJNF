#include <stdio.h>

struct Carta {
    char estado;
    char codigo[4];     
    char cidade[50];    
    unsigned long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
    float superPoder;
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
        scanf("%lu", &cartas[i].populacao);

        printf("Area (em km2): ");
        scanf("%f", &cartas[i].area);

        printf("PIB (em bilhoes): ");
        scanf("%f", &cartas[i].pib);

        printf("Numero de pontos turisticos: ");
        scanf("%d", &cartas[i].pontosTuristicos);

        // Cálculos
        cartas[i].densidade = (float)cartas[i].populacao / cartas[i].area;
        cartas[i].pibPerCapita = (cartas[i].pib * 1000000000.0f) / cartas[i].populacao;

        // Super Poder
        cartas[i].superPoder = (float)cartas[i].populacao 
                             + cartas[i].area 
                             + cartas[i].pib 
                             + (float)cartas[i].pontosTuristicos 
                             + cartas[i].pibPerCapita 
                             + (1.0f / cartas[i].densidade);
    }

    // Exibir informações das cartas
    printf("\n\n=== Informacoes das Cartas ===\n");
    for (i = 0; i < 2; i++) {
        printf("\nCarta %d:\n", i + 1);
        printf("Estado: %c\n", cartas[i].estado);
        printf("Codigo: %s\n", cartas[i].codigo);
        printf("Nome da Cidade: %s\n", cartas[i].cidade);
        printf("Populacao: %lu\n", cartas[i].populacao);
        printf("Area: %.2f km2\n", cartas[i].area);
        printf("PIB: %.2f bilhoes de reais\n", cartas[i].pib);
        printf("Numero de Pontos Turisticos: %d\n", cartas[i].pontosTuristicos);
        printf("Densidade Populacional: %.2f hab/km2\n", cartas[i].densidade);
        printf("PIB per Capita: %.2f reais\n", cartas[i].pibPerCapita);
        printf("Super Poder: %.2f\n", cartas[i].superPoder);
    }

    // Arrays para comparação
    const char *atributos[] = {
        "Populacao",
        "Area",
        "PIB",
        "Pontos Turisticos",
        "Densidade Populacional",
        "PIB per Capita",
        "Super Poder"
    };

    // Valores numéricos para cada carta
    float valoresCarta1[] = {
        (float)cartas[0].populacao,
        cartas[0].area,
        cartas[0].pib,
        (float)cartas[0].pontosTuristicos,
        cartas[0].densidade,
        cartas[0].pibPerCapita,
        cartas[0].superPoder
    };

    float valoresCarta2[] = {
        (float)cartas[1].populacao,
        cartas[1].area,
        cartas[1].pib,
        (float)cartas[1].pontosTuristicos,
        cartas[1].densidade,
        cartas[1].pibPerCapita,
        cartas[1].superPoder
    };

    // Regras: 1 = maior vence, 0 = menor vence
    int regraMaiorVence[] = {1, 1, 1, 1, 0, 1, 1};

    // Comparações com for puro
    printf("\n\n=== Comparacao de Cartas ===\n");
    for (i = 0; i < 7; i++) {
        int carta1Vence;
        if (regraMaiorVence[i]) {
            carta1Vence = valoresCarta1[i] > valoresCarta2[i];
        } else {
            carta1Vence = valoresCarta1[i] < valoresCarta2[i];
        }

        printf("%s: Carta %d venceu (%d)\n", 
               atributos[i], 
               carta1Vence ? 1 : 2, 
               carta1Vence);
    }

    return 0;
}
