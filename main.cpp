#include <iostream>
#include <fstream>
#include <string>
#include "juego.h"
#include "inputoutput.h"
#include "listaundo.h"
#include "listaPosiciones.h"

using namespace std;

void juega(tJuego& juego, int fila, int columna, tListaUndo& lista_undo, tListaPosiciones& lista_pos);
void imprimir_tablero(const tTablero& tablero);

int main() {
    tJuego juego;
    tListaUndo lista_undo;
    tListaPosiciones lista_pos;

    inicializar(lista_undo);
    inicializar(lista_pos);

    if (cargar_juego(juego)) {
        int fila, columna;
        mostrar_juego_consola(juego);
		mostrar_cabecera();
        imprimir_tablero(juego.tablero);  // Imprimir el tablero después de cargar el juego
        dame_num_jugadas(juego);
        do {
            pedir_pos(fila, columna);
            juega(juego, fila, columna, lista_undo, lista_pos);
            mostrar_juego_consola(juego);
            imprimir_tablero(juego.tablero);  // Imprimir el tablero después de cada jugada
        } while (!esta_terminado(juego, fila, columna) && (fila != -1 || columna != -1));

        if (esta_terminado(juego, fila, columna)) {
            mostrar_resultado(juego);
        }
        else {
            cout << "Partida abandonada" << endl;
        }
    }
    else {
        cout << "Error al cargar el juego" << endl;
    }

    return 0;
}

void juega(tJuego& juego, int fila, int columna, tListaUndo& lista_undo, tListaPosiciones& lista_pos) {
    if (fila == -2 && columna == -2) {
        int fila_marcada, columna_marcada;
        pedir_pos(fila_marcada, columna_marcada);
        marcar_desmarcar(juego, juego.tablero, fila_marcada, columna_marcada);
    }
    else if (fila == -3 && columna == -3) {
        if (lista_undo.cont > 0) {
            tListaPosiciones ult_mov = ultimos_movimientos(lista_undo);
            for (int i = 0; i < ult_mov.cont; i++) {
                int x = dame_posX(ult_mov, i);
                int y = dame_posY(ult_mov, i);
                descubrir_celda(dame_tablero(juego.tablero, x, y));
            }
        }
        else {
            cout << "No hay movimientos para deshacer" << endl;
        }
    }
    else {
        juega(juego, fila, columna, lista_pos);
        insertar_final(lista_undo, lista_pos);
    }
}

// Función de depuración para imprimir el tablero
void imprimir_tablero(const tTablero& tablero) {
    for (int i = 0; i < tablero.nFils; ++i) {
        for (int j = 0; j < tablero.nCols; ++j) {
            if (es_mina(tablero.datos[i][j])) {
                cout << "* ";
            }
            else {
                cout << ". ";

            }
        }
    }
}
