#pragma once
#include <iostream>
#include "listaPosiciones.h"

const int MAX_UNDO = 10;

typedef struct {
    tListaPosiciones lista[MAX_UNDO];
    int cont;
} tListaUndo;


void inicializar(tListaUndo& lista_undo); // inicializa el número de elementos a 0.
void insertar_final(tListaUndo& lista_undo, tListaPosiciones lista_pos); // inserta lista_pos al final de la lista. Si no hay espacio desplaza todos los elementos hacia la izquierda, descartando el colocado en la posición. Finalmente inserta en la última posición.
tListaPosiciones ultimos_movimientos(tListaUndo& lista_undo); // devuelve el último elemento de la lista y actualiza su contador
