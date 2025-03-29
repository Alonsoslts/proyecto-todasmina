#include <iostream>
#include <fstream>
#include <string>
#include "celda.h"
using namespace std;

void inicializar(tCelda& celda) {
	celda.estado = VACIA;
	celda.numero = 0;
	celda.visible = false;
	celda.marcada = false;
}

tEstado dame_estado(const tCelda& celda) {
	return celda.estado;
}

int dame_numero(const tCelda& celda) {
	return celda.numero;
}

bool es_visible(const tCelda& celda) {
	return celda.visible;
}

bool es_mina(const tCelda& celda) {
	if (celda.estado == MINA) {
	return true;
}
}

bool esta_vacia(const tCelda& celda) {
	if (celda.estado == VACIA) {
		return true;
	}
}

bool contiene_numero(const tCelda& celda) {
	if (celda.numero != 0) {
		return true;
	}
}

bool esta_marcada(const tCelda& celda) {
	return celda.marcada;
}

void descubrir_celda(tCelda& celda) {
	celda.visible = true;
}

void ocultar_celda(tCelda& celda) {
	celda.visible = false;

}

void poner_mina(tCelda& celda) {
	celda.estado = MINA;
}

void marcar_celda(tCelda& celda) {
	celda.marcada = true;
}

void desmarcar_celda(tCelda& celda) {
	celda.marcada = false;
}

int poner_numero(tCelda& celda, int num) {
	celda.estado = NUMERO;
	celda.numero = num;
	return num;
}

