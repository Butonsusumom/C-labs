
#include <stdio.h>
#include <time.h>

int count=0,l=0,r=0,g=0,nap=0,n;
int a[100];
int b[15];

struct tnode {
	int field;           // поле данных
	struct tnode *left;  // левый потомок
	struct tnode *right; // правый потомок
};


struct tnode * addnode(int x, struct tnode *tree) {
	if (tree == NULL) { // Если дерева нет, то формируем корень
		tree = (struct tnode*)malloc(sizeof(struct tnode));
		//new (tree); // память под узел
		tree->field = x;   // поле данных
		tree->left = NULL;
		tree->right = NULL; // ветви инициализируем пустотой
	}
	else  if (x < tree->field) {  // условие добавление левого потомка
		tree->left = addnode(x, tree->left);
	}
	else {  // условие добавление правого потомка
		tree->right = addnode(x, tree->right);
	}
	return(tree);
}

struct tnode * init(struct tnode *tree,int b,int e) {
	/*int el;
	int center;
	
	if (nap == 0) {  el = a[(e - b) / 2]; 
	center =( e - b) / 2;
	}
	if (nap == 1) {  el = a[(e + b) / 2]; 
	center = (e + b) / 2;
	}
		tree = addnode(el, tree);
		g++;
		if (((e - b) / 2 - 1 >= 0) && ((e + b) / 2 + 1 <= 14)&&(g<=15)) {
		//tree = init(tree, (e - b) / 2 + 1, e);
		nap = 0;
		tree = init(tree, b, center -1);
		nap = 1;
		tree = init(tree,center+1, e);
	}*/
	for (int i = 0; i < n; i++) {
		tree = addnode(a[i], tree);
	}
	return (tree);
}







void find(struct tnode *tree, int a) {
	if (tree != NULL) { //Пока не встретится пустой узел
		if (a == tree->field) count++; //Отображаем корень дерева
		find(tree->left,a); //Рекурсивная функция для левого поддерева
		find(tree->right,a); //Рекурсивная функция для правого поддерева
	}
}

	void treeprint(struct tnode *p,int level) {
		if (p != NULL) {

			treeprint(p->right, level + 1);
			for (int i = 0; i < level; i++) printf("  ");
			printf("%d\n", p->field);
			treeprint(p->left, level + 1);


			
		}
	}

int main() {
	int e;
	printf("Please,enter nuber elements in tree: ");
	scanf_s("%d",&n);
	printf("\n");
	
	struct tnode *Head;
	struct tnode *root;
	Head = (struct tnode*)malloc(sizeof(struct tnode));
	Head = NULL;
	//Head->left = NULL;
	//Head->right = NULL;
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		e = rand() % 15;
		a[i] = e;
	}

/*	for (int i = 0; i < n - 1; i++) {
		for (int j = i+1; j < n; j++) {
			if (a[j] < a[i]) {
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}*/

	Head = init(Head,0,14);
	
	
	treeprint(Head,1);
	int d;
	//Head = init(Head);
	printf("\n");
	printf("Please,enter elements you wsnt to find: ");
	scanf_s("%d", &d);
	printf("\n");

	find(Head, d);
	printf("Element %d, enters in tree %d times\n", d, count);


	system("pause");
	return 0;
}