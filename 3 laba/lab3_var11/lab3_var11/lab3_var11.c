#include <stdio.h>
int main() {
	char text[200];
	char str[20];
	char word[10];
	gets(text);
	gets(word);
	int i = 0,k=0,n=0;
	for (int i = 0; i < strlen(text); i++) {
		text[i] = tolower(text[i]);
	}
	for (int i = 0; i < strlen(word); i++) {
		text[i] = tolower(text[i]);
	}
	while (i < strlen(text)) {
		for (int j = 0; j < strlen(word); j++) {
			if (text[i] == word[j]) {
				if (j == strlen(word) - 1) {
					if (text[i+1]=='\0') n++;
					if (text[i + 1] == ' ') n++;
					i++;
				}
			}
			else {
				if (text[i] != ' ') {
					while (text[i] != ' ') i++;
					
				}
			}
			
		}
		while (text[i] == ' ') i++;
	}

	printf("%d\n", n);
	system("pause");
	return 0;
}

/*
ggg ghggg    fghdgfgggggg ggg     fff   2
ggg    ggg     GGG   GgG  ggghhh hhhggg    ggg GGG    h    6
ggg GGG GgG      ggg ggghhh hhhggg   GGG       gg     ggG  7

*/