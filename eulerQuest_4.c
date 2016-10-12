#include <stdio.h>
int main() {
	int temp, a, b, c;
	int guess = 0;
	for (int i = 100; i < 1000; i++) {
		for (int j = 100; j < 1000; j++) {
			temp = i*j;
			if (temp % 11 == 0 && guess < temp) {
				if (temp > 100000) {
					a = temp / 100000;
					b = temp / 10000 - a * 10;
					c = temp / 1000 - a * 100 - b * 10;
					if (a * 100001 + b * 10010 + c * 1100 == temp)
						guess = temp;
				}
				else {
					a = temp / 10000;
					b = temp / 1000 - a * 10;
					c = temp / 100 - a * 100 - b * 10;
					if (a * 10001 + b * 1010 + c * 100 == temp)
						guess = temp;
				}
			}
		}
	}
	printf("%d\n", guess);
	return 0;
}
