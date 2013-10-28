/*************************************************************************
	> File Name: ./getch.c
	> Author:Ruiqiang
	> Mail:swagle@163.com 
	> Created Time: 2013年10月28日 星期一 16时13分48秒
 ************************************************************************/

#include "calc.h"
#include<stdio.h>

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    if(bufp < BUFSIZE){
        buf[bufp++] = c;
    }
    else
        printf("ungetch: too many characters\n");
}

/*
 * 测试函数用
int main(){
    char c ;
    ungetch('x');
    while((c=getch())!='q'){
        printf("%c", c);
        printf("============\n");
    }

}
*/
