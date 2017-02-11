#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <stack>
#include <string>

using namespace std;

string qArr;
stack<int> A;
int Scount, Bcount;
int flag;
stack<char> B;

int cal_stack(int size) {
	int sum = 0;
	int prev = 0;
	for (int i = 0; i < size; i++) { // 해결한 반례 : (()[[()]])  [[()()]]

		if (qArr[i] == '(') { //i번째 값이 ( 일 때 B스택에 (넣음
			Scount++; // 오류체크용
			B.push('('); // 
			if (i > 0 && (qArr[i - 1] == '(' || qArr[i - 1] == '[')) { // [[()]] 등 연속된 곱셈값 계산 시
				flag++;
			}
			else // 연속된 곱셈 값이 아닐 때 flag 초기화 [[()() <<
			{
				flag = 0;
			}

		}
		else if (qArr[i] == '[') { // (와 동일
			Bcount++;
			B.push('[');
			if (i > 0 && (qArr[i - 1] == '(' || qArr[i - 1] == '[')) {
				flag++;
			}
			else
			{
				flag = 0;
			}

		}
		else if (qArr[i] == ')') { // )일 때 계산진행
			Scount--;
			if (Scount < 0 || B.top() == '[') return 0; // ( 없이 )가 닫혔을 시 or 마지막으로 열린 괄호가 [일 때 오류 리턴
			else if (qArr[i - 1] == '(') { // 덧셈 부분

				if (Bcount == 0 && Scount == 0) { // 최 외부일 때 이전 값 + 2
					prev += 2;

				}
				else { // 어느 괄호의 내부에 속해있을 때 계산 스택에 푸쉬
					A.push(2);
				}
				
				B.pop(); // 열림괄호 스택 pop
			}
			else if (qArr[i - 1] == ')' || qArr[i - 1] == ']') { // 곱셈 부분
				if (!flag && A.size() > 1) { //연속된 곱셈괄호가 아니고 내부에 덧셈이 필요한 값이 있을 때 (()()) ((()[])()) (()[](())) ([[]]()()[[()]]([]))
					while (!A.empty()) { // 계산 스택이 빌 때 까지
						sum += A.top(); // 계산 스택 내에 모든 값들 합산
						A.pop(); 
					}
					sum *= 2; //다 더한 값을 *2
					if (!(Scount == 0 && Bcount == 0)) { // 최 외각이 아닌 경우 계산한 값을 다시 스택에 넣어서 다음 계산에 대비
						A.push(sum);
					}
					else { // 최 외각인 경우 구한 값과 이전 값을 더하여 저장
						prev += sum;
					}
					sum = 0; // 다음 계산을 위한 초기화

					if (i == size - 1) return prev; //마지막 항일 경우 계산 값이 최종 답임(아마도 중복)
				}
				else { // 연속된 곱셈괄호인 경우 
					int tmp = A.top() * 2; // 계산 스택에 가장 위에 있는 값이 현재 계산 중인 연속된 곱셈괄호의 값임
					A.pop(); // 계산 후 이전 값은 pop
					A.push(tmp); // 새로 계산한 값 push
					flag--; // 연속된 곱셈괄호 확인용 flag
					if (Scount == 0 && Bcount ==0) { // 최 외각인 경우 이전 값에 더하여 갱신
						prev += A.top();
						A.pop();
					}
				}
				B.pop();
			}
			if (i == size - 1) return prev;  //마지막 항일 경우 계산 값이 최종 답임
		}
		else {
			Bcount--;
			if (Bcount < 0 || B.top() == '(') return 0;
			else if (qArr[i - 1] == '[') {

				if (Bcount == 0 && Scount == 0) {
					prev += 3;
				}
				else{
					A.push(3);
				}
				B.pop();
			}
			else if (qArr[i - 1] == ')' || qArr[i - 1] == ']') {
				if (!flag && A.size() > 1) {
					while (!A.empty()) {
						sum += A.top();
						A.pop();
					}
					sum *= 3;
					if (!(Scount == 0 && Bcount == 0)) {
						A.push(sum);
					}
					else {
						prev += sum;
					}
					sum = 0;

				}
				else {
					int tmp = A.top() * 3;
					A.pop();
					A.push(tmp);
					flag--;
					if (Bcount == 0 && Scount == 0) {
						prev += A.top();
						A.pop();
					}
				}
				B.pop();
			}
			if (i == size - 1) return prev;
		}

		if (i == size - 1) return 0;
		
	}


}

int main() {
	char tmp;
	int cnt = 0;
	//while ((tmp = getchar()) != '\n') {
	//	qArr[cnt++] = tmp;
	//}
	cin >> qArr;
	int ans = cal_stack(qArr.size());
	cout << ans;

}


/*

*/