#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
using namespace std;

typedef struct node {
	int data;
	struct node *next;
}node;

class que {

public:
	node *front;
	node *rear;
	int size;

	void deleteAll();
	void sizeincrease() { size++; }
	void sizedecrease() { if(size>0) size--; }


	que() {
		front = NULL;
		rear = NULL;
		size = 0;
	}
	~que() {
		deleteAll();
	}

	bool Isempty() {
		if (front == NULL)
			return true;
		else
			return false;
	}


	void push(int v) {
		node *add = new node;
		add->data = v;
		add->next = NULL;
		if (Isempty())
			front = add;
		else
			rear->next = add;

		rear = add;
		
		sizeincrease();
	}

	int pop() {
		if (Isempty()) return -1;
		node* cur = front;
		int d = cur->data;
		front = front->next;

		delete cur;
		cur = NULL;
		if (Isempty()) rear = NULL;
		sizedecrease();
		return d;

	}
	int frontdata() {
		if (Isempty()) { return -1; }
		else
		return front->data;
	}
	int backdata() {
		if (Isempty()) { return -1; }
		else
			return rear->data;
	}
	
};
void que::deleteAll() {
	if (Isempty()) return;
	while (1) {
		if (Isempty()) return;
		node* cur = front;
		front = front->next;

		delete cur;
		cur = NULL;
		if (Isempty()) rear = NULL;
		sizedecrease();
	}
}


int main() {
	int N;
	cin >> N;
	que ne;
	int ans[100000];

	for (int i = 0; i < N; i++) {
		char tmp[10];
		int qnum=0;
		scanf("%s", &tmp);
		if (tmp[1] == 'u')
		{
			scanf("%d", &qnum);
			ne.push(qnum);
		}
		else if (tmp[1] == 'r') {
			cout << ne.frontdata() << endl;
		}
		else if (tmp[1] == 'a') {
			cout << ne.backdata() << endl;
		}
		else if (tmp[1] == 'o') {
			cout << ne.pop() << endl;
		}
		else if (tmp[1] == 'i') {
			cout << ne.size << endl;
		}
		else if (tmp[1] == 'm') {
			cout << ne.Isempty() << endl;
		}
	}


}