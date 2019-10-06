#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>


void SortStrings(char **s, int n)
{
	char *p;
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = n - 1; j > i; j--)
			if (strcmp(s[j - 1], s[j]) > 0) {
				p = s[j];
				s[j] = s[j - 1];
				s[j - 1] = p;
			}
}

int main()
{
	char str[20], **words = NULL, *p = NULL;
	int i, cnt = 0;

	puts("Input String");
	gets(str);
	if (strchr(str, '_')==0) puts(str);
	else {

		for (p = strtok(str, "_"); p != NULL; p = strtok(NULL, "_")) {
			if ((words = (char**)realloc(words, sizeof(char*) * (cnt + 1))) == NULL) {
				printf("No memory to new word!\n");
				exit(1);
			}
			if ((words[cnt] = _strdup(p)) == NULL) {
				printf("Can't duplicate word!\n");
				exit(1);
			}
			++cnt;
		}

		SortStrings(words, cnt);
		int k;
		int t;
		char *y;
		while (1)
		{
			k = cnt - 2;
			while ((strcmp(words[k], words[k + 1]) >= 0) && (k >= 0))
			{
				k--;
				if (k < 0)
					break;
			}
			if (k < 0)
			{
				break;
			}
			t = k + 1;
			while ((t < cnt - 1) && (strcmp(words[t + 1], words[k]) > 0))
				t++;
			y = words[k];
			words[k] = words[t];
			words[t] = y;
			t = 0;
			while (t < (int)((double)(cnt - 1 - k) / 2.0))
			{
				y = words[cnt - 1 - t];
				words[cnt - 1 - t] = words[k + 1 + t];
				words[k + 1 + t] = y;
				t++;
			}
			for (i = 0; i < cnt; ++i) {
				if (i==cnt-1) printf("%s", words[i]);
				else 
				printf("%s_", words[i]);
			}
			printf("\n");

		}

		for (i = 0; i < cnt; ++i) {
			if (words[i] != NULL) {
				free(words[i]);
				words[i] = NULL;
			}
		}
		//free(words);
		//words = NULL;
	}


	system("pause");
	return 0;
}