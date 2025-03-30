#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "inputoutput.h"
using namespace std;
const char CHAR_MINA = '*'

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

void colorNumero(int numero) {
    switch (numero) {
    case 1: cout << BLUE; break;
    case 2: cout << GREEN; break;
    case 3: cout << RED; break;
    case 4: cout << DBLUE; break;
    case 5: cout << DGREEN; break;
    case 6: cout << DRED; break;
    default:
        break;
    }
}

void mostrarCoutSeparadorMat(int huecoCelda) {
    cout << "\t -+";
    for (int col = 0; col < MAX_COLS; ++col) {
        cout << setw(huecoCelda + 1) << setfill('-') << '+' << setfill(' ');
    }
    cout << endl;
}

void mostrarCeldaConsola(const tMatriz& matriz, int fila, int columna, int huecos) {
    tElemento celda = matriz[fila][columna];

    if (!celda.visible && !celda.marcada) {
        cout << BG_GRAY << GRAY << setw(huecos) << setfill(' ') << ' ' << RESET;
    } else {
        cout << BG_BLACK << BLACK;
        if (!celda.marcada) {
            if (celda.estado == MINA) {
                cout << RED << setw(huecos) << setfill(' ') << CHAR_MINA << RESET;
            } else {
                if (celda.estado == VACIA) {
                    cout << setw(huecos) << setfill(' ') << ' ' << RESET;
                } else {
                    if (celda.estado == NUMERO) {
                        int numero = celda.numero;
                        colorNumero(numero);
                        cout << setw(huecos) << setfill(' ') << numero << RESET;
                    } else {
                        cout << BG_RED << RED << setw(huecos) << setfill(' ') << ' ' << RESET;
                    }
                }
            }
        } else {
            cout << BG_ORANGE << ORANGE << setw(huecos) << setfill(' ') << ' ' << RESET;
        }
    }
}

void mostrar_matriz(const tMatriz& matriz) {
    cout << "\t  |";
    for (int col = 0; col < MAX_COLS; col++) {
        cout << LBLUE << setw(N_HUECOS) << col << RESET << '|';
    }
    cout << endl;

    mostrarCoutSeparadorMat(N_HUECOS);
    for (int f = 0; f < MAX_FILS; f++) {
        cout << "\t" << LBLUE << setw(2) << f << RESET << '|';
        for (int c = 0; c < MAX_COLS; c++) {
            mostrarCeldaConsola(matriz, f, c, N_HUECOS);
            cout << '|';
        }
        cout << endl;

        mostrarCoutSeparadorMat(N_HUECOS);
    }
    cout << endl;
