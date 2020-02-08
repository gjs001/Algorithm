#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;
vector<pii> sfood;
bool cmp(pii a, pii b)
{
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}
int solution(vector<int> food_times, long long k) {
	vector<int> visit;
	int answer = 0;
	long long orik = k;
	k++;
	int num = food_times.size();
	visit.resize(num, 0);
	sfood.clear();
	sfood.resize(num);
	for (int i=0;i<num;i++)
	{
		sfood[i].first = food_times[i];
		sfood[i].second = i;
	}
	sort(sfood.begin(), sfood.end(),cmp);
	int st = 0;
	for (auto p : sfood)
	{

		k -= (long long)1*(p.first - st) * num;
		st = p.first;
		if (k <= 0) break;
		visit[p.second] = 1;
		num--;

		if (k <= 0) break;
	}
	int fsize = food_times.size();
	if(k + num <= 0)
	{
		k -= k / num * num;
	}

	for (int i = fsize - 1; i >= 0 && k <= 0; i--)
	{
		if (visit[i]) continue;
		
		if (k == 0) {
			answer = i + 1;
			break;
		}
		k++;
	}

	if (answer == 0) answer = -1;
	return answer;
}

int main()
{
	vector<int> food = {1,2,3,4,5};
	//cout << solution(food, 5) << "\n";
	for (int i = 1; i < 15; i++)
	{
		cout << solution(food, i) << "\n";
	}
}