#include <stdio.h>

struct student {
	char surname[15];
	char city[25];
	float mark;
};

int main() {
	struct student ent[100];
	struct student out[100];
	struct student temp;
	char name[15];
	char s[25];
	char city[25],sit[25];
	int n,m,h;
	float buf;
	char str[25];
	printf("How many students you want to enter? ");
	scanf_s("%d", &n);
	m = 0;
	for (int i = 0; i < n; i++) {
		printf("Surname: ");
		getchar();
		gets(name);
		//scanf_s("%s",name);
		printf("City: ");
 		gets(city);
		for (int d = 0; d < strlen(city); d++)
			s[d] = tolower(city[d]);
		if ((s[0]=='m')&&(s[1] == 'i') && (s[2] == 'n') && (s[3] == 's') && (s[4] == 'k')) {
			for (int j=0;j<15;j++)
			ent[m].surname[j] = name[j];
			for (int j = 0; j < 25; j++)
			ent[m].city[j] = city[j];
			printf("Mark: ");
			scanf_s("%f", &ent[m].mark);
			m++;
		}
		else {
			printf("Mark: ");
			scanf_s("%f", &buf);
		}
		for (int d = 0; d < strlen(city); d++) s[d] = ' ';
	 }

	for (int i = 0; i < m-1; i++) {
		for (int j = i + 1; j < m; j++) {
			if (strcmp(ent[i].surname, ent[j].surname) > 0) {
				temp = ent[i];
				ent[i] = ent[j];
				ent[j] = temp;
			}
		}

	}
	if (m > 0) printf("=============================================\n");
	for (int i = 0; i < m; i++) {
		printf("Surname: ");
		for (int j=0;j<strlen(ent[i].surname);j++)
		printf("%c",ent[i].surname[j]);
		printf("\n");
		printf("City: ");
		for (int j = 0; j < strlen(ent[i].city); j++)
		printf("%c",ent[i].city[j]);
		printf("\n");
		printf("Mark: ");
		printf("%.1f\n", ent[i].mark);

	}


	system("pause");
	return 0;
}

/*
5
BBB
minsk
5.7
FFF
pinsk
3
DDD
Minsk
4
A
MiNsK
9.3
CC
MINSK
7.4


*/