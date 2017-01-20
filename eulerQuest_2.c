#include <stdio.h>
int main(void) {
	int sum=0, temp=0, first_num, last_num;
	//init process , fibonacci 
	first_num = 1;
	last_num = 2;
	while (last_num<=4000000) {
		temp = last_num;
		if (last_num % 2 == 0)
			sum += last_num;
		last_num += first_num;
		first_num = temp;
	}
	printf("sum is %d\n", sum);
	return 0;
}
