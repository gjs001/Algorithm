#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;


int main() {
	int e = { 1 };
	int f = { 2 };
	int *g = &e;
	int *h = &f;
	int **a = &g;
	int **b = &h;

	
	int c[1];
	int *pc = c;


	int **pa = a;
	int **pb = b;
	int ***ppa = &pa;
	int ***ppb = &pb;

	int **temp;

	temp = *ppa;
	ppa = ppb;
	ppb = &temp;

	cout << ***ppa;
	cout << ***ppb;
	cout << a[0][0];
	cout << b[0][0];

}