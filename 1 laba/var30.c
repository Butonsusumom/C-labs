#include <stdio.h> 
int main() {
	int min, max, n;
	for (int i = 0; i < 5; i++) {
		scanf_s("%d", &n);
		if (i == 0) {
			min = n;
			max = n;
		}

		if (max < n) max = n;
		if (min > n) min = n;


	}
	printf("raznost=%d", max - min);
	system("pause");
	return 0;
}//*/