#include <stdlib.h>
#include <iostream>
#include <time.h>
using namespace std;

//Exercici 1
void PresentacioJoc()
{
	cout << "Pedra, paper, tisores, llangardaix, Spock es un joc d'atzar aplicacio del popular Pedra, paper, tisores" << endl;
	cout << "Creat per Sam Kass amb Karen Bryla http://www.samkass.com/theories/RPSSL.html" << endl;
	cout << "Popularitzar per Sheldon Cooper a la serie Big Bang Theory." << endl;
	cout << "Es fa servir per solucionar una disputa Sheldon i Raj en el capitol The Lizard - Spock Expansion" << endl << endl;
	cout << "El joc es al millor de N partides on N es un nombre senar" << endl;
}

//Exercici 2
int Senar(int num)
{
	if ((num % 2) == 0 || num == 0)
		return false;
	else
		return true;
}

//Exercici 3
int LlegirSenar()
{
	cout << "Introduir un nombre senar ";
	int num;
	do {
		cin >> num;
		Senar(num);
		if (Senar(num) == false) {
			cout << "ERROR: El nombre introduit es parell" << endl;
		}
		else {
			return num;
		}
	} while (Senar(num) == false);

	return 0;
}

//Exercici 4
int Aleatori(int min, int max)
{
	int NumAleatori;
	srand((unsigned)time(NULL));
	NumAleatori = min + (rand() % (max - min + 1));

	return NumAleatori;
}

//Exercici 5
void MenuRPSLS()
{
	cout << "Escull entre:" << endl << "1 - Rock" << endl << "2 - Paper" << endl << "3 - Scissors" << endl << "4 - Lizard" << endl << "5 - Spock" << endl;
}

//Exercici 6
int LlegirNombre(int min, int max)
{
	int num;
	do {
		cout << "Entra valor entre " << min << " i " << max << " : ";
		cin >> num;
		cout << endl;
		if (num < min || num > max)
			cout << "Error: valor fora de l'interval " << endl;
	} while (num < min || num > max);
	return num;
}

//Exercici 7
int JocRPSLS(int Player1, int Player2)
{
	const int Rock = 1, Paper = 2, Scissors = 3, Lizard = 4, Spock = 5;
	switch (Player1) {
	case 1:
		if (Player2 == 3 || Player2 == 4)
			return 1;
		if (Player2 == 1)
			return 0;
		if (Player2 == 2 || Player2 == 5)
			return 2;
		break;
	case 2:
		if (Player2 == 1 || Player2 == 5)
			return 1;
		if (Player2 == 2)
			return 0;
		if (Player2 == 3 || Player2 == 4)
			return 2;
		break;
	case 3:
		if (Player2 == 2 || Player2 == 4)
			return 1;
		if (Player2 == 3)
			return 0;
		if (Player2 == 1 || Player2 == 5)
			return 2;
		break;
	case 4:
		if (Player2 == 2 || Player2 == 5)
			return 1;
		if (Player2 == 4)
			return 0;
		if (Player2 == 1 || Player2 == 3)
			return 2;
		break;
	case 5:
		if (Player2 == 1 || Player2 == 3)
			return 1;
		if (Player2 == 5)
			return 0;
		if (Player2 == 2 || Player2 == 4)
			return 2;
		break;
	default:
		break;
	}

	return 0;
}

//Exercici 8
void MissatgeRPSLS(int Player1, int Player2)
{
	switch (Player1) {
	case 1:
		if (Player2 == 1)
			cout << "Empat!!!" << endl;
		if (Player2 == 2)
			cout << "Paper covers Rock" << endl;
		if (Player2 == 3)
			cout << "Rock crushes Scissors" << endl;
		if (Player2 == 4)
			cout << "Rock crushes Lizard" << endl;
		if (Player2 == 5)
			cout << "Spock vaporizes Rock" << endl;

		break;
	case 2:
		if (Player2 == 1)
			cout << "Paper covers Rock" << endl;
		if (Player2 == 2)
			cout << "Empat!!!" << endl;
		if (Player2 == 3)
			cout << "Scissors cuts Paper" << endl;
		if (Player2 == 4)
			cout << "Lizard eats Paper" << endl;
		if (Player2 == 5)
			cout << "Paper disproves Spock" << endl;

		break;
	case 3:
		if (Player2 == 1)
			cout << "Rock crushes Scissors" << endl;
		if (Player2 == 2)
			cout << "Scissors cuts Paper" << endl;
		if (Player2 == 3)
			cout << "Empat!!!" << endl;
		if (Player2 == 4)
			cout << "Scissors decapitates Lizard" << endl;
		if (Player2 == 5)
			cout << "Scissors decapitates Lizard" << endl;

		break;
	case 4:
		if (Player2 == 1)
			cout << "Rock crushes Lizard" << endl;
		if (Player2 == 2)
			cout << "Lizard eats Paper" << endl;
		if (Player2 == 3)
			cout << "Scissors decapitates Lizard" << endl;
		if (Player2 == 4)
			cout << "Empat!!!" << endl;
		if (Player2 == 5)
			cout << "Lizard poisons Spock" << endl;

		break;
	case 5:
		if (Player2 == 1)
			cout << "Spock vaporizes Rock" << endl;
		if (Player2 == 2)
			cout << "Paper disproves Spock" << endl;
		if (Player2 == 3)
			cout << "Spock smashes Scissors" << endl;
		if (Player2 == 4)
			cout << "Lizard poisons Spock" << endl;
		if (Player2 == 5)
			cout << "Empat!!!" << endl;

	default:
		break;
	}
}

//Exercici 9
int main()
{
	int num, Player1, Player2, nosotros = 0, Sheldon = 0;
	PresentacioJoc();
	num = LlegirSenar();
	while (num != 0) {
		Player2 = Aleatori(1, 5);
		MenuRPSLS();
		Player1 = LlegirNombre(1, 5);
		JocRPSLS(Player1, Player2);
		MissatgeRPSLS(Player1, Player2);
		if (JocRPSLS(Player1, Player2) == 1) {
			cout << "Guanyes Tu!!!" << endl;
			nosotros++;
			num--;
		}
		if (JocRPSLS(Player1, Player2) == 2) {
			cout << "Guanya Sheldon Cooper!!!" << endl;
			Sheldon++;
			num--;
		}
		cout << "Marcador -- Sheldon " << Sheldon << " Tu " << nosotros << endl;
	}
	if (nosotros > Sheldon) {
		cout << "Tu ets el guanyador";
	}
	else {
		cout << "El guanyador es Sheldon";
	}
}