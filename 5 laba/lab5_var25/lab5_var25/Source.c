#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>

int main() {
	FILE *f1, *f2;
	char s1[100], s2[100], c, d, my[100];
	int a[30];
	int k = 0,f=0,b=0;

	printf("Plese, enter full way to file1: ");
	//getchar();
	gets(s1);
	//if (symbol_file_exists(s1)) {
	f1 = fopen(s1, "rt");
	if (f1 != NULL) {
		printf("Plese, enter full way to file2: ");
		//getchar();
		gets(s2);
		f2 = fopen(s2, "wt");
		c = ' ';
		while (c != EOF) {
			for (int i = 0; i < k; i++) {
				my[i] = ' ';
			}
			k = 0;
			b = 0;
			c = fgetc(f1);
			while ((c != ' ') && (c != EOF)) {
				my[k] = c;
				c = fgetc(f1);
				k++;
			}
			if ((c == ' ') || (c == EOF)) {
				for (int i = 0; i < f; i++) {
					if (a[i] == atoi(my)) b = 1;
				}
				if (b!=1){
					printf("%d ", atoi(my));
					fprintf(f2, "%d ", atoi(my));
					a[f] = atoi(my);
					f++;
					//fputs(my, f2);
				}
				//c=fgetc(f1);
			}
		}

		fclose(f1);
		fclose(f2);
	}
	else { printf("Such File doesn't exists\n"); }
	system("pause");
	return 0;
}