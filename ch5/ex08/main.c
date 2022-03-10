#include <stdio.h>

int day_of_year(int, int, int);
int month_day(int , int , int *, int *);

int main(int argc, char *argv[])
{
  printf("Today is day %d of the year.\n", day_of_year(2022, 3, 10));
  printf("Jan 1 is day %d of the year.\n", day_of_year(2022, 1, 1));
  printf("Dec 31 is day %d of the year.\n", day_of_year(2022, 12, 31));

  int month; 
  int day;
  
  month_day(-10, 69, &month, &day);
  month_day(2022, 0, &month, &day);
  month_day(2022, 366, &month, &day);
  
  month_day(2022, 69, &month, &day);
  printf("Day 69 of 2022 is month %d day %d.\n", month, day);

  return 0;
}
