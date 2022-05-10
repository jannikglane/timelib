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
    char weekdays[7][10] = {"Sonntag", "Montag", "Dienstag", "Mittwoch", "Donnerstag", "Freitag", "Samstag"};
    struct Date date;

    do
    {
        date = input_date();
    }
    while(exists_date(date) == 0);

    printf("Tag des Jahres: %d \n", day_of_the_year(date));
    printf("Der Tag ist ein: %s \n", weekdays[get_weekday(date)]);

    return 0;
}
