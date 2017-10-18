#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
using namespace std;

//1.���Ḯ��Ʈ // http://luckyyowu.tistory.com/324 << ������ ���� �����ϼ���. �� http://blog.naver.com/ehdqlstkrl/220844688867 �̰��� �ֽ��ϴ�.


typedef struct Node {
	Node* next;
	int data;
};

typedef struct List {
	Node* head;
	Node* tail;
};

List* new_LIst() {
	List *L = (List*)malloc(sizeof(List));
	L->head = NULL;
	L->tail = NULL;
	return L;
}

void createNode(List *L, int data) { // �� ��带 ����Ʈ�� ���� �߰�
	Node *newnode = (Node *)malloc(sizeof(Node));
	newnode->data = data;
	newnode->next = NULL;
	if (L->head == NULL && L->tail == NULL) {
		L->head = L->tail = newnode;
	}
	else {
		L->tail->next = newnode;
		L->tail = newnode;
	}
}

void deleteNode_data(List *L, int data) { // data���� �Ȱ��� ���� �����ִ� ��� ����
	Node *cur = L->head;
	if (cur->data == data) {
		Node* tmp = L->head;
		L->head = L->head->next;
		tmp->data = 0;
		tmp->next = NULL;
		free(tmp);
		return;
	}
	while (cur->next->data != data && cur->data != NULL) {
		cur = cur->next;
	}
	if (cur->data == NULL) return;
	Node *tmp = cur->next;
	cur->next = cur->next->next;
	tmp->data = 0;
	tmp->next = NULL;
	free(tmp);
	while (cur->next != NULL) {
		cur = cur->next;
	}
	L->tail = cur;
	return;
	

}

void delete_all(List *L) {
	Node *cur = L->head->next;
	L->head->next = NULL;
	free(L->head);
	Node *tmp;
	while (cur != NULL) {
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	L->head = L->tail = NULL;
}

void print_List(List* L) {
	if (L->head == NULL) {
		cout << "NULL\n";
		return;
	}
	Node *cur = L->head;
	while (cur != NULL) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << "\n";
	return;

}


// 2. ���� Ž�� Ʈ�� http://blog.eairship.kr/248 << ���� �����ؼ� �ۼ��߽��ϴ�. 

typedef struct bst_node {
	int data;
	bst_node *leftchild;
	bst_node *rightchild;
};

bst_node* createbstnode(int data) {
	bst_node* newnode = (bst_node*)malloc(sizeof(bst_node));
	newnode->leftchild = NULL;
	newnode->rightchild = NULL;
	newnode->data = data;
	return newnode;
}

void insertbstnode(bst_node* tree, bst_node* newnode) {
	if (newnode->data > tree->data) {
		if (tree->rightchild != NULL) insertbstnode(tree->rightchild, newnode);
		else tree->rightchild = newnode;
	}
	else if (newnode->data < tree->data) {
		if (tree->leftchild != NULL) insertbstnode(tree->leftchild, newnode);
		else tree->leftchild = newnode;
	}
}

bst_node* searchbstnode(bst_node* tree, int finddata) {
	if (tree == NULL) return NULL;
	if (tree->data == finddata)return tree;
	else if (tree->data > finddata) searchbstnode(tree->leftchild, finddata);
	else searchbstnode(tree->rightchild, finddata);
}

bst_node* findMinNode(bst_node* tree) {
	if (tree == NULL) return NULL;
	else if (tree->leftchild != NULL) return findMinNode(tree->leftchild);
	else return tree;
}

bst_node* findMaxNode(bst_node* tree) {
	if (tree == NULL) return NULL;
	else if (tree->rightchild != NULL) return findMaxNode(tree->rightchild);
	else return tree;
}

bst_node* removeNode(bst_node* tree, int data) {
	bst_node *tmp;
	if (tree == NULL) cout << "error";
	else if (tree->data > data) tree->leftchild = removeNode(tree->leftchild, data);
	else if (tree->data < data) tree->rightchild = removeNode(tree->rightchild, data);
	else {
		if (tree->leftchild != NULL && tree->rightchild != NULL) {
			tmp = findMinNode(tree->rightchild);
			tree->data = tmp->data;
			tree->rightchild = removeNode(tree->rightchild, tmp->data);
		}
		else {
			tmp = tree;
			if (tree->leftchild == NULL) tree = tree->rightchild;
			else if (tree->rightchild == NULL) tree = tree->leftchild;
			free(tmp);
		}
	}
	return tree;
}

void printTree(bst_node* tree)
{
	if (tree == NULL) return;
	printTree(tree->leftchild);
	printf("%d ", tree->data);
	printTree(tree->rightchild);
}

int main()
{
	// 1. ���Ḯ��Ʈ ����
	List* root = new_LIst();
	createNode(root, 3);
	createNode(root, 7);
	createNode(root, 8);
	createNode(root, 1);
	createNode(root, 2);
	print_List(root);
	deleteNode_data(root, 8);
	print_List(root);
	delete_all(root);
	print_List(root);

	// 2. ���� Ž�� Ʈ�� ���� 
	bst_node* Tree = createbstnode(10);
	bst_node* findNode;
	int input;

	insertbstnode(Tree, createbstnode(5));
	insertbstnode(Tree, createbstnode(1));
	insertbstnode(Tree, createbstnode(6));
	insertbstnode(Tree, createbstnode(17));
	insertbstnode(Tree, createbstnode(14));
	insertbstnode(Tree, createbstnode(21));

	while (1)
	{
		scanf("%d", &input);
		findNode = searchbstnode(Tree, input);

		if (findNode != NULL)
		{
			printf("�ش� ��带 ã�ҽ��ϴ�! ��带 �����մϴ�. ����� ��ġ�� %#x �Դϴ�.\n", findNode);
			removeNode(Tree, input);
			printf("���� Ʈ�� ���: ");
			printTree(Tree); printf("\n");
		}
		else printf("��带 ã�� �� �������ϴ�.\n");

	}

	return 0;
}
