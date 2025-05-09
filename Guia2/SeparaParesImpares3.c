#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "elemento.h"
#include "TAD-Fila.h"
#include "TAD-Pila.h"

void separaParesImpares(FILA valores, PILA *a, PILA *b) {
    FILA copia = crearFila();

    // Clonamos manualmente la fila original para no modificarla
    while (!empty(valores)) {
        int numero = verPrimero(valores)->numero;

        // Clasificamos según paridad
        if (numero % 2 == 0) {
            push(a, crearElemento(numero));
        } else {
            push(b, crearElemento(numero));
        }

        // Mantener los datos en una copia (por si se quiere mostrar después)
        insert(&copia, crearElemento(numero));
        extract(&valores);
    }

    // Restauramos la fila original con los datos clonados
    while (!empty(copia)) {
        insert(&valores, crearElemento(verPrimero(copia)->numero));
        extract(&copia);
    }
}

void separaParesImpares(FILA valores, PILA *a, PILA *b);

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
    PILA pilaPares = crearPila();
    PILA pilaImpares = crearPila();

    // 3. Generar y agregar a la fila
    for (int i = 0; i < n; i++) {
        int valor = desde + rand() % (hasta - desde + 1);
        insert(&fila, crearElemento(valor));
    }

    // 4. Mostrar la fila original
    printf("Contenido de la fila original:\n");
    verFila(fila);

    // 5. Separar en pilas
    separaParesImpares(fila, &pilaPares, &pilaImpares);

    // 6. Mostrar la fila original (ya fue vaciada por verFila, así que no se muestra de nuevo)

    // 7. Mostrar pila de pares
    printf("Contenido de la pila de pares:\n");
    verPila(clonar(pilaPares)); // usamos clonar para no destruir

    // 8. Mostrar pila de impares
    printf("Contenido de la pila de impares:\n");
    verPila(clonar(pilaImpares));

    return 0;
}