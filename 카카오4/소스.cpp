#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Trie {
	bool finish;
	int cnt;    //끝나는 지점을 표시해줌
	Trie* next[26];    //26가지 알파벳에 대한 트라이
	Trie() : finish(false), cnt(0) {
		memset(next, 0, sizeof(next));
	}
	~Trie() {
		for (int i = 0; i < 26; i++)
			if (next[i])
				delete next[i];
	}
	void insert(const char* key) {
		cnt++;
		if (*key == 0 || *key == '?')
			finish = true;    //문자열이 끝나는 지점일 경우 표시
		else {
			int curr = *key - 'a';
			if (next[curr] == nullptr)
				next[curr] = new Trie();    //탐색이 처음되는 지점일 경우 동적할당
			next[curr]->insert(key + 1);    //다음 문자 삽입
		}
	}
	Trie* find(const char* key) {
		if (*key == '?')return this;//문자열이 끝나는 위치를 반환
		int curr = *key - 'a';
		if (next[curr] == nullptr)return nullptr;//찾는 값이 존재하지 않음
		return next[curr]->find(key + 1); //다음 문자를 탐색
	}
};
Trie* forw[10001];
Trie* backw[10001];

void makeTrie(string s) {
	int size = s.size();
	if(forw[size] == nullptr) forw[size] = new Trie(); 
	forw[size]->insert(s.c_str());
	if (backw[size] == nullptr) backw[size] = new Trie();
	reverse(s.begin(), s.end());
	backw[size]->insert(s.c_str());
}

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	answer.resize(queries.size(),0);
	for (auto str : words) {
		makeTrie(str);
	}
	for (int i = 0; i < queries.size();i++) {
		string str = queries[i];
		int size = str.size();
		if (str[0] == '?') {
			if (backw[size] != nullptr) {
				reverse(str.begin(), str.end());
				Trie* ret = backw[size]->find(str.c_str());
				if (ret != nullptr) answer[i] += ret->cnt;
			}
		}
		else {
			if (forw[size] != nullptr) {
				Trie* ret = forw[size]->find(str.c_str());
				if (ret != nullptr)answer[i] += ret->cnt;
			}
		}
	}
	return answer;
}

int main() {
	vector<string> words = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
	vector<string> queries = { "fro??", "????o", "fr???", "fro???", "pro?" };
	vector<int> a;
	a.resize(queries.size());
    a = solution(words, queries);
	for (auto s : a) cout << s << " ";
}