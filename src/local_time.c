/*
** EPITECH PROJECT, 2023
** Main lib
** File description:
** Local_time
*/

#include "my.h"

int bi_year(int year)
{
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

void calculate_date(int *days, date *date)
{
    const int ms[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int mh_d;

    date->year = 1970;
    while (*days >= (bi_year(date->year) ? 366 : 365)) {
        *days -= (bi_year(date->year) ? 366 : 365);
        date->year++;
    }
    date->month = 0;
    mh_d = bi_year(date->year) && date->month == 1 ? 29 : ms[date->month];
    while (*days >= mh_d) {
        *days -= mh_d;
        date->month++;
        mh_d = bi_year(date->year) && date->month == 1 ? 29 : ms[date->month];
    }
    date->day = *days + 1;
}

void local_time(time_t time, date *date)
{
    int days = time / 86400;

    calculate_date(&days, date);
    date->hour = (time / 3600) % 24;
    date->minute = (time / 60) % 60;
}
