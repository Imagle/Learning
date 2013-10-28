/*************************************************************************
	> File Name: getop.c
	> Author:Ruiqiang
	> Mail:swagle@163.com 
	> Created Time: 2013年10月28日 星期一 15时31分14秒
 ************************************************************************/

#include "calc.h"
#include<stdio.h>
#include <ctype.h>

#define NUMBER '0'

int getop(char *s){
    int i=0, c;
    while( (s[i]=c=getch())==' ' || c=='\t' ) ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.')
        return c;
    i = 0;
    if(isdigit(c))
        while(isdigit(s[++i] = c = getch()))
            ;
    if(c == '.')
        while(isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if(c!=EOF)
        ungetch(c);
    return NUMBER;
}

/*
 *测试用
int main(){
    int c;
    char s[100];
    while( (c=getop(s)) != 'q' ){
        printf("%s\n", s);
    }
}
*/

