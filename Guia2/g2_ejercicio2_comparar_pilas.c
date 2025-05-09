/**
 * Guía 2 - Ejercicio 2: Comparar si dos pilas son iguales
 *
 * Se generan dos pilas con `n` valores aleatorios cada una, dentro del intervalo [a, b],
 * leyendo los valores desde la línea de comandos. Cada iteración genera dos números diferentes.
 *
 * La función `sonIguales` compara las pilas elemento a elemento, desde el tope hacia abajo,
 * sin destruirlas, usando copias internas.
 *
 * Aprendizaje: comparación estructural de pilas, clonado de estructuras dinámicas,
 * y validación de igualdad profunda en estructuras LIFO.
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#include "elemento.h"
#include "TAD-Fila.h"
#include "TAD-Pila.h"

int sonIguales(PILA a, PILA b) {
    PILA copiaA = clonar(a);
    PILA copiaB = clonar(b);

    while (!isEmpty(copiaA) && !isEmpty(copiaB)) {
        int valorA = verTope(copiaA)->numero;
        int valorB = verTope(copiaB)->numero;

        if (valorA != valorB) {
            return 0; // Son distintas
        }

        pop(&copiaA);
        pop(&copiaB);
    }

    // Si una quedó con elementos y la otra no: no son iguales
    if (!isEmpty(copiaA) || !isEmpty(copiaB)) {
        return 0;
    }

    return 1; // Son iguales
}



int sonIguales(PILA a, PILA b);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Uso: %s <n> <a> <b>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);

    srand(time(NULL));

    PILA px = crearPila();
    PILA py = crearPila();

    for (int i = 0; i < n; i++) {
        int valX = a + rand() % (b - a + 1);
        int valY = a + rand() % (b - a + 1);

        push(&px, crearElemento(valX));
        push(&py, crearElemento(valY));
    }

    printf("Contenido de la pila px:\n");
    verPila(clonar(px)); // usamos clonar para no destruir

    printf("Contenido de la pila py:\n");
    verPila(clonar(py));

    int iguales = sonIguales(px, py);
    if (iguales) {
        printf("Las pilas son iguales.\n");
    } else {
        printf("Las pilas son distintas.\n");
    }

    return 0;
}
