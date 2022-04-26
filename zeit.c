#include <stdio.h>
#include <stdlib.h>

#include "zeit.h"

const int tage_pro_monat[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

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

int exists_date(int day, int month, int year)
{
    if(year < 1582 && year > 2400)
        return 0;

    if(month < 1 || month > sizeof(tage_pro_monat)/sizeof(tage_pro_monat[0]))
        return 0;

    if(day < 1 || day > tage_pro_monat[month-1])
        return 0;

    return 1;
}

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

int day_of_the_year(int day, int month, int year)
{
    if(!exists_date(day, month, year))
        return -1;

    // Initialisierung der benötigten Variablen
    int sumOfMonths = 0;

    for(int i = 1; i <= month; i++)
    {
        sumOfMonths += get_days_for_month(i, year);
    }

    // Ausgabe der Summer der Tage
    return sumOfMonths - (tage_pro_monat[month-1]-day);
}

int input_date(int *day, int *month, int *year)
{
    do
    {
        // Aufforderung zur Eingabe des Jahres
        printf("Bitte das Jahr angeben: ");
        scanf("%d", year);

        // Eingabe des Monatss
        printf("Bitte den Monat angeben: ");
        scanf("%d", month);

        // Eingabe des Tages
        printf("Bitte den Tag angeben: ");
        scanf("%d", day);
    }
    while(exists_date(*day, *month, *year) == 0);

    return 0;
}

// https://stackoverflow.com/a/21235587
int get_weekday(int *day, int *month, int *year)
{
    int d = *day;
    int m = *month;
    int y = *year;

    return (d += m < 3 ? y-- : y - 2, 23*m/9 + d + 4 + y/4- y/100 + y/400)%7;
}
