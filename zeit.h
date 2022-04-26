#ifndef ZEIT_H_INCLUDED
#define ZEIT_H_INCLUDED

int is_leapyear(int year);

int exists_date(int day, int month, int year);

int get_days_for_month(int month, int year);

int day_of_the_year(int day, int month, int year);

int input_date(int *day, int *month, int *year);

// https://stackoverflow.com/a/21235587
int get_weekday(int *day, int *month, int *year);

#endif // ZEIT_H_INCLUDED
