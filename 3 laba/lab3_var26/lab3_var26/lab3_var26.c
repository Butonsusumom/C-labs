#include <stdio.h>
int main() {
	char word[20];
	char str[20];
	gets(word);
	int i = 0, j = strlen(word),l=1,r=0,k=0;
	while (i != j) {
		if (l == 1) {
				if (word[i] == word[i + 1]) {
					str[k] = '_';
					k++;
					i++;
					l = 0;
					r = 1;
					i++;
				}
			else {
				str[k] = word[i];
				k++;
				i++;
			}
				
		
		}
		if (r == 1) {
			j--;
			if (word[j] == word[j - 1]) {
				str[k] = '_';
				k++;
				j--;
				
				r = 0;
				l = 1;
			}
			else { 
			    str[k] = word[j];
				k++;
			}
			
		}

	}
	str[k] = '\0';
	puts(str);
	system("pause");
	return 0;
}
/*
MILLIOONNBILLIOON
NONNILLION
*/