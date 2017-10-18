#include <iostream>

using namespace std;

struct s_word {
	char data;
	s_word* left;
	s_word* right;
	s_word() { data = 0; left = NULL; right = NULL; };
	s_word(char d) { data = d; left = NULL; right = NULL; }
};

s_word* add_word(s_word *cur, char data) {

	s_word * tmp = new s_word(data);
	tmp->right = cur->right;
	if(tmp->right != NULL) tmp->right->left = tmp;
	cur->right = tmp;
	tmp->left = cur;
	return tmp;
}

s_word* delete_word(s_word *cur) {
	if (cur->data == 0) return cur;
	s_word *tmp = cur;
	s_word *nextcur = tmp->left;
	if (tmp->left != NULL) tmp->left->right = tmp->right;
	if (tmp->right != NULL) tmp->right->left = tmp->left;
	tmp->right = tmp->left = NULL;
	tmp->data = 0;
	delete tmp;
	return nextcur;
}

int main() {
	char d;
	s_word *cur = new s_word;
	s_word *root = cur;
	while ((d = getchar()) != '\n') {
		cur = add_word(cur, d);
	}
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		char cmd;
		char text;
		scanf("%*c %c", &cmd);
		if (cmd == 'P') {
			scanf("%*c %c", &text);
			cur = add_word(cur, text);
		}
		else if (cmd == 'B') {
			cur = delete_word(cur);
		}
		else if (cmd == 'L') {
			if(cur->data != 0) cur = cur->left;
		}
		else {
			if (cur->right != 0) cur = cur->right;
		}
	}
	root = root->right;
	while (root != NULL) {
		printf("%c", root->data);
		root = root->right;
	}
}