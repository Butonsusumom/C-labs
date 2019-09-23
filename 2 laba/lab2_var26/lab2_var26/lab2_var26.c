#include <stdio.h> 
int main() {
	int A[7][7];
	int min, max, x,ki,kj,hi,hj;
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			scanf_s("%d", &A[i][j]);
		}
	}


	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {

			if (j == 1) {
				min = A[i][j];
				max = A[i][j];
				ki = i;
				hi = i;
				hj = j;
				kj = j;
			}
			if (min > A[i][j]) {
				min = A[i][j];
				ki = i;
				kj = j;
			}
			if (max < A[i][j]) {
				max = A[i][j];
				hi = i;
				hj = j;
			}
		}
		x = A[ki][kj];
		A[ki][kj] = A[hi][hj];
		A[hi][hj] = x;
	}





	printf("\n");
	printf("\n");
	for (int i = 1; i <= 6; i++) {
	for (int j = 1; j <= 6; j++) {
		printf("%d ", A[i][j]);
	}
	printf("\n");
}
	system("pause");
	return 0;
}
/*
1 2 2 2 2 9
2 1 2 2 9 2
2 2 1 9 2 2
2 2 9 1 2 2
2 9 2 2 1 2
9 2 2 2 2 1
*/