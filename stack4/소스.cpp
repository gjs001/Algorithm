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
	for (int i = 0; i < size; i++) { // �ذ��� �ݷ� : (()[[()]])  [[()()]]

		if (qArr[i] == '(') { //i��° ���� ( �� �� B���ÿ� (����
			Scount++; // ����üũ��
			B.push('('); // 
			if (i > 0 && (qArr[i - 1] == '(' || qArr[i - 1] == '[')) { // [[()]] �� ���ӵ� ������ ��� ��
				flag++;
			}
			else // ���ӵ� ���� ���� �ƴ� �� flag �ʱ�ȭ [[()() <<
			{
				flag = 0;
			}

		}
		else if (qArr[i] == '[') { // (�� ����
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
		else if (qArr[i] == ')') { // )�� �� �������
			Scount--;
			if (Scount < 0 || B.top() == '[') return 0; // ( ���� )�� ������ �� or ���������� ���� ��ȣ�� [�� �� ���� ����
			else if (qArr[i - 1] == '(') { // ���� �κ�

				if (Bcount == 0 && Scount == 0) { // �� �ܺ��� �� ���� �� + 2
					prev += 2;

				}
				else { // ��� ��ȣ�� ���ο� �������� �� ��� ���ÿ� Ǫ��
					A.push(2);
				}
				
				B.pop(); // ������ȣ ���� pop
			}
			else if (qArr[i - 1] == ')' || qArr[i - 1] == ']') { // ���� �κ�
				if (!flag && A.size() > 1) { //���ӵ� ������ȣ�� �ƴϰ� ���ο� ������ �ʿ��� ���� ���� �� (()()) ((()[])()) (()[](())) ([[]]()()[[()]]([]))
					while (!A.empty()) { // ��� ������ �� �� ����
						sum += A.top(); // ��� ���� ���� ��� ���� �ջ�
						A.pop(); 
					}
					sum *= 2; //�� ���� ���� *2
					if (!(Scount == 0 && Bcount == 0)) { // �� �ܰ��� �ƴ� ��� ����� ���� �ٽ� ���ÿ� �־ ���� ��꿡 ���
						A.push(sum);
					}
					else { // �� �ܰ��� ��� ���� ���� ���� ���� ���Ͽ� ����
						prev += sum;
					}
					sum = 0; // ���� ����� ���� �ʱ�ȭ

					if (i == size - 1) return prev; //������ ���� ��� ��� ���� ���� ����(�Ƹ��� �ߺ�)
				}
				else { // ���ӵ� ������ȣ�� ��� 
					int tmp = A.top() * 2; // ��� ���ÿ� ���� ���� �ִ� ���� ���� ��� ���� ���ӵ� ������ȣ�� ����
					A.pop(); // ��� �� ���� ���� pop
					A.push(tmp); // ���� ����� �� push
					flag--; // ���ӵ� ������ȣ Ȯ�ο� flag
					if (Scount == 0 && Bcount ==0) { // �� �ܰ��� ��� ���� ���� ���Ͽ� ����
						prev += A.top();
						A.pop();
					}
				}
				B.pop();
			}
			if (i == size - 1) return prev;  //������ ���� ��� ��� ���� ���� ����
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