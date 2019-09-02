#include <stdio.h>        
int main() {
	int n, m,xn=1,xm=1,xs=1,s;
	double r;
	scanf_s("%d", &n);
	scanf_s("%d", &m);
	s = m + n;
	for (int i = 2; i <= n; i++) {
		xn = xn * i;
	}
	for (int i = 2; i <= m; i++) {
		xm = xm * i;
	}
	for (int i = 2; i <= s; i++) {
		xs = xs * i;
	}
	r = ((float)xn+(float)xm )/ ((float)xs);
	printf("%f", r);
	system("pause");
	return 0;
}
