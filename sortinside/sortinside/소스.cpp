
#include <string>
#include <iostream>
#include <algorithm>


using namespace std;
int counting_Arr[10];

int main() {
	string Qnum;
	cin >> Qnum;
	
	

	for (int i = 0; i < Qnum.size(); i++) {
		char tmp = Qnum[i];
		counting_Arr[tmp - 48]++;
	}
	for (int i = 9 ; i >= 0; i--) {
		while (counting_Arr[i]--)	printf("%d", i);
	}



}

