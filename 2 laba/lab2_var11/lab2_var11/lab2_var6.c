#include <stdio.h> 
int main() {
	int A[5][6];
	int x;
	int k,l;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 5; j++) {
			scanf_s("%d", &A[i][j]);
		}
	}
	printf("\n");
	printf("\n");
	for (int j = 1; j <= 5; j++) {
		if (j % 2 == 0) {
			for (int i = 1; i <= 3; i++) {
				l = i + 1;
				for (k =l; k <= 4; k++) {
					if (A[i][j] > A[k][j]) {
						x = A[k][j];
						A[k][j] = A[i][j];
						A[i][j] = x;
					}
				}
			}
		}
		else {
			for (int i = 1; i <= 3; i++) {
				l = i + 1;
				for (k = l; k <= 4; k++) {
					if (A[i][j] < A[k][j]) {
						x = A[k][j];
						A[k][j] = A[i][j];
						A[i][j] = x;
					}
				}
			}
		}
	}

		for (int i = 1; i <= 4; i++) {
			for (int j = 1; j <= 5; j++) {
				printf("%d ", A[i][j]);
			}
			printf("\n");
		}
	system("pause");
	return 0;
}
/*
1 4 1 4 1
2 3 2 3 2
3 2 3 2 3
4 1 4 1 4

*/