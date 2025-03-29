#include <iostream>
#include <string>
#include <fstream>
#include "juego.h"
#include "listaPosiciones.h"
using namespace std;

void inicializar(tJuego& juego) {
	juego.num_jugadas = 0;
	juego.mina_explotada = false;
	juego.num_minas = 0;
	juego.num_descubiertas = 0;
}

void inicializar(tJuego& juego, int nfils, int ncols) {
	inicializar(juego);
	inicializar_tablero(juego.tablero, nfils, ncols);
}

int dame_num_jugadas(const tJuego& juego) {
	return juego.num_jugadas;
}

int dame_num_filas(const tJuego& juego) {
	return juego.tablero.nFils;
}

int dame_num_columnas(const tJuego& juego) {
	return juego.tablero.nCols;
}

int dame_num_minas(const tJuego& juego) {
	return juego.num_minas;
}

bool contiene_mina(const tJuego& juego, int fila, int columna) {
	return es_mina(dame_celda(juego.tablero,fila, columna));
}

bool es_visible(const tJuego& juego, int fila, int columna) {
	return es_visible(dame_celda(juego.tablero, fila, columna));
}

bool esta_marcada(const tJuego& juego, int fila, int columna) {
	return esta_marcada(dame_celda(juego.tablero, fila, columna));
}

bool esta_vacia(const tJuego& juego, int fila, int columna) {
	return esta_vacia(dame_celda(juego.tablero, fila, columna));
}

bool contiene_numero(const tJuego& juego, int fila, int columna) {
	return contiene_numero(dame_celda(juego.tablero, fila, columna));
}

int dame_numero(const tJuego& juego, int fila, int columna) {
	return dame_numero(dame_celda(juego.tablero, fila, columna));
}

bool esta_completo(const tJuego& juego) {
	return juego.num_descubiertas == (dame_num_filas(juego) * dame_num_columnas(juego) - juego.num_minas);
}

bool mina_explotada(const tJuego& juego, int fila, int columna) {
	return juego.mina_explotada && es_mina(dame_celda(juego.tablero, fila, columna));
}

bool esta_terminado(const tJuego& juego, int fila, int columna) {
	return esta_completo(juego) || mina_explotada(juego, fila, columna);
}

void poner_mina(tJuego& juego, tTablero& tablero, int fila, int columna) {
	if (!es_mina(dame_celda(tablero, fila, columna))) {
		tCelda celda = dame_celda(tablero, fila, columna);
		poner_mina(celda);  // Esta línea asegura que la celda se configure como una mina
		poner_celda(tablero, fila, columna, celda);
		juego.num_minas++;
	}
}


void marcar_desmarcar(tJuego& juego, tTablero& tablero, int fila, int columna) {
	if (!es_visible(dame_celda(tablero, fila, columna))) {
		if (esta_marcada(dame_celda(tablero, fila, columna))) {
			tCelda celda = dame_celda(tablero, fila, columna);
			desmarcar_celda(celda);
			poner_celda(tablero, fila, columna, celda);
		}
		else {
			tCelda celda = dame_celda(tablero, fila, columna);
			marcar_celda(celda);
			poner_celda(tablero, fila, columna, dame_celda(tablero, fila, columna));
		}
	}
}

void ocultar(tJuego& juego, tTablero& tablero, int fila, int columna) {
	if (!es_visible(dame_celda(tablero, fila, columna))) {
		tCelda celda = dame_celda(tablero, fila, columna);
		ocultar_celda(celda);
	}
}

void juega(tJuego& juego, int fila, int columna, tListaPosiciones& lista_pos) {
	if (!es_visible(dame_celda(juego.tablero, fila, columna)) && !esta_marcada(dame_celda(juego.tablero, fila, columna))) {
		if (es_mina(dame_celda(juego.tablero, fila, columna))) {
			juego.mina_explotada = true;
		}
		else {
			tCelda celda = dame_tablero(juego.tablero, fila, columna);
			descubrir_celda(celda);
			juego.num_descubiertas++;
			if (dame_numero(dame_celda(juego.tablero, fila, columna)) == 0) {
				for (int i = -1; i < 2; i++) {
					for (int j = -1; j < 2; j++) {
						if (es_valida(juego.tablero, fila + i, columna + j)) {
							if (!es_visible(dame_celda(juego.tablero, fila + i, columna + j))) {
								juega(juego, fila + i, columna + j, lista_pos);
							}
						}
					}
				}
			}
		}
	}
}


tCelda& dame_tablero(tTablero& tablero, int fila, int columna) {
	return tablero.datos[fila][columna];
}