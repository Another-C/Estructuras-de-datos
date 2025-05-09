#include <stdio.h>
#include <stdlib.h>


typedef struct s_elemento {
    int valor;
    struct s_elemento *siguiente;
} *ELEMENTO;

typedef struct s_pila {
    ELEMENTO tope;
} PILA;

typedef struct s_matriz {
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
1
Universidad del Bio Bio
Facultad de Ciencias Empresariales - Campus Concepci´on
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


/**
* @brief Retorna una matriz de pilas
* @param cantidad, n´umero de pilas que forman parte de la matriz (asuma que
* cantidad siempre ser´a menor a 20)
* @return matriz de pilas
*/
MATRIZ crearMatrizPilas(int cantidad){
    MATRIZ nueva;
    nueva.total_pilas = cantidad;

    for (int i = 0; i < cantidad; i++) {
        nueva.pilas[i] = crearPila();
    }

    return nueva;
}



/**
* @brief Agrega un nuevo elemento a una de las pilas de la matriz
* @param mp, matriz de pilas a la cual se le agrega el elemento
* @param valor, nuevo valor a agregar a la matriz
* @param nro_pila, ubicaci´on de la pila dentro de la matriz, considere un valor entre 1 y
* el total de pilas de la matriz
* @return matriz de pilas con el nuevo elemento
*/
MATRIZ agregarElementoPila(MATRIZ mp, int valor, int nro_pila){
if (nro_pila < 1 || nro_pila > mp.total_pilas) {
        printf("Número de pila fuera de rango\n");
        return mp;
    }

    ELEMENTO nuevo = (ELEMENTO) malloc(sizeof(struct s_elemento));
    nuevo->valor = valor;
    nuevo->siguiente = NULL;

    // Convertimos de índice 1-based a 0-based
    push(&mp.pilas[nro_pila - 1], nuevo);

    return mp;
}

/**
* @brief Obtener el mayor elemento de los topes de las pilas que forman parte de la matriz
* @param mp, matriz de pilas a procesar
* @return mayor valor considerando todos los topes de las pilas de la matriz
*/
int mayorElemento(MATRIZ mp){
    int mayor = -999999; // Asumimos que todos los valores serán mayores que esto

    for (int i = 0; i < mp.total_pilas; i++) {
        if (!isEmpty(mp.pilas[i])) {
            int valor = verTope(mp.pilas[i])->valor;
            if (valor > mayor) {
                mayor = valor;
            }
        }
    }

    return mayor;
}

int main() {
    MATRIZ m = crearMatrizPilas(3);

    m = agregarElementoPila(m, 10, 1);
    m = agregarElementoPila(m, 20, 2);
    m = agregarElementoPila(m, 15, 3);
    m = agregarElementoPila(m, 30, 2); // 30 ahora está en la cima de la pila 2

    int mayor = mayorElemento(m);
    printf("El mayor de los topes es: %d\n", mayor); // Debe imprimir 30

    return 0;
}
