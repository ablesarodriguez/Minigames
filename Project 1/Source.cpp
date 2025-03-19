#include "Aleatori.h"
#include <iostream>
#include <time.h>
#define SUMA 0 
#define RESTA 1
#define MULTIPLICACIO 2
#define DIVISIO 3
#define FACIL 1
#define MIG 2
#define DIFICIL 3
using namespace std;
int main()
{
	int op, N1, N2, res, respuesta, puntuacion, cadena, coeficiente, puntfinal;
	bool error;
	//srand((unsigned)time(NULL));
	int dificultad;
	float respuesta2;
	res = 0;
	respuesta = 0;
	puntuacion = 0;
	cadena = 0;
	error = false;
	coeficiente = 0;
	cout << "Benvingut" << endl;
	do {
		cin >> dificultad;
		switch (dificultad) {
		case FACIL:
			coeficiente = 8;
			do {
				op = Aleatori(0, 2);
				N1 = Aleatori(0, 9);
				N2 = Aleatori(0, 9);
				switch (op) {
				case 0: res = N1 + N2;
					cout << N1 << " + " << N2 << " = ";
					cin >> respuesta;
					if (respuesta == res) {
						puntuacion = puntuacion + 1;
						cadena = cadena + 1;
					}
					else error = true;

					break;
				case 1: res = N1 - N2;
					cout << N1 << " - " << N2 << " = ";
					cin >> respuesta;
					if (respuesta == res) {
						puntuacion = puntuacion + 1;
						cadena = cadena + 1;
					}
					else error = true;
					break;
				case 2: res = N1 * N2;
					cout << N1 << " x " << N2 << " = ";
					cin >> respuesta;
					if (respuesta == res) {
						puntuacion = puntuacion + 2;
						cadena = cadena + 1;
					}
					else error = true;
					break;
				}
				cout << endl;
			} while (error == false);
			break;
		case MIG:
			coeficiente = 10;
			do {
				op = Aleatori(0, 2);
				N1 = Aleatori(0, 99);
				N2 = Aleatori(0, 99);
				switch (op) {
				case 0: res = N1 + N2;
					cout << N1 << " + " << N2 << " = ";
					cin >> respuesta;
					if (respuesta == res) {
						puntuacion = puntuacion + 1;
						cadena = cadena + 1;
					}
					else error = true;
					break;
				case 1: res = N1 - N2;
					cout << N1 << " - " << N2 << " = ";
					cin >> respuesta;
					if (respuesta == res) {
						puntuacion = puntuacion + 1;
						cadena = cadena + 1;
					}
					else error = true;
					break;
				case 2: res = N1 * N2;
					cout << N1 << " x " << N2 << " = ";
					cin >> respuesta;
					if (respuesta == res) {
						puntuacion = puntuacion + 2;
						cadena = cadena + 1;
					}
					else error = true;
					break;
				}
				cout << endl;
			} while (error == false);
			break;
		case DIFICIL:
			coeficiente = 12;
			do {
				op = Aleatori(0, 3);
				N1 = Aleatori(0, 999);
				N2 = Aleatori(0, 999);
				switch (op) {
				case 0: res = N1 + N2;
					cout << N1 << " + " << N2 << " = ";
					cin >> respuesta;
					if (respuesta == res) {
						puntuacion = puntuacion + 1;
						cadena = cadena + 1;
					}
					else error = true;

					break;
				case 1: res = N1 - N2;
					cout << N1 << " - " << N2 << " = ";
					cin >> respuesta;
					if (respuesta == res) {
						puntuacion = puntuacion + 1;
						cadena = cadena + 1;
					}
					else error = true;
					break;
				case 2: res = N1 * N2;
					cout << N1 << " x " << N2 << " = ";
					cin >> respuesta;
					if (respuesta == res) {
						puntuacion = puntuacion + 2;
						cadena = cadena + 1;
					}
					else error = true;
					break;
				case 3:
					while (N2 == 0) {
						N2 = Aleatori(0, 999);
					}
					float(res) = float(N1) / float(N2);
					res = res * 10;
					res = int(res);
					res = float(res) / 10.0;
					cout << N1 << " : " << N2 << " = ";
					cin >> respuesta2;
					if (respuesta2 == float(res)) {
						puntuacion = puntuacion + 3;
						cadena = cadena + 1;
					}
					else error = true;
					break;
				}
				cout << endl;
			} while (error == false);
			break;

		default: cout << "Seleccio incorrecta. Si us plau, selecciona una dificultat:" << endl;
			break;
		}
	} while (error == false);
	if (error == true) {
		puntfinal = puntuacion * coeficiente;
		cout << "Has aconseguit encadenar " << cadena << " respostes correctes amb una puntuacio final de: " << puntfinal << " punts." << endl;
	}
}