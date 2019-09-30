#include <stdio.h>

void permutation(char m[20][20],int l,int n) {
	char temp[20];
	if (l == n - 1) {
		for (int i = 0; i < n; i++) puts(m[i]);
		printf(" ");
	}
	else {
		for (int i = 1; i < n; i++) {
			for (int h=0;h<strlen(m[l]);h++) temp[h] = m[l][h];
			for (int h = 0; h < strlen(m[i]); h++) m[l][h] = m[i][h];
			for (int h = 0; h < strlen(temp); h++) m[i][h] = temp[h];
			permutation(m, l+1, n);
			for (int h = 0; h < strlen(m[l]); h++) temp[h] = m[l][h];
			for (int h = 0; h < strlen(m[i]); h++) m[l][h] = m[i][h];
			for (int h = 0; h < strlen(temp); h++) m[i][h] = temp[h];

		}
	}
}


int main() {
	char str[100];
	int w = 0, j = 0, k = -1;
	gets(str);
	if (strlen(str) == 0) printf("You entered no worlds");
	else {
		for (int i = 0; i < strlen(str); i++) {
			if (str[i] == '_') w++;
		}
		w++;
		char m[20][20];
		for (int i = 0; i < w; i++) {
			k++;
			j = 0;
			while ((str[k] != '_')&&(k!= strlen(str))) {
				m[i][j] = str[k];
				j++;
				k++;
			}
		}

		for (int i = 0; i < w; i++) {
			printf("%d", strlen(m[i]));
			for (int g = 0; g < strlen(m[i]); g++) {
				printf("%c", m[i][g]);
			}
		}
		permutation(m, 0, w);
	}
	system("pause");
	return 0;
 }