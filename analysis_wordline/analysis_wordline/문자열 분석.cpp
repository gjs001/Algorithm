#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <string>
#include <cstring> 


using namespace std;

char sArr[102]; 
int main() {
	


	int c;
	int small = 0;
	int big = 0;
	int num = 0;
	int space = 0;
	int len;

	while(fgets(sArr, 102, stdin) != '\0') { // EOF가 들어왔을 때까지 입력받음
		// 동일한 표현  >>>  if (feof(stdio)) break;
		len = strlen(sArr);
		for (int i = 0; i < len; i++) {
			if ('a' <= sArr[i] && sArr[i] <= 'z') small++;
			else if ('A' <= sArr[i] && sArr[i] <= 'Z') big++;
			else if ('0' <= sArr[i] && sArr[i] <= '9') num++;
			else if (' ' == sArr[i]) space++;
		}

		printf("%d %d %d %d\n", small, big, num, space);
		small = big = num = space = 0;

	}

}