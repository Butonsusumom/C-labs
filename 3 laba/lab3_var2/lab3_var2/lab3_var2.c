/*#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main() {
	char s[80];
	gets(s);
	int x[3] = {0,0,0};
	for (int i = 1; i <= 80; i++) {
		if (s[i] == "D") x[1] = 1;
		if (s[i] == "O") x[2] = 1;
		if (s[i] == "S") x[3] = 1;
	}
	if (x[1] == 1 | x[2] == 1 | x[3] == 1) printf("yes");
	else printf("no");
	return 0;
	system("pause");

}*/
#include <stdio.h>


main() {
	char word[] = "DOS";
	char s[80];
	gets(s);
	int i, j, w = strlen(word);
	for (j = 0; word[j] != '\0'; j++) {
		for (i = 0; s[i] != '\0'; i++) {
			if (toupper(s[i]) == word[j]) {//преобразование строчных букв в заглавные
				w--;
				break;
			}
		}
	}
	if (w>0) {
		printf("No\n");
	}
	else {
		printf("Yes\n");
	}

	system("pause");
	return 0;
}
/*
This is string with D O nus innbS
This is string with D o nus innbS
This is string only with D innbS

*/