#include <stdio.h>        
int main() {
	//printf("The result of sum of raw 1/i^2, where i from 1 to 100");

	float sum = 0;

	for (int i = 1; i <= 100; i++)
		sum += 1 / ((float)i*(float)i);
	printf("%4.2f\n", sum);
	system("pause");
	return 0;
}