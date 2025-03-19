//Exercici 4
int Aleatori(int min, int max)
{
	int NumAleatori;
//	srand((unsigned)time(NULL));
	NumAleatori = min + (rand() % (max - min + 1));

	return NumAleatori;
}