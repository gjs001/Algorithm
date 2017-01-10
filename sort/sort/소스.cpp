#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

/* STL을 활용한 정렬
int main() {
	int N;
	cin >> N;
	int Narray[1000];
	for (int i = 0; i < N; i++) cin >> Narray[i];
	sort(Narray, Narray + N);
	for (int i = 0; i < N; i++) cout << Narray[i] << endl;


}
*/


//병합정렬

void merge(int *test, int start, int end) {
	int nend = end - start;
	int mid = nend / 2;

		int i = 0;
		int j = mid+1;
		int k = 0;
		int len = end - start + 1;
		int *tmp = new int[len];
		while (i <= mid && j <= len -1 ) {
			
			if (test[i] <= test[j]) {
				tmp[k] = test[i];
				i++;
			}
			else {
				tmp[k] = test[j];
				j++;
			}
			k++;
		}
		int t = 0;
		if (i > mid)
			t = j;
		else
			t = i;
		for (k; k < len; k++, t++)
			tmp[k] = test[t];

		for (int i = 0 ; i < len ; i++) {
			test[i] = tmp[i];
		}

		tmp = NULL;
		delete tmp;
		




}
void merge_sort(int *test, int start, int end) {
	int mid = (start + end) / 2;
	if (start != end) {
			merge_sort(test, start, mid);
			merge_sort(test, mid + 1, end);
			merge(test + start, start, end);
			
	}
}



int main() {
	int N;
	cin >> N;
	int *Narray = new int[N];
	for (int i = 0; i < N; i++) scanf("%d",&Narray[i]);
	merge_sort(Narray, 0, N-1);
	for (int i = 0; i < N; i++) printf("%d\n", Narray[i]);
	delete Narray;
}