#include "FuncionsMasterMind.h"
#include <algorithm>
using namespace std;

//Exercici 1
void Menu()
{
	cout << "MASTER MIND\n" << endl << "Escull una opcio: \n" << endl << "Opcio 1 Ajuda\nOpcio 2 Jugar\nOpcio 3 Sortir\n";
}

//Exercici 2
void Ajuda()
{
	cout << "L0objectiu del joc es trobar el codi ocult\nEl codi es de longitud " << LONG_CODI << " nombres del 0 al 9\nDespres de cada intent et dona la seguent informacio:\n";
	cout << "	Nombre de nombre encertats (en la posicio correcte)\n	Nombre de nombres aproximats (correctes pero mal col.locats)\nEl nombre de intents son " << MAX_INTENTS << "\n";
}

//Exercici 3
int Aleatori(int min, int max)
{
	int NumAleatori;
	srand((unsigned)time(NULL));
	NumAleatori = min + (rand() % (max - min + 1));

	return NumAleatori;
}

void GenerarCodiOcult(int CodiMaster[], int Dim)
{
	int i, num;
	for (i = 0; i < Dim; i++) {
		num = Aleatori(0, 9);
		CodiMaster[i] = num;
	}
}

//Exercici 4

int LlegirNombre(int min, int max)
{
	int valor;
	do {
		cout << "Entra valor entre " << min << " i " << max << endl;
		cin >> valor;
		if (valor < min || valor > max)
			cout << "Error: valor fora de l'interval";
	} while (valor < min || valor > max);
	return valor;
}

//Exercici 5
void IntToArray(int Nombre, int Codi[], int Dim)
{
	int i, res;
	for (i = Dim - 1; i >= 0; i--) {
		res = Nombre % 10;
		Nombre /= 10;
		cout << res << " ";
		Codi[i] = res;
	}
	cout << "\nArray: ";
	for (i = 0; i < Dim; i++) {
		cout << Codi[i] << " ";
	}
}

//Exercici 6

void InicialitzarArray(int Array[], int Dim, int Valor)
{
	int i;
	for (i = 0; i < Dim; i++)
		Array[i] = Valor;
}

//Exercici 7
void FrequenciaDigit(int Codi[], int Dim, int Frequencia[])
{
	int i;
	for (i = 0; i < Dim; i++) {
		if (Codi[i] == 0) {
			Frequencia[0]++;
		}
		if (Codi[i] == 1) {
			Frequencia[1]++;
		}
		if (Codi[i] == 2) {
			Frequencia[2]++;
		}
		if (Codi[i] == 3) {
			Frequencia[3]++;
		}
		if (Codi[i] == 4) {
			Frequencia[4]++;
		}
		if (Codi[i] == 5) {
			Frequencia[5]++;
		}
		if (Codi[i] == 6) {
			Frequencia[6]++;
		}
		if (Codi[i] == 7) {
			Frequencia[7]++;
		}
		if (Codi[i] == 8) {
			Frequencia[8]++;
		}
		if (Codi[i] == 9) {
			Frequencia[9]++;
		}
	}
}

//Exercici 8
int NombreEncerts(int CodiMaster[], int CodiBreaker[], int Dim)
{
	int i, suma = 0;
	for (i = 0; i < Dim; i++) {
		if (CodiMaster[i] == CodiBreaker[i]) {
			suma++;
		}
	}
	return suma;
}

// Exercici 9
int Minim(int Valor1, int Valor2)
{
	if (Valor1 < Valor2)
		return Valor1;
	else
		return Valor2;
}

//Exercici 10
int NombreAproximacions(int FrequenciaCodiMaster[], int FrequenciaCodiBreaker[], int Encerts)
{
	int i, c[10], g[10], minimo = 0, w;
	for (i = 0; i < 10; i++) {
		c[i] = FrequenciaCodiMaster[i];
		g[i] = FrequenciaCodiBreaker[i];
	}
	for (i = 0; i < 10; i++) {
		minimo += min(c[i], g[i]);
	}
	w = minimo - Encerts;
	return w;
}

//Exercici 11
void ImprimirComparacions(int Encerts, int Aproximacions)
{
	cout << "Aquest codi te " << Encerts << " Encerts i " << Aproximacions << " Aproximacions" << endl;
}

//Exercici 12
int JocMasterMind()
{
	int CodiMaster[LONG_CODI], CodiBreaker[LONG_CODI], IntCodiBreaker, FrequenciaCodiMaster[DIGITS], FrequenciaCodiBreaker[DIGITS], Encerts = 0, Aproximacions, Intents = 0;
	GenerarCodiOcult(CodiMaster, LONG_CODI);
	InicialitzarArray(CodiMaster, DIGITS, 0);
	FrequenciaDigit(CodiMaster, DIGITS, FrequenciaCodiMaster);
	while ((CodiBreaker[LONG_CODI] != CodiMaster[LONG_CODI]) && Intents < MAX_INTENTS)
	{
		int a;
		a = pow(10, LONG_CODI) - 1;
		IntCodiBreaker = LlegirNombre(0, a);
		IntToArray(IntCodiBreaker, CodiBreaker, LONG_CODI);
		InicialitzarArray(FrequenciaCodiBreaker, DIGITS, 0);
		FrequenciaDigit(CodiBreaker, DIGITS, FrequenciaCodiBreaker);
		Encerts = NombreEncerts(CodiMaster, CodiBreaker, LONG_CODI);
		Aproximacions = NombreAproximacions(FrequenciaCodiMaster, FrequenciaCodiBreaker, Encerts);
		ImprimirComparacions(Encerts, Aproximacions);
		Intents++;
	}
	if (Intents == MAX_INTENTS) {
		return 0;
	}
	else {
		return Intents;
	}
}

//Exercici 13
void ImprimirResultatJoc(int Intents)
{
	if (Intents == 0) {
		cout << "No has aconseguit descobrir el codi" << endl;
	}
	else {
		cout << "Has aconseguit descobrir el codi en " << Intents << " intents" << endl;
	}
}