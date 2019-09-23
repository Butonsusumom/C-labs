#include <stdio.h> 
int main() {
	char text[200];
	gets(text);
	text[strlen(text)] = ' ';
	int b=0, e=0, max=0, len=0,mb=0,me=0;
	for (int i = 0; i < strlen(text);i++) {
		if (text[i] != ' ') {
			//len++;
			if ((i==0)||(text[i-1]==' ')){
				b = i;
			}
			len++;
		}
		else {
			if ((i == 0) || (text[i - 1] != ' ')) {
				e = i-1;
				if (max<len) {
					max = len;
					mb = b;
					me = e;
					
				}
			}

			len = 0;
		}

	}

	printf("The longest word: ");
	for (int i = mb; i <= me; i++) {
		printf("%c", text[i]);
	}
	//printf("%d", mb);
	//printf("%d", me);
	printf("\n");
	system("pause");
	return 0;
}

/*
ffffffffffff fff   fff     f ffff            ffff ffff f
f ffffffffffffffff fff            f  ff ff     fff  ffffff    
              f    ff         ff   ff f f f  f f fffffffffffff
*/