#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "inputoutput.h"
using namespace std;

void mostrar_cabecera() {
	cout << "BUSCAMINAS" << endl;
	cout << "----------" << endl;
}

void pedir_pos(int& fila, int& columna) {
	cout << "Introduce la fila y la columna: ";
	cin >> fila >> columna;
}

void mostrar_resultado(const tJuego& juego) {
	if (juego.mina_explotada) {
		cout << "Has explotado una mina" << endl;
	}
	else {
		cout << "Has ganado" << endl;
	}
}

void mostrar_juego_consola(const tJuego& juego) {
	for (int i = 0; i < juego.tablero.nFils; ++i) {
		for (int j = 0; j < juego.tablero.nCols; ++j) {
			tCelda celda = juego.tablero.datos[i][j];
			if (es_visible(celda)) {
				if (es_mina(celda)) {
					cout << "* ";
				}
				else if (contiene_numero(celda)) {
					cout << dame_numero(celda) << " ";
				}
				else {
					cout << "  ";
				}
			}
			else if (esta_marcada(celda)) {
				cout << "M ";
			}
			else {
				cout << ". ";
			}
		}
		cout << endl;
	}
}

bool cargar_juego(tJuego& juego) {
	ifstream archivo;
	string nombre;
	cout << "Introduce el nombre del archivo: ";
	cin >> nombre;
	archivo.open(nombre);
	if (archivo.is_open()) {
		archivo >> juego;
		archivo.close();
		return true;
	}
	else {
		return false;
	}
}


