#include <stdio.h>
int main () {
	long long int x=600851475143;
	int y=3;
	while (!(x/y==1 && x%y==0)){
		while (x%y==0){
			x=x/y;
		}
		y+=2;
	}
	printf("%d\n", y);
	return 0;
}
