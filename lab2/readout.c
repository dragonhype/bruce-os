// Author: Spenser Desrochers, Josh Patnaude, Nicholas LaJoie
// ECE 477 - Lab 2
// Date: February 10, 2017
// Description: Program that reads in CSV from lab2 and outputs a summary of the results

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]){
	FILE * ff;
	int a[19682],b[19682],c[19682],d[19682],e[19682],f[19682],g[19682],h[19682],i[19682],j[19682];
	int m=0,n=0;
	int cxw=0,cow=0,cnw=0,gip=0,cxm=0,com=0;
	//Open file for reading
	if(argc == 2){
		ff = fopen(argv[1],"r");
		if(ff<0){
			printf("Fopen issue. Maybe wrong name?\n");
			return -1;
		}
	}else{
		printf("Please give only the filename\n");
		return -1;
	}
	//Get Data from CSV
	//while(!feof(ff)){
	while(fscanf(ff,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,",&a[n],&b[n],&c[n],&d[n],&e[n],&f[n],&g[n],&h[n],&i[n],&j[n]) >= 0){
		n++;
	}
	if(feof(ff)){
		printf("Reached EOF\n");
	} else{
		printf("Scanf issue. File may be in wrong format\n");
		return -1;
	}
	//Scan Last Column to get summary of wins,incompletes, and games in progress
	for(m=0;m<n;m++){
		if(j[m] == 1){
			gip += 1;
		}else if(j[m] == 2){
			cxw += 1;
			if(e[m] == 1){
				cxm += 1;
			}
		}else if(j[m] == 3){
			cow += 1;
			if(e[m] == 2){
				com += 1;
			}
		}else if(j[m] == 4){
			cnw += 1;
		}
	}
	
	printf("Game in Progress: %d\nX Wins: %d\nO Wins: %d\nDraws: %d\n",gip,cxw,cow,cnw);
	printf("X was in middle when it won %d times.\nO was in middle when it won %d times.\n",cxm,com);
	fclose(ff);
	return 0;
}

