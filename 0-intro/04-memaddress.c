#include <stdio.h>

int main(void) {
	int age = 19;
	int year = 2;
	
	printf("Value: %d\n", age);
	printf("Address: %p\n", (void *)&age);

	printf("Year Value: %d\n", year);
	printf("Year Address: %p\n", (void *)&year);

	return 0;
}
