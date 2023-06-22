#include "GatoEnC.h"

int main(){
	int turno = rand() % 2;
	char *arregloGato = malloc(sizeof(char) * 9);
	char ganador;
	inicializarArreglo(arregloGato);
	while(comprobarLineas(arregloGato, &ganador) == false && turno <= 9){
		refrescarPantalla(arregloGato);
		if(turno % 2 == 0){
			turnoUsuario(arregloGato);
		}else{
			turnoBot(arregloGato);	
		}
		turno++;
	}
	refrescarPantalla(arregloGato);
	//	Pantalla de victoria o derrota
	free(arregloGato);
	if(pantallaFinal(ganador))
		main();
	return 0;
}

void inicializarArreglo(char* arregloGato){
	int i = 0;                                
	for(i = 0; i<9; i++){
		arregloGato[i] = '1'+ i;
	}
}

void refrescarPantalla(char* arregloGato){
	system("cls");
	printf("TIC TAC TOE EN C\n\n\n");
	imprimirLinea(arregloGato[0], arregloGato[1], arregloGato[2]);
	imprimirSeparador();
	imprimirLinea(arregloGato[3], arregloGato[4], arregloGato[5]);
	imprimirSeparador();
	imprimirLinea(arregloGato[6], arregloGato[7], arregloGato[8]);
}

void turnoUsuario(char* arregloGato){
	int seleccion;
	printf("\n\nIngrese su seleccion: ");
	seleccion = (int) getch();
	while(!validarPosicionUsuario(seleccion-1, arregloGato)){
		printf("\nIngrese una seleccion valida o no ocupada, por favor: ");
		seleccion = getch();
	}
	seleccion = seleccion - '0';
	arregloGato[seleccion-1] = 'X';
}

bool comprobarLineas(char* arregloGato, char* ganador){
	// Si alguien gano, se retorna true y si aun no se retorna false
	//	Lineas horizontales
	int i = 0;
	for(i = 0; i<3; i++){
		if(arregloGato[i*3] == arregloGato[i*3+1] && arregloGato[i*3+1] == arregloGato[i*3+2]){
			*ganador = arregloGato[i*3];
			return true;
		}
	}
	//	Lineas verticales
	for(i = 0; i<3; i++){
		if(arregloGato[i] == arregloGato[i+3] && arregloGato[i+3] == arregloGato[i+6]){
			*ganador = arregloGato[i];
			return true;
		}
	}
	// Lineas diagonales
	for(i = 0; i<2; i++){
		if(arregloGato[4] == arregloGato[4-(i+1)*2] && arregloGato[4-(i+1)*2] == arregloGato[4+(i+1)*2]){
			*ganador = arregloGato[4];
			return true;
		}
	}
	return false;
}

void imprimirLinea(char a, char b, char c){
	printf(" %c | %c | %c \n", a, b, c);
}

void imprimirSeparador(){
	printf("-----------\n");
}

void turnoBot(char* arregloGato){
	int seleccion;
	// Seleccionar posicion al azar mientras no este ocupada.
	//	Crear una bandera para saber cuando ya se gano.
	do{
		seleccion = rand() % 9;
	}while(isalpha(arregloGato[seleccion]));
	printf("\n\nTurno del BOT.");
	Sleep(450);
	printf(".");
	Sleep(450);
	printf(".");
	arregloGato[seleccion] = 'O';
}

bool validarPosicionUsuario(char seleccion, char* arregloGato){
	// Valida que no sea una letra
	if(isalpha(seleccion))
		return false;
	// Valida que este en el rango
	seleccion = seleccion - '0';
	if(seleccion > 8 || seleccion < 0)
		return false;
	// Valida que no este ocupado
	if(isalpha(arregloGato[seleccion]))
		return false;
	return true;
}

bool pantallaFinal(char ganador){
	printf("\nUsted ha ");
	if(ganador == 'X'){
		printf("ganado.");
	}else{
		printf("perdido.");
	}
	printf("\n\nDesea jugar otra vez? Y/N: ");
	char continuar;
	continuar = getch();
	if(continuar == 'Y' || continuar == 'y'){
		return true;
	}else{
		system("cls");
		printf("\nGRACIAS POR JUGAR!\n\nPresione cualquier tecla para salir...");
		getch();
		return false;
	}
}