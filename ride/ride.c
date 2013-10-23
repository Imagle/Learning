/*
ID: wangrq21
LANG:C
PROG: ride
*/
#include<stdio.h>
void main(){
	 FILE* pFile;
	 FILE* fout;
	 fout = fopen("ride.out", "w");
	 pFile = fopen("ride.in", "r");
	 char str[6];
	 char str2[6];
	 fscanf(pFile, "%s", str);
	 fscanf(pFile, "%s", str2);
	 fclose(pFile);
   int multi1=1;
   int multi2=1;
   int i, k=0;
   for(i=0;i<6;i++){
			 if( (int)str[i] > 64)
			     k = (int)str[i] - 64;
			 else
					 k =1;
       multi1 *= k;
   }
   for(i=0;i<6;i++){
			 if( (int)str2[i] > 64)
			     k = (int)str2[i] - 64;
			 else
					 k =1;
       multi2 *= k;
   }
   if(multi1%47 == multi2%47)
			 fprintf(fout, "GO\n");
	 else
	     fprintf(fout, "STAY\n");
   fclose(fout);
   exit(0);
}


