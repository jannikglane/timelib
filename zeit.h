#ifndef ZEIT_H_INCLUDED
#define ZEIT_H_INCLUDED

struct Date
{
    int year;
    int month;
    int day;
};

int is_leapyear(int year);

int exists_date(struct Date);

int get_days_for_month(int month, int year);

int day_of_the_year(struct Date);

struct Date input_date();

// https://stackoverflow.com/a/21235587
int get_weekday(struct Date);

#endif // ZEIT_H_INCLUDED
