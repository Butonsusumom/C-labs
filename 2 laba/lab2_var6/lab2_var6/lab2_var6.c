#include <stdio.h> 
int main() {
	int min,max,a,b,N=6,T;
	int A[7][7];
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			scanf_s("%d", &A[i][j]);
			if (i == 1) {
				if (j == 1) {
					min = A[i][j];
					a = i;
					b = i;
					max = A[i][j];
				}
			}
			if (min > A[i][j]) {
				min = A[i][j];
				a = i;
			}
			if (max < A[i][j]) {
				max = A[i][j];
				b = i;
			}
		}
	}
	printf("\n");
	printf("\n");

	for (int j = 1; j <= 6; j++) {
			T = A[a][j];
			A[a][j] = A[b][j];
			A[b][j] = T;
	}




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
2 2 2 2 1 2
2 2 2 2 2 2
2 2 2 2 2 2
3 2 2 2 2 2
2 2 2 2 2 2
2 2 2 2 2 2
*/