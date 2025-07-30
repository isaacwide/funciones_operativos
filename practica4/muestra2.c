#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]){

char orden1[30];
char orden2[30];

int i;

for(i=0;i<argc;i++){
	sprintf(orden1,"ls %s",argv[i]);
	sprintf(orden2,"cat %s",argv[i]);
	system(orden1);
	getchar();
	system(orden2);
}



}
