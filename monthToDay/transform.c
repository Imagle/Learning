/*************************************************************************
	> File Name: transform.c
	> Author:Imagle
	> Mail:swagle@163.com
	> Created Time: 2013年10月25日 星期五 15时07分26秒
 ************************************************************************/

#include<stdio.h>

char daytab[2][13] =
{
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day)
{
    if(year<=0){
        printf("error: illegal year\n");
        return -1; 
    }
    if(month<=0 || month >12){
        printf("error: illegal month\n");
        return -1; 
    }
    if( day<1 || day > daytab[year][month]){
        printf("error: illegal day\n");
        return -1; 
    }
    int i,leap;
    leap = (year%4==0 && year%100!=0 || year%400==0);
    for(i=1; i<month; i++)
        day += daytab[leap][i];
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
    if(year<=0){
        printf("error: illegal year\n");
        *pmonth = -1;
        *pday = -1;
        return; 
    }
    int i,leap;
    leap = (year%4==0 && year%100!=0 || year%400==0);
    if( (yearday > 365 && leap==0) ||(yearday > 366 && leap==1)){
        printf("error: year of day is out of range\n");
        *pmonth = -1;
        *pday = -1;
        return; 
    }
    for(i=1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

char *month_name(int n){
    static char *name[] ={
        "illegal month",
        "January", "February", "March", "April", "May","June",
        "July", "August", "September", "October", "November", "December"
    };
    return (n <= 0 || n > 12) ? name[0] : name[n];
}
int main()
{
    int month, day;
    int days = day_of_year(2011, 3, 1);
    printf("day of 2011.3.1: %d\n", days);
    month_day(2012, 61, &month, &day);
    printf("month: %d, day: %d\n", month, day);
}
