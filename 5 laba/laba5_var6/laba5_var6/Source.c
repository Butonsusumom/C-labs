#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int main() {
	FILE *f;
	char s[100],c,d;
	int k=0;
	
	printf("Plese, enter full way to file: ");
	//getchar();
	gets(s);
	f = fopen(s, "r+t");
	if (f != NULL) {

		while ((c = fgetc(f)) != EOF) {
			d = tolower(c);
			fseek(f, -1, SEEK_CUR);
			fputc(d, f);
			//k++;
			fseek(f, 0, SEEK_CUR);
		}
		fclose(f);
	}
	else { printf("Such File doesn't exists\n"); }
	system("pause");
	return 0;
}