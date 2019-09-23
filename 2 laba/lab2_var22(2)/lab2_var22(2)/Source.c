#include <stdio.h>
#include <time.h>
int main() {
	int A[6][6];
	int n = 6;
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {

			A[i][j] = 2+rand() % 15;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			 printf("%-3d", A[i][j]);
		}
		printf("\n");

	}


	int *pt, *pp,s;
	pt = A[0];
	for (int i = 1; i <= n*n; i++) {
		pp = pt + 1;
		s = *pt;
		for (int j = i + 1; j <= n*n; j++) {
			if (s == *pp) {
				*pp = 0;
				*pt = 0;
			}
			pp++;
		 }
		pt++;
	 }

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (A[i][j] != 0) {
				A[i][j] = 1;
			}
		}
	}


	printf("\n");
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
				printf("%-3d", A[i][j]);
		}
		printf("\n");
	}


	system("pause");
	return 0;
}