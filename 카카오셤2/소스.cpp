#include <iostream>

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int player[501];
typedef pair<double, int> pdi;
pdi failrate[200001];
bool cmp(pdi a, pdi b)
{
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	for (auto e : stages)
	{
		player[e]++;
	}
	int people = stages.size();
	for (int i = 1; i <= N; i++)
	{
		failrate[i].first = 1.0 * player[i] / people;
		failrate[i].second = i;
		people -= player[i];
	}
	sort(&failrate[1], &failrate[1] + N,cmp);
	for (int i = 1; i <= N; i++)
	{
		answer.push_back(failrate[i].second);
	}
	return answer;
}

int main()
{
	vector<int> a = { 2,2,2,2,2};
	vector<int> answer = solution(4,a);
	for (auto e : answer) cout << e << "\n";
}