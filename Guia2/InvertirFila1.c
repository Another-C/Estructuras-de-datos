#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#include "elemento.h"
#include "TAD-Fila.h"
#include "TAD-Pila.h"

void invertirFila(FILA *f) {
    PILA auxiliar = crearPila();

    // Paso 1: Pasar todos los elementos de la fila a la pila
    while (!empty(*f)) {
        ELEMENTO e = crearElemento(verPrimero(*f)->numero); // copiamos el valor
        push(&auxiliar, e);
        extract(f);
    }

    // Paso 2: Pasar los elementos de la pila de nuevo a la fila
    while (!isEmpty(auxiliar)) {
        ELEMENTO e = crearElemento(verTope(auxiliar)->numero);
        insert(f, e);
        pop(&auxiliar);
    }
}

void invertirFila(FILA *f);

int main() {
    srand(time(NULL)); // semilla aleatoria

    FILA fila = crearFila();

    // 1. Crear 10 valores aleatorios entre 10 y 99 e insertarlos en la fila
    for (int i = 0; i < 10; i++) {
        int valor = 10 + rand() % 90;
        insert(&fila, crearElemento(valor));
    }

    // 2. Mostrar la fila creada
    printf("Fila original:\n");
    verFila(fila); // verFila extrae, así que hacemos copia para mantener

    // 3. Invertir la fila
    invertirFila(&fila);

    // 4. Mostrar la fila invertida
    printf("Fila invertida:\n");
    verFila(fila);

    return 0;
}