#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Trie {
	bool finish;
	int cnt;    //������ ������ ǥ������
	Trie* next[26];    //26���� ���ĺ��� ���� Ʈ����
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
			finish = true;    //���ڿ��� ������ ������ ��� ǥ��
		else {
			int curr = *key - 'a';
			if (next[curr] == nullptr)
				next[curr] = new Trie();    //Ž���� ó���Ǵ� ������ ��� �����Ҵ�
			next[curr]->insert(key + 1);    //���� ���� ����
		}
	}
	Trie* find(const char* key) {
		if (*key == '?')return this;//���ڿ��� ������ ��ġ�� ��ȯ
		int curr = *key - 'a';
		if (next[curr] == nullptr)return nullptr;//ã�� ���� �������� ����
		return next[curr]->find(key + 1); //���� ���ڸ� Ž��
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