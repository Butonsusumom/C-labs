#include <stdio.h> 
int main() {
	char text[200];
	gets(text);
	int i = strlen(text)-1,j,e=strlen(text);
	while (i >= 0) {
		while (text[i] != ' ') {
			if (i == -1) break;
			i--;
		}
	
		j = i;
		for (int g = i + 1; g < e; g++) {
			printf("%c", text[g]);
		}
		printf(" ");
		e = j;
		i--;
	}
	printf("\n");

	system("pause");
	return 0;
}