#include <iostream>
#include <string>
#include <fstream>
#include "listaUndo.h"
#include "juego.h"
using namespace std;

void inicializar(tListaUndo& lista) {
	lista.cont = 0;
}


void insertar_final(tListaUndo& lista_undo, tListaPosiciones lista_pos) {
    if (lista_undo.cont < MAX_UNDO) {
        lista_undo.lista[lista_undo.cont] = lista_pos;
        lista_undo.cont++;
    }
    else {
        // Desplazar todos los elementos hacia la izquierda
        for (int i = 1; i < MAX_UNDO; i++) {
            lista_undo.lista[i - 1] = lista_undo.lista[i];
        }
        // Insertar en la última posición
        lista_undo.lista[MAX_UNDO - 1] = lista_pos;
    }
}

tListaPosiciones ultimos_movimientos(tListaUndo& lista_undo) {
    if (lista_undo.cont > 0) {
        lista_undo.cont--;
        return lista_undo.lista[lista_undo.cont];
    }
    else {
        return tListaPosiciones();
    }
}

std::istream& operator>> (std::istream& in, tJuego& juego) {
    in >> juego.num_jugadas;
    in >> juego.mina_explotada;
    in >> juego.num_minas;
    in >> juego.num_descubiertas;
    in >> juego.tablero.nFils;
    in >> juego.tablero.nCols;
    for (int i = 0; i < juego.tablero.nFils; ++i) {
        for (int j = 0; j < juego.tablero.nCols; ++j) {
            in >> juego.tablero.datos[i][j].visible;
            int estado;
            in >> estado;
            juego.tablero.datos[i][j].estado = static_cast<tEstado>(estado);
            in >> juego.tablero.datos[i][j].numero;
            in >> juego.tablero.datos[i][j].marcada;
        }
    }
    return in;
}