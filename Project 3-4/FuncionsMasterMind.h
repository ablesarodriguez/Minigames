#include <iostream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LONG_CODI 4
#define MAX_INTENTS 15
#define DIGITS 10

void Ajuda();
int Aleatori(int min, int max);
void GenerarCodiOcult(int CodiMaster[], int Dim);
int LlegirNombre(int min, int max);
void IntToArray(int Nombre, int Codi[], int Dim);
void InicialitzarArray(int Array[], int Dim, int Valor);
void FrequenciaDigit(int Codi[], int Dim, int Frequencia[]);
int NombreEncerts(int CodiMaster[], int CodiBreaker[], int Dim);
int Minim(int Valor1, int Valor2);
int NombreAproximacions(int FrequenciaCodiMaster[], int FrequenciaCodiBreaker[], int Encerts);
void ImprimirComparacions(int Encerts, int Aproximacions);
int JocMasterMind();
void Menu();
void ImprimirResultatJoc(int Intents);