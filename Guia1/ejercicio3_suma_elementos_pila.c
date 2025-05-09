/*
/**
 * Guía 1 - Ejercicio 3: Suma de elementos en una pila
 *
 * Este programa define una función `suma` que recibe una pila como parámetro
 * y retorna la suma de todos sus elementos sin modificar su contenido.
 *
 * Para lograrlo, se clona la pila y se recorre la copia acumulando los valores.
 * 
 * En el main, se construye una pila con 2 elementos, se muestra la suma total
 * y luego se imprime el tope actual para demostrar que la pila original quedó intacta.
 *
 * Aprendizaje: uso de punteros, manipulación segura de estructuras dinámicas,
 * e implementación de operaciones sin efectos colaterales.
 */

*/
#include <stdio.h>
#include <stdlib.h>

typedef struct s_elemento{
    int valor;
    struct s_elemento *siguiente;
    } *ELEMENTO;
    typedef struct s_pila{
    ELEMENTO tope;
    } PILA;
    typedef struct s_matriz{
    PILA pilas[20];
    int total_pilas;
    } MATRIZ;

    /**
* @brief Crea una pila vacia
* @return pila creada
*/
PILA crearPila(){
    PILA nueva;
    nueva.tope = NULL;
    return nueva;
    }
   
    /**
    * @brief Verifica si la pila esta vacia
    * @param p, pila a revisar
    * @return 1 en caso de que la pila este vacia y 0 en caso contrario
    */
    int isEmpty(PILA p){
    return p.tope == NULL;
    }
    /**
    * @brief Agrega un elemento en el tope de la pila
    * @param p, direcci´on de memoria de la pila
    * @param e, puntero a la palabra que se agrega a la pila
    */
  
    void push(PILA *p, ELEMENTO e){
    if (isEmpty(*p)){
    p->tope = e;
    }
    else{
    e->siguiente = p->tope;
    p->tope = e;
    }
    }
   
    /**
    * @brief extraer el tope de la pila
    * @param p, pila a procesar
    */
    void pop(PILA *p){
    p->tope = p->tope->siguiente;
    }
   
    /**
    * @brief Retornar el tope de la pila SIN EXTRAER
    * @param p, pila a procesar
    * @return puntero al elemento que se encuentra en el tope de la pila
    */
    ELEMENTO verTope(PILA p){
    return p.tope;
    }

    //EJERCICIO 3 *Se pide construir una función que retorne la suma de todos los
    //* Elementos de la pila que recibe como parámetro. una vez implementada la función se pide: 

    //FUNCIÓN QUE retorna la suma de todos los elementos de una pila.
int suma(PILA p) {
    int total = 0;
    PILA copia = crearPila();

    // Clonar manualmente los elementos (pila → copia), para preservar orden
    ELEMENTO actual = p.tope;
    while (actual != NULL) {
        // Creamos un nuevo elemento con el mismo valor
        ELEMENTO nuevo = (ELEMENTO) malloc(sizeof(struct s_elemento));
        nuevo->valor = actual->valor;
        nuevo->siguiente = NULL;
        push(&copia, nuevo);

        actual = actual->siguiente;
    }

    // Recorrer la copia para sumar (sin afectar la original)
    while (!isEmpty(copia)) {
        total += verTope(copia)->valor;
        pop(&copia);
    }

    return total;
}

int main() {
    // 1. Crear la pila y agregar 2 elementos
    PILA pila = crearPila();

    ELEMENTO e1 = (ELEMENTO) malloc(sizeof(struct s_elemento));
    e1->valor = 15;
    e1->siguiente = NULL;

    ELEMENTO e2 = (ELEMENTO) malloc(sizeof(struct s_elemento));
    e2->valor = 8;
    e2->siguiente = NULL;

    push(&pila, e1); // e1 (15)
    push(&pila, e2); // e2 (8) queda al tope

    // 2. Imprimir la suma usando la función suma
    int resultado = suma(pila);
    printf("Suma de los elementos de la pila: %d\n", resultado); // 8 + 15 = 23

    // 3. Imprimir el tope de la pila (debe ser 8 aún)
    printf("Tope actual de la pila: %d\n", verTope(pila)->valor);

    return 0;
}
