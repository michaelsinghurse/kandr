#include <stdio.h>

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
  if (year<0) {
    printf("year (%d) must be greater than 0\n", year);
    return -1;
  }

  if (month<1 || month>12) {
    printf("month (%d) must be between 1 and 12\n", month);
    return -1;
  }

  int i, leap;

  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

  if (day<0 || day > daytab[leap][month]) {
    printf("day (%d) is out of range for month (%d) of year (%d)\n", day, month, year);
    return -1;
  }

  for (i = 1; i < month; i++)
    day += daytab[leap][i];

  return day;
}

int month_day(int year, int yearday, int *pmonth, int *pday)
{
  if (year<0) {
    printf("year (%d) must be greater than 0\n", year);
    return -1;
  }

  if (yearday<1 || yearday>365) {
    printf("yearday (%d) must be between 1 and 365\n", yearday);
    return -1;
  }

  int i, leap;

  leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];

  *pmonth = i;
  *pday = yearday;
  return 0;
}
