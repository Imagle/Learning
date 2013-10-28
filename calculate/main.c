#include "calc.h"
#include<stdio.h>
#include<stdlib.h>

int main(){
   int type;
   char s[100];

   while((type=getop(s)) != 'q'){
        printf("%s",s);
       double temp;
       switch(type){
           case NUMBER:
               push(atof(s));
               break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                temp = pop();
                push(pop() - temp);
                break;
            case '/':
                temp = pop();
                if( temp != 0.0 )
                    push(pop() / temp);
                else
                    printf("error: zero divisor\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error:unknow command %s\n", s);
                break;
        }
    }
   return 0;
}
