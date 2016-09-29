#include <stdio.h>
int main(void) {
	int answer_cnt = 0;
	for (int a = 3; a <= 1997; a++) {
		for (int b = 2; b < a; b++) {
			for (int c = 1; c < b; c++) {
				if (a + b + c == 2000) {
					answer_cnt++;
					printf("%d %d %d\n", a, b, c);
				}
			}
		}
	}
	printf("Answer is %d\n", answer_cnt);
	return 0;
}
