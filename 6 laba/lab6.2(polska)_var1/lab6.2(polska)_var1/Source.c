#include <stdio.h>
#include <time.h>


int count = 1, l = 0, r = 0, g = 0, nap = 0, n;
int a[100];
int b[15];
int size = 13;

struct tnode {
	struct tnode *parent;
	int checked;
	char field;           // поле данных
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
	for (int i = 0; i < n; i++) {
		tree = addnode(a[i], tree);
	}
	return (tree);
}

struct tnode * Poskinit(struct tnode *tree) {
	struct tnode *node, *node1, *node2, *node3;
	tree = (struct tnode*)malloc(sizeof(struct tnode));
	tree->parent = (struct tnode*)malloc(sizeof(struct tnode));
	tree->parent->right = NULL;
	tree->parent->left = NULL;
	tree->field = '*';//head
	tree->checked = 0;
	tree->left = NULL;																		
	tree->right = NULL;

	//Left Head
		
		tree->left = (struct tnode*)malloc(sizeof(struct tnode));
		tree->left->parent = tree;
		node= tree->left;
		node->field = '+';
		node->checked = 0;
		node->left = NULL;
		node->right = NULL;

			//Left Node 1
				
				node->left = (struct tnode*)malloc(sizeof(struct tnode));
				node->left->parent = node;
				node = node->left;
				node->field = 'a';
				node->checked = 0;
				node->left = NULL;
				node->right = NULL;
				
			//Right Node 1
				node = node->parent;
				node->right = (struct tnode*)malloc(sizeof(struct tnode));
				node->right->parent = node;
				node = node->right;
				node->field = 'b';
				node->checked = 0;
				node->left = NULL;
				node->right = NULL;

	//Right Head

		tree->right = (struct tnode*)malloc(sizeof(struct tnode));
		tree->right->parent = tree;
		node = tree->right;
		node->field = '*';
		node->checked = 0;
		node->left = NULL;
		node->right = NULL;

			//Left Node 2
				node->left = (struct tnode*)malloc(sizeof(struct tnode));
				node->left->parent = node;
				node = node->left;
				node->field = 'c';
				node->checked = 0;
				node->left = NULL;
				node->right = NULL;

						

			//Right Node 2
				node = node->parent;
				node->right = (struct tnode*)malloc(sizeof(struct tnode));
				node->right->parent = node;
				node = node->right;
				node->field = '^';
				node->checked = 0;
				node->left = NULL;
				node->right = NULL;

					//Left Node 3
						node->left = (struct tnode*)malloc(sizeof(struct tnode));
						node->left->parent = node;
						node1 = node->left;
						node1->field = '-';
						node1->checked = 0;
						node1->left = NULL;
						node1->right = NULL;

						//Left Node1 4
							node1->left = (struct tnode*)malloc(sizeof(struct tnode));
							node1->left->parent = node1;
							node2 = node1->left;
							node2->field = 'y';
							node2->checked = 0;
							node2->left = NULL;
							node2->right = NULL;

						//Right Node1 4
							node1->right = (struct tnode*)malloc(sizeof(struct tnode));
							node1->right->parent = node1;
							node2 = node1->right;
							node2->field = '*';
							node2->checked = 0;
							node2->left = NULL;
							node2->right = NULL;

								//Left Node2 5
									node2->left = (struct tnode*)malloc(sizeof(struct tnode));
									node2->left->parent = node2;
									node3 = node2->left;
									node3->field = 'g';
									node3->checked = 0;
									node3->left = NULL;
									node3->right = NULL;

								//Right Node2 5 
									node2->right = (struct tnode*)malloc(sizeof(struct tnode));
									node2->right->parent = node2;
									node3 = node2->right;
									node3->field = 'd';
									node3->checked = 0;
									node3->left = NULL;
									node3->right = NULL;

					//Right Node 3
						node->right = (struct tnode*)malloc(sizeof(struct tnode));
						node->right->parent = node;
						node1 = node->right;
						node1->field = 'n';
						node1->checked = 0;
						node1->left = NULL;
						node1->right = NULL;

	return (tree);
}



void сreatePol(struct tnode *tree) {
	struct tnode *node = tree;
	int count=0;
	while (count < size) {
		if (node->left != NULL) {
			if (node->left->checked == 0) {
				node = node->left;
				continue;
			}
		}
		 {
			if (node->checked == 0) {
				printf("%c", node->field);
				count++;
				node->checked = 1;
			}
			node = node->parent;
			if (node->right != NULL) {
				if (node->right->checked == 0) {
					node = node->right;
				}
			}
		}


	}
}




void find(struct tnode *tree, int c) {
	if (tree != NULL) {
		if ((tree->left != 0) || (tree->right != 0)) c++;
		find(tree->left, c);
		find(tree->right, c);
	}
	if (c > count) count = c;
}

void treeprint(struct tnode *p, int level) {
	if (p != NULL) {

		treeprint(p->right, level + 1);
		for (int i = 0; i < level; i++) printf("  ");
		printf("%c\n", p->field);
		treeprint(p->left, level + 1);



	}
}

int main() {
	int e;
	//printf("Please,enter nuber elements in tree: ");
//	scanf_s("%d", &n);
	printf("      (a+b)*c*(y-g*d)^n");
	printf("\n");
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


	Head = Poskinit(Head);
	//Head = init(Head, 0, 14);


	treeprint(Head, 1);
	int d;
	//Head = init(Head);
	printf("\n");
	//printf("Please,enter elements you wsnt to find: ");
	//scanf_s("%d", &d);
	printf("\n");
	//find(Head, count);
	printf("\nThe Reverse Polish entry :");
	сreatePol(Head);
	printf("\n");



	system("pause");
	return 0;
}