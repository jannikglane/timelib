/**
* Programm zur bestimmung des Tages anhand eines Datums
* Author: Jannik Glane
* Datum: 15.03.2022
*/

#include <stdio.h>
#include <stdlib.h>

#include "zeit.h"

int main()
{
    int day, month, year;
    day = month = year = 0;

    input_date(&day, &month, &year);

    printf("Tag des Jahres: %d \n", day_of_the_year(day, month, year));

    char weekdays[7][10] = {"Sonntag", "Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag"};
    printf("Der Tag war ein: %s \n", weekdays[get_weekday(&day, &month, &year)]);

    return 0;
}
