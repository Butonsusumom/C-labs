#include <stdio.h> 
int main() {
	int A[7][7];
	int min, max, smin, smax;
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			scanf_s("%d", &A[i][j]);
		}
	}
	printf("\n");
	printf("\n");
	min = 0;
	max = 0;
	smin = 0;
	smax = 0;
	for (int i = 1; i <= 6; i++) {
		
		for (int j = 1; j <= 6; j++) {
			if (i % 2 == 0) {
				if (j == 1) 	min = A[i][j];

				if (min > A[i][j]) min = A[i][j];
			}
			else {
				if (j == 1) max = A[i][j];
				if (max < A[i][j]) max = A[i][j];
			}
		
		}
		smax = smax + max;
		smin = smin + min;
		min = 0;
		max = 0;
	}

	printf("%d\n", smin);
	printf("%d\n", smax);
	/*for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}*/
	system("pause");
	return 0;
}
/*
1 2 3 4 5 6
2 3 4 5 6 7
3 4 5 6 7 8
4 5 6 7 8 9
5 6 7 8 9 1
6 7 8 9 1 2
*/