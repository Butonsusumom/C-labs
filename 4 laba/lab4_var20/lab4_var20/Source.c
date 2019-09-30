#include <stdio.h>
struct book {
	char auth[100];
	char name[30];
	int year;
};
int main() {
	struct book ent[100];
	struct book temp;
	int n, m;

	char s[20];
	printf("How many books you want to enter? ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("Name: ");
		getchar();
		gets(ent[i].name);
		printf("Authors: ");
		gets(ent[i].auth);
		printf("Year: ");
		scanf_s("%d", &ent[i].year);
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (strcmp(ent[i].name, ent[j].name) > 0) {
				temp = ent[i];
				ent[i] = ent[j];
				ent[j] = temp;
			}
		}

	}

	if (n > 0) printf("=============================================\n");
	for (int i = 0; i < n; i++) {
		if (ent[i].year>2000) {
			printf("Name: ");
			for (int j = 0; j < strlen(ent[i].name); j++)
				printf("%c", ent[i].name[j]);
			printf("\n");
			printf("Authors: ");
			for (int j = 0; j < strlen(ent[i].auth); j++)
				printf("%c", ent[i].auth[j]);
			printf("\n");
			printf("Year: ");
			printf("%d\n", ent[i].year);
			printf("\n");
		}

	}



	system("pause");
	return 0;
}