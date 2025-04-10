/**
 * @file 1-tarea-base.c
 * @authors your name (you@domain.com)
 * @brief Tarea 1 de la asignatura de Estructura de datos de la carrera ICInf de la UBB
 * @version 0.1
 * @date 2025-04-05
 * 
 * @copyright Copyright (c) 2025
 * 
 * Compilar usando gcc -Wall -o 1-tarea 1-tarea-base.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definicion de tipo de datos */
typedef struct s_figura{
    char color[50];
    int ancho, alto;
} FIGURA;

typedef struct s_nodo{
    FIGURA f;
    struct s_nodo *siguiente;
} *FIGURAS;

/* Crea y retorna un nodo de la lista */
FIGURAS crearNodo(FIGURA nueva);
/* Crea y retorna una figura */
FIGURA crearFigura(char *color, int ancho, int alto);
/* Agrega una figura a la lista y retorna la lista */
FIGURAS agregaFigura(FIGURAS lista, FIGURA nueva);
/* Muestra la lista y en caso de que sea vacia lo indica con un mensaje */
void verFiguras(FIGURAS lst);
/* Elimina una figura de la lista, dada su posicion */
FIGURAS eliminaPorIndice(FIGURAS lst, int indice);
/* Elimina una figura de la lista, dado su color */
FIGURAS eliminaPorColor(FIGURAS lst, char *eliminado);
/* Intercambia 2 figuras de la lista, dadas sus posiciones */
FIGURAS intercambia(FIGURAS lst, int i_esima, int j_esima);
/* Selecciona y retorna subconjunto de figuras con area mayor al umbral */
FIGURAS subConjunto(FIGURAS lst, float umbral);
/* Selecciona y retorna cuadrados dentro de la lista */
FIGURAS buscaCuadrados(FIGURAS lst);
/* Obtiene la intersección entre 2 listas: elementos que estan en lst_x y en lst_y */
FIGURAS interseccion(FIGURAS lst_x, FIGURAS lst_y);

int main(){
    /* Escriba su codigo aca */
    return 0;
}

/* Implementación de funciones */

/**
 * @brief crea un nodo conteniendo la figura entregada
 * 
 * @param f figura que sera incluida en el nuevo nodo
 * @return direccion de memoria del nodo creado
 */
FIGURAS crearNodo(FIGURA f){
    /* Escriba su codigo aca */
    FIGURAS nuevo = (FIGURAS)malloc(sizeof(struct s_nodo));
    if(nuevo==null){
        printf ("Error al asignar memoria\n")
        return null;
    }
    nuevo ->f = f;
    nuevo -> siguiente = NULL;

    return nuevo;
}

FIGURA crearFigura(char *color, int ancho, int alto){
    FIGURA nueva;
    strncpy(nueva.color, color, sizeof(nueva.color));
    nueva.color[sizeof(nueva.color) - 1];
    nueva.ancho = ancho;
    nueva.alto = alto;
    return nueva; 
}

FIGURAS agregaFigura (FIGURAS lista, FIGURA nueva){
    FIGURAS actual = lista; 
    while (actual != NULL){
        //Acá no supe como seguirla manito xD
    }
}

