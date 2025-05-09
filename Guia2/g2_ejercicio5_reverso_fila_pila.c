/**
 * Guía 2 - Ejercicio 5: Comparar reverso de pila con fila
 *
 * Se generan `n` valores aleatorios entre [a, b] y se insertan
 * tanto en una fila como en una pila. Se verifica si la fila
 * es el reverso exacto de la pila.
 *
 * Aprendizaje: comprensión del comportamiento FIFO y LIFO,
 * comparación de estructuras dinámicas, y manipulación segura
 * de datos mediante copias auxiliares.
 */


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "elemento.h"
#include "TAD-Fila.h"
#include "TAD-Pila.h"

/**
 * @brief Determina si la fila es el reverso exacto de la pila
 * @param f fila a procesar
 * @param p pila a procesar
 * @return 1 si f es reverso exacto de p, 0 en caso contrario
 */
int reversoExacto(FILA f, PILA p) {
    FILA fAux = crearFila();
    PILA pAux = crearPila();

    while (!empty(f) && !isEmpty(p)) {
        int numFila = verPrimero(f)->numero;
        int numPila = verTope(p)->numero;

        if (numFila != numPila) {
            return 0;
        }

        insert(&fAux, crearElemento(numFila));
        push(&pAux, crearElemento(numPila));

        extract(&f);
        pop(&p);
    }

    int resultado = empty(f) && isEmpty(p);

    // Restaurar estructuras
    while (!empty(fAux)) {
        insert(&f, crearElemento(verPrimero(fAux)->numero));
        extract(&fAux);
    }

    while (!isEmpty(pAux)) {
        push(&p, crearElemento(verTope(pAux)->numero));
        pop(&pAux);
    }

    return resultado;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Uso: %s <n> <a> <b>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    int desde = atoi(argv[2]);
    int hasta = atoi(argv[3]);

    srand(time(NULL));

    FILA fila = crearFila();
    PILA pila = crearPila();

    printf("Valores insertados en la FILA:\n");
    for (int i = 0; i < n; i++) {
        int val = desde + rand() % (hasta - desde + 1);
        insert(&fila, crearElemento(val));
        printf("%d ", val);
    }
    printf("\n");

    printf("Valores insertados en la PILA:\n");
    for (int i = 0; i < n; i++) {
        int val = desde + rand() % (hasta - desde + 1);
        push(&pila, crearElemento(val));
        printf("%d ", val);
    }
    printf("\n");

    if (reversoExacto(fila, pila)) {
        printf("La fila ES el reverso exacto de la pila.\n");
    } else {
        printf("La fila NO es el reverso exacto de la pila.\n");
    }

    return 0;
}

