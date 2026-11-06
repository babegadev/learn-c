#include <stdio.h>

void swap(int *a, int *b) {

	int temp = *b;
	*b = *a;
	*a = temp;

}

int main(void) {

	int x = 6;
	int y = 7;

	swap(&x, &y);

	printf("%d %d\n", x, y);

}
