/*
/**
 * Guía 1 - Ejercicio 2: Uso de la función push
 *
 * Crea una pila vacía y luego agrega dos elementos (a y b)
 * utilizando la función push. El objetivo es que el elemento `a`
 * quede sobre `b` (es decir, `a` debe ser el tope de la pila).
 *
 * Finalmente, se recorre la pila imprimiendo sus valores desde el tope
 * hacia el fondo, vaciándola en el proceso.
 *
 * Aprendizaje: comprensión del comportamiento LIFO de una pila y
 * cómo se estructura mediante punteros.
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
    
//     Y las siguientes lineas de código
// EJERCICIO 2 (crear pila y mediante el push hacer que a vaya encima de b)
    int main() {
    
    PILA pila = crearPila();
    

    ELEMENTO a = (ELEMENTO) malloc(sizeof(struct s_elemento));
    a->valor = 29;
    a->siguiente = NULL;
    ELEMENTO b = (ELEMENTO) malloc(sizeof(struct s_elemento));
    b->valor = 6;
    b->siguiente = NULL;

    push(&pila, b); // b queda al tope
    push(&pila, a); // a queda al tope
    
    while (!isEmpty(pila)) {
        ELEMENTO actual = verTope(pila);
        printf("%d\n", actual->valor);
        pop(&pila);
    }

    }
