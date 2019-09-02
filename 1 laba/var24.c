#include <stdio.h> 
int main() {
	int n, counter=0;
	int A[100];
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf_s("%d", &A[i]);
		if (A[i] > 7) {
			A[i] = 7;
			counter++;
		}
	}
	printf("Elements more than 7: %d\n", counter);
	for (int i = 0; i < n; i++) {
		printf("%d  ", A[i]);
	}
	system("pause");
	return 0;
}