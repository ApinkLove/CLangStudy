#include <stdio.h>
#include <stdlib.h>
int main(void) {
	unsigned long long int **point=NULL;
	point=(unsigned long long int**)malloc(sizeof(unsigned long long int*)*21);
	for(int i=0 ; i<21 ; i++) {
		point[i]=(unsigned long long int*)malloc(sizeof(unsigned long long int)*21);
	}
	
	// initializing 
	for(int n=0 ; n<21 ; n++) {
		point[0][n]=1;
		point[n][0]=1;
	}
	
	// scoring
	for(int c=1; c<21; c++) {
		for(int r=1; r<21; r++) {
			point[c][r]=point[c-1][r]+point[c][r-1];
			// For checking
			printf(" %d, %d -> %lld\n ", c, r, point[c][r]);
		}
	}
	
	printf("%lld\n", point[20][20]);
	
	
	for(int i=0 ; i<21 ; i++) {
		free(point[i]);
	}	
	free(point);
	
	return 0;
}
