#include <iostream>
#include "FuncionsBlackJack.h"
using namespace std;

int main()
{
	int i;
	char S;
	Carta baralla[NUM_CARTES];
	InicialitzarBaralla(baralla);
	Remenar(baralla, 1000);
	do {
		for (i = 0; i < NUM_CARTES; i++) {
			MostrarCarta(baralla[i]);
		}
		JocBlackJack(baralla);
		do {
			cout << "Vols fer una altra partida? (S/N)\n";
			cin >> S;
			if (S != 's' || S != 'S' || S != 'n' || S != 'N') {
				cout << "Error: Opcio incorrecta.\n";
			}
		} while (S != 's' || S != 'S' || S != 'n' || S != 'N');
	} while (S != 'N' || S != 'n');
}