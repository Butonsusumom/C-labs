#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int main() {
	FILE *f1, *f2, *f3;
	char s1[100], s2[100], s3[100];
	char c, s;
	printf("Plese, enter full way to file with symbols: ");
	gets(s1);
	f1 = fopen(s1, "rt");
	printf("Plese, enter full way to file with numbers: ");
	gets(s2);
	f2 = fopen(s2, "rt");
	if ((f1 == NULL) || (f2 == NULL)) {
		printf("Some file doesn't exists");
	}
	else {
		printf("Plese, enter full way to file to write: ");
		gets(s3);
		f3 = fopen(s3, "wt");
		c = " ";
		s = " ";
		while ((c != EOF)||(s!=EOF)) {
			if (c != EOF) {
				c = fgetc(f1);
				if (c != EOF) fprintf(f3, "%c", c);
			}
			if (c != EOF) {
				c = fgetc(f1);
				if (c != EOF) fprintf(f3, "%c", c);
			}
			if (s != EOF) {
				s = fgetc(f2);
				if (s != EOF) fprintf(f3, "%c", s);
			}
		}
		fclose(f1);
		fclose(f2);
		fclose(f3);
	}
	system("pause");
	return 0;
}

