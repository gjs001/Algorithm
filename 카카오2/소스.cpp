#include <string>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;


bool checkcorrect(string u) 
{
	stack<char> st;
	bool ans = true;
	for (auto ch : u) {
		if (st.empty()) {
			st.push(ch);
			if (ch == ')') ans = false;
		}
		else if (st.top() == '(' && ch == ')') {
			st.pop();
		}
		else {
			st.push(ch);
		}
	}
	if (!st.empty()) ans = false;
	return ans;
}


string run(string u, string v) {

	int left = 0;
	int right = 0;
	if (v.size() != 0) {
		for (int i = 0; i < v.size(); i++) {
			char ch = v[i];
			if (ch == '(') left++;
			else if (ch == ')') right++;

			if (left != 0 && right != 0 && left == right) {
				string ret;
				if (i + 1 == v.size())ret = run(v.substr(0, i + 1), "");
				else ret = run(v.substr(0, i + 1), v.substr(i + 1, v.size() - (i + 1)));
				v = ret;
				break;
			}
		}
	}

	if (checkcorrect(u)) {
		return u + v;
	}
	else {
		string ans = "(";
		ans = ans + v + ")";
		string ret = "";
		for (int i = 1; i < u.size() - 1; i++) {
			ret += u[i] == '(' ? ')' : '(';
		}
		return ans + ret;
	}

}


string solution(string p) {
	string answer = "";
	if (p.empty()) return p;
	if (checkcorrect(p)) return p;
	else {
		int left = 0;
		int right = 0;
		for (int i = 0; i < p.size(); i++) {
			char ch = p[i];
			if (ch == '(') left++;
			else if (ch == ')') right++;

			if (left != 0 && right != 0 && left == right) {
				if (i + 1 == p.size()) answer = run(p.substr(0, i + 1), "");
				else answer = run(p.substr(0, i + 1), p.substr(i + 1, p.size() - (i + 1)));
				break;
			}
		}
	}
	return answer;
}

int main() {
	string k;
	cin >> k;
	cout << solution(k);
}