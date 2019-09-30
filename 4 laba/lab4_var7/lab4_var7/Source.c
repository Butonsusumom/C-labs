#include <stdio.h>
struct book {
	char auth[100];
	char name[30];
	int year;
  };

int main() {
	struct book ent[100];
	int n, m;
	char s[20];
	printf("How many books you want to enter? ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("Authors: ");
		getchar();
		gets(ent[i].auth);
		//scanf_s("%s",name);
		printf("Name: ");
		gets(ent[i].name);
		printf("Year: ");
		scanf_s("%d", &ent[i].year);
	}

	printf("Please, enter name/part of name of the book you want to find: ");
	getchar();
	gets(s);

	if (n > 0) printf("=============================================\n");
	for (int i = 0; i < n; i++) {
		if (strstr(ent[i].name,s)) {
			printf("Authors: ");
			for (int j = 0; j < strlen(ent[i].auth); j++)
				printf("%c", ent[i].auth[j]);
			printf("\n");
			printf("Name: ");
			for (int j = 0; j < strlen(ent[i].name); j++)
				printf("%c", ent[i].name[j]);
			printf("\n");
			printf("Year: ");
			printf("%d\n", ent[i].year);
			printf("\n");
		}

	}
	system("pause");
	return 0;
}