#include <stdio.h>
#include <time.h>

int count = 1, l = 0, r = 0, g = 0, nap = 0, n;
int a[100];
int b[15];

struct tnode {
	int field;           // поле данных
	struct tnode *left;  // левый потомок
	struct tnode *right; // правый потомок
};


struct tnode * addnode(int x, struct tnode *tree) {
	if (tree == NULL) {
		tree = (struct tnode*)malloc(sizeof(struct tnode));
		tree->field = x;
		tree->left = NULL;
		tree->right = NULL;
	}
	else  if (x < tree->field) {
		tree->left = addnode(x, tree->left);
	}
	else {
		tree->right = addnode(x, tree->right);
	}
	return(tree);
}

struct tnode * init(struct tnode *tree, int b, int e) {
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







void find(struct tnode *tree,int c) {
	if (tree != NULL) {
		if ((tree->left!=0)|| (tree->right != 0)) c++;
		find(tree->left,c);
		find(tree->right,c);
	}
	if (c > count) count = c;
}

void treeprint(struct tnode *p, int level) {
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
	scanf_s("%d", &n);
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



	Head = init(Head, 0, 14);


	treeprint(Head, 1);
	int d;
	//Head = init(Head);
	printf("\n");
	//printf("Please,enter elements you wsnt to find: ");
	//scanf_s("%d", &d);
	printf("\n");
	find(Head,count);
	printf("The largest podderevo: %d \n", count);


	system("pause");
	return 0;
}