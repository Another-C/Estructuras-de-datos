/**
 * Guía 2 - Ejercicio 4: Atención intercalada con prioridad
 *
 * Se simulan dos filas de atención: una normal y otra prioritaria. Las edades
 * se generan aleatoriamente según el tipo de fila (prioritaria: 60-105, normal: 1-59).
 * 
 * La función `atencion` simula la atención intercalando una persona prioritaria
 * por cada dos personas normales, comenzando por la prioritaria. 
 * El proceso imprime la edad de cada persona atendida y su tipo de fila.
 *
 * Aprendizaje: gestión de múltiples estructuras dinámicas con condiciones de parada independientes,
 * manipulación FIFO en contextos de simulación, y lógica de control de turnos con prioridad.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "elemento.h"
#include "TAD-Fila.h"
#include "TAD-Pila.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "elemento.h"
#include "TAD-Fila.h"

/**
 * @brief simula la atención de filas
 *
 * @param prioritaria fila de atención prioritaria
 * @param normal fila de atención normal
 */
void atencion(FILA prioritaria, FILA normal) {
    int turno = 0; // 0: prioritaria, 1 o 2: normal (se reinicia cada 3 turnos)

    while (!empty(prioritaria) || !empty(normal)) {
        if (turno == 0 && !empty(prioritaria)) {
            printf("Atendiendo persona PRIORITARIA de edad: %d\n", verPrimero(prioritaria)->numero);
            extract(&prioritaria);
        } else if (!empty(normal)) {
            printf("Atendiendo persona NORMAL de edad: %d\n", verPrimero(normal)->numero);
            extract(&normal);
        }

        // Avanzar turno: 0 → 1 → 2 → 0...
        turno = (turno + 1) % 3;

        // Si una fila está vacía, continuar con la otra
        if (empty(prioritaria) && !empty(normal)) turno = 1;
        if (empty(normal) && !empty(prioritaria)) turno = 0;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <cantidad_prioritarios> <cantidad_normales>\n", argv[0]);
        return 1;
    }

    int cant_prioritarios = atoi(argv[1]);
    int cant_normales = atoi(argv[2]);

    srand(time(NULL));

    FILA filaPrioritaria = crearFila();
    FILA filaNormal = crearFila();

    // Agregar personas a la fila prioritaria (edades de 60 a 105)
    for (int i = 0; i < cant_prioritarios; i++) {
        int edad = 60 + rand() % (105 - 60 + 1);
        insert(&filaPrioritaria, crearElemento(edad));
    }

    // Mostrar fila prioritaria
    printf("Fila prioritaria:\n");
    verFila(filaPrioritaria);

    // Agregar personas a la fila normal (edades de 1 a 59)
    for (int i = 0; i < cant_normales; i++) {
        int edad = 1 + rand() % 59;
        insert(&filaNormal, crearElemento(edad));
    }

    // Mostrar fila normal
    printf("Fila normal:\n");
    verFila(filaNormal);

    // Simular atención
    printf("\n--- Simulación de atención ---\n");
    atencion(filaPrioritaria, filaNormal);

    return 0;
}




