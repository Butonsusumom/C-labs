#include <stdio.h>

struct man {
	char country[30];
	char name[100];
	int place;
};

int main() {
	struct man ent[100];
	int n;
	int sum1=0, sum2=0;
	struct man temp;
	char Rus[30] = "Belarus";
	char Bel[30] = "Russia";
	printf("How many participants you want to enter? ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		getchar();
		do {
			printf("Country: ");
			
			gets(ent[i].country);
		}while ((strcmp(Rus, ent[i].country) != 0) && ((strcmp(Bel, ent[i].country) != 0)));
		 //scanf_s("%s",name);
		printf("Name: ");
		gets(ent[i].name);
		printf("Place: ");
		scanf_s("%d", &ent[i].place);
		getchar();
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

	printf("=============================================\n");
	printf("             Belarus\n");
	for (int i = 0; i < n; i++) {
		if (strcmp(Bel, ent[i].country) == 0) {

			printf("Name: ");
			for (int j = 0; j < strlen(ent[i].name); j++)
				printf("%c\n", ent[i].name[j]);
			printf("Place: ");
			printf("%.d\n", ent[i].place);
			printf("\n");
			if (ent[i].place == 1) sum1 += 6;
			if (ent[i].place == 2) sum1 += 5;
			if (ent[i].place == 3) sum1 += 4;
		}
			
		
		
	}
	if (sum1 == 0) printf("There no participants from this team\n");
	else
		printf("%.d\n", sum1);
	printf("\n");

	printf("             Russia\n");
	for (int i = 0; i < n; i++) {
		if (strcmp(Rus, ent[i].country) == 0) {

			printf("Name: ");
			for (int j = 0; j < strlen(ent[i].name); j++)
				printf("%c\n", ent[i].name[j]);
			printf("Place: ");
			printf("%.d\n", ent[i].place);
			printf("\n");
			if (ent[i].place == 1) sum2 += 6;
			if (ent[i].place == 2) sum2 += 5;
			if (ent[i].place == 3) sum2 += 4;
		}


		
	}
	if (sum2 == 0) printf("There no participants from this team\n");
	else
		printf("%.d\n", sum2);
	printf("\n");
	if (sum1 > sum2) printf("BELARUS IS THE WINNER!\n");
	if (sum2 > sum2) printf("RUSSIA IS THE WINNER!\n");
	if (sum1 == sum2) printf("IT IS A DEAD HEAT\n");

	system("pause");
	return 0;
}