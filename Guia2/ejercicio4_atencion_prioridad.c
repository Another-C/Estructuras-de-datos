/**
 * Guía 2 - Ejercicio 4: Simulación de Atención con Prioridad en Filas
 *
 * Este ejercicio simula la atención de personas en dos filas: una fila prioritaria y una fila normal.
 * La fila prioritaria atiende primero, y luego se alterna entre una persona de la fila prioritaria
 * y dos de la fila normal. Las edades de las personas en la fila prioritaria están entre 60 y 105 años,
 * mientras que en la fila normal están entre 1 y 59 años.
 *
 * La función `atencion` procesa las filas alternando la atención entre las personas de la fila prioritaria
 * y las de la fila normal, respetando el patrón de atención.
 *
 * Aprendizaje: manejo de filas y simulación de atención con reglas de prioridad, procesamiento dinámico
 * de datos con estructuras auxiliares.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "elemento.h"
#include "TAD-Fila.h"
#include "TAD-Pila.h"

/**
 * @brief Genera un valor aleatorio de edad según el tipo de fila.
 * @param tipo 1 para fila prioritaria, 2 para fila normal.
 * @return Edad aleatoria dentro del rango correspondiente.
 */
int generarEdad(int tipo) {
    if (tipo == 1) { // Fila prioritaria (edad entre 60 y 105)
        return rand() % 46 + 60;
    } else { // Fila normal (edad entre 1 y 59)
        return rand() % 59 + 1;
    }
}

/**
 * @brief Simula la atención de personas en las filas respetando el patrón de prioridad.
 * @param prioritaria Fila de atención prioritaria.
 * @param normal Fila de atención normal.
 */
void atencion(FILA *prioritaria, FILA *normal) {
    int atendidosPrioritaria = 0;
    int atendidosNormal = 0;

    while (!empty(*prioritaria) || !empty(*normal)) {
        // Atendemos una persona de la fila prioritaria
        if (!empty(*prioritaria)) {
            int edad = verPrimero(*prioritaria)->numero;
            printf("Atendiendo persona de la fila prioritaria: %d años\n", edad);
            extract(prioritaria);
            atendidosPrioritaria++;
        }

        // Atendemos dos personas de la fila normal por cada una de la fila prioritaria
        if (!empty(*normal) && atendidosPrioritaria % 2 == 0) {
            int edad = verPrimero(*normal)->numero;
            printf("Atendiendo persona de la fila normal: %d años\n", edad);
            extract(normal);
            atendidosNormal++;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Debe ingresar la cantidad de personas para la fila prioritaria y la fila normal.\n");
        return 1;
    }

    int cantidadPrioritaria = atoi(argv[1]);
    int cantidadNormal = atoi(argv[2]);

    srand(time(NULL)); // Inicializar la semilla para generar números aleatorios

    FILA filaPrioritaria = crearFila();
    FILA filaNormal = crearFila();

    // Agregar personas a la fila prioritaria
    for (int i = 0; i < cantidadPrioritaria; i++) {
        insert(&filaPrioritaria, crearElemento(generarEdad(1))); // Fila prioritaria
    }

    // Mostrar contenido de la fila prioritaria
    printf("Fila prioritaria:\n");
    verFila(filaPrioritaria);

    // Agregar personas a la fila normal
    for (int i = 0; i < cantidadNormal; i++) {
        insert(&filaNormal, crearElemento(generarEdad(2))); // Fila normal
    }

    // Mostrar contenido de la fila normal
    printf("Fila normal:\n");
    verFila(filaNormal);

    // Simular la atención
    atencion(&filaPrioritaria, &filaNormal);

    return 0;
}

