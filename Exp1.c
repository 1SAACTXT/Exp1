#include <stdio.h>
#include <string.h>

#define COMPETIDORES 5
#define DISTANCIAS 3

// Función simple para validar que el nombre solo contenga letras
int nombreValido(char nombre[]) {
    for (int i = 0; i < strlen(nombre); i++) {
        if ((nombre[i] < 'A' || nombre[i] > 'Z') && (nombre[i] < 'a' || nombre[i] > 'z')) {
            return 0; // No es letra
        }
    }
    return 1;
}

int main() {
    char nombres[COMPETIDORES][20];
    float tiempos[COMPETIDORES][DISTANCIAS]; // [competidor][distancia]
    char distancias[DISTANCIAS][10] = {"50m", "100m", "200m"};
    int i, j;

    // Ingreso de nombres y tiempos
    for (i = 0; i < COMPETIDORES; i++) {
        do {
            printf("Ingresa el nombre del competidor %d (solo letras): ", i + 1);
            scanf("%s", nombres[i]);
            if (!nombreValido(nombres[i])) {
                printf("Nombre inválido. Intenta de nuevo.\n");
            }
        } while (!nombreValido(nombres[i]));

        for (j = 0; j < DISTANCIAS; j++) {
            do {
                printf("Tiempo de %s en %s (solo números positivos): ", nombres[i], distancias[j]);
                scanf("%f", &tiempos[i][j]);
                if (tiempos[i][j] <= 0) {
                    printf("Tiempo inválido. Debe ser un número positivo.\n");
                }
            } while (tiempos[i][j] <= 0);
        }
    }

    // Ganadores por distancia
    for (j = 0; j < DISTANCIAS; j++) {
        int ganador = 0;
        float mejorTiempo = tiempos[0][j];
        for (i = 1; i < COMPETIDORES; i++) {
            if (tiempos[i][j] < mejorTiempo) {
                mejorTiempo = tiempos[i][j];
                ganador = i;
            }
        }
        printf("Ganador de %s: %s con %.2f segundos\n", distancias[j], nombres[ganador], mejorTiempo);
    }

    // Mejor tiempo general
    int mejorCompetidor = 0;
    float mejorTiempoGeneral = tiempos[0][0];
    for (i = 0; i < COMPETIDORES; i++) {
        for (j = 0; j < DISTANCIAS; j++) {
            if (tiempos[i][j] < mejorTiempoGeneral) {
                mejorTiempoGeneral = tiempos[i][j];
                mejorCompetidor = i;
            }
        }
    }
    printf("Mejor tiempo de toda la competencia: %s con %.2f segundos\n", nombres[mejorCompetidor], mejorTiempoGeneral);

    return 0;
}
