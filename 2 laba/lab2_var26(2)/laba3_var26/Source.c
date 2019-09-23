#include <stdio.h>
#include <time.h>

int main() {
	int A[6][5];
	int sum=0;
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {

			A[i][j] = rand() % 100;
		}
	}
	int g = 0;
	for (int i = 0; i < 5; i++) {
	
		for (int j = 0; j < 5; j++) {
			sum += A[i][j];
				printf("%-5d", A[j][i]);
		}
		printf("\n");
		A[5][g] = sum;
		sum = 0;
		g++;
	}
	printf("=========================\n");
	for (int i = 0; i < 5; i++) {
		printf("%-5d", A[5][i]);
	}
	int temp;
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 5; j++) {
			if (A[5][i] > A[5][j]) {
				temp = A[5][i];
				A[5][i] = A[5][j];
				A[5][j] = temp;
				for (int n = 0; n < 5; n++) {
					temp = A[i][n];
					A[i][n] = A[j][n];
					A[j][n] = temp;
				}
			}
		}
	}
	


	printf("\n");
	printf("\n");
	printf("\n");

	for (int i = 0; i < 5; i++) {

		for (int j = 0; j < 5; j++) {
			sum += A[i][j];
			printf("%-5d", A[j][i]);
		}
		printf("\n");
	}
	printf("=========================\n");
	for (int i = 0; i < 5; i++) {
		printf("%-5d", A[5][i]);
	}
	printf("\n");

	system("pause");
	return 0;


}