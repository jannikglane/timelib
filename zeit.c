#include <stdio.h>
#include <stdlib.h>

#include "zeit.h"

const int tage_pro_monat[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

/** @brief Die Funktion überprüft, ob ein gegebenes Jahr nach den Regeln des gregorianischen Kalender ein Schaltjahr
 *  ist. Bei Jahreszahlen vor dem Jahr 1582 wird ein Fehler zurückgegeben.
 *
 * @param int year Eingegebenes Jahr
 * @return int 1 wenn Schaltjahr, 0 wenn kein Schaltjahr, -1 wenn das Jahr ungültig ist
 *
 */

int is_leapyear(int year)
{
    if(year< 1582)
        return -1;

    if(year % 4 == 0)
    {
        if(year % 100 == 0)
        {
            if (year % 400 == 0)
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

/** @brief Die Funktion überprüft, ob ein eingegebenes Datum gültig ist.
 *
 * @param int day Eingegebener Tag
 * @param int month Eingegebener Monat
 * @param int year Eingegebenes Jahr
 * @return int 1 wenn das Datum gültig ist. -1 wenn das Datum ungültig ist.
 *
 */
int exists_date(struct Date date)
{
    // Daten vor dem 1.1.1582 sind ungültig, genauso wie alle Daten nach dem 31.12.2400.
    if(date.year < 1582 && date.year > 2400)
        return 0;

    if(date.month < 1 || date.month > sizeof(tage_pro_monat)/sizeof(tage_pro_monat[0]))
        return 0;

    if(date.day < 1 || date.day > tage_pro_monat[date.month-1])
        return 0;

    return 1;
}

/** @brief Die Funktion bestimmt für einen gegebenen Monat eines gegebenen Jahres, wie viele Tage der Monat hat. Der
 *  Wert des Monats muss zwischen 1 und 12 liegen. Schaltjahre werden berücksichtigt.
 *
 * @param int month Eingegebener Monat
 * @param int year Eingegebens Jahr
 * @return int Anzahl der Tage 1-31. -1 Wenn das Datum ungültig ist.
 *
 */
int get_days_for_month(int month, int year)
{
    int days = 0;

    if(month < 1 || month > 12)
        return -1;

    days += tage_pro_monat[month-1];

    if(is_leapyear(year) && month == 1)
        days += 1;

    return days;
}

/** @brief Die Funktion berechnet für ein gegebenes Datum des gregorianischen Kalenders bestehend aus Tag, Monat
 *  und Jahr die Nummer des Tages, gezählt von Jahresbeginn (1. Januar) an. Schaltjahre werden bei der
 *  Berechnung berücksichtigt.
 *
 * @param int day Eingegebenes Jahr
 * @param int month Eingegebener Monat
 * @param int year Eingegebenes Jahr
 * @return int Nummer des Tages. Ist das übergebene Datum ungültig, beträgt der Rückgabewert -1.
 *
 */
int day_of_the_year(struct Date date)
{
    if(!exists_date(date))
        return -1;

    // Initialisierung der benötigten Variablen
    int sumOfMonths = 0;

    for(int i = 1; i <= date.month; i++)
    {
        sumOfMonths += get_days_for_month(i, date.year);
    }

    // Rückgabe der Summer der Tage
    return sumOfMonths - (tage_pro_monat[date.month-1]-date.day);
}

/** @brief Die Funktion liest 3 Ganzzahlwerte (Integer) ein, für Tag, Monat und Jahr. Wenn das angegebene Datum
 *  ungültig ist, wird erneut eingelesen, solange bis ein gültiges Datum eingegeben wurde.
 *
 * @param int day Pointer, zeigt auf die day Variable
 * @param int month Pointer, zeigt auf die month Variable
 * @param int year Pointer, zeigt auf die year Variable
 * @return void
 *
 */
struct Date input_date()
{
    struct Date date;

    // Aufforderung zur Eingabe des Jahres
    printf("Bitte das Jahr angeben: ");
    scanf("%d", &date.year);

    // Eingabe des Monatss
    printf("Bitte den Monat angeben: ");
    scanf("%d", &date.month);

    // Eingabe des Tages
    printf("Bitte den Tag angeben: ");
    scanf("%d", &date.day);

    return date;
}

/** @brief Bestimmt des Tag der Woche. Index beginnt bei Sonntag. Code aus: https://stackoverflow.com/a/21235587
 *
 * @param int day Pointer, zeigt auf die day Variable
 * @param int month Pointer, zeigt auf die month Variable
 * @param int year Pointer, zeigt auf die year Variable
 * @return int Tag der Woche 0-6
 *
 */
int get_weekday(struct Date date)
{
    int d = date.day;
    int m = date.month;
    int y = date.year;

    return (d += m < 3 ? y-- : y - 2, 23*m/9 + d + 4 + y/4- y/100 + y/400)%7;
}
