#include <stdio.h>



int main() {

	char s[80];
	gets(s);
	int n=0,m,l = strlen(s);
	printf(" length of that string: %d\n", l);
	if (l == 10) {
		for (int i = 0; i < l;i++) {
			m = strlen(s);
			if (s[i-n] > 96 & s[i-n] < 123) {
				for (int j = i-n; j < m; j++) {
					s[j] = s[j + 1];
					
				}
				//m = strlen(s);
				s[m] = '\0';
				n++;
			}
		}
	}
	puts(s);
	system("pause");
	return 0;
}

/*
LoVeNotWaR
WANNA SLEEP
*/