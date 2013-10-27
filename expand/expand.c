/*
 * 编写expand(s1,s2)函数，将字符串s1中类似于a-z的速记符号在字符串s2中扩展为等价的完整列表abc...xyz。
 * 该函数可以处理大小写和数字，并可以处理a-b-c,a-z0-9与-a-z等类似的情况。作为前导和尾随的-字符原样排印。
**/

#include<stdio.h>
#include<string.h>

int expand(const char s1[], char s2[]){
    int i=0, j=0;
		char c;
		while( (c=s1[i++]) != '\0' ){
			 if(s1[i]=='-' && s1[i+1]>=c){
					 i++;
					 while(c<s1[i]){
							s2[j++] = c++;
							}
		   }
		   else
						s2[j++]=c;
		 s2[j]='\0';
		 }
}

int main(){
    //char s1[]={'-','a','-','z'};
    char s1[]={'a', 'b', 'c'};
    //char s1[]={'a','-','z','0','-','9'};
    char s2[100];
    int j = expand(s1, s2);
    printf("%s", s2);
    //printf("%c", '9'+1);
    //system("pause");
}
