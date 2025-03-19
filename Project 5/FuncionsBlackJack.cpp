#include "FuncionsBlackJack.h"
using namespace std;

//Escriure a partir d"aqui les funcions demanades NO posar main(), Preguntar() ni la definicio del tipus Carta.

//Exercici 3
void InicialitzarBaralla(Carta baralla[])
{
    int i, x, sum = 0, pal = CORS;
    for (i = 0; i < PALS; i++) {
        for (x = 0; x < NUMEROS; x++) {
            baralla[sum].Numero = x + 1;
            baralla[sum].Pal = i + 1;
            sum++;
        }
    }
}

//Exercici 4
void MostrarCarta(Carta carta)
{
    switch (carta.Numero) {
    case 1:
        cout << "A";
        break;
    case 11:
        cout << "J";
        break;
    case 12:
        cout << "Q";
        break;
    case 13:
        cout << "K";
        break;
    default:
        cout << carta.Numero;
        break;
    }
    switch (carta.Pal) {
    case 1:
        cout << "C" << endl;
        break;
    case 2:
        cout << "D" << endl;
        break;
    case 3:
        cout << "T" << endl;
        break;
    case 4:
        cout << "P" << endl;
        break;
    }
}

//Exercici 5 
void Intercanviar(Carta& carta1, Carta& carta2)
{
    Carta cartasup;
    cartasup = carta1;
    carta1 = carta2;
    carta2 = cartasup;
}

//Exercici 6
int Aleatori(int min, int max)
{
    int NumAleatori;
    //srand((unsigned)time(NULL));
    NumAleatori = min + (rand() % (max - min + 1));

    return NumAleatori;
}

void Remenar(Carta baralla[], int NumIntercanvis)
{
    int num1 = 0, num2 = 0, i;

    for (i = 0; i < NumIntercanvis; i++) {
        num1 = Aleatori(0, (NUM_CARTES - 1));
        num2 = Aleatori(0, (NUM_CARTES - 1));
        Intercanviar(baralla[num1], baralla[num2]);
    }
}

//Exercici 7
int PuntsCarta(Carta carta)
{
    int punt;
    if (carta.Numero >= 1 && carta.Numero <= 10) {
        punt = carta.Numero;
    }
    else {
        punt = 10;
    }
    return punt;
}

//Exercici 9
bool EstrategiaOrdinador(bool JugadorEsPlanta, int PuntsOrdinador, int PuntsJugador)
{
    bool mescarta;
    if (PuntsJugador > 21 || (JugadorEsPlanta == true && PuntsOrdinador > PuntsJugador)) {
        mescarta = false;
    }
    else
        if (PuntsOrdinador < 17) {
            mescarta = true;
        }
        else {
            mescarta = false;
        }
    return mescarta;
}

//Exercici 10
int CalcularGuanyador(bool JugadorHaPerdut, bool OrdinadorHaPerdut, int PuntsJugador, int PuntsOrdinador)
{
    int gana = 0;
    if ((JugadorHaPerdut == true && OrdinadorHaPerdut == true) || (PuntsJugador == PuntsOrdinador)) {
        gana = 0;
        cout << "Empat\n";
    }
    if ((PuntsJugador > PuntsOrdinador) && (JugadorHaPerdut == false)) {
        gana = 1;
        cout << "Jugador guanya\n";
    }
    else
        if ((PuntsJugador > PuntsOrdinador) && (JugadorHaPerdut == true)) {
            gana = 2;
            cout << "Ordinador guanya\n";
        }
    if ((PuntsJugador < PuntsOrdinador) && (OrdinadorHaPerdut == false)) {
        gana = 2;
        cout << "Ordinador guanya\n";
    }
    else
        if ((PuntsJugador < PuntsOrdinador) && (OrdinadorHaPerdut == true)) {
            gana = 1;
            cout << "Jugador guanya\n";
        }
    return gana;
}

//Exercici 11
int JocBlackJack(Carta baralla[])
{
    int punt1 = 0, punt2 = 0, ganador = 0;
    bool jugador = false, ordinador = false;
    bool PJ = true, NPC = true;
    int i = 0;
    do {
        if (PJ == true) {
            cout << "Carta Jugador: ";
            MostrarCarta(baralla[i]);
            punt1 += PuntsCarta(baralla[i]);
            i++;
        }

        if (NPC == true) {
            cout << "Carta Ordinador: ";
            MostrarCarta(baralla[i]);
            punt2 += PuntsCarta(baralla[i]);
            NPC = EstrategiaOrdinador(!PJ, punt2, punt1);
            i++;
        }
    } while ((punt1 <= 21 || punt2 <= 21) && (PJ == true && NPC == true));
    if (punt1 > 21) {
        jugador = true;
    }
    if (punt2 > 21) {
        ordinador = true;
    }
    ganador = CalcularGuanyador(jugador, ordinador, punt1, punt2);
    return ganador;
}