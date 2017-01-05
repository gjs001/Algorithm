#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>


using namespace std;
class node{
	friend class jose;

	private:
	node *prev;
	node *next;
	int value;
 public :
	 node() { prev = this; next = this; value = NULL; }

	void attach(int data) {
		node *addnode = new node;
		addnode->next = this->next;
		this->next->prev = addnode;
		addnode->prev = this;
		this->next = addnode;
		addnode->value = data;
	 }
};

class jose {
public:
	int rear;
	int front;
	int count;

	jose(int n) {
		rear = front = 0;
		count = n;
		node *root = new node;
		for (int i = 1; i <= n; i++) {
			root->attach(i);
		}
	}
};