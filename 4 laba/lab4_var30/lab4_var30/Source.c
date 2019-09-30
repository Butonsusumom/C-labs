#include <stdio.h>

struct man {
	char name[100];
	int otd;
	int day;
	int month;
	int year;
};

int main() {
	struct  man ent[100];
	int n;
	struct  man temp;
	printf("How many employees you want to enter? ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("Name: ");
		getchar();
		gets(ent[i].name);
		//scanf_s("%s",name);
		printf("Plaese enter day of birth: ");
		scanf_s("%d", &ent[i].day);
		printf("Plaese enter month of birth: ");
		scanf_s("%d", &ent[i].month);
		printf("Plaese enter year of birth: ");
		scanf_s("%d", &ent[i].year);
		printf("Department: ");
		scanf_s("%d", &ent[i].otd);
	}

	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (ent[i].otd > ent[j].otd) {
				temp = ent[i];
				ent[i] = ent[j];
				ent[j] = temp;
			}
		}

	}
	int y,d,m;
	printf("What today's date(day,month,year)? ");
	scanf_s("%d", &d);
	scanf_s("%d", &m);
	scanf_s("%d", &y);
	int o,counter=0,h=0;
	float a;
	o = ent[0].otd;
	printf("The Depatrment ¹%d:", o);
	for (int i = 0; i < n; i++) {
		if (o != ent[i].otd) {
			a = (float)counter / (float)h;
			printf("%.1f\n - avarage age", a);
			o = ent[i].otd;
			printf("The Depatrment ¹%d:", o);
			h = 0;
			counter = 0;
		}
		h++;
		if (ent[i].month > m) counter = counter + (y - ent[i].year - 1);
		else counter = counter + y - ent[i].year;
	}
	a = (float)counter / (float)h;
	printf("%.1f\n - avarage age", a);


	system("pause");
	return 0;
}