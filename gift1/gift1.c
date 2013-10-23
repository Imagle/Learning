#include<stdio.h>

typedef struct person{
	char name[16];
	int money ;
}person;

int getPeople(char name[16], const person people[], const int n){
	int i=0;
	for(;i<n;i++){
		if( !strcmp(name, people[i].name) ){
			return i;
		}
	}
	return 22;
}

int main(){
	FILE* fin;
	FILE* fout;
	printf("ready to read\n");
	fin = fopen("gift1.in", "r");
	fout = fopen("gift1.out","w");
	int np = 0;
	fscanf(fin,"%d", &np);
	printf("%d\n", np);
	person people[np];
	int i=0;
	for(i=0;i<np;i++){
		fscanf(fin, "%s", people[i].name);
	}

	char giverName[16];
	int p;
	while( fscanf(fin, "%s", giverName) ){
		int money=0, num=0;
		fscanf(fin, "%d", &money);
		fscanf(fin, "%d", &num);
		if(num==0) continue;
		if( (p = getPeople(giverName, people, np)) && p==22) continue;
		int k=0;
		char tempName[16];
		int averageMoney = money/num;
		people[p].money -= averageMoney*num;
		for( ;k<num;k++){
			fscanf(fin, "%d", &tempName);
			if( (p = getPeople(giverName, people, np)) && p==22) continue;
			//p = getPeople(tempName, people, np);
			people[p].money += averageMoney;
		}
	}
	close(fin);
	for( i=0;i<np;i++)
		//fprintf(fout, "%s %d\n", people[i].name, people[i].money);
		printf("%s %d\n", people[i].name, people[i].money);
	close(fout);
	exit(0);
}
