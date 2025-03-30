#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "celda.h" //si no lo incluyo no renconoce el tCelda 

const int MAX_FILS = 50;  //hay que dar a estas dos un valor alto y luego tomar de los ficheros los valores reales?
const int MAX_COLS = 50;

typedef struct {
	int nFils, nCols;
	tCelda datos[MAX_FILS][MAX_COLS];
}tTablero;

void inicializar(tTablero& tablero);
void inicializar_tablero(tTablero& tablero, int nflis, int ncols);
int num_filas(tTablero& tab);
int num_columnas(tTablero& tab);
tCelda dame_celda(const tTablero& tablero, int fila, int columna);
bool es_valida(tTablero& tablero, int fila, int columna);
void poner_celda(tTablero& tablero, int fila, int columna, tCelda celda);

/pull 
