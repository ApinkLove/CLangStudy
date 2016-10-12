#include <stdio.h>
int main() {
	int num = 3;
	int count = 1;
	int temp, guess;
	while (count != 10001) {
		for (int i = 3; i <= num; i+=2) {
			if (num%i == 0 && num!=i)
				break;
			if (i == num) {
				count++;
				if (count != 10001)
					temp = num;
				else
					guess = num;
			}
		}
		num += 2;
	}
	printf("%d", guess);
	return 0;
}
