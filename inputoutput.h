#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "juego.h"

void mostrar_cabecera();
void pedir_pos(int& fila, int& columna);
void mostrar_resultado(const tJuego& juego);
void mostrar_juego_consola(const tJuego& juego);
bool cargar_juego(tJuego& juego);
std::istream& operator>> (std::istream& in, tJuego& juego);
