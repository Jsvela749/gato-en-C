#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>

void inicializarArreglo(char* arregloGato);

void pantallaInicial();

void imprimirLinea(char a, char b, char c);

void imprimirSeparador();

bool comprobarLineas(char* arregloGato, char* ganador);

void refrescarPantalla(char* arregloGato);

void turnoBot(char* arregloGato);

void turnoUsuario(char* arregloGato);

bool validarPosicionUsuario(char seleccion, char* arregloGato);

bool pantallaFinal(char ganador);