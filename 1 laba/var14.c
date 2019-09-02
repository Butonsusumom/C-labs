#include <stdio.h> 
int main() {
	int c=1, x,n;
	
	double sum,s;
	scanf_s("%d", &x);
	sum = x;
	s = x;
	//n = x;
	for (int i = 1; i <= 6; i++) {
		
		 sum = (-1)*sum*(float)x*(float)x / ((float)(c+1)*(float)(c+2));
		 s = s + sum;
		c = c + 2;
		//n = n * x * x;
	}
	printf("%f  ", s);
	system("pause");
	return 0;
}