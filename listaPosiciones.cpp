#include <iostream>
#include "listaPosiciones.h"
using namespace std;

void inicializar(tListaPosiciones& lista) {
	lista.cont = 0;
}

void insertar_final(tListaPosiciones& lista, int x, int y) {
	if (lista.cont < MAX_LISTA) {
		lista.lista[lista.cont].posx = x;
		lista.lista[lista.cont].posy = y;
		lista.cont++;
	}
}

int longitud(tListaPosiciones& lista) {
	return lista.cont;
}

int dame_posX(tListaPosiciones& lista, int i) {
	return lista.lista[i].posx;
}

int dame_posY(tListaPosiciones& lista, int i) {
	return lista.lista[i].posy;
}

