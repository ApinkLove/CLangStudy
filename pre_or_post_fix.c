#include <stdio.h>
int main(void) {
	int age=0;
	printf("전위형 증감(prefix)은 증감후 return합니다. \n");
	printf("%d\n", ++age);
	printf("후위형 증감(postfix)은 return후 증감합니다. \n");
	printf("%d\n", age++);
	printf("%d\n", age);
	return 0;
}
