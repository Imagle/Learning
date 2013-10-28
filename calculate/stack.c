/*************************************************************************
	> File Name: stack.c
	> Author:Ruiqiang
	> Mail:swagle@163.com 
	> Created Time: 2013年10月28日 星期一 15时12分45秒
 ************************************************************************/

#include<stdio.h>
#include "calc.h"

#define Max 100
double stack[Max];
int sp;

void push(double op){
    if(sp < Max){
        stack[sp++] = op;
    }
    else{
        printf("error: no memory!");
        return;
    }
}

double pop(){
    if(sp > 0){
        return stack[--sp];
    }
    else{
        printf("error: no elements in stack");
        return 0.0;
    }
}
