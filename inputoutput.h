#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "juego.h"
#include "colors.h"

const int N_HUECOS = 2;
const int MAX_FILS = 5;
const int MAX_COLS = 5;

typedef enum { NUMERO, VACIA, MINA } tEstado;

typedef struct {
    bool visible; /* celda descubierta */
    tEstado estado; /* tipo de celda */
    int numero; /* numero de bombas que la rodean */
    bool marcada; /* para marcar posiciones de las minas */
} tElemento;

typedef tElemento tMatriz[MAX_FILS][MAX_COLS];

void mostrar_cabecera();
void pedir_pos(int& fila, int& columna);
void mostrar_resultado(const tJuego& juego);
void mostrar_juego_consola(const tJuego& juego);
bool cargar_juego(tJuego& juego);
void mostrar_matriz(const tMatriz& matriz);
std::istream& operator>> (std::istream& in, tJuego& juego);
