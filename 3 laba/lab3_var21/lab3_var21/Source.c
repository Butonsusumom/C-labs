#include <stdio.h> 
int main() {
	char text[200];
	gets(text);

	for (int i = strlen(text) - 1; i >= 0; i--) {
		if (isalpha(text[i])) printf("%c", text[i]);
	}
	for (int i =0; i <strlen(text); i++) {
		if (isdigit(text[i])) printf("%c", text[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}

/*
ab2e78b8
777666888abd456ghj
*/