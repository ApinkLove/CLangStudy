#include <stdio.h>
int main () {
	long long int x=600851475143;
	int y=3;
	/* factor will be % answer = 0, prime factor will be odd number except 2 */
	while (x!=y) {
    		if(x%y==0) x=x/y;
		y+=2;
	}
	printf("%d\n", y);
	return 0;
}
