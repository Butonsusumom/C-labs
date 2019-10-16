#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h> 
#include <stdlib.h>
# define str_len 30  


void enter_new();
void del();
void change();
void out();
void defoltout();
void sort();
struct rating {
	int math;
	int prog;
	int phil;
	int okt;
	int ti;
	float avarage;
	int zad;
};
struct Student {
	int group;
	char name[str_len];
	struct rating marks;
};
struct Student list[100];
struct Student bad;
int current_size = 0; int choice;
FILE *f;
int main() {
	char s[30];
	int id = 0;
	f = fopen("1.txt","rt");
	while (feof(f)!=1) {
		
		current_size++;
		fgets(s,30,f);
		list[id].group = atoi(s);
		fgets(s, 30, f);
		strcpy(list[id].name, s);
		fgets(s, 30, f);
		list[id].marks.math = atoi(s);
		fgets(s, 30, f);
		list[id].marks.prog = atoi(s);
		fgets(s, 30, f);
		list[id].marks.phil = atoi(s);
		fgets(s, 30, f);
		list[id].marks.okt = atoi(s);
		fgets(s, 30, f);
		list[id].marks.ti = atoi(s);
		
		list[id].marks.avarage = ((float)list[id].marks.math + list[id].marks.prog + list[id].marks.phil + list[id].marks.okt + list[id].marks.ti) / 5;
		id++;
	}
	fclose(f);
	sort();
	do {
		printf("Enter\n");
		printf("1: Delete\n");
		printf("2: Add new student\n");
		printf("3: Correct\n");
		printf("4: Print students\n");
		printf("5: Exit\n");
		printf("\n");
		scanf_s("%d", &choice);

		//do
		//{
			switch (choice)
			{
			case 1:  del();	break;
			case 2:  enter_new();  break;
			case 3:  change();  break;
			case 4:  out();	break;
			}
		//} while (choice != 5);
	} while ((choice == 0)&& (choice != 5));
	f = fopen("1.txt", "wt");
	char str[100];
	for (int i = 0; i < current_size; i++) {
		_itoa(list[i].group, str, 10);
		fputs(str,f);
		fputs("\n", f);
		fputs(list[i].name,f);
		//fputs("\n", f);
		_itoa(list[i].marks.math, str, 10);
		fputs(s, f);
		fputs("\n", f);
		_itoa(list[i].marks.prog, str, 10);
		fputs(str, f);
		fputs("\n", f);
		_itoa(list[i].marks.phil, str, 10);
		fputs(str, f);
		fputs("\n", f);
		_itoa(list[i].marks.okt, str, 10);
		fputs(str, f);
		fputs("\n", f);
		_itoa(list[i].marks.ti, str, 10);
		fputs(str, f);
		if (i<current_size-1)
		fputs("\n", f);
		


	}
	fclose(f);
}
void enter_new() {
	int n;
	 printf ("\nEnter new student\n");
	 printf("How many students you want to enter? ");
	 scanf_s("%d",&n);
	 for (int i = 0; i < n;i++) {
		 printf("Group: ");
		 scanf_s("%d", &list[i+ current_size-1].group);
		 getchar();
		 printf("Surname: ");
		 gets(list[i+ current_size-1].name);
		 list[i + current_size - 1].name[strlen(list[i + current_size - 1].name)]='\n';
		 printf("Math mark: ");
		 
		 scanf_s("%d", &list[i+ current_size-1].marks.math);
		 if (list[i+ current_size-1].marks.math < 4) list[i+ current_size-1].marks.zad++;
		 printf("Programming mark: ");
		 scanf_s("%d", &list[i+ current_size-1].marks.prog);
		 if (list[i+ current_size-1].marks.prog < 4) list[i+ current_size-1].marks.zad++;
		 printf("Philosophy mark: ");
		 scanf_s("%d", &list[i+ current_size-1].marks.phil);
		 if (list[i+ current_size-1].marks.phil < 4) list[i+ current_size-1].marks.zad++;
		 printf("OKT mark: ");
		 scanf_s("%d", &list[i+ current_size-1].marks.okt);
		 if (list[i+ current_size-1].marks.okt < 4) list[i+ current_size-1].marks.zad++;
		 printf("TI mark: ");
		 scanf_s("%d", &list[i+ current_size-1].marks.ti);
		 if (list[i+ current_size-1].marks.ti<4 ) list[i+ current_size-1].marks.zad++;
		 list[i+ current_size-1].marks.avarage = ((float)list[i+ current_size-1].marks.math + list[i+ current_size-1].marks.prog + list[i+ current_size-1].marks.phil + list[i+ current_size-1].marks.okt + list[i+ current_size-1].marks.ti) / 5;
		 current_size++;
	 }	
	 sort();
	 choice = 0;

}
void del() {
	defoltout();
	int d;
	printf("\nEnter number of string to delete: ");
	scanf_s("%d", &d);
	for (int i = d-1; i < current_size-1; i++) {
		list[i] = list[i + 1];
	}
	current_size--;
	choice = 0;
}
void change() {
	defoltout();
	printf("\n");
	int d, c,co;
	printf("Enter number of string to change : ");
	scanf_s("%d", &d);
	do {
		printf("\n1: Change group\n");
		printf("2: Change surname\n");
		printf("3: Change marks\n");
		scanf_s("%d", &c);
	} while ((c != 1) && (c != 2) && (c != 3));
	if (c == 1) {
		printf("Enter new group: ");
		scanf_s("%d", &list[d-1].group);
	}
	if (c == 2) {
		printf("Enter new surname: ");
		scanf_s("%s", list[d - 1].name);
	}
	if (c == 3) {
		do {
			printf("\n1: Change math mark\n");
			printf("2: Change programming mark\n");
			printf("3: Change philosophy mark\n");
			printf("4: Change okt mark\n");
			printf("5: Change ti marks\n");
			scanf_s("%d", &co);
		} while ((co != 1) && (co != 2) && (co != 3) && (co != 4) && (co != 5));
		if (co == 1) {
			printf("Enter new math mark: ");
			scanf_s("%d", &list[d - 1].marks.math);
		}
		if (co == 2) {
			printf("Enter new programming mark: ");
			scanf_s("%d", &list[d - 1].marks.prog);
		}
		if (co == 3) {
			printf("Enter new philosophy mark: ");
			scanf_s("%d", &list[d - 1].marks.phil);
		}
		if (co == 4) {
			printf("Enter new okt mark: ");
			scanf_s("%d", &list[d - 1].marks.okt);
		}
		if (co == 5) {
			printf("Enter new ti mark: ");
			scanf_s("%d", &list[d - 1].marks.ti);
		}
	}


	choice = 0;

	
}
void out() {
	int c,g;
	do {
		printf("\n1: Underperfoming\n");
		printf("2: Some group\n");
		scanf_s("%d", &c);
	}
		while ((c != 1) && (c != 2));
		if (c == 1) {
			for (int i = 0; i < current_size; i++) {
				if ((list[i].marks.math < 4) || (list[i].marks.prog < 4) || (list[i].marks.okt < 4) || (list[i].marks.phil < 4) || (list[i].marks.ti < 4)) {
					printf("%d) %s %d\n", list[i].group, list[i].name, list[i].marks.zad);
				}
			}
		}
		else {
			int kol=0;
			float a = 0;
			getchar();
			printf("Please, enter group: ");
			scanf_s("%d", &g);
				for (int i = 0; i < current_size; i++) {
					if (list[i].group == g) {
						printf("%s  ", list[i].name);
						printf("%.2f\n", list[i].marks.avarage);
						a += list[i].marks.avarage;
						kol++;
					}
				}
				a = a / kol;
				printf("\nGroup avarage %.2f\n", a);
		}
		choice = 0;
}

void defoltout() {
	for (int i = 0; i < current_size; i++) {
		printf("%d) %d %s\n", i+1,list[i].group, list[i].name);
	}
}


void sort() {
	struct Student temp;
	for (int i = 0; i < current_size-1; i++) {
		for (int j = i + 1; j < current_size; j++) {
			if (list[i].group > list[j].group) {
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
		}

	}
	
}