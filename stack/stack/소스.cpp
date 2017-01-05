#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>


using namespace std;

typedef struct node {
	int data;
	struct node * next;
}node;


class stack {
	public:
		node *head;
		int size;


		void deleteAll();
		void push(int);
		int pop();
		int getSize();
		bool IsEmpty();
		int getTop();
		
		stack() { head = NULL; size = 0; }
		~stack() { deleteAll(); }


};


void stack::push(int v) {
	node *add = new node;
	add->data = v;

	if (IsEmpty()) {
		head = add;
		add->next = NULL;
	}
	else {
		add->next = head;
		head = add;
	}
	size++;
}
int stack::pop() {
	if (IsEmpty()) return -1;
	int pdata = head->data;
	node *tmp = head;
	head = head->next;
	delete tmp;
	tmp == NULL;
	size--;
	return pdata;
}
int stack::getSize() {
	return size;
}
bool stack::IsEmpty() {
	if (head == NULL) return 1;
	else return 0;
}

int stack::getTop() {
	if (IsEmpty()) return -1;
	return head->data;
}
void stack::deleteAll() {
	if (IsEmpty()) return;
	while (1) {
		if (IsEmpty()) return;
		node*tmp = head;
		head = head->next;

		delete tmp;
		tmp = NULL;

		size--;
		}
}

int main() {
	int N;
	cin >> N;
	stack ne;
	int ans[100000];

	for (int i = 0; i < N; i++) {
		char tmp[10];
		int qnum = 0;
		scanf("%s", &tmp);
		if (tmp[1] == 'u')
		{
			scanf("%d", &qnum);
			ne.push(qnum);
		}
		else if (tmp[1] == 'o' && tmp[0] == 'p') {
			cout << ne.pop() << endl;
		}
		else if (tmp[1] == 'i') {
			cout << ne.size << endl;
		}
		else if (tmp[1] == 'm') {
			cout << ne.IsEmpty() << endl;
		}
		else if (tmp[0] == 't') {
			cout << ne.getTop() << endl;
		}
	}


}