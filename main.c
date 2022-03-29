/**
* Programm zur bestimmung des Tages anhand eines Datums
* Author: Jannik Glane
* Datum: 15.03.2022
*/


#include <stdio.h>
#include <stdlib.h>

int IstSchaltjahr(int jahr);
int TagErmitteln(int tag, int monat, int *tage_pro_monat);

int main()
{
    // Initialisierung der benötigten Variablen
    int tag = 0;
    int monat = 0;
    int jahr = 0;
    int tageGesamt = 0;
    int tage_pro_monat[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

    printf("*** Tag des Jahres ***\n");

    // Aufforderung zur Eingabe des Jahres
    printf("Bitte das Jahr angeben: ");
    scanf("%i", &jahr);

    // Eingabe des Monats
    printf("Bitte den Monat angeben: ");
    scanf("%i", &monat);

    // Eingabe des Tages
    printf("Bitte den Tag angeben: "); // TODO check ob tag im monat ist
    scanf("%i", &tag);

    // Aufruf einer Funktion die bestimmt ob das übergebene Jahr ein Schaltjahr ist
    if(IstSchaltjahr(jahr))
        tage_pro_monat[1] = 29;

    // Aufruf einer Funktion die die Tage der Monate zusammenrechnet
    tageGesamt = TagErmitteln(tag, monat, tage_pro_monat);

    // Ausgabe der Summer der Tage
    printf("Heute ist der %i. Tag im Jahr", tageGesamt);
}

int IstSchaltjahr(int jahr)
{
    if(jahr % 4 == 0)
    {
        if(jahr % 100 == 0)
        {
            if (jahr % 400 == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}

int TagErmitteln(int tag, int monat, int *tage_pro_monat)
{
    int summe;
    for(int i = 0; i < monat-1; i++)
    {
        summe += tage_pro_monat[i];
    }
    summe += tag;
    return summe;
}
