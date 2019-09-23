#include <stdio.h> 

int main() {
	int A[100][100];
	int n=5;
	//scanf("%d\n",&n);
	for (int i = 1; i <= n; i++) {
	  	for (int j = 1; j <= n; j++) {
			scanf_s("%d",&A[i][j]);
		}
		printf("\n");
	}
	int cmin=0,cmax=0,min=0,max=0,k=0,h=0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (A[i][j] < 0) cmin++;
			if (A[j][i] > 0) cmax++;
		}
		if (min < cmin) {
			min = cmin;
			k = i;
		}
		if (max < cmax) {
			max = cmax;
			h = i;
		}
		cmin = 0;
		cmax = 0;
	}
	for (int i = 1; i <= n; i++) {
		if (i != k) {
			for (int j = 1; j <= n; j++) {
				if (j != h) printf("%d ",A[i][j]);
			}
			printf("\n");
		}
	}
	system("pause");
	return 0;
}
/*
 5  1  2  3 4

-2 -2 -1 -2 1

 5  6  4  3 2

-1  5  9 -7 4

 1  1  2  2 2

 vivod :
 5  1  2  3 

 5  6  4  3 

-1  5  9 -7 

 1  1  2  2 

*/