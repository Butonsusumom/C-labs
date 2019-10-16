#include <stdio.h>

struct  _Node *last, *head, *h, *l;
char temp;

typedef struct _Node {
	char value;
	struct _Node *next;
	struct _Node *prev;
} Node;

typedef struct _DblLinkedList {
	size_t size;
	Node *head;
	Node *tail;
} DblLinkedList;

struct  _Node * init(char a)  // а- значение первого узла
{
	struct  _Node *lst;
	// выделение памяти под корень списка
	lst = (struct  _Node*)malloc(sizeof(struct  _Node));
	head = lst;
	lst->value = a;
	lst->next = NULL; // указатель на следующий узел
	lst->prev = NULL; // указатель на предыдущий узел
	return(lst);
}

struct _Node * addelem(struct _Node * lst, char number)
{
	struct _Node *temp, *p;
	temp = (struct _Node*)malloc(sizeof(struct _Node));
	p = lst->next; // сохранение указателя на следующий узел
	lst->next = temp; // предыдущий узел указывает на создаваемый



	temp->value = number; // сохранение поля данных добавляемого узла
	temp->next = p; // созданный узел указывает на следующий узел
	temp->prev = lst; // созданный узел указывает на предыдущий узел
	if (p != NULL)
		p->prev = temp;
	return(temp);
}
 
int main() {
	//struct _Node* Node;
	int n;
	char c;
	printf("Please, enter the number of balls: ");
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++) {
		printf("Please, enter the colour of ball number %d: ",i+1);
		getchar();
		scanf_s("%c",&c);
		if (i == 0)  last=init(c);
		else last=addelem(last,c);
	}
	h = head;
	l = last;
	int k = 0,count=0;
	while (k <n) {
		while ((h->value != 'b')&&(k<n)) {
			h = h->next;
			k++;
		}
		k++;
		while ((l->value != 'w')&&(k<n)) {
			l = l->prev;
			k++;
		}
		k++;
		if ((h->value == 'b') && (l->value == 'w')&&(k<n)) {
			temp = h->value;
			h->value = l->value;
			l->value = temp;
			h = h->next;
			l = l->prev;
			count++;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%c\n", head->value);
		head = head->next;
	}
	printf("%d permutations done\n", count);




	system("pause");
	return 0;
}