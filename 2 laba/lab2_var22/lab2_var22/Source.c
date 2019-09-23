#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 int main() {
	 int A[100][100];
	 int n=0; 
	 srand(time(NULL));
	 while (n%2==0)
	 scanf_s("%d", &n);
	 for (int i = 0; i < n; i++) {
		 for (int j = 0; j < n; j++) {
			
			 A[i][j] = rand() % 100;
		 }
	 }
	 for (int i = 0; i < n; i++) {
		 for (int j = 0; j < n; j++) {
			 if (A[i][j] %10==0)
			 printf("%-3d  ", A[i][j]);
			 else printf("%-3d ", A[i][j]);
		 }
		 printf("\n");
	 }

	 int max = -1,x=-1,y=-1;
	 for (int i = 0; i < n; i++) {
		 if (A[i][i] > max) {
			 max = A[i][i];
			 x = i;
			 y = i;
		 }
	 }

	 for (int i = 0; i < n; i++) {
		 if (A[i][n - i-1] > max) {
			 max = A[i][n-i-1];
			 x = i;
			 y = n-i-1;
		 }
	}

	  printf("%d\n", A[x][y]);
	 //printf("%d\n", max);
	printf("%d\n", A[(n - 1) / 2][(n - 1) / 2]); 

	 int temp;
	 temp = A[(n - 1) / 2 ][(n - 1) / 2 ];
	 A[(n - 1) / 2 ][(n-1) / 2 ] = A[x][y];
	 A[x][y] = temp;
	 printf("\n");
	 printf("\n");
	 for (int i = 0; i < n; i++) {
		 for (int j = 0; j < n; j++) {
			 if (A[i][j] % 10 == 0)
				 printf("%-3d  ", A[i][j]);
			 else printf("%-3d ", A[i][j]);
		 }
		 printf("\n");
	 }


	 system("pause");
	 return 0;
}