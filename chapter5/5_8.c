#include<stdio.h>

int day_of_year(int y, int m, int d);
int month_day(int y, int dy, int *m, int *d);

int main()
{
    int year, month, day, day_year; 

    year = 2022;
    day = 32; /* testing error check */
    month = 1;
    if ((day_year = day_of_year(2022, 1, 32))!=-1){
        printf("Day of the year:%d\n", day_year);
    }else{
        printf("Error!\n");
    }

    day_year = 143;    
    if ((month_day(year, day_year, &month, &day))!=-1){
        printf("Year %d, day %d: day %d, month %d\n", year, day_year, day, month);
    }else{
        printf("Error!\n");
    }
    return 0;
}

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};


int day_of_year(int y, int m, int d)
{
    int i, leap;
    leap = y % 4 == 0 && y%100 != 0 || y  % 400 == 0;
    
    if(d>daytab[leap][m] || d<1){
        return -1;
    }
    for(i=1; i<m; i++){
        d+=daytab[leap][i];
    }
    return d;
}

int month_day(int y, int dy, int *m, int *d)
{
    int leap;
    leap = y % 4 == 0 && y%100 != 0 || y  % 400 == 0;
    if(leap && dy>366 || !leap && dy>365){
        return -1;
    }

    for(*m = 1; dy > daytab[leap][*m]; (*m)++){
        dy -= daytab[leap][*m];
    }
    *d = dy;
    return 0;
}
