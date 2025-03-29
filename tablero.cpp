#include <iostream>
#include <fstream>
#include <string>
#include "tablero.h"
#include "celda.h"
using namespace std;

void inicializar(tTablero& tablero) {
    tablero.nFils = 0;
    tablero.nCols = 0;
}

void inicializar_tablero(tTablero& tablero, int nfils, int ncols) {
    tablero.nFils = nfils;
    tablero.nCols = ncols;
    for (int i = 0; i < nfils; i++) {
        for (int j = 0; j < ncols; j++) {
            inicializar(tablero.datos[i][j]);
        }
    }
}

int num_filas(tTablero& tab) {
    return tab.nFils;
}

int num_columnas(tTablero& tab) {
    return tab.nCols;
}

tCelda dame_celda(const tTablero& tablero, int fila, int columna) {
    return tablero.datos[fila][columna];
}


bool es_valida(tTablero& tablero, int fila, int columna) {
    return fila >= 0 && fila < tablero.nFils && columna >= 0 && columna < tablero.nCols;
}

void poner_celda(tTablero& tablero, int fila, int columna, tCelda celda) {
    tablero.datos[fila][columna] = celda;
}