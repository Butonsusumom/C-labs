#include <stdio.h> 
int main() {
	int N=6,k,T,f;
	int A[7][7];
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			scanf_s("%d", &A[i][j]);
		}
	}
	scanf_s("%d", &f);
	if (f == 1) {

		printf("\n");
		
		for (int i = 1; i <= 6; i++) {
			for (int j = 1; j <= 3; j++) {
				k = N  + 1 -j;
				T = A[i][k];
				A[i][k] = A[i][j];
				A[i][j] = T;
			}
		}
	}
	if (f == 2) {
		printf("\n");
		
			for (int j = 1; j <= 6; j++) {
				for (int i = 1; i <= 3; i++) {
				k = N + 1 -i;
				T = A[k][j];
				A[k][j] = A[i][j];
				A[i][j] = T;
			}
		}
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
1 2 3 4 5 6
1 2 3 4 5 6
1 2 3 4 5 6
1 2 3 4 5 6
1 2 3 4 5 6
1 2 3 4 5 6
1

1 1 1 1 1 1
2 2 2 2 2 2
3 3 3 3 3 3
4 4 4 4 4 4
5 5 5 5 5 5
6 6 6 6 6 6
2


*/