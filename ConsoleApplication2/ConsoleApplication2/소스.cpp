#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>


using namespace std;

int N, M;
int ans[5001];

class node{
	friend class jose;

	private:
	node *prev;
	node *next;
	int value;
	int visited;
 public :
	 node() { prev = this; next = this; value = NULL; visited = 0; }

	void attach(int data) {
		node *addnode = new node;
		addnode->value = data;
		addnode->next = this;
		this->prev->next = addnode;
		addnode->prev = this->prev;
		this->prev = addnode;

	 }
	int getValue() {

		return value;
	}
	node* getNext() {
		return next;
	}
	void setValue(int data) {
		this->value = data;
	}
	int getVisited() {
		return visited;
	}
	void setVisited() {
		visited = 1;
	}
};

void josephus(node *head) {
	node *tmp = head;
	int cnt = 0;

	while (cnt < N) {
		int move = 0;
		while (move < M - 1) {
			tmp = tmp->getNext();
			if (!(tmp->getVisited())) move++;
		}
			ans[cnt] = tmp->getValue();
			tmp->setVisited();
			if (cnt != N - 1) {
				tmp = tmp->getNext();
				while (tmp->getVisited()) {
					tmp = tmp->getNext();
				}
			}
			
		
	cnt++;
			

	}
}

int main() {
	cin >> N >> M;
	node a;
	a.setValue(1);
	for (int i = 1; i < N; i++) {
		a.attach(i + 1);
	}
	josephus(&a);
	cout << "<";
		for (int i = 0; i < N -1 ; i++) {
		cout << ans[i] <<", ";
	}
		cout << ans[N - 1] << ">\n";

   
}