#include <stdio.h>

struct man {
	char name[100];
	int year;
	int cl;
	int place;
};

int main(){
	int n;
	struct man ent[100];
	struct man temp;
	printf("How many pertisipants you want to enter? ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("Name: ");
		getchar();
		gets(ent[i].name);
		//scanf_s("%s",name);
		printf("Year: ");
		scanf_s("%d", &ent[i].year);
		do {
			printf("Class(enter 1(violin) or 2(piano): ");
			scanf_s("%d", &ent[i].cl);
		} while ((ent[i].cl != 1) && (ent[i].cl != 2));
		printf("Place in competition: ");
		scanf_s("%d", &ent[i].place);
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ent[i].place> ent[j].place) {
				temp = ent[i];
				ent[i] = ent[j];
				ent[j] = temp;
			}
		}

	}
	printf("=============================================\n");
	printf("             Violin\n");
	for (int i = 0; i < n; i++) {
		if (ent[i].cl == 1) {
			printf("Place: ");
			printf("%.d\n", ent[i].place);
			printf("Name: ");
			for (int j = 0; j < strlen(ent[i].name); j++)
				printf("%c", ent[i].name[j]);
			printf("\n");
			printf("Year: ");
			printf("%.d\n", ent[i].year);
			printf("\n");
		}
	}

	printf("             Piano\n");
	for (int i = 0; i < n; i++) {
		if (ent[i].cl == 2) {
			printf("Place: ");
			printf("%d\n", ent[i].place);
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